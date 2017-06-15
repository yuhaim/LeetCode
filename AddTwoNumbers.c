#include    <stdio.h>
#include    <stdlib.h>
#include    <stddef.h>
#include    <stdbool.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

int getDecNum(struct ListNode *list)
{
    int num = 0;
    int order = 1;
    struct ListNode *currentList = list;
    
    while(true)
    {
        if(NULL == currentList)
        {
            break;
        }
        num += order*currentList->val;
        order *= 10;
        currentList = currentList->next;
    }

    return num;
}

struct ListNode *setDecNum(int num)
{
    return NULL;
}

struct ListNode *addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    return NULL; 
}

int main(int argc, char *argv[])
{
    struct ListNode node12;
    node12.val = 3;
    node12.next = NULL;

    struct ListNode node11;
    node11.val = 4;
    node11.next = &node12;

    struct ListNode node10;
    node10.val = 2;
    node10.next = &node11;

    struct ListNode node22;
    node22.val = 4;
    node22.next = NULL;

    struct ListNode node21;
    node21.val = 6;
    node21.next = &node22;

    struct ListNode node20;
    node20.val = 5;
    node20.next = &node21;

    printf("num 1 = %d\nnum 2 = %d\n", getDecNum(&node10), getDecNum(&node20));
    getchar();
    
}
