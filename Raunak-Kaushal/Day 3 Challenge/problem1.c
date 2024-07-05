/*
Problem : Implementing a circular queue using array
*/


#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define size 5

int qu[size];
int fr = -1;
int rr = -1;

void circular_enqueue(int);
int circular_dequeue();
void queue_display();

int main(){
    int ch, key;
    do{
        printf("\nChoose Operation\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
        case 1:
            printf("Enter key: ");
            scanf("%d", &key);
            circular_enqueue(key);
            break;
        case 2:
            circular_dequeue();
            break;
        case 3:
            queue_display();
            break;
        case 4:
            printf("Exiting\n");
            exit(0);
        default:
            printf("Invalid Choice!\n");
        }
    } while (ch != 4);
    return 0;
}

void circular_enqueue(int key){
    if((fr == 0 && rr == size - 1) || (fr == rr + 1)){
        printf("Overflow\n");
        return;
    }
    else if(fr == -1){
        fr = rr = 0;
    }
    else if(rr == size - 1){
        rr = 0;
    }
    else{
        rr = rr + 1;
    }
    qu[rr] = key;
}
int circular_dequeue(){
    if (fr == -1){
        printf("Underflow\n");
        return INT_MIN;
    }
    int temp = qu[fr];
    if (fr == rr){
        fr = rr = -1;
    }
    else if (fr == size - 1){
        fr = 0;
    }
    else{
        fr = fr + 1;
    }
    printf("Dequeued element: %d\n", temp);
    return temp;
}

void queue_display(){
    if (fr == -1){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    if(rr >= fr){
        for (int i = fr; i <= rr; i++)
            printf("%d ", qu[i]);
    }
    else{
        for (int i = fr; i < rr; i++)
            printf("%d ", qu[i]);
        for (int i = 0; i <= rr; i++)
            printf("%d ", qu[i]);
    }
    printf("\n");
}


/*
Output :
Choose Operation
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter key: 10

Choose Operation
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter key: 20

Choose Operation
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter key: 30

Choose Operation
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Queue elements: 10 20 30

Choose Operation
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
Dequeued element: 10

Choose Operation
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 4
Exiting

*/