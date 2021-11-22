#include <stdio.h>
#include <stdlib.h>
//Variaveis globais
int topo = -2;

void IniciarPilha(){
    topo = -1;
}

void Push(int *pilha, int valor){
    if (topo == 4){
        printf("Pilha cheia! \n");
    }
    else if (topo == -2){
        IniciarPilha();
        topo++;
        pilha[topo] = valor;
        printf("Elemento adicionado \n");
    }
    else{ 
        topo++;
        pilha[topo] = valor;
        printf("Elemento adicionado \n");
    }
    

}
void Pop(int *pilha){
    if (topo == -1){
        printf("Pilha vazia! \n");
    }
    else{ 
        pilha[topo] = 0;
        topo--;
        printf("Elemento eliminado\n");
    }
}

int PilhaVazia(){
    if (topo < 0){
        return 1;
        //printf("Pilha Vazia\n");
    }
    else{
        return 0;
        //printf("Pilha nao vazia");
    }
    

}

void ExcluirPilha(int *pilha){
    for (int i = 0; i <= topo; i++){
        pilha[i] = 0;
        
    }
    topo = -2;
    printf("Pilha excluida \n");

}

int ConsultaPilha(int *pilha){
    return pilha[topo];
}

void Imprimir(int *pilha){
    printf("Pilha: \n");
    for (int i = 0; i < 5; i++){
        printf(" %d |", pilha[i]);
    }
    
}

//---------------------FUNCAO PRINCIPAL------------------------------------------
int main(){
    int pilha[4];
    int opcao = 111;
    int valor;
    int retorno;

    for (int i = 0; i < 5; i++){
        pilha[i] = 0;
    }
    
    
    while (opcao != 0){

        printf("\n -------------------------------------------------------- \n");
        printf("\n 1- Inserir \n");
        printf("\n 2- Remover \n");
        printf("\n 3- Busca \n");
        printf("\n 4- Imprimir \n");
        printf("\n 5- Iniciar Pilha \n");
        printf("\n 6- Pilha vazia? \n");
        printf("\n 7- Excluir pilha \n");
        printf("\n 0- Sair \n");

        Imprimir(pilha);
        
        printf("\n Digite a opcao: ");
        scanf("%d", &opcao);
        

        switch (opcao){
        case 1:
            printf("\n 1- Inserir \n");
            printf("\n Digite o valor: ");
            scanf("%d", &valor);
            Push(pilha, valor);
            
            break;
        
        case 2:
            printf("\n 2- Remover \n");
            Pop(pilha);
            break;
        
        case 3:
            printf("\n 3- Busca \n");
            int retorno;
            retorno = ConsultaPilha(pilha);
            printf("Valor do topo= %d", retorno);
            break;
        
        case 4:
            Imprimir(pilha);

            break;
        
        case 5:
            IniciarPilha();
            
            break;
        
        case 6:
            retorno = PilhaVazia();
            if (retorno == 1){
                printf("\n Sim, esta vazia \n");
            }
            else{
                printf("\n Nao esta vazia \n");
            }
            
            break;
        
        case 7:
            ExcluirPilha(pilha);
            
            break;
        
        default:
            printf("\n Programa encerrado \n");
            opcao = 0;
            break;
    
        }
    
    }



}