#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  unsigned int val;
  struct ListNode *next;
};

void listAppend(struct ListNode **pList, unsigned int value) {
  struct ListNode *pNode =
      (struct ListNode *)calloc(1, sizeof(struct ListNode));
  pNode->val = value;
  pNode->next = NULL;

  if (NULL == *pList) {
    *pList = pNode;
    return;
  } else {
    struct ListNode *pListCurrent = *pList;
    while (NULL != pListCurrent->next) {
      pListCurrent = pListCurrent->next;
    }

    pListCurrent->next = pNode;
    return;
  }
}

void listFree(struct ListNode *pList) {
  struct ListNode *pCurrent = pList;
  struct ListNode *pTemp = NULL;
  while (NULL != pCurrent) {
    pTemp = pCurrent;
    printf("free value: %d\n", pTemp->val);
    pCurrent = pCurrent->next;
    free(pTemp);
  }
  return;
}

unsigned int getDecNum(struct ListNode *list) {
  unsigned int num = 0;
  unsigned int order = 1;
  struct ListNode *currentList = list;

  while (NULL != currentList) {
    num += order * currentList->val;
    order *= 10;
    currentList = currentList->next;
  }

  return num;
}

struct ListNode *setDecNum(unsigned int num) {
  unsigned int digit = num % 10;
  struct ListNode *pNodeInit =
      (struct ListNode *)calloc(1, sizeof(struct ListNode));
  pNodeInit->val = digit;
  pNodeInit->next = NULL;
  num /= 10;

  struct ListNode *pNodeCurrent = pNodeInit;

  while (0 < num) {
    digit = num % 10;
    struct ListNode *pNode =
        (struct ListNode *)calloc(1, sizeof(struct ListNode));

    pNode->val = digit;
    pNode->next = NULL;

    pNodeCurrent->next = pNode;
    pNodeCurrent = pNode;
    num /= 10;
  }

  return pNodeInit;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  // unsigned int num1 = getDecNum(l1);
  // unsigned int num2 = getDecNum(l2);
  // unsigned int numSum = num1 + num2;
  // return setDecNum(numSum);
  struct ListNode *lSum = NULL;
  struct ListNode *l1Current = l1;
  struct ListNode *l2Current = l2;
  unsigned int carryDigit = 0;
  
  while(NULL != l1Current || NULL != l2Current || 0 != carryDigit )
  { 
    unsigned int num1, num2 = 0;
    if (NULL != l1Current)
    {
      num1=l1Current->val;
      l1Current = l1Current->next;
    }
    else
    {
      num1=0;
    }

    if (NULL != l2Current)
    {
      num2=l2Current->val;
      l2Current = l2Current->next;
    }
    else
    {
      num2=0;
    }

    unsigned int sumTemp = num1 + num2 + carryDigit;
    if (9<sumTemp)
    {
      listAppend(&lSum, sumTemp%10);
      carryDigit = 1;
    }
    else
    {
      listAppend(&lSum, sumTemp);
      carryDigit = 0;
    }
  }
  return lSum;
}

int main(int argc, char *argv[]) {
  struct ListNode *l1 = NULL;
  struct ListNode *l2 = NULL;
  printf("%d,%d,%d\n",__INT32_MAX__,sizeof(unsigned int),sizeof(unsigned long));
  // unsigned int numArray1[] = {3,4,2};
  // unsigned int length1 = 3;
  // unsigned int numArray2[] = {4,6,5};
  // unsigned int length2 = 3;
  unsigned int numArray1[] = {9};
  unsigned int length1 = 1;
  unsigned int numArray2[] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 1};
  unsigned int length2 = 10;

  for (unsigned int i = 0; i < length1; i++) {
    listAppend(&l1, numArray1[length1 - 1 - i]);
  }

  for (unsigned int i = 0; i < length2; i++) {
    listAppend(&l2, numArray2[length2 - 1 - i]);
  }
  
  struct ListNode *pSum = addTwoNumbers(l1,l2);
  // unsigned int numSum = getDecNum(pSum);
  // printf("num List Sum = %lf\n", 1.0*numSum);
  listFree(l1);
  listFree(l2);
  listFree(pSum);
  getchar();
}
