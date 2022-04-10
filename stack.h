//
// Created by Progs on 09.04.2022.
//

#ifndef PRACTICUMALGORITHM_STACK_H
#define PRACTICUMALGORITHM_STACK_H

#include <vector>

template <typename T>
class Stack{
public:
    Stack() = default;

    void push(T&& value) {
        data.push_back(std::move(value));
    }

    void push(const T& value) {
        data.push_back(value);
    }

    template<typename... Args>
    void emplace(Args&&... args) {
        data.emplace_back(args...);
    }

    void pop() noexcept {
        data.pop_back();
    }

    T peek() const {
        return data.back();
    }

    bool empty() const noexcept{
        return data.empty();
    }

    size_t size() const noexcept{
        return data.size();
    }

    size_t capacity() const noexcept{
        return data.capacity();
    }

    typename std::vector<T>::iterator begin() noexcept{
        return data.begin();
    }

    typename std::vector<T>::iterator end() noexcept{
        return data.end();
    }

    typename std::vector<T>::const_iterator begin() const noexcept{
        return data.begin();
    }

    typename std::vector<T>::const_iterator end() const noexcept{
        return data.end();
    }

    typename std::vector<T>::const_iterator  cbegin() const noexcept{
        return data.cbegin();
    }

    typename std::vector<T>::const_iterator  cend() const noexcept{
        return data.cend();
    }

private:
    std::vector<T> data;
};

#endif //PRACTICUMALGORITHM_STACK_H
