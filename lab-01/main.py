from math import sqrt, sin, cos, pi

import matplotlib.pyplot as plt
import numpy as np
from scipy.integrate import odeint


def model(y, t, a, b, alpha):
        """Связанные ОДУ (вектор).
        Параметры alpha, a, b передаются при вызове odeint.
        Безразмерные единицы измерения."""
        xx, yy, vx, vy = y
        
        dxdt =  vx / (2 * cos(alpha))
        dydt =  2 * vy / (sin(alpha))

        dvxdt = (-a * sin(alpha) - b * sin(alpha) * sqrt(vx*vx + vy*vy) ) * vx
        dvydt = -sin(alpha) - a * sin(alpha) * vy - b * sin(alpha) * sqrt(vx*vx + vy*vy) * vy
        
        return [dxdt, dydt, dvxdt, dvydt]


def model2(y, t, k1, k2, g, m):
        """Связанные ОДУ (вектор).
        Параметры alpha, a, b передаются при вызове odeint."""
        xx, yy, vx, vy = y
        
        dxdt =  vx
        dydt =  vy
        
        dv_xdt = ( - (k1 + k2 * (vx**2 + vy**2) ** 0.5 ) / m ) * vx
        dv_ydt = -g - ( (k1 + k2 * (vx**2 + vy**2) ** (0.5) ) / m ) * vy

        return [dxdt, dydt, dv_xdt, dv_ydt]


def main():
    # зонд - шаровид.  формы
    DRAG_COEFFICIENT = 0.5 # c, шар
    k1 = 0 # пренебречь
    k2 = 0.5*DRAG_COEFFICIENT*pi*0.25*0.25*1.29
    
    alpha = 60.            # в градусах
    alpha = alpha * pi / 180. # в радианах

    m = 10
    g = 9.81

    v0 = 50.
    v0x = v0*cos(alpha)
    v0y = v0*sin(alpha)
    
    a = (k1*v0) / (m*g)
    b = (k2*v0*v0) / (m*g)
#     a = 0.013
#     b = 0.049
    
    # начальные условия
    y0 = [0.0, 0.0, v0x, v0y]

    t = np.linspace(0., 3, 100)
    sol = odeint(model2, y0, t, args=(k1, k2, g, m))
    
#     t = np.linspace(0., 1, 100)
#     sol = odeint(
#             model,
#             [0, 0, cos(alpha), sin(alpha)],
#             t,
#             args=(a, b, alpha)
#         )

    X = sol[:,0]
    Y = sol[:,1]
    
    plt.plot(X, Y)
    plt.axis('equal')  # обязательно настроить, иначе непонятно будет отображаться график
    plt.grid(
        color='r',
        linestyle='-',
        linewidth=0.5
    )
    plt.show()


if __name__ == "__main__":
    main()
