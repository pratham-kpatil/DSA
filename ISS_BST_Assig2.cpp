#include<iostream>

using namespace std;

struct node{
    int data;
    node *left;
    node *right;
}*bst=NULL;

node *create(int n){
    node *temp = new node();
    temp->data = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(node *root, int n){
    node *temp = create(n);
    while(root){
        if(root->data>n){
            if(root->left)
                root = root->left;
            else{
                root->left=temp;
                return;
            }
        }
        else{
            if(root->right)
                root = root->right;
            else{
                root->right = temp;
                return;
            }
        }
    }
}

node *find(node *root, int n){
    while(root){
        if(root->data==n) return root;

        else if(root->data>n)
            root = root->left;
        
        else
            root = root->right;
    }
    return NULL;
}

int height(struct node *root){
    int x=0,y=0;
    if(!root) 
        return 0;        
    x = height(root->left);
    y = height(root->right);
    if(x>y)
        return x+1;
    return y+1;
}

struct node *inPre(struct node *root){
    while(root && root->right)
        root=root->right;
    return root;
}

struct node *inSuc(struct node *root){
    while(root && root->left)
        root= root->left;
    return root;
}
struct node *remove(struct node *t,int key){
    
    if(!t) return NULL;
    if(!t->left && !t->right){
        if(t==bst) 
            bst = NULL;
        free(t);
        return NULL;
    }
    struct node *rep;
    if(t->data>key)
        t->left = remove(t->left, key);
    else if(t->data<key)
        t->right = remove(t->right, key);
    else{
        if(height(t->left)>height(t->right)){
            rep = inPre(t->left);
            t->data = rep->data;
            t->left = remove(t->left, rep->data); 
        }
        else{
            rep = inSuc(t->right);
            t->data = rep->data;
            t->right = remove(t->right, rep->data); 
        }
    }
    return t;
}

void preorder(struct node *root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    cout<<"------Executed------"<<endl;
    bst = create(50);
    insert(bst,25);
    insert(bst,57);
    insert(bst,500);
    insert(bst,2);
    insert(bst,7);
    insert(bst,125);
    insert(bst,35);
    insert(bst,81);
    insert(bst,21);
    cout<<"Preorder = ";
    preorder(bst);
    cout<<endl;
    cout<<find(bst,7)<<endl;
    remove(bst,7);
    cout<<find(bst,7)<<endl;
    cout<<"Preorder = ";
    preorder(bst);
    cout<<endl;
    remove(bst,50);
    cout<<"Preorder = ";
    preorder(bst);
    return 0;
}