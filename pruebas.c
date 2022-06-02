#include <stdio.h>
#include <stdlib.h>

void recorrer_matriz_de_forma_cuadrada();
void leer_matrices();
void introduce_cero();

int main(){
    int matriz_de_prueba[10][10];
    introduce_cero(matriz_de_prueba);
    recorrer_matriz_de_forma_cuadrada(matriz_de_prueba);
    leer_matrices(matriz_de_prueba);
    return 0;
}

void recorrer_matriz_de_forma_cuadrada(int matriz[10][10]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matriz[i][j]=1;
        }
        
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