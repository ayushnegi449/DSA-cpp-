/*Circular Queue Data Structure | C++ Program to Implement Circular Queue Operations
Circular Queue is a linear data structure in which the operations are performed based on FIFO(First In First Out) principle
and the last position is connected back to the first position to make a circle.
It is also called ‘Ring Buffer’. It is a type of Queue data structure which overcomes some drawback of the simple queue
data structure.
In a Linear queue, once the queue is completely full, it’s not possible to insert more elements.
Even if we dequeue the queue to remove some of the elements, until the queue is reset, no new elements can be inserted.
You must be wondering why?

simple queue ds drawback

When we dequeue any element to remove it from the queue, we are actually moving the front of the queue forward,
thereby reducing the overall size of the queue. And we cannot insert new elements,
because the rear pointer is still at the end of the queue. The only way is to reset the linear queue, for a fresh start.

simple queue data structure drawbacks

Standard Queue Operations –
Enqueue() – Add item to the queue from the REAR.
Dequeue() – Remove item from the queue from the FRONT.
isFull() – Check if queue is full or not.
isEmpty() – Check if queue empty or not.
count() – Get number of items in the queue.
A simple modification in the exist simple queue data structure algorithm/code can convert it into a circular queue data
structure.

Program Code for Queue Data Structure in C++ Programming –*/

#include <bits/stdc++.h>

using namespace std;

class circular_queue
{

private:
    int front, rear;
    int arr[5];
    int itemCount;

public:
    circular_queue()
    {
        itemCount = 0;
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
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
        if ((rear + 1) % 5 == front) // 5 means dividing by the size.
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is full ! \n\n";
            return;
        }
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
            arr[rear] = val;
        }
        else
        {
            rear = (rear + 1) % 5;
            arr[rear] = val;
        }
        itemCount++;
    }

    int dequeue()
    {
        int x = 0;
        if (isEmpty())
        {
            cout << "Queue is empty ! \n\n";
            return x;
        }

        else if (rear == front)
        {
            x = arr[rear];
            arr[rear] = 0;
            rear = -1;
            front = -1;

            return x;
        }
        else
        {
            cout << "front value: " << front << endl;
            x = arr[front];
            arr[front] = 0;
            front = (front + 1) % 5;

            return x;
        }
        
        itemCount--;
    }

    void count()
    {
        cout << "The number of item(s) in queue are : " << itemCount << "\n\n";
    }

    void display()
    {
        cout << "All values in the queue are : \n";
        for (int i = 0; i < 5; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    circular_queue q;
    int option, value;

    do
    {
        cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl
             << endl;

        cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter the value you want to add to the queue : ";
            cin >> value;
            q.enqueue(value);
            cout << "\n\n";

            break;

        case 2:
            cout << "dequeue operation called.....\nDequeued value is : " << q.dequeue() << "\n\n";
            break;

        case 3:
            if (q.isEmpty())
            {
                cout << "Queue is empty !\n\n";
            }
            else
            {
                cout << "Queue is not empty !\n\n";
            }
            break;

        case 4:
            if (q.isFull())
            {
                cout << "Queue is full!\n\n";
            }
            else
            {
                cout << "Queue is not full!\n\n";
            }
            break;

        case 5:
            q.count();
            break;

        case 6:
            q.display();
            break;

        case 7:
            system("cls");
            break;

        default:
            cout << "Enter correct choice !";
            break;
        }
    } while (option != 0);

    return 0;
}
