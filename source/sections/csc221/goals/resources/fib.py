def fib(n, fibs={0: 1, 1: 1}):
    """
      >>> fib(0)
      1
      >>> fib(1)
      1
      >>> fib(4)
      5
      >>> fib(5)
      8
      >>> fib(11)
      144
      >>> fib(35)
      14930352
    """
    print(f"fib({n}) called.")
    if n not in fibs:
        fibs[n] = fib(n-1, fibs) + fib(n-2, fibs)
    return fibs[n]


if __name__ == '__main__':
    """
    import doctest
    doctest.testmod()
    """
    print(fib(35))
