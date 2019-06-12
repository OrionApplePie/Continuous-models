from math import sqrt, sin, cos, pi

import numpy as np
from scipy.constants import g as G
from scipy.integrate import odeint
import matplotlib.pyplot as plt


def model_dimensionless_quantities(y, t, a, b, alpha):
    """
    Модель запуска тела под углом к горизонту с учетом сопротивления воздуха.
    Безразмерные единицы измерения.
    Связанные ОДУ (вектор).
    Параметры a, b, alpha передаются при вызове решателя.
    """
    print(f"y={y}")
    xx, yy, vx, vy = y
    dxdt = vx / (2.0 * cos(alpha))
    dydt = (2.0 * vy) / sin(alpha)

    dvxdt = -a * vx * sin(alpha)
    - b * vx * sin(alpha) * sqrt(vx**2 + vy**2)
    dvydt = -sin(alpha)
    - a * vy * sin(alpha)
    - b * sin(alpha) * vy * sqrt(vx**2 + vy**2)
    return [dxdt, dydt, dvxdt, dvydt]


def modeling_dimensionless_quantities_odeint():
    """
    Dimensionless quantities - безразмерные единицы.
    Моделирование в безразмерных единицах и решение решателем из numpy.
    """
    # зонд - шаровид.  формы
    DRAG_COEFFICIENT = 0.5  # c, шар
    k1 = 0.2
    k2 = 0.5 * DRAG_COEFFICIENT * pi * 0.25 * 0.25 * 1.29

    m = 120.0
    g = G

    v_plane = 0.0
    v0 = 123

    angle = 88.0  # в градусах
    alpha = angle * (pi / 180.0)

    v0x = cos(alpha) + v_plane  # + начальная скорость самолета
    v0y = sin(alpha)
    X0 = 0
    Y0 = 0  # начальная высота

    a = (k1 * v0) / (m * g)
    b = (k2 * v0 * v0) / (m * g)

    # TODO: добавить нач. скорость самолета в безразмерные и нач. высоту
    y0 = (X0, Y0, v0x, v0y)
    print(f"start y0={y0}")
    t = np.linspace(0.0, 2.0, 50)

    # решение решателем odeint
    solution_odeint = odeint(
            func=model_dimensionless_quantities,
            y0=y0,
            t=t,
            args=(a, b, alpha)
        )
    X = solution_odeint[:, 0]
    Y = solution_odeint[:, 1]
    VX = solution_odeint[:, 2]
    VY = solution_odeint[:, 3]

    for x, y, vx, vy in zip(X, Y, VX, VY):
        print(f"x={x}, y={y}, vx={vx}, vy={vy}")

    plt.plot(X, Y, 'y--')
    # обязательно настроить, иначе график будет отображаться криво
    plt.axis('equal')
    plt.grid(
        color='b',
        linestyle=':',
        linewidth=0.5
    )
    plt.show()


if __name__ == "__main__":
    modeling_dimensionless_quantities_odeint()
