from math import sqrt, sin, cos, pi

import matplotlib.pyplot as plt
import numpy as np
from scipy.constants import g as G
from scipy.integrate import odeint

from integrate.runge_kutta import rk4


def model_celestial_mech_si(y_, t, g, m):
    """
    Модель движения небесных тел.
    Единицы измерения СИ.
    Связанные ОДУ (вектор).
    Параметры g, m, передаются при вызове решателя.
    """
    x, y, vx, vy = y_

    dx_dt = vx
    dy_dt = vy

    dvx_dt = - g * m * (x / sqrt((x * x + y * y) ** 3))
    dvy_dt = - g * m * (y / sqrt((x * x + y * y) ** 3))

    return dx_dt, dy_dt, dvx_dt, dvy_dt


def modeling_SI():
    """Моделирование в единицах СИ."""
    m = 6e24  # масса Земли
    g = 6.67408e-11
    r_earth = 6371 * 1000  # earth radius
    r = 6.4e6 
    v0 = 7000.0  + 100 # 100 м \ с
    h_station = 408 * 1000  + r_earth  # высота орбиты станции

    X0 = 0.0
    Y0 = 0.0 + h_station
    
    y0 = [X0, Y0, v0, v0]  # начальные условия
    t = np.linspace(0., 100000, 1000)
    
    sol_station_track = odeint(
        func=model_celestial_mech_si,
        y0=(0, h_station, 7000, 7000),
        t=t,
        args=(g, m)
    )

    solution_rk4 = odeint(  # решение своей реализацией метода Рунге-Кутты (4)
            func=model_celestial_mech_si,
            y0=y0,
            t=t,
            args=(g, m)
        )
    
    X = solution_rk4[:, 0]
    Y = solution_rk4[:, 1]
    VX = solution_rk4[:, 2]
    VY = solution_rk4[:, 3]
    

    X_station = sol_station_track[:, 0]
    Y_station = sol_station_track[:, 1]

    with plt.style.context(('ggplot')):
        plt.plot(X, Y, 'g--', X_station, Y_station, 'r')
        # обязательно настроить, иначе график будет отображаться криво
        plt.axis('equal')
        plt.grid(
            color='b',
            linestyle=':',
            linewidth=0.5
        )
        plt.xlabel('X, м')
        plt.ylabel('Y, м')
        plt.scatter(0, 0, linewidth=7, color='blue')
        plt.annotate('Земля', xy=(0, 0), xytext=(r/10, r/10),
            arrowprops=dict(arrowstyle="->", connectionstyle="arc3"),
        )


    plt.show()


if __name__ == "__main__":
    modeling_SI()
