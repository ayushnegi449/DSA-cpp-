/*Circular Queue Data Structure | C++ Program to Implement Circular Queue Operations

Circular Queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and
the last position is connected back to the first position to make a circle. It is also called ‘Ring Buffer’. 
It is a type of Queue data structure which overcomes some drawback of the simple queue data structure.
In a Linear queue, once the queue is completely full, it’s not possible to insert more elements.
Even if we dequeue the queue to remove some of the elements, until the queue is reset, no new elements can be inserted. You must be wondering why?

simple queue ds drawback :
When we dequeue any element to remove it from the queue, we are actually moving the front of the queue forward, 
thereby reducing the overall size of the queue. And we cannot insert new elements, because the rear pointer is still at the end of the queue. 
The only way is to reset the linear queue, for a fresh start.

simple queue data structure drawbacks

Standard Queue Operations – 
Enqueue() – Add item to the queue from the REAR.
Dequeue() – Remove item from the queue from the FRONT.
isFull() – Check if queue is full or not.
isEmpty() – Check if queue empty or not.
count() – Get number of items in the queue.
A simple modification in the exist simple queue data structure algorithm/code can convert it into a circular queue data structure.

Program Code for Queue Data Structure in C++ Programming –*/


#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
        next = NULL;
    }
};

class Queue
{
public:
    Node *front;
    Node *rear;

    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = front;
        do
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        } while (ptr != front);

        return temp;
    }

    void enqueue(Node *n)
    {
        if (isEmpty())
        {
            front = n;
            rear = n;
            rear->next = n;
            cout << "\nValue successfully enqueued as the front value!\n\n";
        }
        else if (nodeExists(n->key) != NULL)
        {
            cout << "\nNode already exists with the same key value !\n\n";
        }
        else
        {
            Node *temp = rear;
            rear = n;
            temp->next = n;
            n->next = front;
            cout << "\nValue successfully enqueued!\n\n";
        }
    }

    Node *dequeue()
    {
        Node *temp = NULL;
        if (isEmpty())
        {
            cout << "Queue is empty !\n";
            return temp;
        }
        else if (front == rear)
        {
            temp = front;
            front = NULL;
            rear = NULL;
            return temp;
        }
        else
        {
            temp = front;
            front = front->next;
            rear->next = front;
            return temp;
        }
    }

    int count()
    {
        int count = 0;
        Node *ptr = front;

        if (front == NULL)
        {
            return count;
        }
        else
        {
            do
            {
                count++;
                ptr = ptr->next;
            } while (ptr != front);

            return count;
        }
    }

    void display()
    {
        Node *ptr = front;
        cout << "\nThe queue is :\n";
        do
        {
            cout << "(" << ptr->key << "," << ptr->data << "," << ptr->next << ")->";
            ptr = ptr->next;
        } while (ptr != front);
        cout << "(Front:" << ptr << "," << ptr->key << "," << ptr->data << ")\n";
    }
};
int main()
{
    Queue q;
    int option, key, data;

    do
    {
        cout << "What operation do you want to perform? "
             << "Select Option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. count()" << endl;
        cout << "5. display()" << endl;
        cout << "6. Clear Screen" << endl
             << endl;
        cout << "Enter the option number : ";
        cin >> option;

        // Node n1 = new Node();
        Node *new_node = new Node();

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "\nENQUEUE Function Called -" << endl;
            cout << "Enter KEY and VALUE of NODE to ENQUEUE in the Queue"
                 << endl;
            cin >> key;
            cin >> data;
            new_node->key = key;
            new_node->data = data;
            q.enqueue(new_node);
            break;
        case 2:
            cout << "DEQUEUE Function Called - " << endl;
            new_node = q.dequeue();
            cout << "Dequeued Value is: (" << new_node->key << ","
                 << new_node->data << ")";
            delete new_node;
            cout << endl;

            break;
        case 3:
            cout << "isEmpty Function Called - " << endl;
            if (q.isEmpty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queue is NOT Empty" << endl;
            break;
        case 4:
            cout << "Count Function Called - " << endl;
            cout << "No of nodes in the Queue: " << q.count()
                 << endl;
            break;
        case 5:
            cout << "Display Function Called - " << endl;
            q.display();
            cout << endl;
            break;

        case 6:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}