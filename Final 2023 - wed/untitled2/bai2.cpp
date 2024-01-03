#include <iostream>
#include <vector>

using namespace std;



int main(){
    vector<int>v={1,2,3,4,5,6};
    int target=5;

    vector<int>m(1e5+10,0);
    for(auto x:v){
        m[x]+=1;
    }
    for(auto x:v){
        if(m[target-x]) {
            cout<<"TRUE";
            return 0 ;
        }
    }
    cout<<"FALSE";
}