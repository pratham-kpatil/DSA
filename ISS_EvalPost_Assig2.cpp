#include<iostream>
#include<string>
#include<math.h>

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

void push(struct stk *st, int c){
        st->top++;
        st->arr[st->top] = c ;
}

int pop(struct stk *st){
        int c;
        c = st->arr[st->top];
        st->top--;
        return c;
}

int calculate(char c, struct stk *st)
{
    int num1=pop(st);
    int num2=pop(st);
    switch(c){
        case'+':
            return num2+num1;
        
        case'-':
            return num2-num1;
        
        case'*':
            return num2*num1;
        
        case'/':
            return num2/num1;
        
        case'^':
            return pow(num2,num1);
    }
    return 0;
}

bool isNumber(char c){
    if(c>=48 && c<=57)
        return true;
    return false;
}

int main(){
    struct stk st;
    string pst;
    cout<<"Enter Postfix Experssion = ";
    cin>>pst;
    create(&st);
    int ans;
    int s = pst.size();
    for(int i=0; i<s; i++){

        if(isNumber(pst[i]))
            push(&st,pst[i]-'0');
        
        else{
            ans = calculate(pst[i], &st);
            push(&st,ans);
        }
    }
    cout<<"Answer = "<<pop(&st)<<endl;
    return 0;
}