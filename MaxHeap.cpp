#include<iostream>

using namespace std;

struct heap{
    int *arr;
    int size=100;
    int pos;
};

void create(struct heap *hp){
    hp->arr = new int[hp->size];
    hp->pos=-1;
}

void insert(struct heap *hp, int n){
    if(hp->pos==hp->size-1){
        cout<<"Heap is full cannot insert "<<n<<endl;
        return;
    }
    hp->pos++;
    if(hp->pos==0)
        hp->arr[hp->pos] = n;
        
    else{
        int i=hp->pos, j=hp->pos;
        while(i>0 && hp->arr[(i-1)/2]<n){
            i = (i-1)/2;
            hp->arr[j] = hp->arr[i];
            hp->arr[i]=n;
            j=i;
        }
        hp->arr[i]=n;
    }
}

int delete_max_ele(struct heap *hp){
    if(hp->pos==-1){
        cout<<"Heap is Empty"<<endl;
        return -1;
    }
    int max_ele = hp->arr[0];
    hp->arr[0]=hp->arr[hp->pos];
    hp->pos--;
    int i=0;
    while(i<=hp->pos/2){
        if(2*i+2<=hp->pos && (hp->arr[2*i+1] < hp->arr[2*i+2])){
            swap(hp->arr[i],hp->arr[2*i+2]);
            i = 2*i+2;
        }
        else if (hp->arr[i]<hp->arr[2*i+1]){
            swap(hp->arr[i],hp->arr[2*i+1]);
            i = 2*i+1;
        }
        else break;
    }
    return max_ele;
}

bool isHeapEmpty(struct heap *hp){
    if(hp->pos==-1)
        return true;
    return false;
}

bool isHeapFull(struct heap *hp){
    if(hp->pos==hp->size-1)
        return true;
    return false;
}

int main(){
    struct heap hp;
    create(&hp);
    insert(&hp,4444);
    insert(&hp,12);
    insert(&hp,71);
    insert(&hp,10);
    insert(&hp,8);
    insert(&hp,6);
    //for(int i=0; i<6; i++){
        //cout<<hp.arr[i]<<" ";
    //}
    cout<<endl;
    cout<<"Max Element = "<<delete_max_ele(&hp)<<endl;
    cout<<"Max Element = "<<delete_max_ele(&hp)<<endl;
    cout<<"Max Element = "<<delete_max_ele(&hp)<<endl;
    cout<<"Max Element = "<<delete_max_ele(&hp)<<endl;
    cout<<"Max Element = "<<delete_max_ele(&hp)<<endl;
    cout<<"Max Element = "<<delete_max_ele(&hp)<<endl;
    cout<<"Max Element = "<<delete_max_ele(&hp)<<endl;
    cout<<"Max Element = "<<delete_max_ele(&hp)<<endl; 
    cout<<"Max Element = "<<delete_max_ele(&hp)<<endl;
    return 0;
}