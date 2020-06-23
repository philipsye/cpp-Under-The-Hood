//
// Created by y on 6/23/20.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <cstdio>
#include <iostream>

template<typename T>
class Vector{
public:
    explicit Vector ();
    explicit Vector (size_t n, const T& val =T());
    template <class InputIterator>
    Vector(InputIterator first, InputIterator last);
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    const T& operator[](size_t index)const {return m_vector[index];}
    T& operator[](size_t index){return m_vector[index];}
    const T& at(size_t index)const ;
    T& at(size_t index);
    const T&  front() const{return m_vector[0];}
    T& front(){return m_vector[0];}
    const T& back() const{return m_vector[m_size-1];}
    T& back(){return m_vector[m_size-1];}
    const T* data() const {return m_vector;}
    T* data() { return m_vector; }

    template <class InputIterator>
    void assign (InputIterator first, InputIterator last);
    void assign (size_t n, const T& val);

    ~Vector();

    size_t size(){return m_size;}
    size_t max_size(){return std::string::npos;}
    size_t capacity(){return m_capacity;}
    void resize(size_t n, const T& val =T());
    bool empty(){return m_size==0;}
    void reserve(size_t n);
    void push_back(const T& obj);
    void pop_back();
    void clear();
    void swap (Vector& other);


private:
    void initVector(Vector<T> vector);
    void isValid(size_t n);
    size_t m_capacity;
    size_t m_size;
    T* m_vector;
};

template<typename T>
void Vector<T>::initVector(Vector<T> vector) {
    m_vector = new T[vector.m_capacity];
    m_capacity = vector.m_capacity;
    m_size = vector.m_size;
    for(size_t i=0; i< m_size; i++){
        m_vector[i] = vector[i];
    }
}

template<typename T>
Vector<T>::Vector(): m_capacity(0), m_size(0), m_vector(NULL) {}

template<typename T>
Vector<T>::Vector(size_t n, const T& val):m_capacity(n), m_size(n), m_vector(new T [n]){
    for (size_t i=0; i<n; i++){
        m_vector[i] = val;
    }
}


template<typename T>
template <class InputIterator>
Vector<T>::Vector(InputIterator first, InputIterator last):m_capacity(){
    if(last<first){
        throw "index of begin bigger index of end";
    }
    m_size = last - first;
    m_capacity = last - first;
    m_vector = new T[last - first];
    size_t i=0;

    for(InputIterator it = first; it<last ; i++, it++){
        m_vector[i] = *it;
        it++;
    }
}


template<typename T>
Vector<T>::Vector(const Vector &other){
    initVector(other);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector &other) {
    if(this == other){
        return *this;
    }
    delete [] m_vector;
    m_vector =NULL;
    initVector(other);
    return *this;
}


template<typename T>
Vector<T>::~Vector() {
    delete [] m_vector;
    m_vector = NULL;
}

template<typename T>
void Vector<T>::resize(size_t n, const T &val) {
    if(n > m_size && n <= m_capacity){
        for(size_t i = m_size; i < n; i++){
            m_vector[i] = val;
        }
    }

    if(n > m_capacity){
        T* tmp = new T [n];
        int i;
        for(i =0; i < m_size; i++){
            tmp[i] = m_vector[i];
        }
        for(; i < n; i++){
            tmp[i] = val;
        }
        delete [] m_vector;
        m_vector = tmp;
        m_capacity = n;
    }
    m_size = n;
}

template<typename T>
void Vector<T>::reserve(size_t n) {
    if(n > m_capacity){
        T* tmp = new T [n];
        for(int i =0; i < m_size; i++){
            tmp[i] = m_vector[i];
        }
        delete [] m_vector;
        m_vector = tmp;
        m_capacity = n;
    }
}

template<typename T>
const T &Vector<T>::at(size_t index) const {
    isValid(index);
    return m_vector[index];
}

template<typename T>
T &Vector<T>::at(size_t index) {
    isValid(index);
    return m_vector[index];
}

template<typename T>
void Vector<T>::isValid(size_t n) {
    if(n >= m_size || n < 0){
        throw std::out_of_range ("INVALID INDEX ACCESS");
    }
}


template<typename T>
template <class InputIterator>
void Vector<T>::assign(InputIterator first, InputIterator last) {
    if(last<first){
        throw "index of begin bigger index of end";
    }
    m_size = last - first;
    if((last - first) > m_capacity){
        m_capacity = last - first;
        m_vector = new T[last - first];
    }

    size_t i=0;

    for(InputIterator it = first; it<last ; i++, it++){
        m_vector[i] = *it;
        it++;
    }
}



template<typename T>
void Vector<T>::assign(size_t n, const T &val) {
    m_size = n;
    m_capacity = n;
    m_vector = new T[n];
    for (size_t i=0; i<n; i++){
        m_vector[i] = val;
    }
}


template<class T>
inline void Vector<T>::push_back(const T& obj){
    if (m_capacity == 0)
        reserve(8);
    else if (m_size == m_capacity)
        reserve(2 * m_capacity);

    m_vector[m_size] = obj;

    ++m_size;
}


template<class T>
void Vector<T>::pop_back(){
    m_size--;
}


template<class T>
void Vector<T>::clear() {
    m_size = 0;
}


template<class T>
void Vector<T>::swap(Vector &other) {
    Vector<T> temp(this);
    this = other;
    other = temp;
}

#endif //VECTOR_VECTOR_H
