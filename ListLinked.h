#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <iostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

using namespace std;

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    ListLinked() : first(nullptr), n(0) {}

    ~ListLinked() {
        Node<T>* current = first;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw out_of_range("Index out of range");
        }
        Node<T>* current = first;
        for (int i = 0; i < pos; ++i) {
            current = current->next;
        }
        return current->data;
    }

    friend ostream& operator<<(ostream &out, const ListLinked<T> &list) {
        Node<T>* current = list.first;
        out << "List -> [";
        while (current) {
            out << current->data;
            if (current->next != nullptr) {
                out << ", ";
            }
            current = current->next;
        }
        out << "]";
        return out;
    }

    void insert(int pos, T e) {
        if (pos < 0 || pos > n) {
            throw out_of_range("Index out of range");
        }
        Node<T>* newNode = new Node<T>(e);
        if (pos == 0) {
            newNode->next = first;
            first = newNode;
        } else {
            Node<T>* current = first;
            for (int i = 1; i < pos; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        n++;
    }

    void append(T e) {
        insert(n, e);
    }

    void prepend(T e) {
        insert(0, e);
    }

    T remove(int pos) {
        if (pos < 0 || pos >= n) {
            throw out_of_range("Index out of range");
        }
        Node<T>* current = first;
        T data;
        if (pos == 0) {
            first = first->next;
            data = current->data;
            delete current;
        } else {
            Node<T>* prev = nullptr;
            for (int i = 0; i < pos; i++) {
                prev = current;
                current = current->next;
            }
            prev->next = current->next;
            data = current->data;
            delete current;
        }
        n--;
        return data;
    }

    T get(int pos) const {
        if (pos < 0 || pos >= n) {
            throw out_of_range("Index out of range");
        }
        Node<T>* current = first;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        return current->data;
    }

    int search(T e) const {
        Node<T>* current = first;
        int index = 0;
        while (current != nullptr) {
            if (current->data == e) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }

    bool empty() const override {
        return n == 0;
    }

    int size() const override {
        return n;
    }
};

#endif
