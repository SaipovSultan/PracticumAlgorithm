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
    for(;begin != prev_end;++begin){
        out << (*begin) << ", ";
    }
    return out << (*prev_end) << "]";
}

template <typename T>
std::istream& operator>>(std::istream& in, std::vector<T>& vector_){
    for(auto begin = vector_.begin(), end = vector_.end();
        begin != end && in >> *begin;
        ++begin);
    return in;
}

