def fib(n):
    a, b = 1, 0
    x, y = 0, 1
    while n:
        if n & 1:
            a, b = a * x + y * b, a * y + b * (x + y)
        x, y = x * x + y * y, y * y + 2 * x * y
        n >>= 1
    return b
