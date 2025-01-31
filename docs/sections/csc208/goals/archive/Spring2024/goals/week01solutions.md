# Solutions to Week 1 Class Exercises

1.  Each mathematician shakes hands with everyone else but themself, but each
    handshake involves two mathematicians, yet should only be counted as a
    single handshake.  Thus to compute the total number of handshakes,
    assuming we have ``n`` mathematicians, there will be:

    $$\frac {n(n-1)}{2}$$

2.  We could let Python help us with this one.  Here are two functions that
    will provide solutions:
    ```
    def numdogs(people):
        if people == 1:
            return 1
        return 2 + numdogs(people - 1)

    def totaldogs(people):
        total = 0
        for person in range(people, 0, -1):
            print(f"Person number {person} ate {numdogs(person)} hotdogs.")
            total += numdogs(person)
        return total
    ```
    An explicit formula for that 2nd computation that does not require
    iteration or recursion, and is thus much faster to compute, can be derived
    from the following observation.
    Our total sum can be written like this:
    ```
        n+51 + n+49 + n+47 + ... + n+5  + n+3  + n+1
      + n+1  + n+3  + n+5  + ... + n+47 + n+49 + n+51
      -----------------------------------------------
        52   + 52   + 52   + ... + 52   + 52   + 52
    ```
    or 52, 51 times, but each one has been counted twice, so we end up with:

    $$\frac {52 \cdot 51}{2}$$

    Look familiar?
