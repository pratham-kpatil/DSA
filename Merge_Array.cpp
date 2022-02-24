#include<bits/stdc++.h>

using namespace std;

int main(){

    int a [] = {0,1,8,33};
    int b [] = {-1,0,3,47};

    int sa = sizeof(a)/sizeof(a[0]);
    int sb = sizeof(b)/sizeof(b[0]);
    int r[sa+sb];

    int count=0,i=0,j=0;
    while(i<sa && j<sb)
    {
        if(a[i]>b[j]){
            r[count++] = b[j++];
        }
        else{
            r[count++] = a[i++];
        }
    }

    if(i<sa){
        r[count++] = a[i++];
    }

    if(j<sb ){
        r[count++] = b[j++];
    }

    for(int z=0; z<sa+sb; z++)
    {
        cout<<r[z]<<" ";
    }
}