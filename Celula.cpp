#include <stdio.h>

int main()
{
    char tablero[7][7];//El tablero será un arreglo tipo char para poder poner 'V' de vivo y 'M' de muerto
    char tablero2[7][7]; //Tablero secundario para almacenar variables
    char continuar;
    int x, y; //Coordenadas para que el usuario establezca las casillas donde habrá celulas vivas
    int gen; //Numero de generaciones, tambien introducidas por el usuario
    int i, j, k, inicio, vivas;

    for (i = 0; i < 7; i++)  //Inicializando el tablero con todas las celulas en estado M
    {
        for (j = 0; j < 7; j++) {
            tablero[i][j] = '-';
        }
    }
    printf("               - EL JUEGO DE LA VIDA -\n\n");

    //Imprime el tablero inicial

    printf("    1 | 2 | 3 | 4 | 5 |[X]\n");
    for (i = 1; i < 6; i++)
    {
        printf("%i |", i);
        for (j = 1; j < 6; j++) {
            printf(" %c |", tablero[i][j]);
        }
        printf("\n");
    }
    printf("[Y]\n");
    printf("---> Tablero vacio\n");
    printf("     X = Celulas vivas\n");
    printf("     - = Celulas muertas\n");
    //Introduccion de celulas vivas por el usuario
    printf("\n        - Configuracion inicial - ");
    printf("\nCuantas celulas vivas deseas? Introduce tu respuesta: ");
    scanf_s("%i", &inicio);

    for (i = 0; i < inicio; i++)
    {
        printf("\nPara la celula viva numero %i", i + 1);
        printf("\nEscribe la coordenada x: ");
        scanf_s("%i", &x);
        printf("Escribe la coordenada y: ");
        scanf_s("%i", &y);
        tablero[y][x] = 'X';
    }

    //Imprimimos el tablero creado por el usuario
    printf("\n-----------------------------------------------------\n");
    printf("    1 | 2 | 3 | 4 | 5 |[X]\n");
    for (i = 1; i < 6; i++)
    {
        printf("%i |", i);
        for (j = 1; j < 6; j++) {
            printf(" %c |", tablero[i][j]);
        }
        printf("\n");
    }
    printf("[Y]\n");
    printf("---> Tablero inicial (generacion 0)\n");
    printf("     X = Celulas vivas\n");
    printf("     - = Celulas muertas\n");
    printf("Introduzca el numero de generaciones que desea (maximo 10): ");
    scanf_s("%i", &gen);
    printf("\n---------------------------------------------------------------\n");

    //Inicia el proceso para la generacion
    for (k = 0; k < gen; k++)
    {
        for (i = 1; i < 6; i++)
        {
            for (j = 1; j < 6; j++)
            {
                vivas = 0;
                for (x = -1; x < 2; x++)
                {
                    if (tablero[i - 1][j + x] == 'X')
                    {
                        vivas++;
                    }
                }
                for (x = -1; x < 2; x++)
                {
                    if (tablero[i + 1][j + x] == 'X')
                    {
                        vivas++;
                    }
                }
                if (tablero[i][j - 1] == 'X')
                    vivas++;
                if (tablero[i][j + 1] == 'X')
                    vivas++;
                //Determina si la celula vive o muere
                if ((vivas <= 1) || (vivas >= 4))
                    tablero2[i][j] = '-';
                else {
                    if (vivas == 3)
                        tablero2[i][j] = 'X';
                    else
                        tablero2[i][j] = tablero[i][j];
                }

            }


        }
        for (i = 0; i < 7; i++) //Copiamos tableros
        {
            for (j = 0; j < 7; j++)
            {
                tablero[i][j] = tablero2[i][j];
            }
        }

        printf("    1 | 2 | 3 | 4 | 5 |[X]\n");
        for (i = 1; i < 6; i++)
        {
            printf("%i |", i);
            for (j = 1; j < 6; j++) {
                printf(" %c |", tablero[i][j]);
            }
            printf("\n");
        }
        printf("[Y]\n");
        printf("---> Generacion: %i\n", k + 1);
        printf("     X = Celulas vivas\n");
        printf("     - = Celulas muertas\n\n");

        printf("\n---------------------------------------------------------------\n\n");
    }
}
