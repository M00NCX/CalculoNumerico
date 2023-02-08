#include <stdio.h>
#include <stdlib.h>

float RegraTrapezio (int, float, float, float *);
float RegraSimpson (int, float, float, float *);

float h, sfx;
int i;

int main(){
    int n, o;
    float a, b, *fx = NULL;
    
    printf ("Bem vindo ao grande solucionador de integracao numerica!\n");
    
    do{
        setbuf (stdin, NULL);
        printf ("Digite 1 para utilizar meu exemplo ou 2 para inserir os valores manualmente: ");

        do{
            scanf ("%d", &o);
            switch (o){
                case 1:
                    n = 10;
                    a = 0.0;
                    b = 20.0;

                    fx = (float *) malloc (sizeof(float)*n+2);
                    if (!fx){
                        printf("Memoria insuficiente!");
                        exit (1);
                    }
                    fx[0] = 0.0;
                    fx[1] = 1.8;
                    fx[2] = 2.0;
                    fx[3] = 4.0;
                    fx[4] = 4.0;
                    fx[5] = 6.0;
                    fx[6] = 4.0;
                    fx[7] = 3.6;
                    fx[8] = 3.4;
                    fx[9] = 2.8;
                    fx[10] = 0.0;
                    printf ("\nO intervalo vai de %.1f ate %.1f e tem %d sub-intervalos, sendo que os pontos sao: \n", a, b, n);
                    for (i = 0; i <= n; i++)
                        printf ("fx[%d] = %.1f\n", i, *(fx+i));
                    break;

                case 2:
                    printf ("Insira o numero de sub-intervalos: ");
                    scanf ("%d", &n);
                    printf ("Insira o intervalo (Ex.: 2 3): ");
                    scanf ("%f %f", &a, &b);

                    fx = (float *) malloc (sizeof(float)*n+2);
                    if (!fx){
                        printf("Memoria insuficiente!\n\n");
                        exit (1);
                    }
            
                    for (i = 0; i <= n; i++){
                        printf ("Insira o valor de fx[%d]: ", i);
                        scanf ("%f", &fx[i]);
                    }
                    break;

                default:
                    printf ("\nOpcao indisponivel! Insira uma opcao valida: ");
                    break;
            }
        }while(o != 1 && o != 2);

        setbuf (stdin, NULL);
        printf ("\nAgora digite 1 se deseja utilizar a Regra do Trapezio ou 2 se deseja utilizar a Regra de Simpson (Ambas regras sao em suas versoes repetidas!): ");

        do{
            scanf ("%d", &o);
            switch (o){
                case 1:
                    printf ("\nO resultado e: %.4f", RegraTrapezio (n, a, b, fx));
                    break;

                case 2:
                    printf ("\nO resultado e: %.4f", RegraSimpson (n, a, b, fx));
                    break;

                default:
                    printf ("\nOpcao indisponivel! Insira uma opcao valida: \n\n");
            }
        }while(o != 1 && o != 2);

        free (fx);
        setbuf (stdin, NULL);
        printf ("\n\nDeseja realizar um novo calculo? Se nao, insira 0 para sair, e se sim, insira qualquer valor: ");
        scanf ("%d", &o);
    }while(o);

    system ("pause");
    return 0;
}

float RegraTrapezio (int n, float a, float b, float *fx){
    sfx = 0.0;
    h = (b - a) / n;

    for (i = 1; i < n; i++)
        sfx += fx[i];

    sfx = ((fx[0] + fx[n] + sfx*2) * h) / 2;

    return (sfx);
}

float RegraSimpson (int n, float a, float b, float *fx){
    float sfxi = 0.0, sfxp = 0.0;

    sfx = 0.0;
    h = (b - a) / n;

    for (i = 1; i < n; i++){
        if (i%2)
            sfxi += fx[i];
        else
            sfxp += fx[i];
    }

    sfx = ((fx[0] + fx[n] + 4*sfxi + 2*sfxp) * h) / 3;

    return (sfx);
}