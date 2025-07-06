#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void printList(Node *head) {
    if (head==NULL) { return;}
    Node *current = head;
    int i=1;
    while (current != NULL) {
        printf("Node %d: %d\n", i,current->data);
        i++;
        current = current->next;
    }
}
int main(){
    Node *head = NULL;
    Node *tail = NULL;
    for (int i = 1; i <= 5; i++) {
        Node *node = createNode(i);
        if (head==NULL) {
            head = tail = node;
        }else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    printList(head);

    return 0;
}