#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for memory allocation

#define Node struct node

struct node{
    struct node* next;
    int data;
};

Node* deleteNodeAtIndex(Node* head, int index, char errorMsg[100]){
    int count = 0;
    Node* runner = head;
    if(index < 0){
        return head;
    }

    if(index == 0){
        Node* newHead = head -> next;
        free(head);
        return newHead;
    }
    
    Node* prev = NULL;
    while(count != index && runner != NULL){
        prev = runner;
        runner = runner -> next;
        count++;
    }

    if(runner == NULL) return head;
    // if(count-1 != index) return head;

    Node* nodeToBeDeleted = runner;
    prev -> next = runner -> next;
    runner -> next = NULL;
    free(runner);

    return head;
}

Node* deleteNode(Node* head, int d){
    if(head -> data == d){
        Node* newHead = head -> next;
        free(head);
        return newHead;
    }

    Node* runner = head;
    Node* prev = NULL;

    while(runner -> data != d && runner != NULL){
        prev = runner;
        runner = runner -> next;
    }

    Node* nodeToBeDeleted = runner;
    prev -> next = runner -> next;
    free(nodeToBeDeleted);

    return head;
}

struct node* createNode(int d){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = d;
    newNode->next = NULL;

    return newNode;
}

struct node* append(struct node* head, int data){
    if(head == NULL){
        return createNode(data);
    } else {
        head->next = append(head->next, data);
    }
    return head;
}

void display(struct node* head){
    struct node* current = head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(){
    struct node* head = NULL;

    head = append(head, 5);
    head = append(head, 10);
    head = append(head, 15);
    head = append(head, 20);
    head = deleteNode(head, 5);
    head = deleteNodeAtIndex(head);
    display(head);

    return 0;
}