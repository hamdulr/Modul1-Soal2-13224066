#include <stdio.h>
#include <string.h>

typedef struct{
    int indeks;
    char kode[25];
    char kata[50];
}paket;


int main(){
    int N;
    char key[25];
    scanf("%d %s", &N, key);
    paket package[N+1];
    for(int i=0;i<N+1;i++){
        package[i].indeks = 99999;
    }
    int ind;
    char kod[25];
    char word[50];
    int val = 0;
    for(int i = 0;i<N;i++){
        scanf("%d %s %s", &ind, kod, word);
        if(strcmp(kod, key)==0){
            val++;
            package[i].indeks = ind;
            strcpy(package[i].kode, kod);
            strcpy(package[i].kata, word);
        }
    }

    paket temp;
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            if(package[j].indeks>package[j+1].indeks){
                temp = package[j];
                package[j] = package[j+1];
                package[j+1] = temp;
            }
        }
    }

   /* for(int i=0;i<val;i++){
        printf("%d %s %s\n", package[i].indeks, package[i].kode, package[i].kata);
    }*/

    int lentotal = 0;
    for(int i=0;i<val;i++){
        char input[25];
        strcpy(input,package[i].kata);
        char out[25] = "";
        int len = strlen(input);
        lentotal += len;
        for(int i=0;i<len;i++){
            out[len-i-1] = input[i];
        }
        strcpy(package[i].kata,out);
    }

    for(int i=0;i<val;i++){
        printf("%s ", package[i].kata);
    }
    printf("\n");
    printf("LENGTH %d\n", lentotal);




}
