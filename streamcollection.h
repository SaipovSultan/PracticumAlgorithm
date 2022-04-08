//
// Created by Sultan on 08.04.2022.
//

#ifndef PRACTICUMALGORITHM_STREAMCOLLECTION_H
#define PRACTICUMALGORITHM_STREAMCOLLECTION_H

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vector_){
    out << "[";
    if(vector_.empty()){
        return out << "]";
    }
    auto begin = vector_.cbegin(), end = std::prev(vector_.cend());
    while(begin != end){
        out << (*begin) << ", ";
        begin = std::next(begin);
    }
    return out << (*end) << "]";
}

template <typename T>
std::istream& operator>>(std::istream& in, std::vector<T>& vector_){
    auto begin = vector_.begin(), end = vector_.end();
    while(begin != end && in >> *begin){
        begin = std::next(begin);
    }
    return in;
}

#endif //PRACTICUMALGORITHM_STREAMCOLLECTION_H
