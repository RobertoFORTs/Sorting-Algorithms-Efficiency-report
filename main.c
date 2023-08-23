#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"


int main(){
    // "menu"
    //------------------------------------------------------------
    // declaração de variáveis que serão necessárias para execução
    int inc, fim, stp, rpt;
    printf("Digite o tamanho inicial, final, intervalo e número de repetições desejadas, repectivamente: \n");
    scanf("%d %d %d %d", &inc, &fim, &stp, &rpt);
    int i = 0;
    int j = 0;
    int quantidadeDeN = (fim - inc)/stp;

    //---------------------------------------------------------
    //Construção dos vetores para os diversos casos de testes
    




    //---------------------------------------------------------
    //Primeiro Caso (execução dos processos repetidas vezes)
    printf("Primeiro caso, Vetor preenchido aleatóriamente:\n");

    while (i < quantidadeDeN){
        
        j = 0; //controla a quantidade de repetições para cada caso de teste

        while (j < rpt){

            //obter soma dos tempos de execução para cada algorítimo
            
            j++;
        }
        //calcular media para cada n e exibir
        i++;
    }
    
    //---------------------------------------------------------------
    // Para os restante dos casos, utilizar os mesmos valores de entrada, porém com apenas uma execução para cada vetor de tamanho n
    
    i = 0;
    printf("Segundo caso\n");
    while (i < quantidadeDeN){

        i++;
    }

    //---------------------------------------
    i = 0;
    printf("terceiro caso\n");
    while (i < quantidadeDeN){

        i++;
    }

    //----------------------------------------
    i = 0;
    printf("Quarto caso \n");
    while (i < quantidadeDeN){

        i++;
    }
}