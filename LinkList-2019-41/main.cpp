//
// Created by SSS on 2023/2/16.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    LNode *next;
} LNode;

void insertLinkList(LNode *&L, int pInt[], int len);

void traverseLinkList(LNode *L);

LNode *getMiddleAndReturnLinkList(LNode *&L);

void revertLinkList(LNode *&L);

void merge(LNode *&L, LNode *&R);

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    LNode *L;
    insertLinkList(L, arr, 5);
    traverseLinkList(L);
    printf("-----------------------\n");
    // 获取链表中间数,以及返回后半段链表
    LNode *R = getMiddleAndReturnLinkList(L);
    traverseLinkList(L);
    traverseLinkList(R);
    printf("-----------------------\n");
    // 逆转后半截
    revertLinkList(R);
    traverseLinkList(R);
    // 合并链表
    merge(L, R);
    traverseLinkList(L);

    return 0;
}

void merge(LNode *&L, LNode *&R) {
    LNode *r = L->next;//pcur
    LNode *s = L->next;//p
    LNode *t = R->next;//q
    s = s->next;
    while (t != nullptr && s != nullptr) {
        r->next = t;
        t = t->next;
        r = r->next;
        r->next = s;
        s = s->next;
        r = r->next;
    }
    if (t != nullptr) {
        r->next = t;
    }
    if (s != nullptr) {
        r->next = s;
    }
}

void revertLinkList(LNode *&L) {
    LNode *p1 = L->next;
    if (!p1) {
        return;
    }
    LNode *p2 = p1->next;
    if (!p2) {
        return;
    }
    LNode *p3 = L->next->next->next;
    while (p3 != nullptr) {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }
    p2->next = p1;
    L->next->next = nullptr;
    L->next = p2;
}

LNode *getMiddleAndReturnLinkList(LNode *&L) {
    LNode *R = (LNode *) malloc(sizeof(LNode));
    LNode *p1 = L->next;
    LNode *p2 = L->next;
    while (p2 != nullptr) {
        p2 = p2->next;
        if (p2 == nullptr) {
            break;
        }
        p2 = p2->next;
        if (p2 == nullptr) {
            break;
        }
        p1 = p1->next;
    }
    R->next = p1->next;
    p1->next = nullptr;
    return R;
}

void traverseLinkList(LNode *L) {
    int count = 0;
    while (L->next) {
        count++;
        L = L->next;
        printf("%d\t", L->data);
        if (count % 5 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void insertLinkList(LNode *&L, int pInt[6], int len) {
    L = (LNode *) malloc(sizeof(LNode));
    L->next = NULL;
    LNode *p;
    LNode *r;
    r = L;
    for (int i = 0; i < len; ++i) {
        p = (LNode *) malloc(sizeof(LNode));
        p->data = pInt[i];
        r->next = p;
        r = r->next;
    }
    r->next = NULL;
}
