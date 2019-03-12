from math import sqrt, sin, cos, pi

import numpy as np


def main():
    # зонд - каплевидной формы
    DRAG_COEFFICIENT = 0.045
    k1 = 0 # пренебречь
    k2 = 0.5*DRAG_COEFFICIENT*0.4*1.29

    v0 = 12
    m = 5
    g = 9.8

    a = (k1*v0) / (m*g)
    b = (k2*v0*v0) / (m*g)

    alpha = pi / 2.0

    print(a, b)

    dv_xdt = lambda t, vx, vy: -a * sin(alpha) * vx - b * sin(alpha)*sqrt(vx*vx + vy*vy) * vx
    dv_ydt = lambda t, vx, vy: -sin(alpha) - a * sin(alpha) * vy - b * sin(alpha) * sqrt(vx*vx + vy*vy) * vy
    
    dxdt = lambda t, vx: vx / (2 * cos(alpha))
    dydt = lambda t, vy: 2*vy / sin(alpha)
    
    X0 = Y0 = 0
    
    Vx0 = cos(alpha)
    Vy0 = sin(alpha)

    h = 0.1
    


def rk4_step(f, x, y):
    # for i in range(1, n + 1):
    k1 = h * f(x, y)
    k2 = h * f(x + 0.5 * h, y + 0.5 * k1)
    k3 = h * f(x + 0.5 * h, y + 0.5 * k2)
    k4 = h * f(x + h, y + k3)
    
    vy = y + (k1 + k2 + k2 + k3 + k3 + k4) / 6
    return vy


def f(x, y):
    return x * sqrt(y)
 
vx, vy = rk4(f, 0, 1, 10, 100)
for x, y in list(zip(vx, vy))[::10]:
    print("%4.1f %10.5f %+12.4e" % (x, y, y - (4 + x * x)**2 / 16))

if __name__ == "__main__":
    main()
