#include <stdio.h>
#include <stdlib.h>

float obtem_modulo(float numero){
    if(numero < 0){
        numero = numero * -1;
    }
    return numero;
}

int main(void){
    int qtd, i;
    float incerteza_certif;

    printf("\nDigite a quantidade de pontos de calibração do certificado:"); 
    scanf("%d", &qtd);
    printf("Limite de aceitação conforme INMETRO:");
    scanf("%f", &incerteza_certif);
    printf("\n");

    float valor_ref[qtd], valor_medio[qtd], erro[qtd], incerteza_INMETRO[qtd], ca[qtd];

    for(i = 1; i <= qtd; i++){
        printf("\nPonto referência [%d]:", i);
        scanf("%f", &valor_ref[i]);
        printf("Ponto medido [%d]:", i);
        scanf("%f", &valor_medio[i]);
        printf("Limite de aceitação ponto [%d]:", i);
        scanf("%f", &incerteza_INMETRO[i]);
        
        valor_ref[i] = obtem_modulo(valor_ref[i]);
        valor_medio[i] = obtem_modulo(valor_medio[i]); 
        erro[i] = valor_medio[i] - valor_ref[i];
        erro[i] = obtem_modulo(erro[i]);
        ca[i] = erro[i] + incerteza_INMETRO[i];

        printf("|CA| = |VR| - |valor_medio|, ponto [%d]:%.2f\n", i, erro[i]);
        printf("Incerteza do certificado ponto[%d] = [%.2f]\n", i, ca[i]);    

        //VERIFICA SE O VALOR ESTA DENTRO DO LIMITE DE ACEITACAO DO INMETRO
        if(ca[i] > incerteza_certif){
            printf("REPROVADO no ponto: [%d]\n", i);
        }else{
            printf("APROVADO no ponto: [%d]\n", i);
        }
    }
    return 0;
}