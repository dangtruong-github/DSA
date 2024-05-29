#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

const long long VAL = 1e5 + 3; 

/* 
    Link to problem:
    https://leetcode.com/problems/get-the-maximum-score/description/
*/

long long main() {
    long long n[2], num;
    vector<long long> nums1, nums2;
    for (long long i = 0; i < 2; i++) {
        cin >> n[i];
    }
    
    for (long long i = 0; i < n[0]; i++) {
        cin >> num;  
        nums1.push_back(num);
    }
    
    for (long long i = 0; i < n[1]; i++) {
        cin >> num;  
        nums2.push_back(num);
    }
    
    long long prev_num = 0, best_num_1, best_num_2;
    map<long long, vector<long long>> edges;
    map<long long, long long> max_value;

    prev_num = 0;
    for (auto it = nums1.begin(); it != nums1.end(); it++) {
        if (edges.find(prev_num) == edges.end()) {
            vector<long long> tmp;
            edges.insert({prev_num, tmp});
            max_value.insert({prev_num, 0});
        } 
        
        edges[prev_num].push_back(*it);
        prev_num = *it;
    }
    best_num_1 = nums1.back();

    //cout << "finish nums1\n";

    prev_num = 0;
    for (auto it = nums2.begin(); it != nums2.end(); it++) {
        if (edges.find(prev_num) == edges.end()) {
            vector<long long> tmp;
            edges.insert({prev_num, tmp});
            max_value.insert({prev_num, 0});
        } 
        
        edges[prev_num].push_back(*it);
        prev_num = *it;
    }
    best_num_2 = nums2.back();

    //cout << "start\n";

    for (auto it = edges.begin(); it != edges.end(); it++) {
        //cout << it->first << ": ";

        for (auto it_int = it->second.begin(); it_int != it->second.end(); it_int ++) {
            cout << *it_int << " ";
            max_value[*it_int] = max(max_value[it->first] + *it_int, max_value[*it_int]);
        }

        //cout << "\n";
    }

    cout << max(max_value[best_num_1], max_value[best_num_2]);

    return 0;
}