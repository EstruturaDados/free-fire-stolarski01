#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

int main(){
    Item mochila[10];
    int qtd=0;
    int opcao;

    do{
        printf("\n--- Mochila Free Fire - Nivel Novato ---\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        getchar();

        if(opcao==1){
            if(qtd<10){
                printf("Nome: ");
                fgets(mochila[qtd].nome,30,stdin);
                mochila[qtd].nome[strcspn(mochila[qtd].nome,"\n")] = 0;
                printf("Tipo: ");
                fgets(mochila[qtd].tipo,20,stdin);
                mochila[qtd].tipo[strcspn(mochila[qtd].tipo,"\n")] = 0;
                printf("Quantidade: ");
                scanf("%d",&mochila[qtd].quantidade);
                getchar();
                qtd++;
            } else {
                printf("Mochila cheia!\n");
            }
        }
        else if(opcao==2){
            char nomeRem[30];
            printf("Digite nome do item para remover: ");
            fgets(nomeRem,30,stdin);
            nomeRem[strcspn(nomeRem,"\n")] = 0;
            int achou=0;
            for(int i=0;i<qtd;i++){
                if(strcmp(mochila[i].nome,nomeRem)==0){
                    for(int j=i;j<qtd-1;j++){
                        mochila[j]=mochila[j+1];
                    }
                    qtd--;
                    achou=1;
                    printf("Item removido!\n");
                    break;
                }
            }
            if(!achou) printf("Item nao encontrado.\n");
        }
        else if(opcao==3){
            printf("\nItens na mochila:\n");
            for(int i=0;i<qtd;i++){
                printf("%s - %s - %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            }
        }
    }while(opcao!=0);

    return 0;
}
