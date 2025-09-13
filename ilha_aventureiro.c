#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

int main(){
    Item mochila[10];
    int qtd=0, opcao;

    do{
        printf("\n--- Mochila Free Fire - Nivel Aventureiro ---\n");
        printf("1 - Adicionar\n2 - Remover\n3 - Listar\n4 - Buscar\n0 - Sair\n");
        scanf("%d",&opcao);
        getchar();

        if(opcao==1){
            if(qtd<10){
                printf("Nome: ");
                fgets(mochila[qtd].nome,30,stdin);
                mochila[qtd].nome[strcspn(mochila[qtd].nome,"\n")] = 0;
                printf("Tipo: ");
                fgets(mochila[qtd].tipo,20,stdin);
                mochila[qtd].tipo[strcspn(mochila[qtd].tipo,"\n")] = 0;
                printf("Qtd: ");
                scanf("%d",&mochila[qtd].quantidade);
                getchar();
                qtd++;
            } else printf("Mochila cheia\n");
        }
        else if(opcao==2){
            char nomeRem[30];
            printf("Nome pra remover: ");
            fgets(nomeRem,30,stdin);
            nomeRem[strcspn(nomeRem,"\n")]=0;
            int f=0;
            for(int i=0;i<qtd;i++){
                if(strcmp(mochila[i].nome,nomeRem)==0){
                    for(int j=i;j<qtd-1;j++) mochila[j]=mochila[j+1];
                    qtd--; f=1; printf("Removido!\n"); break;
                }
            }
            if(!f) printf("Nao achei\n");
        }
        else if(opcao==3){
            for(int i=0;i<qtd;i++){
                printf("%s - %s - %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            }
        }
        else if(opcao==4){
            char busca[30];
            printf("Nome pra buscar: ");
            fgets(busca,30,stdin);
            busca[strcspn(busca,"\n")]=0;
            int f=0;
            for(int i=0;i<qtd;i++){
                if(strcmp(mochila[i].nome,busca)==0){
                    printf("Item encontrado: %s - %s - %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
                    f=1; break;
                }
            }
            if(!f) printf("Nao existe esse item\n");
        }
    }while(opcao!=0);

    return 0;
}
