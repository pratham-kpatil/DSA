#include<bits/stdc++.h>

using namespace std;

int main(){

    struct stack{
        int size;
        int top;
        int *s;
    };

    stack st;
    cout<<"Enter size of stack : ";
    cin>>st.size;
    st.s = new int[st.size];
    st.top = -1;
    

    return 0;
}