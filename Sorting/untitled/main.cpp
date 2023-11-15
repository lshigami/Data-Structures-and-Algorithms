# include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define str string
#define strstr stringstream
#define sz s.size()
#define f first
#define s second
#define endl '\n'
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void Heapify(int a[], int n, int i){
    int largest =i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && a[l]>a[largest]) largest=l;
    if(r<n && a[r]>a[largest]) largest=r;
    if(largest!=i) {
        swap(a[i],a[largest]);
        Heapify(a,n,largest);
    }
}
void HeapSort(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        Heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        Heapify(a,i,0);
    }
}
void Merge(int a[],int l, int m, int r){
    int n1=m-l+1;
    int n2=r-m;
    int n=r-l+1;
    int x=0;
    int y=0;
    int k=l;
    int a1[n1];
    int a2[n2];
    for(int i=l;i<m+1;i++){
        a1[i-l]=a[i];
    }
    for(int i=m+1;i<=r;i++){
        a2[i-m-1]=a[i];
    }
    while(x<n1 && y<n2){
        if(a1[x]<=a2[y]){
            a[k++]=a1[x++];
        }
        else a[k++]=a2[y++];
    }
    while(x<n1) a[k++]=a1[x++];
    while(y<n2) a[k++]=a2[y++];
}
void MergeSort(int a[], int l, int r){
    if(l<r){
        int m=(r+l)/2;
        MergeSort(a,l,m);
        MergeSort(a,m+1,r);
        Merge(a,l,m,r);
    }
}
void BubbleSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
}
void SelectionSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        int idx=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[idx]){
                idx=j;
            }
        }
        swap(a[i],a[idx]);
    }
}
void CountingSort(int a[], int n){
    int MAX=*max_element(a,a+n);
    int MIN=*min_element(a,a+n);
    int range=MAX-MIN+1;
    int count[range];
    int out[n];
    fill_n(count, range, 0);
    for(int i=0;i<n;i++){
        count[a[i]-MIN]++;
    }
    for(int i=1;i<range;i++){
        count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        out[count[a[i]-MIN]-1]=a[i];
        count[a[i]-MIN]--;
    }
    for(int i=0;i<n;i++){
        a[i]=out[i];
    }
}
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j) {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}
void RadixSort(int a[], int n){
    int MAX=*max_element(a,a+n);
    for(int exp=1;MAX/exp>0;exp*=10){
        int count[10]={0};
        int ouput[n];
        for(int i=0;i<n;i++){
            count[(a[i]/exp)%10]++;
        }
        for(int i=1;i<10;i++){
            count[i]+=count[i-1];
        }
        for(int i=n-1;i>=0;i--){
            ouput[count[(a[i]/exp)%10]-1]=a[i];
            count[(a[i]/exp)%10]--;
        }
        for(int i=0;i<n;i++){
            a[i]=ouput[i];
        }
    }
}

int main(){
    int n=5;
    int a[5] ={1,5,4,9,3};
//    //quickSort(a,0,n-1);
//    int i=partition(a,0,n-1);
//    cout<<i<<endl;
    RadixSort(a,n);
    for(int x:a) cout<<x<<" ";
}