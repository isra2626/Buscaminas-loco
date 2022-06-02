#include <stdio.h>
#include <stdlib.h>

void recorrer_fila_1();
void leer_matrices();
void introduce_cero();

int main(){
    int matriz_de_prueba[10][10];
    introduce_cero(matriz_de_prueba);
    recorrer_fila_1(0,10,matriz_de_prueba);
    leer_matrices(matriz_de_prueba);
    return 0;
}

void recorrer_fila_1(int fila,int t_columna,int matriz[10][10]){
    for (int i = 1; i < t_columna-1; i++)
    {
        matriz[fila][i]=4;
    }
    
}

void leer_matrices(int matriz[][10]){
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
           printf("%i ",matriz[i][j]);
        }
        printf("\n");
    }   
}

void introduce_cero(int matriz [][10]){
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matriz[i][j]= 0;
        }      
    }
}