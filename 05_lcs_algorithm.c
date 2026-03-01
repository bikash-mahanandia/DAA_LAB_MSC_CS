// Program to Find the Longest Common Subsequence (LCS) using Dynamic Programming.

#include <stdio.h>
#include <string.h>

int max(int a, int b);
void lcs(char *x, char *y, int xlen, int ylen);
int max(int a, int b){
    return (a > b) ? a : b;
}
void lcs(char *x, char *y, int xlen, int ylen){
    int x1 = xlen;
    int y1 = ylen;
    int l[30][30];
    int r, c, i;

    for(r = 0; r <= x1; r++){
        for(c = 0; c <= y1; c++){
            if(r == 0 || c == 0){
                l[r][c] = 0;
            }else{
                if(x[r - 1] == y[c - 1]){
                    l[r][c] = l[r - 1][c - 1] + 1;
                }else{
                    l[r][c] = max(l[r - 1][c], l[r][c - 1]);
                }
            }
        }
    }

    r = x1;
    c = y1;
    i = l[r][c];
    char ch[20];
    ch[i + 1] = '\0';

    while(r > 0 && c > 0){
        if(x[r - 1] == y[c - 1]){
            ch[i - 1] = x[r - 1];
            i--;
            r--;
            c--;
        }else{
            if(l[r - 1][c] > l[r][c - 1]){
                r--;
            }else{
                c--;
            }
        }
    }

    printf("\n length of LCS : %d", l[xlen][ylen]);
    printf("\n LCS : %s", ch);
}

void main(){

    char x[30], y[30];
    int xlen;
    int ylen;

    printf("Enter first sequence: ");
    scanf("%s", x);

    printf("Enter second sequence: ");
    scanf("%s", y);

    xlen = strlen(x);
    ylen = strlen(y);

    lcs(x, y, xlen, ylen);
}