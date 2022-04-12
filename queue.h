//
// Created by Progs on 10.04.2022.
//

#ifndef PRACTICUMALGORITHM_QUEUE_H
#define PRACTICUMALGORITHM_QUEUE_H


#include <vector>
#include <list>

template <typename T, size_t max_size>
class Queue{
public:
    Queue() : data(max_size), head(0u), tail(0u), size(0u){}

    bool empty() const noexcept{
        return size == 0u;
    }

    void push(T&& value){
        if(size >= max_size){
            throw std::bad_alloc();
        }
        data[tail] = std::move(value);
        tail = (tail + 1) % max_size;
        ++size;
    }

    void push(const T& value){
        if(size >= max_size){
            throw std::bad_alloc();
        }
        data[tail] = value;
        tail = (tail + 1) % max_size;
        ++size;
    }

    T pop(){
        if(empty()){
            throw std::bad_alloc();
        }
        T res = data[head];
        head = (head + 1) % max_size;
        --size;
        return res;
    }

    T peek() const{
        if(empty()){
            throw std::bad_alloc();
        }
        return data[head];
    }

private:
    std::vector<T> data;
    size_t head;
    size_t tail;
    size_t size;
};

template <typename T>
class QueueList{
public:
    QueueList() = default;

    bool empty() const noexcept{
        return data.empty();
    }

    void push(T&& value){
        data.push_back(std::move(value));
    }

    void push(const T& value){
        data.push_back(value);
    }

    T pop(){
        T value = data.front();
        data.pop_back();
        return value;
    }

    T peek() const{
        return data.front();
    }

private:
    std::list<T> data;
};

#endif //PRACTICUMALGORITHM_QUEUE_H
