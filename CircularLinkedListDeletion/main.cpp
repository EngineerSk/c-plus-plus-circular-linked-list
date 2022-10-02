#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
} *head = nullptr;

struct Node *create(const int *A, int n) {
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
    last = temp = nullptr;
    free(last);
    free(temp);
    return head;
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
    p = first = nullptr;
    free(p);
    free(first);
    return counter;
}

void display(struct Node *p) {
    if (p == nullptr)
        return;
    struct Node *first = p;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != first);
    p = first = nullptr;
    free(p);
    free(first);
}

void insert(struct Node *p, int index, int x) {
    if (index < 0 || index > count(p))
        return;
    struct Node *first = p, *temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = x;
    if (index == 0) {
        if (p == nullptr) {
            temp->next = temp;
            head = temp;
        } else {
            temp->next = first;
            while (p->next != first)
                p = p->next;
            p->next = temp;
            first = temp;
            head = first;
        }
    } else {
        for (int i = 0; i < index - 1; ++i)
            p = p->next;
        temp->next = p->next;
        p->next = temp;
    }
    first = temp = p = nullptr;
    free(first);
    free(temp);
    free(p);
}

int deleteNode(struct Node *p, int index) {
    if (index < 1 || index > count(p))
        return -1;
    int x;
    struct Node *first = p, *q = p;
    if (index == 1) {
        if (p == nullptr)
            x = -1;
        else {
            x = q->data;
            if (q->next != first) {
                while (p->next != first)
                    p = p->next;
                head = first = q->next;
                p->next = first;
            }
            q->next = nullptr;
            free(q);
        }
    } else {
        head = p;
        for (int i = 0; i < index - 1; ++i) {
            p = q;
            q = q->next;
        }
        p->next = q->next;
        x = q->data;
        q->next = nullptr;
        free(q);
    }
    first = p = nullptr;
    free(first);
    free(p);
    return x;
}

int main() {
    int A[] = {2, 3, 4, 5, 7, 11, 15, 16, 18, 20, 21, 24, 27};
    head = create(A, sizeof(A) / sizeof(int));
    display(head);
    cout << endl;
    insert(head, 13, 9);
    cout << deleteNode(head, 1) << endl;
    cout << deleteNode(head, 8) << endl;
    cout << deleteNode(head, 5) << endl;
    cout << deleteNode(head, 10) << endl;
    display(head);
    return 0;
}
