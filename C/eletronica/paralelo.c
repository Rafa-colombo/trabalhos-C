#include <stdio.h>
#include <math.h>


float r_equivalente(float res[], int n) {
    if (n == 1) { 
        return res[0];
    } else {
        float r_eq = (res[0] * res[1]) / (res[0] + res[1]);
        res[1] = r_eq;
        return r_equivalente(res + 1, n - 1);
    }
}

void r_paralelo() {
    int n;
    printf("Quantos resistores em paralelo: ");
    scanf("%d", &n);

    float res[n];
    printf("Digite os valores dos %d resistores: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &res[i]);
    }

    float r_eq = r_equivalente(res, n);
    printf("Resistencia equivalente: %.2f\n", r_eq);
}

void d_tensao(){
    float r1, r2, vcc;

    printf("R1 R2 VCC: ");
    scanf("%f %f %f", &r1, &r2, &vcc);
    float calculo = vcc * (r1/(r1+r2));

    printf("\nTensao de R1: %.2fV\n", calculo);
}

void main(){
    char n[10];
    while (n)
    {
        printf("Digite operacao: \nd divisor tensao\nr paralelo\ns sair\n");
        scanf("%s", n);

        switch (n[0])
        {
        case 'd':
            d_tensao();
            printf("\n");
            break;
        case 'r':
            r_paralelo();
            printf("\n");
            break;
        case 's':
            return;

        default:
            break;
        }
    }

}
