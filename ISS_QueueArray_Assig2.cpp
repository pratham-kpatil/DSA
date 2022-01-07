#include<iostream>
using namespace std;

struct que{
    int *arr;
    int size=100;
    int front;
    int rear;
};

void create(struct que *q){
    q->front=-1;
    q->rear=-1;
    q->arr = new int[q->size];
}

void addQ(struct que *q, int n){
    
    if(q->rear==q->size-1)
        cout<<"Queue is Full"<<endl;
    else{
        cout<<"Added Element "<<n<<" to Queue"<<endl;
        q->rear++;
        q->arr[q->rear] = n ;
    }
}

int deleteQ(struct que *q){
    int n=-1;
    if(q->front==q->rear)
        cout<<"Queue is Empty"<<endl;
    else{
        q->front++;
        n = q->arr[q->front];
        cout<<"Front Element of Queue = "<<n<<endl;
    }
    return n;
}

bool isFull(struct que *q){
    if(q->rear==q->size-1)
        return true;
    return false;
}

bool isEmpty(struct que *q){
    if(q->rear<q->size-1)
        return true;
    return false;
}


int main(){
    struct que q;
    create(&q);
    addQ(&q,23);
    addQ(&q,56);
    addQ(&q,40);
    addQ(&q,96);
    deleteQ(&q);
    deleteQ(&q);
    cout<<"Is Empty? = "<<isEmpty(&q)<<endl;
    cout<<"Is Full? = "<<isFull(&q)<<endl;
    return 0;
}