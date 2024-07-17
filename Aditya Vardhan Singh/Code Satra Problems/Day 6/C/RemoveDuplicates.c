/*** Custom linked list header file ***/
#include "./List.h"

/*** Procedure to remove duplicate elements form a list ***/
void unique(List ** head) {
    // only a single element or none
    // in that case, list already has unique element
    if (!*head || !(*head)->next) return;

    List *ptr = *head;
    List *temp;
    while (ptr->next) {
        if (ptr->data == ptr->next->data) { 
            // duplicates found at ptr and ptr->next
            temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp);
        } else {
            ptr = ptr->next;
        }
    }
}

/*** Driver code ***/
int main(int argc, const char **argv) {
    // Check file arguments
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open file and scan list
    FILE *fin = fopen(argv[1], "r");
    List* head = NULL;
    int data, n;
    fscanf(fin, "%d", &n);
    while (n--) {
        fscanf(fin, "%d", &data);
        push_back(&head, data);
    }
    // File operations end

    // Show list
    printf("Original list:\n");
    print_list(&head);

    // Remove duplicates from list
    unique(&head);

    // Show list
    printf("List after removing duplicates:\n");
    print_list(&head);

    // Close and exit drive code
    fclose(fin);
    return EXIT_SUCCESS;
}