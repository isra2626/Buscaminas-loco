#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void introduce(int matriz[][5]);
void leer(int matriz[][5]);
int main()
{   int matriz[7][5];
    introduce(matriz);
    leer(matriz);
    printf("\n\n");
    introduce(matriz);
    leer(matriz);
    return 0;
}

void leer(int matriz[][5]){
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 5; j++)
        {
           printf("%i ",matriz[i][j]);
        }
        printf("\n");
    }   
}

void introduce(int matriz [][5]){
    srand (getpid());
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matriz[i][j]= random()%2;
        }      
    }
}