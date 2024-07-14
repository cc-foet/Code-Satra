#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char character;
    int frequency;
} CharFreq;

int cmp(const void *a, const void *b) {
    CharFreq *cf1 = (CharFreq *)a;
    CharFreq *cf2 = (CharFreq *)b;
    return cf2->frequency - cf1->frequency;
}

char *rearrange(char *s) {
    int len = strlen(s);
    int freq[256] = {0};

    for (int i = 0; i < len; i++) {
        freq[(int)s[i]]++;
    }

    CharFreq *charFreqs = (CharFreq *)malloc(sizeof(CharFreq) * 256);
    int n = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            charFreqs[n].character = (char)i;
            charFreqs[n].frequency = freq[i];
            n++;
        }
    }
    qsort(charFreqs, n, sizeof(CharFreq), cmp);

    char *result = (char *)malloc(len + 1);
    result[len] = '\0';
    int index = 0;

    for (int i = 0; i < n; i++) {
        int freq = charFreqs[i].frequency;
        char ch = charFreqs[i].character;
        for (int j = 0; j < freq; j++) {
            if (index >= len) {
                free(result);
                free(charFreqs);
                return "";
            }
            result[index] = ch;
            index += 2;
            if (index >= len) {
                index = 1;
            }
        }
    }
    free(charFreqs);
    return result;
}

void main() {
    char s[] = "caaabbbaacdddd";

    char *result = rearrange(s);
    printf("%s\n", result);
}