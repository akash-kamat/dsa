#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List elements: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    return head;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    return head;
}

Node* deleteFromBeginning(Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
    } else {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

Node* deleteFromEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
    } else {
        Node* temp = head;
        Node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL)
            head = NULL;
        else
            prev->next = NULL;
        free(temp);
    }
    return head;
}

Node* deleteElement(Node* head, int data) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
    } else {
        Node* temp = head;
        Node* prev = NULL;
        while (temp != NULL && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Element not found in the list.\n");
        } else {
            if (prev == NULL)
                head = head->next;
            else
                prev->next = temp->next;
            free(temp);
        }
    }
    return head;
}


int main() {
    Node* head = NULL;
    int choice, data;
    clrscr();

    do {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from end\n");
        printf("5. Delete a given element\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter element to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                head = deleteFromBeginning(head);
                break;
            case 4:
                head = deleteFromEnd(head);
                break;
            case 5:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                head = deleteElement(head, data);
                break;
            case 6:
                display(head);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                        printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 7);
    getch();
    return 0;
}
