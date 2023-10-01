#include <stdio.h>
#include <stdbool.h>
#ifdef _WIN32
  #include<windows.h>
#endif  

void clear_screen()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

// Variables
char option;

// Function
void optUno()
{
    clear_screen();
    printf("Opcion Uno\n");
}

void optDos()
{
    clear_screen();
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
            clear_screen();
            printf("La opcion no existe\n");
        }
    }
    return 0;
}
