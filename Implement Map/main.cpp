#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

template<typename K, typename V>
class UnorderedMap {
public:
    UnorderedMap(size_t numBuckets = 1000) : buckets(numBuckets) {}

    void insert(K key, V value) {
        auto& bucket = buckets[hash(key)];
        auto it = std::find_if(bucket.begin(), bucket.end(),[=](auto& pair) { return pair.first == key; });
        if (it != bucket.end()) {
            it->second = value;
        } else {
            bucket.push_back(std::make_pair(key, value));
        }
    }

    V* find(K key) {
        auto& bucket = buckets[hash(key)];
        auto it = std::find_if(bucket.begin(), bucket.end(),[=](auto& pair) { return pair.first == key; });
        if (it != bucket.end()) {
            return &it->second;
        } else {
            return nullptr;
        }
    }

private:
    vector<list<pair<K, V>>> buckets;

    size_t hash(K key) {
        return std::hash<K>{}(key) % buckets.size();
    }
};


template<typename K,typename V>
class Map{
private:
    vector<vector<pair<K,V>>>buckets;
    int Hash(K key){
        return hash<K>{}(key) % buckets.size();
    }
public:
    Map(int size=1000) :buckets(size){}
    void insert(K key, V value){
        auto &vp = buckets[Hash(key)];
        for(auto &x:vp){
            if(x.first==key){
                x.second=value;
                return;
            }
        }
        vp.push_back({key,value});
    }
    V* find(K key){
        auto &vp = buckets[Hash(key)];
        for(auto &x:vp){
            if(x.first==key){
                return &x.second;
            }
        }
        return nullptr;
    }

};

int main() {
    std::vector<int> scores = {9, 3, 2, 5, 4, 7, 8, 7};
    std::vector<int> sorted_scores = scores;
    std::sort(sorted_scores.begin(), sorted_scores.end(), std::greater<int>());

    Map<int, int> score_to_rank;
    int rank = 1;
    for (int score : sorted_scores) {
        if (score_to_rank.find(score) == nullptr) {
            score_to_rank.insert(score, rank);
            rank++;
        }
    }

    for (int score : scores) {
        std::cout << *score_to_rank.find(score) << " ";
    }

    return 0;
}