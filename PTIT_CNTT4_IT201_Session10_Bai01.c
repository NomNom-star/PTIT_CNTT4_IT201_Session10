#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    Node* head = createNode(11);
    head->next = createNode(22);
    head->next->next = createNode(33);
    head->next->next->next = createNode(44);
    head->next->next->next->next = createNode(55);

    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    return 0;
}
