#include <stdio.h>
#include <stdlib.h>
int inicioFila = -2, fimFila = -2;

void Iniciarfila(){
    inicioFila = -1;
    fimFila = -1;
}

void Queue(int *fila, int valor){
    if (inicioFila == -2){
        Iniciarfila();
    }
    
    if (fimFila == 4){
        printf("Fila cheia");
    }
    else{

        if ( inicioFila == -1 ){
            inicioFila++;
            fimFila++;
            fila[0] = valor;
        }
        else{
            fimFila++;
            fila[fimFila] = valor;
        }
        

    }
    

}


void Dequeue(int *fila){
    if (fimFila == -1 || fimFila == -2){
        printf("Vazia ou não inicializada \n");
    }
    else{

        fila[0] = 0;
        int j = fimFila - 1;

        for (int i = 0; i <= j ; i++){
            fila[i] = fila[i+1];
        }
        fila[fimFila] = 0;
        fimFila--;

    }
    
}

int consultaFila(int *fila){
    return fila[0];
}

void filaVazia(int *fila){
    if (fimFila == -1 || fimFila == -2 || inicioFila == -1 || inicioFila == -2){
        printf("\n Fila esta vazia  \n");
    }
    else{
        printf("\n Fila NAO esta vazia  \n");
    }
    
}

void excluifila(int *fila){
    for (int i = 0; i <= fimFila; i++){
        fila[i] = 0;
    }
    fimFila = -2;
    inicioFila = -2;
}



void Imprimir(int *fila){
    printf("Fila: \n");
    for (int i = 0; i < 5; i++){
        printf(" %d |", fila[i]);
    }
    printf("\n Inicio Fila: %d \n", inicioFila);
    printf("\n Fim Fila: %d \n", fimFila);
}

int main(){

    int fila[4];
    int opcao = 111;
    int valor;
    int retorno;

    for (int i = 0; i < 5; i++){
        fila[i] = 0;
    }
    
    
    while (opcao != 0){

        printf("\n -------------------------------------------------------- \n");
        printf("\n 1- Inicializa Fila \n");
        printf("\n 2- Queue \n");
        printf("\n 3- Dequeue \n");
        printf("\n 4- Fila Vazia \n");
        printf("\n 5- Consulta Fila \n");
        printf("\n 6- Exclui Fila \n");
        printf("\n 7- Imprimir fila \n");
        printf("\n 0- Sair \n");

        Imprimir(fila);
        
        printf("\n Digite a opcao: ");
        scanf("%d", &opcao);
        

        switch (opcao){
        case 1:
            printf("\n 1- Inicializar Fila \n");
            Iniciarfila();
            
            break;
        
        case 2:
            printf("\n 2- Queue \n");
            printf("\n Digite um valor: \n");
            scanf("%d", &valor);
            Queue(fila, valor);
        

            break;
        
        case 3:
            printf("\n 3- Dequeue \n");
            Dequeue(fila);
            
            break;
        
        case 4:
            filaVazia(fila);

            break;
        
        case 5:
            retorno = consultaFila(fila);
            printf("Retorno: %d", retorno);
            
            break;
        
        case 6:
            excluifila(fila);
            
            
            break;
        
        case 7:
            Imprimir(fila);
            break;
        
        default:
            printf("\n Programa encerrado \n");
            opcao = 0;
            break;
    
        }
    
    }


    return 0;
}
