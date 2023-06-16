#include <stdio.h>
#include <string.h>

int longitud(char *cad); /* Prototipo de función. */

int main(void)
{
    int i, n, l = -1, p, t;
    char cad[50], FRA[20][50];
    printf("\nIngrese el número de filas del arreglo: ");
    scanf("%d", &n);
    getchar(); // Se agrega getchar() para capturar el salto de línea después del scanf

    for (i = 0; i < n; i++)
    {
        printf("Ingrese la línea %d de texto. Máximo 50 caracteres: ", i + 1);
        fflush(stdin);
        fgets(FRA[i], 50, stdin); // Se utiliza fgets en lugar de gets
        FRA[i][strcspn(FRA[i], "\n")] = '\0'; // Se elimina el salto de línea capturado por fgets
    }

    printf("\n");

    for (i = 0; i < n; i++)
    {
        strcpy(cad, FRA[i]);
        t = longitud(cad);
        if (t > l)
        {
            l = t;
            p = i;
        }
    }

    printf("\nLa cadena con mayor longitud es: ");
    puts(FRA[p]);
    printf("Longitud: %d\n", l);

    return 0;
}

int longitud(char *cadena)
{
    int cue = 0;
    while (cadena[cue] != '\0') // Se corrige la condición de salida del ciclo
        cue++;
    return cue;
}
