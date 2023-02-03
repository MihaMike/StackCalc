// =====================================
// One task on the StackCalc project
// (C) rdmr, 2k6
// Unautorized Duplication Appreciated!
// =====================================

//
// Stack of real numbers, implementation
//
#include "RealStack.h"

RealStack::RealStack():
    stack(0),
    max_size(STACK_MAXSIIZE),
    size(0)
{
    stack = new double[max_size];
}

RealStack::RealStack(int maxSize):
    stack(0),
    max_size(maxSize),
    size(0)
{
    stack = new double[max_size];
}

void RealStack::push(double x) throw (StackException) {
    if (size >= max_size)
        throw StackException("Stack overflow");
    stack[size] = x;
    size++;
}

double RealStack::pop() throw (StackException) {
    if (size == 0)
        throw StackException("Stack empty");
    double x = stack[size - 1];
    size--;
    return x;
}

double RealStack::top() const throw (StackException) {
    if (size == 0)
        throw StackException("Stack empty");
    return stack[size - 1];
}

int RealStack::depth() const {
    return size;
}

void RealStack::init() {
    size = 0;
}

bool RealStack::empty() const {
    return (size == 0);
}

double RealStack::elementAt(int i) const {
    if (i >= size)
        throw StackException("Out of bounds");
    return stack[size - 1 - i];
}
