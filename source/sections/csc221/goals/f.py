def lots_of_letters(word):

    """
      >>> lots_of_letters('Lidia')
      'Liidddiiiiaaaaa'
      >>> lots_of_letters('Python')
      'Pyyttthhhhooooonnnnnn'
      >>> lots_of_letters('')
      ''
      >>> lots_of_letters('1')
      '1'
    """
    s = ''
    for index, letter in enumerate(word):
        s += (index + 1) * letter 
    return s


if __name__ == '__main__':
    import doctest
    doctest.testmod()
