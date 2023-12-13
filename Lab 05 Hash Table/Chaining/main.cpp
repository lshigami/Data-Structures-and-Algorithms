#include<bits/stdc++.h>
using namespace std;
const int p = 31;
const int m = 1e9 + 9;
struct Company{
    string name;
    string profit_tax;
    string address;
    void xuat(){
        cout<<name<<" "<<profit_tax<<" "<<address<<endl;
    }
};

vector<Company>ReadCompanyList(string filename){
    ifstream CIN(filename);
    string x;
    vector<Company>ans;
    while(getline(CIN,x)){
        stringstream xx(x);
        string token;
        vector<string>v;
        while(getline(xx,token,'|')){
            v.push_back(token);
        }
        Company c;
        c.name=v[0];
        c.profit_tax=v[1];
        c.address=v[2];
        ans.push_back(c);
    }
    return ans;
}

long long HashString(string company_name){
    string newname = "";
    if(company_name.size() >= 20){
        for(int i= company_name.size()-20;i<company_name.size();i++){
            newname+=string(1,company_name[i]);
        }
    } else newname = company_name;

    long long index = 0;
    long long p_pow = 1;
    for(int i = 0; i < newname.size(); i++){
        index = (index + newname[i] * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return index;
}

vector<Company>*CreateHashTable(vector<Company>list_company){
    vector<Company>*hashtable=new vector<Company>[200];
    for(auto x: list_company){
        long long idx= HashString(x.name)%200;
        hashtable[idx].push_back(x);
    }
    return hashtable;
}

void Insert(vector<Company>*hashtable,Company x){
    long long idx= HashString(x.name)%200;
    hashtable[idx].push_back(x);
}

vector<Company>Search(vector<Company>*hashtable,string name){
    long long idx= HashString(name)%200;
    vector<Company>ans;
    for(auto x : hashtable[idx]){
        if(x.name==name) ans.push_back(x);
    }
    return ans;
}

int main(){
    vector<Company>ans= ReadCompanyList("C:\\Users\\yanke\\CLionProjects\\untitled\\MST.txt");
    vector<Company>*hash= CreateHashTable(ans);
    for(int i=0;i<200;i++){
        cout<<i<<endl;
        for(auto x: hash[i]){
            cout<<x.name<<endl;
        }
    }
}