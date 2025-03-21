#include <stdio.h>
#include <stdlib.h>

int main(){
    //recomendable asignar nulo a un apuntador
    int *arreglo, *arreglo2=NULL, num, cont;
    printf("¿Cuántos elementos tiene el conjunto?\n");
    scanf("%d", &num);
    arreglo = (int*)malloc(num *sizeof(int));
    if(arreglo != NULL){        
        for(cont =0; cont <num; cont++){
            printf("Ingresa el elemento %d del conjunto\n", cont+1);
            scanf("%d", (arreglo+cont));
        }
        printf("Vector reservado:\n\t[");
        for(cont =0; cont <num; cont++){
            printf("\t%d", *(arreglo + cont));            
        }
        printf("\t]\n");

        printf("Aumentando el espacio reservado al doble\n");
        num *=2;
        arreglo2 = (int*)realloc(arreglo, num*sizeof(int));//Modifica el tamaño de una ona de memoria ya reservada recibe el puntador de la zona de memoria a modificar y el nuevo tamaño
        if(arreglo2 != NULL){ 
            arreglo = arreglo2;       
            for(; cont <num; cont++){
                printf("Ingresa el elemento %d del conjunto\n", cont+1);
                scanf("%d", (arreglo2+cont));
            }
            printf("Vector reservado:\n\t[");
            for(cont =0; cont <num; cont++){
                printf("\t%d", *(arreglo2 + cont));            
            }
            printf("\t]\n");    
            
        }
        printf("Liberando el espacio reservado\n");

        free(arreglo);//Solo se libera un arreglo porque arreglo 1 y 2 apuntan a la misma direcion de memoria
        arreglo = arreglo2 = NULL;
    }
    return 0;
}