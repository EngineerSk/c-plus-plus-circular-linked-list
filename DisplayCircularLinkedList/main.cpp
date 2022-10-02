#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
} *head = nullptr;

struct Node *create(const int *A, int n) {
    if (A == nullptr || n == 0)
        return nullptr;
    auto *temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = A[0];
    temp->next = temp;
    head = temp;
    struct Node *last = temp;
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

void recursiveDisplay(struct Node *p, struct Node *first) {
    if (p == nullptr)
        return;
    static int flag = 0;
    if (flag < 6 || p != first) {
        if (p == first) {
            if (flag++ == 0)
                printf("\n");
        }
        printf("%d ", p->data);
        if (p->next == first)
            printf("\n");
        recursiveDisplay(p->next, first);
    }
    first = p = nullptr;
    free(first);
    free(p);
}

int main() {
    int A[] = {2, 3, 4, 6, 12, 15, 17, 25};
    create(A, sizeof(A) / sizeof(int));
    display(head);
    printf("\n");
    recursiveDisplay(head, head);
    return 0;
}
