#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

template <typename T>
class Node
{
public:
    int key;
    T data;
    Node<T> *next;

public:
    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, T d)
    {
        key = k;
        data = d;
        next = NULL;
    }
};

template <typename T>
class SinglyLinkedList
{
private:
    Node<T> *head;

public:
    SinglyLinkedList()
    {
        head = NULL;
    }

    SinglyLinkedList(Node<T> *n)
    {
        head = n;
    }

    Node<T> *nodeExists(int k)
    {
        Node<T> *temp = NULL;
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
                break;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    void appendNode(Node<T> *n)
    {
        if (nodeExists(n->key) == NULL)
        {
            if (head == NULL)
            {
                head = n;
            }
            else
            {
                Node<T> *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
            }
        }
    }

    void prependNode(Node<T> *n)
    {
        if (nodeExists(n->key) == NULL)
        {
            if (head == NULL)
            {
                head = n;
            }
            else
            {
                n->next = head;
                head = n;
            }
        }
    }

    void insertNodeAfter(int k, Node<T> *n)
    {
        if (nodeExists(n->key) == NULL)
        {
            Node<T> *ptr = nodeExists(k);
            if (ptr != nullptr)
            {
                n->next = ptr->next;
                ptr->next = n;
            }
        }
    }

    void deleteNode(int k)
    {
        if (head != nullptr)
        {
            if (head->key == k)
            {
                head = head->next;
            }
            else
            {
                Node<T> *temp = nullptr;
                Node<T> *prevptr = head;
                Node<T> *currentptr = head->next;
                while (currentptr != nullptr)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = nullptr;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }

                if (temp != nullptr)
                {
                    prevptr->next = temp->next;
                }
            }
        }
    }

    void updateNodeByKey(int k, T d)
    {
        Node<T> *ptr = nodeExists(k);
        if (ptr != nullptr)
        {
            ptr->data = d;
        }
    }

    void printList()
    {
        if (head != nullptr)
        {
            Node<T> *temp = head;
            while (temp != nullptr)
            {
                std::cout << "{ " << temp->key << ", " << temp->data << " }" << std::endl;
                temp = temp->next;
            }
        }
    }
};

#endif // SINGLYLINKEDLIST_H