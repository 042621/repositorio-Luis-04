#include <stdio.h>
#include <string.h>

int main(void)
{
    char *cad0;
    cad0 = "Argentina";
    puts(cad0);
    cad0 = "Brasil";
    puts(cad0);

    char cad1[100]; // Se reserva espacio para la cadena
    gets(cad1);

    char cad2[20] = "Mexico";
    puts(cad2);
    gets(cad2);
    puts(cad2);

    strcpy(cad2, "Guatemala"); // Se utiliza strcpy para asignar una cadena a otra

    return 0;
}
