#include <stdio.h>

int main() {
    char str[] = "Hi!";
    char chars[] = {'H', 'i', '!'};

    printf(
        "str[] has length %u, but chars[] has length %u\n",
        (unsigned)sizeof(str),
        (unsigned)sizeof(chars)
    );

    return 0;
}
