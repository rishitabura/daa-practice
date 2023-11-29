/* 
Time - O(n^2)
Space - O(n)    
*/

#include<stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *next;
}*head = NULL;

void create(int n)
{
    head = (struct node *)malloc(sizeof(struct node));
    struct node *temp, *new;

    int a;

    head->data = 1;
    head->next = NULL;

    temp = head;

    for (int i = 2; i <= n; i++)
    {
        new = (struct node *)malloc(sizeof(struct node));
        new->data = i;
        temp->next = new;
        new->next = head;
        temp = temp->next;
    }
}


int josephusList( int k)
{
    create(7);
    struct node *p, *q;
    p = q = head;
    while (p->next!= p)
    {   
        for (int i = 0; i < k-1; i++)
        {
            q=p;
            p = p->next;
        }
        q->next = p->next;
        printf("Killed : %d\n",p->data);
        free(p);
        p = q->next;
    }

    head = p;
    return (head->data);
    
}

int main()
{
    int ans = josephusList(3);
    printf("%d",ans);
    return 0;
}