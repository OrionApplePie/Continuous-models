from math import sqrt, sin, cos, pi

import matplotlib.pyplot as plt
import numpy as np
import scipy.constants as CONST 
from scipy.integrate import odeint

from integrate.runge_kutta import rk4


def model_dimensionless_quantities(y, t, a, b, alpha):
    """
    Модель запуска тела под углом к горизонту с учетом сопротивления воздуха.
    Безразмерные единицы измерения.
    Связанные ОДУ (вектор).
    Параметры a, b, alpha передаются при вызове решателя.
    """
    xx, yy, vx, vy = y

    dxdt = vx / (2 * cos(alpha))
    dydt = 2 * vy / (sin(alpha))

    dvxdt = -a * sin(alpha) * vx
    - b * sin(alpha) * sqrt(vx*vx + vy*vy) * vx
    dvydt = -sin(alpha)
    - a * sin(alpha) * vy
    - b * sin(alpha) * sqrt(vx*vx + vy*vy) * vy

    return [dxdt, dydt, dvxdt, dvydt]


def model_si(y, t, k1, k2, g, m):
    """
    Модель запуска тела под углом к горизонту с учетом сопротивления воздуха.
    Единицы измерения СИ.
    Связанные ОДУ (вектор).
    Параметры k1, k2, g, m, передаются при вызове решателя.
    """
    xx, yy, vx, vy = y

    dxdt = vx
    dydt = vy

    dv_xdt = (- (k1 + k2 * (vx**2 + vy**2) ** 0.5) / m) * vx
    dv_ydt = -g - ((k1 + k2 * (vx**2 + vy**2) ** (0.5)) / m) * vy

    return [dxdt, dydt, dv_xdt, dv_ydt]


def modeling_SI():
    """Моделирование в единицах СИ."""
    # зонд - шаровид.  формы
    DRAG_COEFFICIENT = 0.5  # коэффициент c, шар
    k1 = 0.0  # пренебречь - скорость
    k2 = 0.5 * DRAG_COEFFICIENT * pi * 0.25 * 0.25 * 1.29

    alpha = 90.0  # угол запуска относительно оси X в градусах
    alpha = alpha * pi / 180.0  # в радианах

    m = 120.0  # 120 кг
    g = CONST.g

    v_plane = 222.0  # по инф. из мнтернета
    v0 = 100.0  # 100 м \ с
    v0x = v0*cos(alpha) + v_plane  # + скорость самолета
    v0y = v0*sin(alpha)

    X0 = 0.0
    Y0 = 15000.0  # начальная высота 15 000 метров

    y0 = [X0, Y0, v0x, v0y]  # начальные условия
    t = np.linspace(0., 5, 100)

    # sol = odeint(model2, y0, t, args=(k1, k2, g, m))

    solution_rk4 = rk4(  # решение своей реализацией метода Рунге-Кутты (4)
            model_si,
            y0,
            t,
            args=(k1, k2, g, m)
        )

    # X = solution_odeint[:, 0]
    # Y = solution_odeint[:, 1]

    max_ind = np.where(
        solution_rk4 == np.amax(solution_rk4[:, 1])
    )

    X2 = solution_rk4[:, 0][:max_ind[0][0]]
    Y2 = solution_rk4[:, 1][:max_ind[0][0]]

    with plt.style.context(('ggplot')):
        # plt.plot(X, Y, 'r')
        plt.plot(X2, Y2, 'g')

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
    k1 = 0.0  # пренебречь
    k2 = 0.5 * DRAG_COEFFICIENT * pi * 0.25 * 0.25 * 1.29

    alpha = 90.0  # в градусах
    alpha = alpha * pi / 180.0  # в радианах

    m = 120.0
    g = CONST.g

    v_plane = 222.0
    v0 = 100.0
    v0x = v0*cos(alpha) + v_plane  # + начальная скорость самолета
    v0y = v0*sin(alpha)

    X0 = 0
    Y0 = 10000.0  # начальная высота

    a = (k1 * v0) / (m * g)
    b = (k2 * v0 * v0) / (m * g)

    # TODO: добавить нач. скорость самолета в безразмерные и нач. высоту
    y0 = [X0, Y0, cos(alpha), sin(alpha)]
    t = np.linspace(0., 2, 200)

    # решение решателем odeint
    # solution_odeint = odeint(
    #         model,
    #         y0,
    #         t,
    #         args=(a, b, alpha)
    #     )

    # решение своей реализацией метода Рунге-Кутты (4)

    solution_rk4 = rk4(
            model_dimensionless_quantities,
            y0,
            t,
            args=(a, b, alpha)
        )

    # X = solution_odeint[:, 0]
    # Y = solution_odeint[:, 1]

    max_ind = np.where(
        solution_rk4 == np.amax(solution_rk4[:, 1])
    )

    X2 = solution_rk4[:, 0][:max_ind[0][0]]
    Y2 = solution_rk4[:, 1][:max_ind[0][0]]

    with plt.style.context(('ggplot')):
        # plt.plot(X, Y, 'r')
        plt.plot(X2, Y2, 'g')

        # обязательно настроить, иначе график будет отображаться криво
        plt.axis('equal')
        plt.grid(
            color='b',
            linestyle=':',
            linewidth=0.5
        )

    plt.show()


if __name__ == "__main__":
    # modeling_SI()
    modeling_dimensionless_quantities()
