#include <iostream>
#include <list>

using namespace std;

void show_list(list<int>& ll) {
    for (auto itr = ll.begin(); itr != ll.end(); ++itr) {
        cout << *itr << " -> ";
    }
    cout << "NULL" << endl;
}

int main() {
    list<int> ll = {1, 2, 2, 4, 4, 4, 5};

    // Show original list
    cout << "Original list:\n";
    show_list(ll);

    // Remove duplicate elements form list
    ll.unique();

    // Show duplicates removed list
    cout << "List after removing duplicates:\n";
    show_list(ll);

    return EXIT_SUCCESS;
}