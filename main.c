#include <stdio.h>
#include <stdbool.h>

// Variables
char option;

// Function
void optUno()
{
    printf("Opcion Uno\n");
}

void optDos()
{
    printf("Opcion dos\n");
}

// Main
int main()
{
    while (true)
    {
        printf("Introduce la opcion: ");
        scanf("%s", &option);
        if (option == '1')
        {
            optUno();
        }
        else if (option == '2')
        {
            optDos();
        }
        else if (option == '0')
        {
            break;
        }
        else
        {
            printf("La opcion no existe\n");
        }
    }
    return 0;
}
