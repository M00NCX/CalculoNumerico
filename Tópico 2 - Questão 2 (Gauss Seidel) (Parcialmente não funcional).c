#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void criarsistema (float **, float *, float *, float *)
void inicializarsistema (float **, float*, float *);
void imprimirsistema (int, float **, float *);
void imprimirsolucao (int, float *);
float diferencarelativa (float *, float *);
void liberar (float **, float *, float *, float *);

int i, j, n=0;

int main(){
    int o, k = 0;
    float e, dRk, **A = NULL, *B = NULL, *Xk = NULL, *Xk1 = NULL;
    
    printf ("Bem vindo ao grande solucionador de problemas de trelica com o Metodo de Gauss-Seidel!\n");
    
    do{
        setbuf (stdin, NULL);
        printf ("Digite 1 para utilizar meu exemplo ou 2 para inserir os valores manualmente: ");

        do{
            scanf ("%d", &o);
            switch (o){
                case 1:
                    n = 7;
                    e = 0.0001;

                    A = (float **) calloc (n, sizeof(float *));
                    if (!A){
                        printf("Memoria insuficiente!");
                        exit (1);
                    }

                    for (i = 0; i < n; i++){
                    A[i] = calloc (n, sizeof(float));
                    if (!A[i]){
                        printf("Memoria insuficiente!");
                        exit (1);
                        }
                    }

                    B = calloc (n, sizeof(float));
                    if (!B){
                        printf("Memoria insuficiente!");
                        exit (1);
                    }         

                    Xk = calloc (n, sizeof(float));
                    if (!Xk){
                        printf("Memoria insuficiente!");
                        exit (1);
                    }
    
                    Xk1 = calloc (n, sizeof(float));
                    if (!Xk1){
                        printf("Memoria insuficiente!");
                        exit (1);
                    }

                    A[0][0] = -cos(45);
                    A[0][2] = 1;
                    A[0][3] = cos(45);
                    A[1][0] = -sin(45);
                    A[1][3] = -sin(45);
                    A[2][1] = -1;
                    A[2][2] = -cos(45);
                    A[2][4] = cos(60);
                    A[2][5] = 1;
                    A[3][2] = sin(45);
                    A[3][4] = sin(60);
                    A[4][3] = -1;
                    A[4][4] = -cos(60);
                    A[4][6] = cos(30);
                    A[5][4] = -sin(60);
                    A[5][6] = -sin(30);
                    A[6][5] = -1;
                    A[6][6] = -cos(30);

                    imprimirsistema (k, A, B);
                    printf ("/n/n");
                    
                    break;

                case 2:
                    printf ("Insira a ordem do sistema linear: ");
                    scanf ("%d", &n);
                    printf ("Insira a precisao: ");
                    scanf ("%f", &e);

                    A = (float **) calloc (n, sizeof(float *));
                    if (!A){
                        printf("Memoria insuficiente!");
                        exit (1);
                    }

                    for (i = 0; i < n; i++){
                    A[i] = calloc (n, sizeof(float));
                    if (!A[i]){
                        printf("Memoria insuficiente!");
                        exit (1);
                        }
                    }

                    B = calloc (n, sizeof(float));
                    if (!B){
                        printf("Memoria insuficiente!");
                        exit (1);
                    }         

                    Xk = calloc (n, sizeof(float));
                    if (!Xk){
                        printf("Memoria insuficiente!");
                        exit (1);
                    }
    
                    Xk1 = calloc (n, sizeof(float));
                    if (!Xk1){
                        printf("Memoria insuficiente!");
                        exit (1);
                    }
                    
                    inicializarsistema (A, B, Xk);
                    imprimirsistema (k, A, B);
                    printf ("/n/n");
                    
                    break;

                default:
                    printf ("\nOpcao indisponivel! Insira uma opcao valida: ");
                    break;
            }
        }while(o != 1 && o != 2);

        do{
            for (i = 0; i < n; i++){
                Xk1[i] = B[i];

                for (j = 0; j < n; j++){
                    if (i < j)
                        Xk1[i] -= A[i][j] * Xk[j];
                    else{
                        if (i > j)
                            Xk1[i] -= A[i][k] * Xk1[j];
                    }
                }

                Xk1[i] /= A[i][i];
            }

            imprimirsolucao (k, Xk1);
            k++;
            dRk = diferencarelativa (Xk, Xk1);
            printf ("\n\nA diferenca relativa e: %f\n\n", dRk);

            for (i = 0; i < n; i++)
                Xk[i] = Xk1[i];

        }while (dRk > e);

        imprimirsistema (k, A, B);
        imprimirsolucao (k, Xk1);
        printf ("\nA precisao foi de %f", dRk);

        liberar (A, B, Xk, Xk1);
        setbuf (stdin, NULL);
        printf ("\n\nDeseja realizar um novo calculo? Se nao, insira 0 para sair, e se sim, insira qualquer valor: ");
        scanf ("%d", &o);
    }while(o);

    system ("pause");
    return 0;
}

void criarsistema (float **A, float *B, float *Xk, float *Xk1){
    A = (float **) calloc (n, sizeof(float *));
    if (!A){
        printf("Memoria insuficiente!");
        exit (1);
    }

    for (i = 0; i < n; i++){
        A[i] = calloc (n, sizeof(float));
        if (!A[i]){
            printf("Memoria insuficiente!");
            exit (1);
        }
    }

    B = calloc (n, sizeof(float));
    if (!B){
        printf("Memoria insuficiente!");
        exit (1);
    }

    Xk = calloc (n, sizeof(float));
    if (!Xk){
        printf("Memoria insuficiente!");
        exit (1);
    }
    
    Xk1 = calloc (n, sizeof(float));
    if (!Xk1){
        printf("Memoria insuficiente!");
        exit (1);
    }
}

void inicializarsistema (float **A, float *B, float *Xk){
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf ("Insira a%d%d: ", i, j);
            scanf ("%f", A[i][j]);
        }

        printf ("Insira b%d: ", i);
        scanf ("%f", B[i]);
    }

    printf ("Insira a proposta inicial (k=0).\n");
    for (i = 0; i < n; i++){
        printf ("Xk%d: ", i);
        scanf ("%f", Xk[i]);
    }
}

void imprimirsistema (int k, float **A, float *B){
    printf ("Sistema Linear da %d iteracao:\n\n", k);
    for (i = 0; i < n; i++){
        for (j = 0; j <= n; j++){
            if (j == n)
                printf ("= %f\n", B[i]);
            else{
                if (j == n-1)
                    printf ("%fx%d ", A[i][j], j+1);
                else
                    printf ("%fx%d + ", A[i][j], j+1);
            }
        }
    }
}

void imprimirsolucao (int k, float *Xk1){
    printf ("\nA solucao da %d iteracao e: \n\n", k);
    for (i = 0; i < n; i++)
        printf ("x%d = %f\n", i+1, Xk1[i]);
}

float diferencarelativa (float *Xk, float *Xk1){
    float dk = 0.0, MXk1 = 0.0, dRk;

    for (i = 0; i < n; i++){
        if (dk < abs(Xk1[i] - Xk[i]))
            dk = abs(Xk1[i] - Xk[i]);

        if (MXk1 < Xk1[i])
            MXk1 = Xk1[i];
    }
    
    dRk = dk / MXk1;

    return (dRk);
}

void liberar (float **A, float *B, float *Xk, float *Xk1){
    for (i = 0; i < n; i++)
        free (A[i]);
    free (A);
    free (B);
    free (Xk);
    free (Xk1);
}