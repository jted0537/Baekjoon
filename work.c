#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char bin_file[50];
    int s, f, p;
    int m, n;
    int word[1];
    char buf[1];
    char X[100], Y[100];
    int tmp;
    FILE *fp_r = fopen("input.txt", "r");
    FILE *fp_w = fopen("output.txt", "w");
    if(fp_r == NULL) {
        printf("Input file open error!\n");
        return 0;
    }
    tmp = fscanf(fp_r, "%s", bin_file);
    tmp = fscanf(fp_r, "%d %d %d", &s, &f, &p);
    bin_file[strlen(bin_file)] = '\0';
    /*
    FILE* read_bin = fopen(bin_file, "rb");
    if(read_bin == NULL){
        printf("Binary file open error!\n");
        return 0;
    }
    fread(word, sizeof(word), 1, read_bin);
    m = word[0];
    fread(word, sizeof(word), 1, read_bin);
    n = word[0];
    for(int i = 0; i < m; i++){
        fread(buf, sizeof(buf), 1, read_bin);
        X[i] = buf[0];
    }
    for(int i = 0; i < n; i++){
        fread(buf, sizeof(buf), 1, read_bin);
        Y[i] = buf[0];
    }
    */
    //fclose(read_bin);
    printf("%d %d %d\n",s,f,p);
    fclose(fp_r);
    fclose(fp_w);
}