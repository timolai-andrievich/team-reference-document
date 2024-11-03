def egcd(a, b):
    x, y, x1, y1, a1, b1 = 1, 0, 0, 1, a, b
    while b1 != 0:
        q = a1 // b1
        x, x1 = x1, x - q * x1
        y, y1 = y1, y - q * y1
        a1, b1 = b1, a1 - q * b1
    g = a1
    assert a * x + b * y == g
    return g, x, y
