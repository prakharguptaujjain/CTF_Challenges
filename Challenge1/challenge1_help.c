#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int entry;
    char buffer[64];

    entry = 0;
    // put argv[1] into buffer
    strcpy(buffer, argv[1]);

    if (entry != 0)
    {
        printf("you have changed the 'modified' variable\n");
        return 1;
    }
    else
    {
        printf("Try again?\n");
        return 0;
    }
}