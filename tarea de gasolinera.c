#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tirePerf 45000 // Km
#define anualKm 15000 // Km
#define oilChKm 25000 // Km

// Prototipos de funciones
float gComb(float D, float eMx, float eMn, float fl);
float vCost(float D, float tireCost, float ensCost, float oilCost);
void getInfo();
void print();

// Estructura para almacenar los datos de la visita
struct tabla {
    char nombre[20];
    float distance;
    float gFuel;
    float gVar;
    float total;
};

float dist;
struct tabla tabla0;

void main() {
    int con = 1;
    float comb, eMax, eMin, tireC, ensC, oilChange;

    printf("\nCalculo de costo por visita.");
    printf("\nIngrese los siguientes datos.");
    printf("\nPrecio del Combustible (RD$xGal): ");
    scanf("%f", &comb);
    printf("\nEficiencia Maxima del Vehiculo (L/100km): ");
    scanf("%f", &eMax);
    printf("\nEficiencia Minima del Vehiculo (L/100km): ");
    scanf("%f", &eMin);
    printf("\nPrecio de las llantas (RD$xkilometro): ");
    scanf("%f", &tireC);
    printf("\nCosto del Seguro Anual (RD$): ");
    scanf("%f", &ensC);
    printf("\nCosto de Cambio de Aceite (RD$): ");
    scanf("%f", &oilChange);

    while (con) {
        getInfo();
        tabla0.gFuel = gComb(dist, eMax, eMin, comb);
        tabla0.gVar = vCost(dist, tireC, ensC, oilChange);
        tabla0.total = tabla0.gFuel + tabla0.gVar;
        print();

        printf("\n¿Desea hacer un nuevo calculo?\n 1- Si\t 0- No\n");
        scanf("%d", &con);
    }
}

void getInfo() {
    char name[20];

    printf("\nNombre del cliente: ");
    fflush(stdin);
    gets(name);
    strcpy(tabla0.nombre, name);
    fflush(stdin);
    printf("\nDistancia a recorrer (Km): ");
    scanf("%f", &dist);
    tabla0.distance = dist;
}

float gComb(float D, float eMx, float eMn, float fl) {
    float newCombPrice = fl / 3.71;
    float eProm;
    eProm = ((eMx + eMn) / 2) / 100;
    float finalComb = newCombPrice * eProm * D;
    return finalComb;
}

float vCost(float D, float tireCost, float ensCost, float oilCost) {
    // Costo de las llantas
    float totalTireC = 4 * tireCost;
    float tirePerKM = totalTireC / tirePerf;

    // Costo del seguro
    float ensPerKm = ensCost / anualKm;

    // Costo del cambio de aceite
    float oilCostPerKm = oilCost / oilChKm;

    return tirePerKM + ensPerKm + oilCostPerKm;
}

void print() {
    printf("\n-------------------------------------------");
    printf("\n| Cliente: %-19s |", tabla0.nombre);
    printf("\n-------------------------------------------");
    printf("\n| Costo   | Distancia | Combustible | Gastos Varios | Total   |");
    printf("\n-------------------------------------------");
    printf("\n| %7.2f | %9.2f | %11.2f | %13.2f | %7.2f |", tabla0.gFuel, tabla0.distance, tabla0.gFuel * 3.78541, tabla0.gVar, tabla0.total);
    printf("\n-------------------------------------------");
}
