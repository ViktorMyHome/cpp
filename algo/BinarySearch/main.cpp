#include <iostream>
#include <assert.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// lower_bound gives the position of element not less than the given value
// upper_bound gives the position of first element strictly greater than the given value
// equal_range is used to find the sub-range within a given range [first,last)

int main(){
    vector<int> v={4,6,8,10,12,14,16,18};
    vector<int>::iterator it = lower_bound(v.begin(), v.end(), 7);
    std::cout<<" lower_bound = "<<*it<<endl; // 8
    it = lower_bound(v.begin(), v.end(), 6);
    std::cout<<" lower_bound = "<<*it<<endl; // 6
    it = lower_bound(v.begin(), v.end(), 25);
    std::cout<<" lower_bound = "<<*it<<endl; //v.end();

    it = v.begin();
    cout<<" v.begin() = "<<*it<<endl; //first element
    it = upper_bound(v.begin(), v.end(), 14);
    cout<<" upper_bound = "<<*it<<endl;
    it = upper_bound(v.begin(), v.end(), 18);
    cout<<" upper_bound not found = "<<*it<<endl;

    auto p = equal_range(v.begin(), v.end(), 14);
    cout<<"equal_range first = "<<*p.first<<"equal_range second = "<<*p.second<<endl;

    cout<<" p.first index = "<<p.first - v.begin()<<endl;

    return 0;
}
