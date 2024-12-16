//Le agrega una nueva variable, que me diga cuantas temporadas tiene la serie.
//Y por ultimo, que te imprima en un texto tadas tus series.


#include <stdio.h>
#include <stdlib.h>
#define MAX_AL 30
#define SALIR 3
typedef struct Series{
    char Nombre[30];
    int Temporadas;
    int Episodios;
    struct Series *next;
}Serie_t; 

Serie_t * Netflix=NULL;
FILE *archivo;

void menu(void);
void imprimir_Series(Serie_t);
void pedir_datos(Serie_t * Series);
void ver_lista(void);
void cargar_Series(void);
void liberar_memoria(void);

int main(){
    archivo = fopen("Tus series.txt", "w"); 
    if (archivo == NULL) {
    printf("Error!\n");
    exit(1);
    }
    menu();
    liberar_memoria();
    fclose(archivo); 
    return 0;
    return 0;
}

void imprimir_Series(Serie_t Series){
    printf("----------------------------------\n");
    printf("Nombre: %s\n",Series.Nombre);
    printf("Temporadas: %d\n",Series.Temporadas);
    printf("Episodios: %d\n",Series.Episodios);
    printf("----------------------------------\n");
    
    fprintf(archivo, "----------------------------------\n");
    fprintf(archivo, "Nombre: %s\n", Series.Nombre);
    fprintf(archivo, "Temporadas: %d\n", Series.Temporadas);
    fprintf(archivo, "Episodios: %d\n", Series.Episodios);
    fprintf(archivo, "----------------------------------\n");

}
void pedir_datos(Serie_t * Series){
    printf("\n¿Cual es el nombre de la serie?:");
    scanf(" %[^\n]%*c", Series->Nombre);
    printf("¿Cuantas Temporadas tiene la serie?:");
    scanf("%d",&(Series->Temporadas));
    printf("¿Cuantos episodios tiene la serie, en total?:");
    scanf("%d",&(Series->Episodios));
    while(getchar() != '\n');
    printf("!cargardo con exito!\n");
    printf("\n");
    
}



void menu(void){
    int opcion;
    do{
        printf("Opcion N°1= Cargar una nueva serie\n");
        printf("Opcion N°2= Ver todas las series cargadas\n");
        printf("Opcion N°3= Salir\n\n");
        printf("Tu opcion elegida es: ");
        scanf("%d",&opcion);
        if(opcion==1)cargar_Series();
        if(opcion==2)ver_lista();
    }while(opcion!=SALIR);
    
}

void cargar_Series(){
    Serie_t *Serie_aux;
    Serie_aux=malloc(sizeof(Serie_t));
    if(Serie_aux==NULL){
        printf("Out of memory\n");
    }else{
        pedir_datos(Serie_aux);
        Serie_aux->next=Netflix;
        Netflix=Serie_aux;
    }
     
        
}

void ver_lista(void){
    Serie_t *lista=Netflix;
    while(lista!=NULL){
        imprimir_Series(*lista);
        lista=lista->next;
    }
}
void liberar_memoria(void){
    Serie_t *aux=NULL;
    while(Netflix!=NULL){
        aux=Netflix;
        Netflix=Netflix->next;
        free(aux);

    }
    
}









