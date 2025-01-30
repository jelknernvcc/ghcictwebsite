f = open('mbox.txt')
[print(line.rstrip()) for line in f if line.startswith('From:')]
