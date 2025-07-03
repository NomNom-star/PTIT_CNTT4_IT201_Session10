#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

void printList(Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf("->");
        head = head->next;
    }
    printf("->NULL\n");
}

Node* deleteLast(Node* head) {
    if (!head) return NULL;
    if (!head->next) {
        free(head);
        return NULL;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    return head;
}

int main() {
    Node* head = createNode(5);
    head->next = createNode(4);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);

    printList(head);

    head = deleteLast(head);

    printList(head);

    return 0;
}
