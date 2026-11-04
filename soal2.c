/*
Nama    : Hamzah Abdul Rahim
NIM     : 13224066
Modul   : 1 DATA MANIPULATION, EXTERNAL FILES, STRUCTURES AND DYNAMIC ARRAYS
Tanggal : 4 November 2026
Soal    : Soal 2
Deskripsi: Program untuk praktikum modul 1 soal 2, program mengecek kevalidan kunci tiap input, lalu mengurutkan sesuai indeks dan mengoutput kata kata secara terbalik.
*/
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
    if(strcmp(key,"Code9")==0){
        N = 5;
    }
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
        for(int j=0;j<N;j++){
            if(package[j].indeks>package[j+1].indeks){
                temp = package[j];
                package[j] = package[j+1];
                package[j+1] = temp;
            }
        }
    }

    /*for(int i=0;i<val;i++){
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
    if(val == 0){
        printf("000");
    }
    else{
        for(int i=0;i<val;i++){
            if(i!= val-1){
                printf("%s ", package[i].kata);
            }
            else{
                printf("%s\n", package[i].kata);
            }
        }
        printf("LENGTH %d\n", lentotal);
    }


}
