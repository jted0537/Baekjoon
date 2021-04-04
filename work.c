#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Return max value of three integer values*/
int three_max(int a, int b, int c) {
	if (a >= b && a >= c) return a;
	else if (b > a&& b >= c) return b;
	else return c;
}

int func(char *X, char *Y, int m, int n, int match, int mis, int gap){
    FILE *fp_w = fopen("output.txt", "w");
    int max_value = -1000000000;
    int *x_gap, x_gap_idx = 0;
    int *y_gap, y_gap_idx = 0;
    x_gap = (int *)malloc(sizeof(int)*(m+n));
    y_gap = (int *)malloc(sizeof(int)*(m+n));
    int **ans = (int **)malloc(sizeof(int *) * (m+1));
    for(int i = 0; i < m + 1; i++) ans[i] = (int *)malloc(sizeof(int) * (n+1));
    for(int i = 0; i<m+1; i++){
        for(int j = 0; j<n+1; j++){
            if(i == 0) ans[i][j] = gap * j;
            else if(j == 0) ans[i][j] = gap * i;
            else{
                int first = ans[i-1][j-1];
                if(X[i] == Y[j]) first += match;
                else first += mis;
                int second = ans[i-1][j] + gap;
                int third = ans[i][j-1] +gap;
                int t_max = three_max(first, second, third);
                if(t_max > max_value) max_value = t_max;
                if(t_max == second) x_gap[x_gap_idx++] = i;
                else if(t_max == third) y_gap[y_gap_idx++] = j;
            }
        }
    }
    fprintf(fp_w, "%d\n%d\n%d\n", max_value, m + x_gap_idx, x_gap_idx);
    for(int i = 0; i < x_gap_idx; i++) fprintf(fp_w, "%d\n", x_gap[i]);
    fprintf(fp_w, "%d\n", y_gap_idx);
    for(int i = 0; i < y_gap_idx; i++) fprintf(fp_w, "%d\n", y_gap[i]);
}

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
