#include <stdio.h>
#include <stdlib.h>

// Implementar em C uma lista encadeada com as operações 
//de inserção e remoção no início, meio e fim. 


typedef struct noh{
    int dado;
    struct noh *proximo;
}*tipoLista;


tipoLista criarNoh(int valor){
    tipoLista novoNoh = (tipoLista) malloc(sizeof(tipoLista));

    if (novoNoh == NULL){
        printf("\n erro para criar noh");
        return NULL;
    }
    else{
        novoNoh->dado = valor;
        novoNoh->proximo = NULL;
        return novoNoh;
    }
    
}


tipoLista inserirEsquerda(int valor, tipoLista lista){
    tipoLista novoNoh = criarNoh(valor);

    if (lista == NULL){
        return novoNoh;
    }
    else{
        novoNoh->proximo = lista;
        return novoNoh;
    }
}


tipoLista inserirDireita(int valor, tipoLista lista){
    tipoLista novoNoh = criarNoh(valor);

    if (lista == NULL){
        return novoNoh;
    }
    else{
        tipoLista listaAux = lista;

        while (listaAux->proximo != NULL){
            listaAux = listaAux->proximo;
        }

        listaAux->proximo = novoNoh;
   //?     
        return lista;
    }
}

tipoLista removerEsquerda(tipoLista lista){
    if (lista == NULL){
        printf("\n vazia");
    }
    else{
        tipoLista listaAux = lista;
        lista = lista->proximo;
        free(listaAux);
        listaAux = NULL;
    }
    //?
    return lista;
    
}

tipoLista removerDireita(tipoLista lista){
    if (lista == NULL){
        printf("\n vazia");
    }
    else{
        if (lista->proximo == NULL){
            free(lista);
            lista = NULL;
        }
        
        else{
            tipoLista listaAux;
            listaAux = lista;

            while (listaAux->proximo->proximo != NULL){
                listaAux = listaAux->proximo;
            }
            tipoLista nohDescartar;
            nohDescartar = listaAux->proximo;
//?
            free(nohDescartar);
            nohDescartar = NULL;

            listaAux->proximo = NULL;
            
        }    
     
       
    }
    
    return lista;
    
}

void exibir(tipoLista lista){
    printf("\n----------Lista atual--------\n");
    if (lista == NULL){
        printf("\nVazia\n");
    }
    else{
        tipoLista listaAux = lista;
        while (listaAux != NULL){
            printf("[%d] ", listaAux->dado);
            listaAux = listaAux->proximo;
        }
        
    }
    printf("\n-----------------------------------\n");
    
}

void pesquisar(int valor, tipoLista lista){
    int contador = 0;
    tipoLista listaAux = lista;
    while (listaAux != NULL){
        if (listaAux->dado == valor){
            contador++;
        }
        listaAux = listaAux->proximo;
        
    }

    printf("\n %d ocorrencias do valor %d \n", contador, valor);
    
}
tipoLista excluirMeio(int valor, tipoLista lista){
    int contador = 0;
    tipoLista listaAux = lista;
    tipoLista listaAux2;
    
    while (listaAux->proximo->dado != valor){
        listaAux = listaAux->proximo;
    }
    listaAux2 = listaAux;

    printf("\n anterior %d ", listaAux2->dado);

    listaAux = listaAux->proximo;

    printf("\n proximo %d ", listaAux->dado);

    listaAux2->proximo = listaAux->proximo;
    free(listaAux);
    listaAux = NULL;


    return lista;
    
}


int main(){
    int op = 11;
    int valor = 0;
    tipoLista lista = NULL;


    while (op != 0){
        exibir(lista);
        printf("\n 1- inserir esquerda \n");
        printf("\n 2- inserir direita \n");
        printf("\n 3- remover esquerda \n");
        printf("\n 4- remover direita \n");
        printf("\n 5- exibir lista \n");
        printf("\n 6- pesquisar \n");
        printf("\n 7- excluir meio \n");
        printf("\n 0- sair \n");
        printf("Digite: ");
        scanf("%d", &op);
        switch (op){
        case 1:
            printf("Valor: \n");
            scanf("%d", &valor);
            lista = inserirEsquerda(valor, lista);
            break;
        case 2:
            printf("Valor: \n");
            scanf("%d", &valor);
            lista = inserirDireita(valor, lista);
            break;
        case 3:
            printf("Remover esquerda \n");
            lista = removerEsquerda(lista);
    
            break;
        case 4:
            printf("Remover direita \n");
            lista = removerDireita(lista);
    
            break;
        case 5:
            printf("Exibir \n");
            exibir(lista);
            break;
        case 6:
            printf("Pequisar: \n");
            scanf("%d", &valor);
            pesquisar(valor, lista);
            break;
        case 7:
            printf("Excluir no meio: \n");
            scanf("%d", &valor);
          lista =   excluirMeio(valor, lista);
            break;
        

        default:
            op = 0;
            printf("O programa ira encerrar \n");
            break;
        }
    }
    





    return 0;
}
