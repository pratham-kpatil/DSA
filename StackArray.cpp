#include<iostream>
using namespace std;

struct stk{
    int *arr;
    int size=100;
    int top;
};

void create(struct stk *st){
    st->top=-1;
    st->arr = new int[st->size];
}

void push(struct stk *st, int n){
    
    if(st->top==st->size-1)
        cout<<"Stack Full"<<endl;
    else{
        cout<<"Pushed Element "<<n<<" to Stack"<<endl;
        st->top++;
        st->arr[st->top] = n ;
    }
}

void pop(struct stk *st){
    
    if(st->top==-1)
        cout<<"Stack Empty"<<endl;
    else{
        cout<<"Element Popped"<<endl;
        st->top--;
    }
}

int top(struct stk *st){
    if(st->top==-1)
        return -1;
    int n;
    n = st->arr[st->top];
    return n;
}

bool isFull(struct stk *st){
    if(st->top==st->size-1)
        return true;
    return false;
}

bool isEmpty(struct stk *st){
    if(st->top==-1)
        return true;
    return false;
}


int main(){
    struct stk st;
    create(&st);
    push(&st,23);
    push(&st,56);
    push(&st,40);
    push(&st,96);
    cout<<"Top = "<<top(&st)<<endl;
    pop(&st);
    pop(&st);
    cout<<"Top = "<<top(&st)<<endl;
    cout<<"Is Empty? = "<<isEmpty(&st)<<endl;
    cout<<"Is Full? = "<<isFull(&st)<<endl;
    return 0;
}