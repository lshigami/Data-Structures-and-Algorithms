#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Company {
    string name;
    string profit_tax;
    string address;
};

vector<Company> ReadCompanyList(string file_name) {
    vector<Company> companies;
    ifstream file(file_name);
    string line;
    getline(file, line); // Skip the header line
    while (getline(file, line)) {
        stringstream ss(line);
        string name, profit_tax, address;
        getline(ss, name, '|');
        getline(ss, profit_tax, '|');
        getline(ss, address, '|');
        companies.push_back({name, profit_tax, address});
    }
    file.close();
    return companies;
}

long long HashString(string company_name) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : company_name) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

Company* CreateHashTable(vector<Company> list_company) {
    Company* hash_table = new Company[200];
    for (Company company : list_company) {
        long long index = HashString(company.name) % 200;
        while (!hash_table[index].name.empty()) {
            index = (index + 1) % 200; // Linear probing
        }
        hash_table[index] = company;
    }
    return hash_table;
}

void Insert(Company* hash_table, Company company) {
    long long index = HashString(company.name) % 200;
    while (!hash_table[index].name.empty()) {
        index = (index + 1) % 200; // Linear probing
    }
    hash_table[index] = company;
}

Company* Search(Company* hash_table, string company_name) {
    long long index = HashString(company_name) % 200;
    while (!hash_table[index].name.empty() && hash_table[index].name != company_name) {
        index = (index + 1) % 200; // Linear probing
    }
    if (hash_table[index].name == company_name) {
        return &hash_table[index];
    } else {
        return NULL;
    }
}
