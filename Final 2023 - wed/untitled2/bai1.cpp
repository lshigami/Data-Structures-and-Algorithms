#include <iostream>
#include <vector>

using namespace std;




void MaxHeapify(vector<int>&a,int n,int i){
    int largest=i;
    int l=i*2+1;
    int r=i*2+2;
    if(l<n && a[l]>a[largest]) largest=l;
    if(r<n && a[r]>a[largest]) largest=r;
    if(largest!=i){
        swap(a[i],a[largest]);
        MaxHeapify(a,n,largest);
    }
}
void MinHeapify(vector<int>&a,int n,int i){
    int lowest=i;
    int l=i*2+1;
    int r=i*2+2;
    if(l<n && a[l]<a[lowest]) lowest=l;
    if(r<n && a[r]<a[lowest]) lowest=r;
    if(lowest!=i){
        swap(a[i],a[lowest]);
        MinHeapify(a,n,lowest);
    }
}

void Greater(vector<int>&a,int n){
    for(int i=n/2-1;i>=0;i--){
        MaxHeapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        MaxHeapify(a,i,0);
    }
}
void Lower(vector<int>&a,int n){
    for(int i=n/2-1;i>=0;i--){
        MinHeapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        MinHeapify(a,i,0);
    }
}

int main(){
    int a[8]={9,2,3,5,6,1,0,10};

    vector<int>odd;
    vector<int>even;
    for(auto x:a){
        if(x%2==0) even.push_back(x);
        else odd.push_back(x);
    }

    Greater(even,even.size());
    Lower(odd,odd.size());
    int i=0;
    int j=0;
    while (i<even.size() && j<odd.size()){
        cout<<odd[j++]<<" "<<even[i++]<<" ";
    }
    while (j<odd.size()){
        cout<<odd[j++]<<" ";
    }
    while (i<even.size()){
        cout<<even[i++]<<" ";
    }






}