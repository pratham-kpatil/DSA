#include<iostream>
#include<string>

using namespace std;

struct stk{
    char *arr;
    int size=100;
    int top;
};

void create(struct stk *st){
    st->top=-1;
    st->arr = new char[st->size];
}

void push(struct stk *st, char c){
        st->top++;
        st->arr[st->top] = c ;
}

char pop(struct stk *st){
        char c;
        c = st->arr[st->top];
        st->top--;
        return c;
}

int top_ele(struct stk *st){
    return st->arr[st->top];
}

bool isEmpty(struct stk *st){
    if(st->top==-1)
        return true;
    return false;
}

int pre(char c)
{
    if(c == '^')
        return 3;
    else if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
    return 0;
}

bool isOperand(char c){
    if(c>=97 && c<=122)
        return true;
    return false;
}

int main(){
    struct stk st;
    string inf, pst;
    cout<<"Enter Infix Experssion = ";
    cin>>inf;
    create(&st);
    int s = inf.size();
    for(int i=0; i<s; i++){

        if(isOperand(inf[i]))
            pst += inf[i];

        else if(inf[i]=='(')
            push(&st,'(');

        else if(inf[i]==')'){
            while(top_ele(&st)!='(')
                pst += pop(&st);

            pop(&st);
        }

        else if(!isEmpty(&st) && pre(inf[i])<=pre(top_ele(&st))){
            while(!isEmpty(&st) && pre(inf[i])<=pre(top_ele(&st)))
                pst += pop(&st);
        
            push(&st, inf[i]);
        }

        else{
            push(&st,inf[i]);
        }
    }
    while(!isEmpty(&st)){
        pst += pop(&st);
    }
    cout<<"Infix to Postfix = "<<pst<<endl;
    return 0;
}