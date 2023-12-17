#include "header.h"

int main(int argc, char *argv[]) {
    string filename = argv[1];
    string outputfile;
    int m;
    int n_insert;
    int n_search;
    ifstream CIN(filename);
    CIN >> outputfile;
    CIN >> m;
    CIN >> n_insert;
    cout << outputfile << endl;
    cout << m << endl;
    cout << n_insert << endl;
    HashTable<int> map(m, outputfile);
    for (int i = 0; i < n_insert; i++) {
        int key;
        CIN >> key;
        map.Insert(key);
    }
    CIN >> n_search;
    cout << n_search << endl;
    for (int i = 0; i < n_search; i++) {
        int key;
        CIN >> key;
        map.Search(key);
    }
}

