#include <ctype.h>
#include <stdio.h>

void interpreta(char *cadena);

int main(void)
{
    char cad[50];
    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin); // Utilizamos fgets en lugar de gets para leer la cadena de caracteres

    interpreta(cad);

    return 0;
}

void interpreta(char *cadena)
{
    int i = 0, j, k;
    while (cadena[i] != '\0') {
        if (isalpha(cadena[i])) {
            k = cadena[i - 1] - '0'; // Convertimos el dígito en caracter a entero
            for (j = 0; j < k; j++)
                putchar(cadena[i]);
        }
        i++;
    }
}
