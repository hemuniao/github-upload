#include <stdio.h>
#include <stdlib.h>

struct Node {
    char *data;
    struct Node *next;
};

void swap(char **s1, char **s2)
{
    char *t = *s1;
    *s1 = *s2;
    *s2 = t;
}

int measure(const char *s)
{
    int ret = 0;
    for (int i = 0; s[i] != 0; i++) {
        for (int j = i; s[j] != 0; j++) {
            if (s[i] > s[j]) {
                ret++;
            }
        }
    }
    return ret;
}

// bubble sorting based on linked list
void bubbleSort(struct Node *head)
{
    struct Node *p = NULL;
    struct Node *q = NULL;
    struct Node *t = NULL;
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    for (p = head; p != NULL; p = p->next)
    {
        for (q = head; q->next != NULL; q = q->next)
        {
            // to be updated
            // if (q->data > q->next->data)
            if (measure(q->data) > measure(q->next->data))
            {
                // to be updated
                swap(&q->data, &q->next->data);
            }
        }
    }
}

// 10
// 6
// AACATGAAGG
// TTTTGGCCAA
// GATCAGATTT
// CCCGGGGGGA
// ATCGATGCAT
// TTTGGCCAAA
int main()
{
    struct Node *head = NULL;
    int len, num;

    scanf("%d %d", &len, &num);

    for (int i = 0; i < num; i++) {
        struct Node *p = (struct Node*)malloc(sizeof(struct Node));
        p->data = (char*)malloc(len + 1);
        p->next = NULL;

        scanf("%s", p->data);

        if (head) {
            struct Node *last = head;
            while (last->next) {
                last = last->next;
            }
            last->next = p;
        } else {
            head = p;
        }
    }

    bubbleSort(head);

    for (struct Node *p = head; p != NULL; p = p->next) {
        printf("%s\n", p->data);
    }
    return 0;
}
