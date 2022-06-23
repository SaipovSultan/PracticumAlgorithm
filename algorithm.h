#pragma once

#include <vector>
#include <string>

int nth_fibonacci(int n){
    static std::vector<int> numbers;
    static constexpr int SENTINEL = -1;
    if(numbers.size() <= n){
        numbers.resize(n + 1, SENTINEL);
    }
    if(n <= 1){
        return n;
    }
    if(numbers[n] == SENTINEL){
        numbers[n] = nth_fibonacci(n - 1) + nth_fibonacci(n - 2);
    }
    return numbers[n];
}

void generate_bracket_seq(int left_open, int left_closed, std::string& accum, std::vector<std::string>& result){
    if(!left_open && !left_closed){
        result.push_back(accum);
        return;
    }
    if(left_open){
        accum.push_back('(');
        generate_bracket_seq(left_open - 1u, left_closed, accum, result);
        accum.pop_back();
    }
    if(left_closed > left_open){
        accum.push_back(')');
        generate_bracket_seq(left_open, left_closed - 1u, accum, result);
        accum.pop_back();
    }
}

std::vector<std::string> generate_bracket_seq(int N){
    std::vector<std::string> result;
    std::string accum;
    generate_bracket_seq(N, N, accum, result);
    return result;
}