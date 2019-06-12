from math import sqrt, sin, cos, pi

import matplotlib.pyplot as plt
import numpy as np
from scipy.constants import g as G
from scipy.integrate import odeint

from integrate.runge_kutta import rk4


def model_free_fall_motion(y, t, k1, k2, g, m):
    """
    Модель свободного падения тела с учетом сопротивления воздуха.
    Единицы измерения СИ.
    """
    x, h, vx, vh = y

    dxdt = vx
    dhtd = vh

    dvx_dt = (m * g - k1 * vx - k2 * vx * vx) / m
    dvh_dt = (m * g - k1 * vh - k2 * vh * vh) / m

    return dxdt, dhtd, dvx_dt, dvh_dt


def model_si(y, t, k1_up, k2_up, k1_par, k2_par, g, m, eps):
    """
    Модель запуска тела под углом к горизонту с учетом сопротивления воздуха.
    Единицы измерения СИ.
    Связанные ОДУ (вектор).
    Параметры k1, k2, k2_par, g, m, передаются при вызове решателя.
    """
    xx, yy, vx, vy = y
    if vy < eps:
        k2 = k2_par
        k1 = k1_par
    else:
        k2 = k2_up
        k1 = k1_up

    dxdt = vx
    dydt = vy

    dv_xdt = (- (k1 + k2 * sqrt(vx**2 + vy**2)) / m) * vx
    dv_ydt = -g - ((k1 + k2 * sqrt(vx**2 + vy**2)) / m) * vy

    return [dxdt, dydt, dv_xdt, dv_ydt]


def model_dimensionless_quantities(y, t, a, b, alpha):
    """
    Модель запуска тела под углом к горизонту с учетом сопротивления воздуха.
    Безразмерные единицы измерения.
    Связанные ОДУ (вектор).
    Параметры a, b, alpha передаются при вызове решателя.
    """
    xx, yy, vx, vy = y
    dxdt = vx / (2.0 * cos(alpha))
    dydt = (2.0 * vy) / sin(alpha)

    dvxdt = -a * vx * sin(alpha) - b * vx * sin(alpha) * ((vx**2 + vy**2)**0.5)

    dvydt = -sin(alpha) - a * vy * sin(alpha) - b * sin(alpha) * vy * ((vx**2 + vy**2)**0.5)

    return dxdt, dydt, dvxdt, dvydt


def modeling_SI():
    """Моделирование в единицах СИ."""
    # зонд - шаровид.  формы
    DRAG_COEFFICIENT = 0.5  # коэффициент c, шар
    k1 = 0.1  # пренебречь - скорость
    k2 = 0.5 * DRAG_COEFFICIENT * pi * 0.25 * 0.25 * 1.29
    rho_air = 1.29
    S_par = 50  # площадь купола парашута
    k1_par = 6 * pi * 0.02 * 12
    k2_par = 0.5 * 1.33 * rho_air * S_par

    alpha = 90.0  # угол запуска относительно оси X в градусах
    alpha = alpha * (pi / 180.0)  # в радианах

    m = 100.0  # 120 кг
    g = G
    eps = 0.001

    v_plane = 12.0  # по инф. из мнтернета
    v0 = 120.0  # 100 м \ с
    v0x = v0*cos(alpha) + v_plane  # + скорость самолета
    v0y = v0*sin(alpha)

    X0 = 0.0
    Y0 = 15000.0  # начальная высота 15 000 метров

    y0 = [X0, Y0, v0x, v0y]  # начальные условия
    t = np.linspace(0., 120, 100)

    # sol = odeint(model2, y0, t, args=(k1, k2, g, m))

    solution_rk4 = odeint(  # решение своей реализацией метода Рунге-Кутты (4)
            model_si,
            y0,
            t,
            args=(k1, k2, k1_par, k2_par, g, m, eps)
        )

    X = solution_rk4[:, 0]
    Y = solution_rk4[:, 1]
    VX = solution_rk4[:, 2]
    VY = solution_rk4[:, 3]
    
    # max_ind = np.where(
    #     solution_rk4 == np.amax(solution_rk4[:, 1])
    # )

    # X2 = solution_rk4[:, 0][:max_ind[0][0]]
    # Y2 = solution_rk4[:, 1][:max_ind[0][0]]

    # VX = solution_rk4[:, 2][:max_ind[0][0]]
    # VY = solution_rk4[:, 3][:max_ind[0][0]]

    #  free fall modeling
    # x0_free_fall = X2[-1]
    # y0_free_fall = Y2[-1]
    # vx_ff = VX[-1]
    # vy_ff = VY[-1]

    # solution_free_fall = rk4(
    #     f=model_free_fall_motion,
    #     y0=(x0_free_fall, y0_free_fall, vx_ff, 0.0),
    #     t=t,
    #     args=(k1, 0, g, m)
    # )

    # X_ff = solution_free_fall[:, 0]
    # Y_ff = solution_free_fall[:, 1]

    with plt.style.context(('ggplot')):
        # plt.plot(X_ff, Y_ff, 'r--')
        plt.plot(X, Y, 'g')

        # обязательно настроить, иначе график будет отображаться криво
        plt.axis('equal')
        plt.grid(
            color='b',
            linestyle=':',
            linewidth=0.5
        )

    plt.show()
    with plt.style.context(('ggplot')):
        # plt.plot(X_ff, Y_ff, 'r--')
        plt.plot(t, VY, 'r--')

        # обязательно настроить, иначе график будет отображаться криво
        plt.axis('equal')
        plt.grid(
            color='b',
            linestyle=':',
            linewidth=0.5
        )

    plt.show()


def modeling_dimensionless_quantities():
    """
    Dimensionless quantities - безразмерные единицы.
    Моделирование в безразмерных единицах.
    """
    # зонд - шаровид.  формы
    DRAG_COEFFICIENT = 0.5  # c, шар
    k1 = 0.2  # пренебречь
    k2 = 0.5 * DRAG_COEFFICIENT * pi * 0.25 * 0.25 * 1.29

    alpha_ = 100.0  # в градусах
    angle_2 = 45.0

    alpha = (alpha_ * pi) / 180.0  # в радианах
    angle_2_rad = (angle_2 * pi) / 180.0
    m = 120.0
    g = G

    v_plane = 0
    v0 = 123
    v0x = cos(alpha) + v_plane  # + начальная скорость самолета
    v0y = sin(alpha)

    X0 = 0
    Y0 = 0  # начальная высота

    a = (k1 * v0) / (m * g)
    b = (k2 * v0 * v0) / (m * g)
    # TODO: добавить нач. скорость самолета в безразмерные и нач. высоту
    y0 = [X0, Y0, v0x, v0y]
    t = np.linspace(0., 1, 200)

    # решение решателем odeint
    solution_odeint = odeint(
            model_dimensionless_quantities,
            y0,
            t,
            args=(a, b, alpha)
        )

    # решение своей реализацией метода Рунге-Кутты (4)

    solution_rk4 = rk4(
            model_dimensionless_quantities,
            y0,
            t,
            args=(a, b, alpha)
        )

    X = solution_odeint[:, 0]
    Y = solution_odeint[:, 1]

    max_ind = np.where(
        solution_rk4 == np.amax(solution_rk4[:, 1])
    )

    X2 = solution_rk4[:, 0][:max_ind[0][0]]
    Y2 = solution_rk4[:, 1][:max_ind[0][0]]

    with plt.style.context(('ggplot')):
        plt.plot(X, Y, 'r--')
        plt.plot(X2, Y2, 'g')

        # обязательно настроить, иначе график будет отображаться криво
        plt.axis()
        plt.grid(
            color='b',
            linestyle=':',
            linewidth=0.5
        )

    plt.show()


if __name__ == "__main__":
    modeling_SI()
    # modeling_dimensionless_quantities()
