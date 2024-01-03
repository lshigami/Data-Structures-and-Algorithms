
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    //vector<int>a={1,2,0,3,4,3,0,5,6};
    vector<int>a={1,2,3,3,5,6};

    int MAX=*max_element(a.begin(),a.end());
    vector<int>m(MAX+100,0);
    int diff=0;
    for(auto x:a){
        if(m[x]==0) {
            diff++;
        }
        m[x]++;
    }
    int ans=0;
    int l=0;
    int r=a.size()-1;
    while (l<=r){
        if(a[l]!=a[r]){
            diff-=2;
            ans+=2;
            l++;
            r--;
        }else{
            diff-=1;
            ans+=2;
            l++;
            r--;
        }
        if(diff==1){
            cout<<ans;
            break;
        }
    }

}