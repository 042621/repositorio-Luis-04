#include <stdio.h>

const int MES = 12;
const int DEP = 3;
const int AÑO = 8;

void Lectura(float[MES][DEP][AÑO], int, int, int);
void Funcion1(float[MES][DEP][AÑO], int, int, int);
void Funcion2(float[MES][DEP][AÑO], int, int, int);
void Funcion3(float[MES][DEP][AÑO], int, int, int);

int main(void)
{
    float PRO[MES][DEP][AÑO];
    Lectura(PRO, MES, DEP, AÑO);
    Funcion1(PRO, MES, DEP, 1);
    Funcion2(PRO, MES, DEP, AÑO);
    Funcion3(PRO, MES, DEP, AÑO);

    return 0;
}

void Lectura(float A[][DEP][AÑO], int F, int C, int P)
{
    int K, I, J;
    for (K = 0; K < P; K++)
    {
        for (I = 0; I < F; I++)
        {
            for (J = 0; J < C; J++)
            {
                printf("Año: %d\tMes: %d\tDepartamento: %d ", K + 1, I + 1, J + 1);
                scanf("%f", &A[I][J][K]);
            }
        }
    }
}

void Funcion1(float A[][DEP][AÑO], int F, int C, int P)
{
    int I, J;
    float SUM = 0.0;
    for (I = 0; I < F; I++)
    {
        for (J = 0; J < C; J++)
        {
            SUM += A[I][J][P - 1];
        }
    }
    printf("\n\nVentas totales de la empresa en el primer año: %.2f", SUM);
}

void Funcion2(float A[][DEP][AÑO], int F, int C, int P)
{
    int I, J;
    float MAX_VENTAS = 0.0;
    int MAX_DEPARTAMENTO = -1;
    for (J = 0; J < C; J++)
    {
        float SUM = 0.0;
        for (I = 0; I < F; I++)
        {
            SUM += A[I][J][P - 1];
        }
        if (SUM > MAX_VENTAS)
        {
            MAX_VENTAS = SUM;
            MAX_DEPARTAMENTO = J;
        }
    }
    if (MAX_DEPARTAMENTO != -1)
    {
        switch (MAX_DEPARTAMENTO)
        {
            case 0:
                printf("\n\nDepartamento con mayores ventas en el último año: Hilos");
                break;
            case 1:
                printf("\n\nDepartamento con mayores ventas en el último año: Licra");
                break;
            case 2:
                printf("\n\nDepartamento con mayores ventas en el último año: Lanas");
                break;
        }
        printf(" Ventas: %.2f", MAX_VENTAS);
    }
}

void Funcion3(float A[][DEP][AÑO], int F, int C, int P)
{
    int K, I, J;
    float MAX_VENTAS = 0.0;
    int MAX_DEPARTAMENTO = -1;
    int MAX_MES = -1;
    int MAX_AÑO = -1;
    for (K = 0; K < P; K++)
    {
        for (I = 0; I < F; I++)
        {
            for (J = 0; J < C; J++)
            {
                if (A[I][J][K] > MAX_VENTAS)
                {
                    MAX_VENTAS = A[I][J][K];
                    MAX_DEPARTAMENTO = J;
                    MAX_MES = I;
                    MAX_AÑO = K;
                }
            }
        }
    }
    if (MAX_DEPARTAMENTO != -1 && MAX_MES != -1 && MAX_AÑO != -1)
    {
        printf("\n\nDepartamento: %d\tMes: %d\tAño: %d", MAX_DEPARTAMENTO + 1, MAX_MES + 1, MAX_AÑO + 1);
        printf("\tVentas: %.2f", MAX_VENTAS);
    }
}
