#include<bits/stdc++.h>

using namespace std;

struct Node{
        int data;
        Node *next;
}*first=NULL;

void create_LL(int A[], int n){
    Node *temp,*last;
    first = new Node();
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1; i<n; i++){
        temp = new Node();
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}


void Display(Node *p)
{   
    cout<<"Display Executed"<<endl;
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;

}

/*void find_rep(Node *ptr, int key)
{
    Node *q;
    if(key!=ptr->data){
        q = ptr;
        ptr = ptr->next;
        while(ptr!=NULL){
            if(key == ptr->data){
                q->next = ptr->next;
                ptr->next = first;
                first = ptr;
                break;
            }
            
            else{
                q = ptr;
                ptr = ptr->next; 
            }
        }
    }
}*/

/*void insert(Node *ptr, int ind, int num){
    cout<<"Insert Executed"<<endl;
    Node *temp;
    temp = new Node();
    if(ind==1){
        temp->data = num;
        temp->next = ptr;
        first=temp;
    }
    else{
        for(int i=1; i<ind-1; i++)
        {
            ptr = ptr->next;
        }

        temp->data = num;
        temp->next = ptr->next;
        ptr->next = temp;
    }
}*/


int main(){
    
    int A[]={1,8,33,101,786};
    int An = sizeof(A)/sizeof(A[0]);
    create_LL(A,An);
    Display(first);
    
    Node *temp;
    temp = new Node();
    temp = first;
    temp->data = 3;
    cout<<first->next->next->next<<endl;
    cout<<temp->data<<endl;

    return 0;
} 