#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
    int prioridade; // 1 a 5
} Item;

void ordenarNome(Item v[], int n){
    for(int i=1;i<n;i++){
        Item temp = v[i];
        int j=i-1;
        while(j>=0 && strcmp(v[j].nome,temp.nome)>0){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=temp;
    }
}

int buscaBinaria(Item v[], int n, char* alvo){
    int ini=0,fim=n-1;
    while(ini<=fim){
        int meio=(ini+fim)/2;
        int cmp=strcmp(v[meio].nome,alvo);
        if(cmp==0) return meio;
        else if(cmp<0) ini=meio+1;
        else fim=meio-1;
    }
    return -1;
}

int main(){
    Item mochila[10];
    int qtd=0, opcao;

    do{
        printf("\n--- Mochila Free Fire - Nivel Mestre ---\n");
        printf("1-Adicionar 2-Ordenar por nome 3-Busca binaria por nome 4-Listar 0-Sair\n");
        scanf("%d",&opcao);
        getchar();

        if(opcao==1){
            if(qtd<10){
                printf("Nome: "); fgets(mochila[qtd].nome,30,stdin);
                mochila[qtd].nome[strcspn(mochila[qtd].nome,"\n")]=0;
                printf("Tipo: "); fgets(mochila[qtd].tipo,20,stdin);
                mochila[qtd].tipo[strcspn(mochila[qtd].tipo,"\n")]=0;
                printf("Qtd: "); scanf("%d",&mochila[qtd].quantidade); getchar();
                printf("Prioridade (1-5): "); scanf("%d",&mochila[qtd].prioridade); getchar();
                qtd++;
            } else printf("Cheio\n");
        }
        else if(opcao==2){
            ordenarNome(mochila,qtd);
            printf("Mochila ordenada por nome.\n");
        }
        else if(opcao==3){
            char busca[30];
            printf("Digite nome: ");
            fgets(busca,30,stdin);
            busca[strcspn(busca,"\n")]=0;
            int pos=buscaBinaria(mochila,qtd,busca);
            if(pos>=0){
                printf("Achei: %s - %s - %d - prioridade %d\n", mochila[pos].nome, mochila[pos].tipo, mochila[pos].quantidade, mochila[pos].prioridade);
            } else printf("Nao achei\n");
        }
        else if(opcao==4){
            for(int i=0;i<qtd;i++){
                printf("%s - %s - %d - prioridade %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade, mochila[i].prioridade);
            }
        }
    }while(opcao!=0);

    return 0;
}
