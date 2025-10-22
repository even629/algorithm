#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct LNode {
  ElemType data;
  struct LNode *next;
} LNode, *LinkList;

// 头插法建立单链表
LinkList LinkListInit_HeadInsert(void) {
  LinkList L;
  LNode *node;
  int x;

  L = (LNode *)malloc(sizeof(LNode));
  L->next = NULL;

  while (scanf("%d", &x) != EOF) {
    node = (LNode *)malloc(sizeof(LNode));
    node->data = x;
    node->next = L->next;
    L->next = node;
  }
  return L;
}
