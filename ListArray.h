#include <ostream>
#include <stdexcept>
#include "List.h"
using namespace std;

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;
    int max;
    int n;
    static const int MINSIZE = 2;

    void resize(int new_size) {
        T* new_arr = new T[new_size];
        for (int i = 0; i < n; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max = new_size;
    }

public:
    ListArray() {
        arr = new T[MINSIZE];
        max = MINSIZE;
        n = 0;
    }

    ~ListArray() {
        delete[] arr;
    }

    T operator[](int pos) const {
        if (pos >= size() || pos < 0) {
            throw out_of_range("Fuera de rango la posición");
        }
        return arr[pos];
    }

    friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
        out << "List -> [";
        for (int i = 0; i < list.size(); i++) {
            out << list.arr[i];
            if (i < list.size() - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }

    friend ListArray<T> operator+(const ListArray<T>& a, const ListArray<T>& b) {
        ListArray<T> result;
        for (int i = 0; i < a.size(); i++) {
            result.append(a.arr[i]);
        }
        for (int i = 0; i < b.size(); i++) {
            result.append(b.arr[i]);
        }
        return result;
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > size()) {
            throw out_of_range("La posición no es válida");
        }
        if (size() >= max) {
            resize(max * 2);
        }
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = e;
        n++;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= size()) {
            throw out_of_range("La posición no es válida");
        }
        T valor = arr[pos];
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        if (size() <= max / 2 && max > MINSIZE) {
            resize(max / 2);
        }
        return valor;
    }

    T get(int pos) const override {
        if (pos < 0 || pos >= size()) {
            throw out_of_range("La posición no es válida");
        }
        return arr[pos];
    }

    int search(T e) const override {
        for (int i = 0; i < n; i++) {
            if (arr[i] == e) {
                return i;
            }
        }
        return -1;
    }

    bool empty() const override {
        return (n == 0);
    }

    int size() const override {
        return n;
    }
};

