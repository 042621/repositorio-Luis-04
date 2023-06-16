#include <ctype.h>
#include <stdio.h>
#include <string.h>

void minymay(char *cad); // Prototipo de función.

int main(void)
{
    int i, n;
    char FRA[20][50];

    printf("Ingrese el número de filas del arreglo: ");
    scanf("%d", &n);

    // Limpiar el búfer de entrada después de leer un número entero.
    getchar();

    for (i = 0; i < n; i++)
    {
        printf("Ingrese la línea %d de texto: ", i + 1);
        fgets(FRA[i], sizeof(FRA[i]), stdin);

        // Eliminar el carácter de nueva línea ('\n') al final de la cadena.
        FRA[i][strcspn(FRA[i], "\n")] = '\0';
    }

    printf("\n\n");

    for (i = 0; i < n; i++)
        minymay(FRA[i]);

    return 0;
}

void minymay(char *cadena)
{
    int i = 0, mi = 0, ma = 0;

    while (cadena[i] != '\0')
    {
        if (islower(cadena[i]))
            mi++;
        else if (isupper(cadena[i]))
            ma++;

        i++;
    }

    printf("\n\nNúmero de letras minúsculas: %d", mi);
    printf("\nNúmero de letras mayúsculas: %d", ma);
}
