#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[50];
    int edad;
} Estudiante;

int main() {
    int size = 2;
    Estudiante *estudiantes = (Estudiante *)malloc(size * sizeof(Estudiante));

    if (estudiantes == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    int count = 0;
    char nombre[50];
    int edad;
    printf("Ingrese estudiantes (nombre y edad, ingrese 'fin' para terminar):\n");
    while (1) {
        printf("Nombre: ");
        scanf("%s", nombre);
        if (strcmp(nombre, "fin") == 0) break;

        printf("Edad: ");
        scanf("%d", &edad);

        if (count >= size) {
            size *= 2;
            estudiantes = (Estudiante *)realloc(estudiantes, size * sizeof(Estudiante));
            if (estudiantes == NULL) {
                printf("Error: No se pudo reasignar memoria.\n");
                return 1;
            }
        }

        strcpy(estudiantes[count].nombre, nombre);
        estudiantes[count].edad = edad;
        count++;
    }

    printf("Lista de estudiantes:\n");
    for (int i = 0; i < count; i++) {
        printf("Nombre: %s, Edad: %d\n", estudiantes[i].nombre, estudiantes[i].edad);
    }

    free(estudiantes);
    return 0;
}