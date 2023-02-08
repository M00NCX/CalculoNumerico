#include<stdio.h>
#include<math.h>
#include<stdlib.h>
/*
  x{  0,  1.5, 2.6, 4.2, 6, 8.2, 10, 11.4}
F(x){18, 13,  11,   9,   6, 4,   2,  1}

*/
void menu(){
    printf("\nMENU");
    printf("\n1-Reta (F(x) = a + bx)");
    printf("\n2-Parabola (F(x) = a + bx + cx^2)");
    printf("\n3-Exponencial (F(x) = a * e^(bx))");
    printf("\nEscolha o ajuste de curva: ");
}

int main(){

    int i, n, op;
    double somaX=0.0, somaY=0.0, somaXquadrado=0.0, somaXY=0.0, erro=0.0;
    double somaX3=0.0, somaX4 = 0.0, somaX2Y = 0.0;
    double somaXlnFx = 0.0, somaLnFx=0.0;
    do{
        printf("\nInsira a quantidade de dados: ");
        scanf("%d", &n);
        if (n ==0)
            exit(0);
        

        double dados[n][2], valores[n]; //array para n valores, com X e Y
        
        for (int i = 0; i < n; i++) {
        printf("\nInsira os dados X e Y do ponto %d (ex.: 0 0): ",i+1);
        scanf("%lf%lf",&dados[i][0],&dados[i][1]);
        }

        menu();
        scanf("%d", &op);

        switch (op){
        case 1://somatórios para reta consoante a tabela estudada
            for ( i = 0; i < n; i++){
                somaX += dados[i][0];
                somaY += dados[i][1];
                somaXquadrado += dados[i][0]*dados[i][0];
                somaXY += dados[i][0] * dados[i][1];
            }
            valores[1] = (n*somaXY-somaX*somaY)/(n*somaXquadrado-somaX*somaX); //b
            valores[0] = (somaY-valores[1]*somaX)/n;     //a
            printf("\nA equacao eh: F(x) = %.3lf + (%.3lfx)\n", valores[0], valores[1]);//impressao dos resultados
            for ( i = 0; i < n; i++){
                erro += pow(dados[i][1]-(valores[0]+valores[1]*dados[i][0]),2);//calculo do erro quadrático
            }
            printf("\nErro quadratico cometido: %.3lf\n", erro);
            break;
        case 2:
            for (i = 0; i < n; i++){//somatório para parábola
                somaX += dados[i][0];
                somaY += dados[i][1];
                somaXY += dados[i][0] * dados[i][1];
                somaXquadrado += dados[i][0] * dados[i][0];
                somaX3 += pow(dados[i][0],3);
                somaX4 += pow(dados[i][0],4);
                somaX2Y += pow(dados[i][0],2.0) * dados[i][1];
            }
            /*
                cálculo da parábola aqui [não consegui realizar a implementação]

                valores[2] =;
                valores[1] =;
                valores[0] =;

            printf("\nA equacao eh: F(x) = %1.3lf + %1.3lfx + %1.3lfx^2\n", valores[0], valores[1], valores[2]);

            for ( i = 0; i < n; i++){
                erro += pow(dados[i][1]-(valores[0]+valores[1]*dados[i][0])+valores[2]*dados[i][0]*dados[i][0],2);//calculo do erro quadrático
            }
            printf("\nErro quadratico cometido: %.3lf\n", erro);*/

            break;
        case 3:
            for (int i = 0; i < n; i++) {//somatorio para exponencial 
                somaX += dados[i][0];
                somaXquadrado += pow(dados[i][0],2);
                somaXlnFx += dados[i][0] * log(dados[i][1]);//ln fx * x
                somaLnFx += log(dados[i][1]);
            }
            valores[1] = (somaLnFx - somaX*(somaXlnFx - somaX*valores[1])/somaXquadrado)/n ;//b
            valores[0] = (somaXlnFx - somaX*valores[1])/somaXquadrado;//a

            printf("\nA equacao eh: F(x) = %.3lf*%.3lf^x\n", exp(valores[1]), exp(valores[0]));

        break;
        default:
            printf("\nOpcao invalida!\n");
            break;
        }

        printf("\nAjuste realizado com sucesso!\n");
        printf("\nPara finalizar digite 0\n\n");
    } while (n);
    return 0;
}