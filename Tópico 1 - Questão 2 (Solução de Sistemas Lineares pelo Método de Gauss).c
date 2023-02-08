// T1Q2 Eliminação de Gauss

/*  15  17    19   |3890
    0.3 0.4   0.55 |  95  Resp: [90 60 80]
    1   1.2   1.5  | 282
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int eq, n, i, j, k;
    double A[25][25], B[25], x[25], elem, b;
    printf("\nRESOLUCAO DE SISTEMA LINEAR PELO METODO DE GAUSS\nPara finalizar digite '0'\n");
    
    while (1){    
        printf("\nQuantidade de equacoes: "); //ler a qntd de equações do sistema
        scanf("%d", &eq);
        if (eq==0)
            exit(0);
        
        printf("Numero de variaveis: "); //ler número de variáveis
        scanf("%d", &n);
        
        printf("Digite os coeficientes da matriz A:\n"); //ler a matriz A
        for (i = 0; i < eq; i++) {
            printf("\nLinha %d\n", i+1);
            for (j = 0; j < n; j++) {
                printf("Elemento A%d%d: ", i+1,j+1);
                scanf("%lf", &A[i][j]);
            }
        }

        printf("\nMatriz digitada:\n"); //imprimir a matriz A digitada
        for (i = 0; i < eq; i++) {
            for (j = 0; j < n; j++) {
                printf("%.2lf ", A[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        
        printf("\nDigite os valores de B:\n");  //ler os valores da matriz B
        for (i = 0; i < eq; i++) {
            printf("B%d= ", i+1);
            scanf("%lf", &B[i]);
        }
        
        
        for(i=0;i<eq;i++){//transformar numa matriz triangular superior com base nos pivôs Ann
            for (j = i+1; j < eq; j++){
                elem = A[j][i]/A[i][i]; //valor do 'm', elemento abaixo do pivô dividido por ele
                for (k = i; k <=n; k++){
                    A[j][k] = A[j][k] - (elem * A[i][k]);//atualiza a linha fazendo 'L2 = L2 - m*L1' até n
                }
                B[j] = B[j] - elem*B[i]; //atualiza os termos B, assim como a linha anterior
            }
            
        }

        for ( i = n-1; i>=0; i--){//solução retroativa
            b = B[i];//variável b recebe os valores da matriz B, termos independentes
            for (j = i+1; j < n; j++){
                b = b - A[i][j]*x[j];
            }
            x[i] = b /A[i][i]; //inicialmente o ultimo x recebe o valor calculado de b, dividindo pelo pivô e obtendo o valor de Xn 
        }
        printf("\nSolucao so sistema:\n");
        for ( i = 0; i < n; i++){
            printf("x%d = %.2lf\n", i+1, x[i]);
        }
                
    
    }
return 0;
    }