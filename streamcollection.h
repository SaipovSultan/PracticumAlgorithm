#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vector_){
    out << "[";
    if(vector_.empty()){
        return out << "]";
    }
    auto begin = vector_.cbegin(), prev_end = std::prev(vector_.cend());
    while(begin != prev_end){
        out << (*begin) << ", ";
        begin = std::next(begin);
    }
    return out << (*prev_end) << "]";
}

template <typename T>
std::istream& operator>>(std::istream& in, std::vector<T>& vector_){
    auto begin = vector_.begin(), end = vector_.end();
    while(begin != end && in >> *begin){
        begin = std::next(begin);
    }
    return in;
}

