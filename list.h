#pragma once
#include <iostream>

template <typename T>
struct ForwardNode{
    T value;
    ForwardNode* next;
    explicit ForwardNode(T&& value, ForwardNode* next) : value(std::move(value)), next(next) {}
};

template <typename T>
ForwardNode<T>* next(ForwardNode<T>* node, size_t step = 0u){
    while(node && step > 0u){
        node = node->next;
        --step;
    }
    if(step > 0){
        throw std::invalid_argument("Invalid argument");
    }
    return node;
}

template <typename T>
ForwardNode<T>* delete_node(ForwardNode<T>* head, size_t step = 0u){
    if(!head){
        throw std::invalid_argument("Invalid argument");
    }
    if(step == 0u){
        return head->next;
    }
    ForwardNode<T>* prev_node = next(head, step - 1u);
    if(!prev_node->next){
        throw std::invalid_argument("Invalid argument");
    }
    prev_node->next = prev_node->next->next;
    return head;
}

template <typename T>
void print_node(ForwardNode<T>* head, std::ostream& out){
    while(head){
        out << head->value << "->";
        head = head->next;
    }
    out << "nullptr";
}

template <typename T>
int find(ForwardNode<T>* head, const T& value){
    int pos = 0;
    while(head){
        if(head->value == value){
            return pos;
        }
        head = next(head, 1u);
        ++pos;
    }
    return -1;
}

template <typename T>
ForwardNode<T>* reverse(ForwardNode<T>* head){
    ForwardNode<T>* new_head = nullptr;
    while(head){
        std::swap(head->next, new_head);
        std::swap(head, new_head);
    }
    return new_head;
}

template <typename T>
struct Node{
    T value;
    Node* next;
    Node* prev;
    explicit Node(T&& value, Node* next, Node* prev) : value(std::move(value)), next(next), prev(prev) {}
};

template <typename T>
Node<T>* reverse(Node<T>* head){
    Node<T>* new_head = nullptr;
    while(head){
        std::swap(head->next, new_head);
        std::swap(head, new_head);
        new_head->prev = head;
    }
    return new_head;
}

template <typename T>
void print_node(Node<T>* head, std::ostream& out){
    while(head){
        out << head->value << "<->";
        head = head->next;
    }
    out << "nullptr";
}

