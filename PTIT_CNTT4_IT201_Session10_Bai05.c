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

Node* deleteByValue(Node* head, int value) {
    while (head && head->data == value) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data == value) {
            Node* temp = curr->next;
            curr->next = temp->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }
    return head;
}

int main() {
    Node* head = createNode(5);
    head->next = createNode(4);
    head->next->next = createNode(3);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(2);
    head->next->next->next->next->next = createNode(1);
    head->next->next->next->next->next->next = createNode(5);

    printList(head);

    int x;
    scanf("%d", &x);

    head = deleteByValue(head, x);

    printList(head);

    return 0;
}
