#ifndef STACK_H
#define STACK_H

/*
    We should not keep the definition of class methods in header file.
    Because, it may be included in several places and hence compiled
    more than once.
    So, we keep declarations in header files and definitions in cpp files
    using scope resolution operator Stack::funcName()

    But in case of template class.
    Template get compiled only when we give there types
    So, keeping definition in header file is fine.
    We can't keep the definition in cpp file, because, we don't know the type before hand and 
    hence cpp file will not compile. Result will give reference error
*/

template <typename T, int N>
class Stack
{
private:
    unsigned int top;
    unsigned int size;
    T arr[N];

public:
    Stack()
    {
        top = -1;
        size = N;
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (top == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //push operation
    void push(T val)
    {
        if (this->isFull())
        {
            std::cout << "Stack overflow" << std::endl;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }

    // pop operation
    T pop()
    {
        if (this->isEmpty())
        {
            std::cout << "Stack underflow" << std::endl;
            return -1;
        }
        else
        {
            T popValue = arr[top];
            arr[top] = 0;
            top--;
            return popValue;
        }
    }

    // count operation
    unsigned int count()
    {
        return top + 1;
    }

    T peek(unsigned int pos)
    {
        if (pos <= top && !(this->isEmpty()))
        {
            return arr[pos];
        }
        else
        {
            std::cout << "Stack underflow" << std::endl;
            return -1;
        }
    }

    void change(unsigned int pos, T val)
    {
        if (!(this->isEmpty()) && pos <= top)
        {
            arr[pos] = val;
        }
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            std::cout << arr[i] << std::endl;
        }
    }
};

#endif // STACK_H