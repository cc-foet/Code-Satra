#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 100

void autocomplete(char words[][MAX_WORD_LENGTH], int num_words, char *prefix, char results[][MAX_WORD_LENGTH], int *num_results) {
    *num_results = 0;
    int prefix_length = strlen(prefix);

    for (int i = 0; i < num_words; ++i) {
        if (strncmp(words[i], prefix, prefix_length) == 0) {
            strcpy(results[*num_results], words[i]);
            (*num_results)++;
        }
    }
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH] = {"cat", "car", "cart", "dog", "dove", "door"};
    int num_words = 6;
    char prefix[] = "car";
    char results[MAX_WORDS][MAX_WORD_LENGTH];
    int num_results;

    autocomplete(words, num_words, prefix, results, &num_results);

    printf("Words with prefix \"%s\":\n", prefix);
    for (int i = 0; i < num_results; ++i) {
        printf("%s\n", results[i]);
    }

    return 0;
}
