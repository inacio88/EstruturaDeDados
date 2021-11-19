#include <stdio.h>
#include <stdlib.h>
//VARIAVEIS GLOBAIS
int inicioLista = -1, finalLista = -1;

//Prototipacao da funcao
int BuscarNodo(int *lista, int valor);
int ImprimirLista(int *lista);

//INSERIR ELEMENTO NO INICIO
int InserirInicio(int *lista, int valor){
    ImprimirLista(lista);
    
    if (inicioLista == 0 && finalLista == 4){
        printf("Lista cheia \n");
    }
    else if (inicioLista == -1 && finalLista == -1){
        printf("Lista vazia \n");
        ImprimirLista(lista);
        inicioLista++;
        finalLista++;
        lista[inicioLista] = valor;
    }
    else{

        if (inicioLista == 0){
          finalLista++;
          ImprimirLista(lista);
          for (int i = finalLista; i >= 0; i--){
                lista[i+1] = lista[i]; 
           }  
           lista[inicioLista] = valor;
           ImprimirLista(lista);
        }
        else if (inicioLista != 0){
            inicioLista--;
            lista[inicioLista] = valor;
            ImprimirLista(lista);            
        }
        
        



        //finalLista++;
        //for (int i = finalLista; i >= 0; i--){
        //    lista[i+1] = lista[i];
        //}
        //lista[inicioLista] = valor;
        
        
    }
    
    return 0;    
}


//INSERIR ELEMENTO NO FINAL
int InserirFinal(int *lista, int valor){
    ImprimirLista(lista);
    if (inicioLista == 0 && finalLista == 4){
        printf("Lista cheia \n");
    }
    else if (inicioLista == -1 && finalLista == -1){
        printf("Lista vazia \n");
        inicioLista++;
        finalLista++;    
        lista[inicioLista] = valor;
        ImprimirLista(lista);
        
    }
    else{
        if (inicioLista == 0){
            finalLista++;
            ImprimirLista(lista);
            lista[finalLista] = valor;
        }

        else if (inicioLista != 0){
            inicioLista--;
            ImprimirLista(lista);
            for (int i = inicioLista; i < finalLista; i++){
                lista[i] = lista[i+1];
            }
            lista[finalLista] = valor;
            
        }
            

            
    }
    
    return 0;    
}

//INSERIR ELEMENTO NO MEIO
int InserirMeio(int *lista, int valor, int posicao){

    ImprimirLista(lista);
    if (inicioLista == 0 && finalLista == 4){
        printf("Lista cheia \n");
    }
    else if (inicioLista == -1 && finalLista == -1){
        printf("Lista vazia \n");
        inicioLista++;
        finalLista++;
        ImprimirLista(lista);
        lista[inicioLista] = valor;

        
    }
    else{
        ImprimirLista(lista);

        if (lista[posicao] == 0){
            lista[posicao] = valor;
        }
        else{
            finalLista++;
            ImprimirLista(lista);
            for (int i = finalLista; i >= posicao; i--){
                lista[i] = lista[i-1];
            }
            lista[posicao] = valor;
            
        }
            

            
    }
    
    return 0;    
}

//EXCLUIR NODO
int ExcluirNodo(int *lista, int valor){
    int posicao;
    ImprimirLista(lista);
    posicao = BuscarNodo(lista, valor);
    if (posicao == 404){
        return 404;
    }
    else if (inicioLista == -1 && finalLista == -1){
        printf("Lista vazia \n");
        
    }
    else{
        
        if (posicao == inicioLista){
            lista[posicao] = 0;
            ImprimirLista(lista);
            inicioLista = posicao + 1;
        }
        else if (posicao == finalLista){
            lista[posicao] = 0;
            finalLista = posicao - 1;
        }
        
        else{
            lista[posicao] = 0;
            finalLista--;
            ImprimirLista(lista);
            for (int i = posicao; i <= finalLista; i++){
                lista[i] = lista[i+1];
            }
            lista[finalLista+1] = 0;
            
        }
        
                
            
    }
    
    return 0;    
}

int BuscarNodo(int *lista, int valor){
    int contador=0;
    ImprimirLista(lista);
    for (int i = inicioLista; i <= finalLista; i++){
        if (lista[i] == valor){
            return i;
        }
        else{
            contador++;
        }
        if (i == finalLista && lista[i] != valor){
            return 404;
        }
        
        
    }
    
}

// VISUALIZAR A LISTA
int ImprimirLista(int *lista){
    printf("\n-------------------------------------------------\n");
    for (int j = 0; j <= 4; j++){
        printf("\n valor salvo: %d", lista[j]);
    }
    printf("\nInicio da lista: %d", inicioLista);
    printf("\nFinal da lista: %d", finalLista);
    printf("\n-------------------------------------------------\n");
}


//------------------- FUNCAO PRINCIPAL ----------------------------------
int main(){
    int lista[] = {0, 0, 0, 0, 0};
    int valor = 22, opcao = 1, posicao;
    int retorno5;
    do
    {
        
        printf("\n Digite uma opcao: ");
        printf("\n 1 - Inserir no inicio");
        printf("\n 2 - Inserir no final");
        printf("\n 3 - Inserir no meio");
        printf("\n 4 - Deletar nodo");
        printf("\n 5 - Buscar nodo \n");
        scanf("%d", &opcao);
       
        switch (opcao){
        case 1:
            printf("Inserir elemento no inicio \n");
            printf("Digite o valor: \n");
            scanf("%d", &valor);
            
           
            InserirInicio(lista, valor);

            ImprimirLista(lista);
            break;
        
        
        case 2:
            printf("Inserir elemento no final \n");
            printf("Digite o valor: \n");
            scanf("%d", &valor);

            InserirFinal(lista, valor);
            ImprimirLista(lista);
            
            break;
        
        
        case 3:
            printf("Inserir elemento no meio \n");
            printf("Digite o valor: \n");
            scanf("%d", &valor);
            
            printf("Digite a posicao: \n");
            scanf("%d", &posicao);

            InserirMeio(lista, valor, posicao);
            ImprimirLista(lista);
            
            break;
        
        
        case 4:
            printf("Excluir elemento \n");
            printf("Digite o valor: \n");
            scanf("%d", &valor);
            
            if (ExcluirNodo(lista, valor) == 404){
                printf("Elemento nao encontrado");
            }
            else{
                printf("O elemento foi removido\n");
            }
            ImprimirLista(lista);
            
            break;
        
        case 5:
            printf("Buscar elemento \n");
            printf("Digite o valor: \n");
            scanf("%d", &valor);
            retorno5 = BuscarNodo(lista, valor);
            if ( retorno5 == 404){
                printf("Elemento nao encontrado \n");
            }
            else{
                printf("\n O elemento esta na posicao: %d", retorno5);
            }
            

            break;
        
        default:
            opcao = 0;
            break;
        }


    } while (opcao != 0);
      
    return 0;
}
