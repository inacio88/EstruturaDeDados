#include <stdio.h>
#include <stdlib.h>

typedef struct noh{
    int dado;
    struct noh *proximo;
    struct noh *anterior;
}*tipoLista;

tipoLista criarNoh(int valor){
    tipoLista novoNoh = (tipoLista) malloc(sizeof(tipoLista));
    if (novoNoh == NULL){
        printf("\n erro para criar noh\n");
        return NULL;
    }
    else{
        novoNoh->dado = valor;
        novoNoh->proximo = NULL;
        novoNoh->anterior = NULL;
        return novoNoh;
    }
    
}

tipoLista inserirEsquerda(int valor, tipoLista lista){
    tipoLista novoNoh = criarNoh(valor);
    if (lista == NULL){
        return novoNoh;
    }
    else{
        lista->anterior = novoNoh;
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
        novoNoh->anterior = listaAux;
        listaAux->proximo = novoNoh;
   //?     
        return lista;
    }
}

void exibir(tipoLista lista){
    int contador=0;
    printf("\n----------Lista atual--------\n");
    if (lista == NULL){
        printf("\nVazia\n");
    }
    else{
        tipoLista listaAux = lista;
        tipoLista listaAux2 = NULL;
        while (listaAux != NULL){
            printf("[%d] ", listaAux->dado);
            listaAux = listaAux->proximo;
            contador++;
        }
        if (contador > 2){
            //printf("%d ultimo:  \n", listaAux->dado);
            listaAux2 = listaAux;
            listaAux2 = listaAux2->anterior;
            printf("%d penultimo \n", listaAux2->dado);
        }
        
        
        
    }
    printf("\n-----------------------------------\n");
    
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
            //lista = removerEsquerda(lista);
    
            break;
        case 4:
            printf("Remover direita \n");
            //lista = removerDireita(lista);
    
            break;
        case 5:
            printf("Exibir \n");
            exibir(lista);
            break;
        case 6:
            printf("Pequisar: \n");
            scanf("%d", &valor);
           // pesquisar(valor, lista);
            break;
        case 7:
            printf("Excluir no meio: \n");
            scanf("%d", &valor);
          //lista =   excluirMeio(valor, lista);
            break;
        

        default:
            op = 0;
            printf("O programa ira encerrar \n");
            break;
        }
    }
    


    
    return 0;
}
