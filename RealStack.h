// =====================================
// One task on the StackCalc project
// (C) rdmr, 2k6
// Unautorized Duplication Appreciated!
// =====================================

//
// Stack of real numbers
//
#ifndef REAL_STACK_H
#define REAL_STACK_H

#pragma warning (disable: 4290) 

const int STACK_MAXSIIZE = 1024;

class StackException
{
public:
    const char *reason;
    StackException(): reason("") {}
	StackException(const char *cause):reason(cause) {}
};

class RealStack
{
private:
    double* stack;
    int max_size;
    int size;
public:
    RealStack();
    RealStack(int maxSize);
    void push(double) throw (StackException);
    double pop() throw (StackException);
    double top() const throw (StackException);
    int depth() const;
    void init();
    bool empty() const;
    double elementAt(int i) const;
};

#endif
