from math import sqrt, sin, cos, pi
import matplotlib.pyplot as plt
import numpy as np
from scipy.integrate import odeint


def main():
    # зонд - каплевидной формы
    DRAG_COEFFICIENT = 0.045
    k1 = 0 # пренебречь
    k2 = 0.5*DRAG_COEFFICIENT*0.4*1.29

    m = 5
    g = 9.8

    # a = (k1*v0) / (m*g)
    # b = (k2*v0*v0) / (m*g)
    a = 0.063
    b = 0.034
    alpha = pi /2

    def model(x0, t):
        vx = x0[0]
        vy = x0[1]

        dv_xdt = -a * sin(alpha) * vx - b * sin(alpha) * sqrt(vx*vx + vy*vy) * vx
        dv_ydt = -sin(alpha) - a * sin(alpha) * vy - b * sin(alpha) * sqrt(vx*vx + vy*vy) * vy
        dxdt =  vx / (2 * cos(alpha))
        dydt =  2*vy / sin(alpha)

        return [dv_xdt, dv_ydt, dxdt, dydt]

    model0 = [cos(alpha), sin(alpha), 0, 0]
    t = np.linspace(0, 1, 100)
    sol = odeint(model, model0, t)
    X = sol[:,2]
    Y = sol[:,3]
    plt.plot(X, Y)
    plt.show()

if __name__ == "__main__":
    main()
