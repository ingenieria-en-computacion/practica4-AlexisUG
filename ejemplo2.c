#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arreglo, num, cont;
    printf("¿Cuántos elementos tiene el conjunto?\n");
    scanf("%d", &num);

    arreglo = (int*)calloc(num , sizeof(int));//Calloc recibe dos argumentos a diferencia de malloc que recibe uno. (Numero de elementos,tamaño de los elementos a reservar)
    if(arreglo != NULL){//Calloc garantiza que haya 0 en la localidad
        printf
        ("Vector reservado:\n\t[");
        for(cont =0; cont <num; cont++){
            printf("\t%d, %p", *(arreglo + cont), (arreglo+cont));            
        }
        printf("\t]\n");
        printf("Liberando el espacio reservado\n");
        free(arreglo);
        arreglo = NULL;      
    }
    return 0;
}