#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, i;
    float vr[50], vm[50], ac[50], u[50], uc;

    printf("\n");
        printf("Digite todos os pontos de calibração do certificado:");
            scanf("%d",&a);
        printf("Limite de aceitação conforme INMETRO:");
            scanf("%f",&uc);
    printf("\n");

    for(i = 1; i <= a; i++){
        printf("\n");
            printf("Ponto referência [%d]:",i);
                scanf("%f",&vr[i]);
                    printf("Ponto medido [%d]:",i);
                        scanf("%f",&vm[i]);
                            printf("Limite de aceitação ponto [%d]:",i);
                                scanf("%f",&u[i]);
        printf("\n");
                                    if(vr[i] < 0){
                                        vr[i] = vr[i]* - 1;
                                    }
                                            else{
                                                vr[i] = vr[i];
                                            }
                                                    if(vm[i] < 0){
                                                        vm[i] = vm[i]* - 1;
                                                    }
                                                            else{
                                                                vm[i] = vm[i];
                                                            }
                                                                    ac[i] = vm[i] - vr[i];
                                                                        if(ac[i] < 0){
                                                                            ac[i] = ac[i]* - 1;
                                                                        }
                                                                                else{
                                                                                    ac[i] = ac[i];
                                                                                    }
                                                                                        printf("\n|CA| = |VR| - |VM|, ponto [%d]:%.2f",i,ac[i]);


    }




    return 0;
}
