#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define FILAS 10
#define COLUMNAS 10
#define CANTIDAD_DE_MINAS 5

void colocador_de_minas();
void mete_la_mina();
void leer_matrices();
void introduce_cero();
int aleatorio_en_rango();
void minas_cercanas_1();
void imprimir_pantalla_del_juego();
void introduce_uno();
int contare(int matriz_de_minas[][10],int matriz_estado_pantalla[][10]);
void abridor_minas();


int main()
{   int matriz_minas[FILAS][COLUMNAS];
    int matriz_general[FILAS][COLUMNAS];
    int matriz_dePantalla[FILAS][COLUMNAS];
    srand(time(NULL));
    introduce_cero(matriz_minas);
    introduce_cero(matriz_general);
    introduce_cero(matriz_dePantalla);
    colocador_de_minas(matriz_minas);
    minas_cercanas_1(matriz_minas,matriz_general);
    leer_matrices(matriz_minas);
    imprimir_pantalla_del_juego(matriz_dePantalla,matriz_general);
    abridor_minas(matriz_minas,matriz_dePantalla,matriz_general);
    return 0;
}
int aleatorioEnRango(int minimo, int maximo){
    
   return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void mete_la_mina(int fila, int columna, int matriz[][COLUMNAS]){
    matriz[fila][columna]=1;
}

void colocador_de_minas (int matriz[FILAS][COLUMNAS]){
    int l;
  for (l = 0; l < CANTIDAD_DE_MINAS; l++) {
    int fila = aleatorioEnRango(1, FILAS - 2);
    int columna = aleatorioEnRango(1, COLUMNAS - 2);
    if(matriz[fila][columna]==0){
        mete_la_mina(fila, columna, matriz);
        }else{
            l=l-1;
            continue;
        }
    
  }
} 

void leer_matrices(int matriz[][COLUMNAS]){
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
           printf("%i ",matriz[i][j]);
        }
        printf("\n");
    }   
}

void introduce_cero(int matriz [][COLUMNAS]){
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            matriz[i][j]= 0;
        }      
    }
}

int recorrer_matriz_de_forma_cuadrada(int fila,int columna,int matriz[][COLUMNAS]){
    fila = fila -1;
    columna = columna -1;
    int contador=0;
    for (int k = 0+fila; k < 3+fila; k++)
    {
        for (int l = 0+columna; l < 3+columna; l++)
        {
            if (matriz[k][l]==1)
            {
                contador++;
            }
             
        }
        
    }
    return contador;  
}

void minas_cercanas_1(int matriz_a_calcular[][COLUMNAS], int matriz_a_devolver[FILAS][COLUMNAS]){

    for (int i = 1; i < FILAS-1; i++)
    {
        for (int j = 1; j < COLUMNAS-1; j++)
        {
            int minas = 0;
            if (matriz_a_calcular[i][j]==1)
            {
                matriz_a_devolver[i][j]=9;
                continue;
            }
            
            minas = recorrer_matriz_de_forma_cuadrada(i,j,matriz_a_calcular);
            matriz_a_devolver[i][j]= minas;
        }
        
    }
    
}

void imprimir_pantalla_del_juego(int matriz_estado_de_pantalla[][10],int matriz_del_tablero[][10]){
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (matriz_estado_de_pantalla[i][j]==0)
            {
                printf("# ");
            }
            else
            {
                if (matriz_del_tablero[i][j]==9)
                {
                    printf("* ");
                }
                else
                {
                    printf("%i ",matriz_del_tablero[i][j]);
                }
                
            }
            
        }
        printf("\n");
    }   
}

void introduce_uno(int matriz [][COLUMNAS]){
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            matriz[i][j]= 1;
        }      
    }
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

void abridor_minas(int matriz_de_minas[][COLUMNAS], int matriz_de_pantalla[][COLUMNAS],int matrizGeneral[][COLUMNAS]){
    for(;;)
    {
        int fila_analizada;
        int columna_anilizada;
        
        
        printf("Coloca la fila a descubrir: ");
        scanf("%i",&fila_analizada);
        /*if (fila_analizada==0)break;*/
        if (fila_analizada>=FILAS)
        {
            do
            {
                printf("Coloca la fila correcta: ");
                scanf("%i",&fila_analizada);
                if (fila_analizada>-1&&fila_analizada<FILAS)
                {
                    break;
                }
                
            } while (1);
            
        }
        
        printf("Coloca la columna a descubrir: ");
        scanf("%i",&columna_anilizada);
        /*if(columna_anilizada==0)break;*/
        if (columna_anilizada>=COLUMNAS)
        {
            do
            {
                printf("Coloca la columna correcta: ");
                scanf("%i",&columna_anilizada);
                if (columna_anilizada>-1&&columna_anilizada<FILAS)
                {
                    break;
                }
                
            } while (1);
            
        }
        if (contare(matriz_de_minas,matriz_de_pantalla)>=((FILAS*COLUMNAS)-1))
        {
            introduce_uno(matriz_de_pantalla);
            imprimir_pantalla_del_juego(matriz_de_pantalla,matrizGeneral);
            printf("\nYOU WIN\n");
            break;
        }
        if (matriz_de_minas[fila_analizada][columna_anilizada]==1)
        {
            introduce_uno(matriz_de_pantalla);
            imprimir_pantalla_del_juego(matriz_de_pantalla,matrizGeneral);
            printf("\nYOU LOSE\n");
            break;
        }
        else
        {
            matriz_de_pantalla[fila_analizada][columna_anilizada]=1;
            imprimir_pantalla_del_juego(matriz_de_pantalla,matrizGeneral);
        }
    }
}