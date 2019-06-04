from math import sqrt, sin, cos, pi

import matplotlib.pyplot as plt
import numpy as np
import scipy.constants as CONST 
from scipy.integrate import odeint

from integrate.runge_kutta import rk4


def model(y, t, a, b, alpha):
    """Связанные ОДУ (вектор).
    Параметры alpha, a, b передаются при вызове odeint.
    Безразмерные единицы измерения."""
    xx, yy, vx, vy = y

    dxdt = vx / (2 * cos(alpha))
    dydt = 2 * vy / (sin(alpha))

    dvxdt = -a * sin(alpha) * vx
    - b * sin(alpha) * sqrt(vx*vx + vy*vy) * vx
    dvydt = -sin(alpha)
    - a * sin(alpha) * vy
    - b * sin(alpha) * sqrt(vx*vx + vy*vy) * vy

    return [dxdt, dydt, dvxdt, dvydt]


def model2(y, t, k1, k2, g, m):
    """Связанные ОДУ (вектор).
    Параметры alpha, a, b передаются при вызове odeint.
    Обычные единицы измерения."""
    xx, yy, vx, vy = y

    dxdt = vx
    dydt = vy

    dv_xdt = (- (k1 + k2 * (vx**2 + vy**2) ** 0.5) / m) * vx
    dv_ydt = -g - ((k1 + k2 * (vx**2 + vy**2) ** (0.5)) / m) * vy

    return [dxdt, dydt, dv_xdt, dv_ydt]


def main():
    # зонд - шаровид.  формы
    DRAG_COEFFICIENT = 0.5  # c, шар
    k1 = 0.0  # пренебречь
    k2 = 0.5*DRAG_COEFFICIENT*pi*0.25*0.25*1.29

    alpha = 90.0  # в градусах
    alpha = alpha * pi / 180.0  # в радианах

    m = 120
    g = CONST.g

    v0 = 10
    v0x = v0*cos(alpha) + 2.0  # + начальная скорость самолета
    v0y = v0*sin(alpha)

    X0 = 0
    Y0 = 123.0  # начальная высота

    a = (k1*v0) / (m*g)
    b = (k2*v0*v0) / (m*g)
#     a = 0.013
#     b = 0.049

    # начальные условия для обычныз ед. измерения
    y0 = [X0, Y0, v0x, v0y]
    t = np.linspace(0., 3, 100)
    # sol = odeint(model2, y0, t, args=(k1, k2, g, m))

    # TODO: добавить нач. скорость самолета в безразмерные и нач. высоту
    # y0 = [X0, 1, cos(alpha), sin(alpha)]
    # t = np.linspace(0., 2, 200)

    # решение решателем odeint
    # solution_odeint = odeint(
    #         model,
    #         y0,
    #         t,
    #         args=(a, b, alpha)
    #     )
    # решение моей реализацией метода Рунге-Кутты (4)
    solution_rk4 = rk4(
            model2,
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


if __name__ == "__main__":
    main()
