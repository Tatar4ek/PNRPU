#pragma once
#include <iostream>

class Object {
public:
    Object () {};
    ~Object () {};
    virtual void print() = 0;
};