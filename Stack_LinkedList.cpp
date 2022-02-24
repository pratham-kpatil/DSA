#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;
}*top = NULL;

void push(int x){
    Node *t = new Node;
    if(t==NULL) cout<<"Stack Overflow";
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop(){
    Node *p;
    int x=-1;
    if(top==NULL) cout<<"Stack is Empty";
    else{
        p=top;
        x = top->data;
        top = top->next;
        delete(p);
    }
    return x;
}

int peek(int pos){
    Node *p = top;
    for(int i=0; p!=NULL && i<pos-1; i++) 
        p=p->next;
    if(p!=NULL) return p->data;
    else return -1;
}

int stackTop(){
    if(top) return top->data;
    return -1;
}

int isEmpty(){
    return top?0:1;
}

int  isFull(){
    Node *t = new Node;
    int r=t?0:1;
    free(t);
    return r;
}

void display(){
    Node *p=top;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
    
int main(){
    push(10);
    push(22);
    push(35);
    push(88);
    push(56);
    display();
    cout<<" Is Empty : "<<isEmpty()<<endl;
    cout<<" Is Full : "<<isFull()<<endl;
    pop();
    display();
    cout<<"Peek at position 3 : "<<peek(3)<<endl;
    cout<<"Stack Top : "<<stackTop()<<endl;
    pop();
    pop();
    pop();
    pop();
    cout<<" Is Empty : "<<isEmpty()<<endl;
    cout<<" Is Full : "<<isFull()<<endl;

    return 0;
}