#pragma once
//Make vector class to store CSV files' data
#include "Requirement.h"

using ll = long long;

template <class T>
class vector {
private:
    T* _data;
    ll s;          // Current size of the vector (Number of elements)
    ll capacity;   // Maximum size of the vector's array (If reached double it)

public:
    vector() : _data(nullptr), s(0), capacity(0) {}

    vector(ll cellNum, const T& val) : s(cellNum), capacity(cellNum) {
        _data = new T[cellNum];
        std::fill(_data, _data + cellNum, std::move(val));
    }
    vector(const ll cellNum) : s(cellNum), capacity(cellNum) {
        _data = new T[cellNum];
    }

    ~vector() {
        clear();
        _data = NULL;
    }

    void clear() {
        if (_data) {
            delete[] _data;
            this->_data = nullptr;
        }
        this->capacity = 0;
        this->s = 0;
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

    void insert(const T& val, long long index) 
    {
        assert(index >= 0); 
        assert(index <= s); 
        if (s == capacity) {
            upsize();
        }
        ++s;
        for (long long i = s - 1; i > index; --i)
        {
            _data[i] = _data[i - 1]; 
        }
        _data[index] = val; 
    }
    void insert(T&& val, long long index)
    {
        assert(index >= 0);
        assert(index <= s);
        if (s == capacity) {
            upsize();
        }
        ++s;
        for (int i = s - 1; i > index; --i)
        {
            _data[i] = _data[i - 1];
        }
        _data[index] = val;
    }
    void erase(long long index)
    {
        for (int i = index; i < s-1; ++i)
        {
            _data[i] = _data[i + 1]; 
        }
        --s; 
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

    T* begin()
    {
        return _data; 
    }
    T* end()
    {
        return _data + s; 
    }
private:
    void upsize() {
        capacity = (capacity == 0) ? 1 : 2 * capacity;
        T* ne = new T[capacity];
        std::move(_data, _data + s, ne);
        delete[] _data;
        _data = ne;
    }

public:
   
    void sort()
    {
        std::sort(_data, _data + s); 
    }
    void decrease_sort()
    {
        std::sort(_data, _data + s, std::greater<T>()); 
    }

    void setDefault(int n, T def[]) {
        for (int i = 0; i < n; i++)
            this->push_back(def[i]);
    }
};
