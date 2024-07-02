#include <stdio.h>
#include <stdlib.h>
#define MAX_CON 15

typedef struct carrera{
    char Nombre[MAX_CON];
    int Mejor_tiempo;
    struct carrera *next;
}carrera_t;

carrera_t * formula1=NULL;
void menu(void);
void pedir_conductor (void);
void imprimir_conductor (carrera_t);
void ver_lista (void);
void liberar_memoria (void);
    
int main(){
    menu();
    liberar_memoria();
    return 0;
}

void pedir_conductor (void){
    
            carrera_t * carrera_nueva;
        carrera_nueva=malloc(sizeof(carrera_t));
        if (carrera_nueva==NULL){
            printf("No tiene espacio la memoria\n");
        }
        else{
            printf("Ingrese los nombres de los corredores: \n");
            scanf(" %[^\n]%*c", carrera_nueva->Nombre);
            printf("Ingrese el tiempo del corredor (s): \n");
            scanf(" %d", &(carrera_nueva->Mejor_tiempo));
            carrera_nueva->next = formula1;
            formula1 = carrera_nueva;
        }
        
}

void imprimir_conductor(carrera_t carrera){
    printf("Nombre del conductor: %s\n", carrera.Nombre);
    printf("Tiempo que alcanzo en la carrera (s): %d\n\n", carrera.Mejor_tiempo);
}
void ver_lista (void){
    carrera_t * carrera_c=formula1;
    while(carrera_c!=NULL){
        imprimir_conductor(*carrera_c);
        carrera_c=carrera_c->next;
    }
}

void menu(void){
    int opcion;
    do{
        printf("1_Mostrar carrera\n");
        printf("2_Cargar nueva carrera\n");
        printf("3_Exit\n");
        scanf("%d", &opcion);
        switch (opcion){
            case 1: 
                ver_lista();
                break;
                
            case 2:
                pedir_conductor();
                break;
        }
    }while(opcion!=3);
}
    
void liberar_memoria(void){
    carrera_t *posicion=NULL;
    while(formula1!=NULL){
        posicion=formula1;
        formula1=formula1->next;
        free(posicion);
    }    
}