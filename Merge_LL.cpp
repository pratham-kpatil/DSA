#include<bits/stdc++.h>

using namespace std;

struct Node{
        int data;
        Node *next;
}*first=NULL, *first1=NULL, *meg=NULL;

void create_LLA(int A[], int n){
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

void create_LLB(int B[], int n){
    Node *temp,*last;
    first1 = new Node();
    first1->data = B[0];
    first1->next = NULL;
    last = first1;

    for(int i=1; i<n; i++){
        temp = new Node();
        temp->data = B[i];
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
        cout<<p->data<<endl;
        p = p->next;
    }

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

void M_two_LL(Node* ptr, Node *ptr1){

    Node *last;

    if(ptr->data > ptr1->data){
        meg = last = ptr1;
        ptr1 = ptr1->next;
        meg->next = NULL;
    }
    else{
        meg = last = ptr;
        ptr = ptr->next;
        meg->next = NULL;
    }

    while(ptr && ptr1){
        if(ptr->data > ptr1->data)
        {
            last->next = ptr1;
            last = ptr1;
            ptr1 = ptr1->next;
            last->next = NULL;
        }
        else{
            last->next = ptr;
            last = ptr;
            ptr = ptr->next;
            last->next = NULL;
        }
    }

    if(ptr) last->next = ptr;
    if(ptr1) last->next = ptr1;
}
int main(){
    
    int A[]={1,8,33,101,786};
    int B[]={0,3,47,51,77,98,666};
    int An = sizeof(A)/sizeof(A[0]);
    int Bn = sizeof(B)/sizeof(B[0]);
    create_LLA(A,An);
    create_LLB(B,Bn);
    //create_LL(B,Bn,first2);
    cout<<"First LL --- ";
    Display(first);
    cout<<"Second LL --- ";
    Display(first1);
    cout<<"Merge LL ---";
    M_two_LL(first,first1);
    Display(meg);
    //find_rep(first,6);
    //cout<<"Modified LL"<<endl;
    ////Create LL using insert 
    //for(int i=0;i<n;i++){
    //    insert(first, i+1, A[i]);
    //}
    return 0;
} 