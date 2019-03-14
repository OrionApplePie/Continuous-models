import numpy as np


def rk4(f, y0, t, args):
    """Runge-Kutta method for vector function."""
    """f arguments: y, t, args"""
    t = np.array(t)
    n = t.size
    # TODO: Есть ли другой способ получить шаг?
    h = (t[n-1] - t[0]) / float(n)

    vy = [0] * n  # массив для результатов вычисленных на каждом шаге
    vy[0] = y = np.array(y0)  # инициализация нач. значения вектор-функции

    enum_t = enumerate(t)
    next(enum_t)  # пропускаем 1й эл., т.к. уже есть нач. значение
    # TODO: выяснить почему в результате нет последней точки
    for i, tt in enum_t:
        k1 = h * np.array(
            f(y, tt, *args)
        )
        k2 = h * np.array(
            f(y + 0.5 * k1, tt + 0.5 * h, *args)
        )
        k3 = h * np.array(
            f(y + 0.5 * k2, tt + 0.5 * h, *args)
        )
        k4 = h * np.array(
            f(y + k3, tt + h, *args)
        )
        vy[i] = y = y + (k1 + k2 + k2 + k3 + k3 + k4) / 6

    return np.array(vy)
