#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int subsequence(char *str1, char *str2, char *str3, int len1, int len2, int len3) {
    int L[len1+1][len2+1][len3+1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            for (int k = 0; k <= len3; k++) {
                if (i == 0 || j == 0 || k == 0) {
                    L[i][j][k] = 0;
                } else if (str1[i-1] == str2[j-1] && str2[j-1] == str3[k-1]) {
                    L[i][j][k] = L[i-1][j-1][k-1] + 1;
                } else {
                    L[i][j][k] = max(max(L[i-1][j][k], L[i][j-1][k]), L[i][j][k-1]);
                }
            }
        }
    }
    return L[len1][len2][len3];
}

void main() {
    char str1[] = "abcd1e2";
    char str2[] = "bc12ea";
    char str3[] = "bd1ea";
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len3 = strlen(str3);

    printf("%d", subsequence(str1, str2, str3, len1, len2, len3));
}