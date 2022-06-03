#include <stdio.h>
#include <stdlib.h>

void minas_cercanas_2_1();
int recorrer_de_forma_rectangular();
void leer_matrices();
void introduce_cero();


int main(){
    int matriz_de_prueba[10][10];
    introduce_cero(matriz_de_prueba);
    minas_cercanas_2_1(0,10,matriz_de_prueba,matriz_de_prueba);
    leer_matrices(matriz_de_prueba);
    return 0;
}



int recorrer_de_forma_rectangular(int fila, int columna,int matriz_a_recorrer[10][10]){
    int contadorDeMinas = 0;
    for (int k = 0+fila; k < 2+fila; k++)
    {
        for (int l = 0+columna; l < 3+columna; l++)
        {
            if (matriz_a_recorrer[k][l]==1)
            {
                contadorDeMinas++;
            }
        }
        
    }
    return contadorDeMinas;
}

void minas_cercanas_2_1(int fila,int t_columna,int matriz_a_recorrer[10][10],int matriz_a_devolver[10][10]){
    for (int i = 1; i < t_columna-1; i++)
    {
        int minas=0;
            if (matriz_a_recorrer[0][i]==1)
            {
                matriz_a_devolver[0][i]=9;
                continue;
            }
        minas=recorrer_de_forma_rectangular(0,i,matriz_a_recorrer);
        matriz_a_devolver[0][i]=minas;

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