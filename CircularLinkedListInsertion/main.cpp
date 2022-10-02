#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
} *head = nullptr;

struct Node *create(const int *A, const int n) {
    if (A == nullptr || n == 0)
        return nullptr;
    struct Node *temp = (struct Node *) malloc(sizeof(struct Node)), *last;
    temp->data = A[0];
    temp->next = temp;
    last = head = temp;
    for (int i = 1; i < n; ++i) {
        temp = (struct Node *) malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
    temp = last = nullptr;
    free(temp);
    free(last);
    return head;
}

void display(struct Node *p) {
    if (p == nullptr)
        return;
    struct Node *first = p;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != first);
    first = p = nullptr;
    free(first);
    free(p);
}

int count(struct Node *p) {
    if (p == nullptr)
        return 0;
    int counter = 0;
    struct Node *first = p;
    do {
        ++counter;
        p = p->next;
    } while (p != first);
    first = p = nullptr;
    free(first);
    free(p);
    return counter;
}

void insert(struct Node *p, const int index, const int x) {
    if (index < 0 || index > count(p))
        return;
    struct Node *first = p, *temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = x;
    if (index == 0) {
        if (p == nullptr) {
            temp->next = temp;
            p = temp;
            head = p;
            return;
        } else {
            temp->next = first;
            while (p->next != first) {
                p = p->next;
            }
            p->next = temp;
            first = temp;
            head = first;
        }
    } else {
        for (int i = 0; i < index - 1; ++i) {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
    first = temp = p = nullptr;
    free(first);
    free(p);
    free(temp);
}

int main() {
    int A[] = {};
    head = create(A, sizeof(A) / sizeof(int));
    insert(head, 1, 5);
    insert(head, 1, 15);
    insert(head, 0, 8);
    display(head);
    return 0;
}
