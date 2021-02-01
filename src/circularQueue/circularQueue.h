#ifndef QUEUE_H
#define QUEUE_H

template <typename T, int N>
class Queue
{
private:
    T arr[N];
    unsigned int size;
    unsigned int front;
    unsigned int rear;

public:
    Queue()
    {
        rear = -1;
        front = -1;
        size = N;
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

    bool isFull()
    {
        if ((rear + 1) % N == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    unsigned int count()
    {
        if (!(isEmpty()))
        {
            return rear - front + 1;
        }
        else
        {
            return 0;
        }
    }

    void enqueue(T val)
    {
        if (this->isFull())
        {
        }
        else if (this->isEmpty())
        {
            rear = front = 0;
        }
        else
        {
            rear = (rear + 1) % N;
        }
        arr[rear] = val;
    }

    T denqueue()
    {
        T x = 0;
        if (isEmpty())
        {
            return;
        }
        else if (front == rear)
        {
            x = arr[front];
            front = rear = -1;
        }
        else
        {
            x = arr[front];
            front = (front + 1) % N;
        }
        return x;
    }
};

#endif // QUEUE_H