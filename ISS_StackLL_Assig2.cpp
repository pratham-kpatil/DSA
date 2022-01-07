#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
}*top=NULL;

void push(int n){
    node *temp = new node();
    if(temp==NULL) 
        cout<<"Stack is Full"<<endl;
    else{
        cout<<"Pushed Element "<<n<<" to Stack"<<endl;
        temp->data = n;
        if(top==NULL) 
            temp->next = NULL;
        else 
            temp->next = top;
        top = temp;
    }
}

void pop(){
    if(top==NULL)
        cout<<"Stack is Empty"<<endl;
    else{
        cout<<"Element Popped"<<endl;
        top = top->next;
    }
}

int top_ele(){
    if(top==NULL)
        return -1;
    int n;
    n = top->data;
    return n;
}

bool isFull(){
    node *temp = new node();
    if(temp==NULL)
        return true;
    return false;
}

bool isEmpty(){
    node *temp = new node();
    if(temp!=NULL)
        return true;
    return false;
}


int main(){
    push(23);
    push(56);
    push(40);
    push(96);
    cout<<"Top Element = "<<top_ele()<<endl;
    pop();
    pop();
    cout<<"Top Element = "<<top_ele()<<endl;
    cout<<"Is Empty? = "<<isEmpty()<<endl;
    cout<<"Is Full? = "<<isFull()<<endl;
    return 0;
}