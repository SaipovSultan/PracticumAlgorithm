#include "test_runner.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename ForwardIt>
bool sub_seq(ForwardIt begin1, ForwardIt end1, ForwardIt begin2, ForwardIt end2){
    while(begin1 != end1 && begin2 != end2){
        if(*begin1 == *begin2){
            begin1 = next(begin1);
        }
        begin2 = next(begin2);
    }
    return begin1 == end1;
}


int cookies(vector<int>& greedies, vector<int>& size_cookies){
    sort(greedies.begin(), greedies.end());
    sort(size_cookies.begin(), size_cookies.end());

    auto greedy_it = greedies.rbegin();
    auto size_cookie_it = size_cookies.rbegin();
    while(greedy_it != greedies.rend() && size_cookie_it != size_cookies.rend()){
        if(*size_cookie_it >= *greedy_it){
            size_cookie_it = next(size_cookie_it);
        }
        greedy_it = next(greedy_it);
    }
    return distance(size_cookies.rbegin(), size_cookie_it);
}

void Test(){
    {
        vector<int> greedies = {1, 2};
        vector<int> size_cookies = {2, 1, 3};
        AssertEqual(cookies(greedies, size_cookies), 2);
    }
    {
        vector<int> greedies = {2, 1, 3};
        vector<int> size_cookies = {1, 1};
        AssertEqual(cookies(greedies, size_cookies), 1);
    }
}

int main(){
    TestRunner tr;
    RUN_TEST(tr, Test);
    return 0;
}