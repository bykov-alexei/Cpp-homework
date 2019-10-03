//
// Created by Alexei on 03.10.2019.
//

#include <iostream>
#include "Vector.h"

Vector::Vector() {
    capacity = 1;
    values = new int[capacity + 1];
    values[0] = 0;
}

Vector::Vector(int size) {
    capacity = size + 1;
    this->size = 0;
    values = new int[capacity + 1];
    for (int i = 0; i < capacity; i++)
        values[i] = 0;
}

Vector::Vector(int * values, int size) {
    this->values = values;
    this->size = size;
    this->capacity = size;
}

Vector::~Vector() {
    delete[] this->values;
}

void Vector::push_back(int a) {
    if (this->size < this->capacity) {
        this->size++;
        this->values[this->size - 1] = a;
        return;
    }
    reallocate(this->capacity * 2);
    this->push_back(a);
}

void Vector::push_front(int a) {
    if (this->size < this->capacity) {
        this->size++;
        for (int i = this->size - 1; i >= 1; i--) {
            values[i] = values[i - 1];
        }
        values[0] = a;
        return;
    }
    reallocate(this->capacity * 2);
    this->push_front(a);
}

void Vector::extend(int index, Vector & nv) {
    if (index < 0 || index >= this->size)
        throw IndexError();

    reallocate(nv.length() + this->size);
    int old_size = this->size;
    int nv_size = nv.length();
    this->size += nv.length();

    for (int i = index; i < size; i++) {
        this->values[i + nv_size] = this->values[i];
    }

    for (int i = index; i < index + nv_size; i++) {
        this->values[i] = nv[i - index];
    }
}

void Vector::reallocate(int new_size) {
    int * new_values = new int [new_size + 1];
    for (int i = 0; i < this->size; i++) {
        new_values[i] = this->values[i];
    }
    delete[] values;
    this->values = new_values;
    this->capacity = new_size;
}

int & Vector::operator[](int i) {
    if (i >= 0 && i < this->size)
        return this->values[i];
    throw IndexError();
}

int Vector::operator[](int i) const {
    if (i >= 0 && i < this->size)
        return this->values[i];
    throw IndexError();
}

int Vector::length() const {
    return this->size;
}

void Vector::remove(int index) {
    for (int i = index; i < size; i++) {
        this->values[index] = this->values[index + 1];
    }
    size--;
}
