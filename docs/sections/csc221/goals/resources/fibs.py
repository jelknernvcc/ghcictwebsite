def fib1(n, debug=False):
    """
      >>> fib1(0)
      1
      >>> fib1(1)
      1
      >>> fib1(4)
      5
      >>> fib1(5)
      8
      >>> fib1(11)
      144
      >>> fib1(35)
      14930352
    """
    if debug:
        print(f"fib({n}) called.")
    if n == 0 or n == 1:
        return 1
    else:
        return fib1(n-1) + fib1(n-2)


def fib2(n, fibs={0: 1, 1: 1}, debug=False):
    """
      >>> fib2(0)
      1
      >>> fib2(1)
      1
      >>> fib2(4)
      5
      >>> fib2(5)
      8
      >>> fib2(11)
      144
      >>> fib2(35)
      14930352
    """
    if debug:
        print(f"fib({n}) called.")
    if n not in fibs:
        fibs[n] = fib2(n-1, fibs, debug) + fib2(n-2, fibs, debug)
    return fibs[n]


if __name__ == '__main__':
    """
    import doctest
    doctest.testmod()
    """
    print(fib2(35, debug=True))
