// Input:  -3  <--- Top
//         14 
//         18 
//         -5 
//         30 

// Output: 30  <--- Top
//         18 
//         14 
//         -3 
//         -5 

#include<iostream>
using namespace std;

struct stack {
    int data;
    struct stack *next;
};
//utility function to initialize the stack
void initStack(struct stack** s) {*s = NULL}

//utility function to check if stack is empty
int isEmpty(struct stack *s) {
    if(s == NULL)
        return 1;
    return 0;
}

void push(struct stack** s, int x) {
    struct stack *p = (struct stack*)malloc(sizeof(*p));

    if(p == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    p->data = x;
    p->next = *s;
    *s = p;
}

void sortStack(struct stack **s) {
    if(!isEmpty(*s)) {
        //remove the top item
        int x = pop(s);
        //sort the remaining stack
        sortStack(s);
    }
}

void printStack(struct stack *s) {
    while(s) {
        cout<<s->data<<" ";
        s = s->next;
    }
    cout<<"\n";
}

int main()
{
    struct stack *top;

    initStack(&top);
    push(&top, 30);
    push(&top, -5);
    push(&top, 18);
    push(&top, 14);
    push(&top, -3);
    
    cout<<"Stack elements before sorting :\n";
    printStack(top);

    sortStack(&top);
    cout<<"\n";

    cout<<"Stack elements after sorting:\n";
    printStack(top);

    return 0;
}