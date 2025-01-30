#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello there, friend!";
    char str2[] = "Pat";
    char bytes[4] = {80, 97, 116, 0};

    printf("%s\n", str1);
    printf("The string above is %lu bytes long.\n", strlen(str1));
    printf("The string, %s, is %lu bytes long.\n", str2, strlen(str2));
    printf("Can we print bytes? Let's see: %s.\n", bytes);
    printf("We can, and it's just the same as str2 ;-)\n");
    printf("We can confirm this by using strcmp().\n");
    printf(
        "Calling strcmp(str2, bytes) gives: %d.\n",
        strcmp(str2, bytes)
    );

    return 0;
}
