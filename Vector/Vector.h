#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

class IndexError{};

class Vector {
    int * values;
    int size = 0;
    int capacity = 1;

    void reallocate(int new_size);
public:
    Vector();
    Vector(int size);
    Vector(int * values, int size);
    ~Vector();

    int length() const;

    int operator[](int i) const;
    int & operator[](int i);

    void push_back(int a);
    void push_front(int a);
    void remove(int);
    void extend(int i, Vector & nv);
};


#endif //VECTOR_VECTOR_H
