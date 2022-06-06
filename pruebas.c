#include <stdio.h>
#include <stdlib.h>

void leer_matrices();
void introduce_cero();
void explorando_minas();
int contare();

int main(){
    int matriz_de_prueba[10][10];
    int matriz_de_prueba_2[10][10];
    introduce_cero(matriz_de_prueba);
    introduce_cero(matriz_de_prueba_2);
    matriz_de_prueba[2][4]=1;
    matriz_de_prueba[2][5]=1;
    leer_matrices(matriz_de_prueba);
    printf("    %i",contare(matriz_de_prueba,matriz_de_prueba_2));
    return 0;
}
void explorando_minas(int matriz_de_la_pantalla[][10], int matriz_de_las_minas[][10]){
    int fila_analizada;
    int columna_analizada;
    printf("Coloca el numero de fila: ");
    scanf("%i",&fila_analizada);
    printf("Coloca el numero de columna: ");
    scanf("%i",&columna_analizada);
        
}
   int contare(int matriz_de_minas[][10],int matriz_estado_pantalla[][10]){
       int contador=0;
       for (int i = 0; i < 10; i++)
       {
           for (int j = 0; j < 10; j++)
           {
               if (matriz_de_minas[i][j]==1)
               {
                  contador++; 
               }
                if (matriz_estado_pantalla[i][j]==1)
                {
                    contador++;
                }
                   
    
               
           }
           
       }
       return contador;
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
            matriz[i][j]=0;
        }      
    }
}
