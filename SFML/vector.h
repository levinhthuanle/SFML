#pragma once
//Make vector class to store CSV files' data
#include "Requirement.h"
using ll = long long;

template <typename T>
class vector {
private:
    T* _data;
    ll s;          // Current size of the vector (Number of elements)
    ll capacity;   // Maximum size of the vector's array (If reached double it)

public:
    vector() : _data(nullptr), s(0), capacity(0) {}

    vector(ll num, const T& val) : s(num), capacity(num) {
        _data = new T[num];
        std::fill(_data, _data + num, std::move(val));
    }

    ~vector() {
        delete[] _data;
    }

    void push_back(const T& val) {
        if (s == capacity) {
            upsize();
        }
        _data[s++] = val;
    }

    void push_back(T&& val) {
        if (s == capacity) {
            upsize();
        }
        _data[s++] = std::move(val);
    }

    T& operator[] (ll __offset) {
        assert(__offset < s);
        return _data[__offset];
    }

    const T& operator[] (ll __offset) const {
        assert(__offset < s);
        return _data[__offset];
    }

    vector& operator= (const vector& rhs) {
        if (this == &rhs) {
            return *this;
        }
        if (s < rhs.s) {
            delete[] _data;
            _data = new T[rhs.s];
            capacity = rhs.s;
        }
        s = rhs.s;
        std::copy(rhs._data, rhs._data + rhs.s, _data);
        return *this;
    }

    void pop_back() {
        assert(s > 0);
        --s;
    }

    ll size() const {
        return s;
    }

private:
    void upsize() {
        capacity = (capacity == 0) ? 1 : 2 * capacity;
        T* ne = new T[capacity];
        std::move(_data, _data + s, ne);
        delete[] _data;
        _data = ne;
    }
};
