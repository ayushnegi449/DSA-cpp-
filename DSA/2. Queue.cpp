/*What is Queue Data Structure ? | Queue Operations & Working | C++ Program to Implement Queue Operations

Definition –
Queue is a linear data structure which operates in a First IN First OUT or Last IN Last OUT.
It is named queue as it behaves like a real-world queue, for example – queue(line) of cars in a single lane,
queue of people waiting at food counter etc.
Queue is an abstract data type with a bounded (predefined) capacity.
It is a simple data structure that allows adding and removing elements in a particular order.
The order is FIFO(First IN First OUT) or LILO(Last In Last Out).
queue data structure diagram

Standard Queue Operations –
Enqueue() – Add item to the queue from the REAR.
Dequeue() – Remove item from the queue from the FRONT.
isFull() – Check if queue is full or not.
isEmpty() – Check if queue empty or not.
count() – Get number of items in the queue.
Some types of Queue (We will discuss them in detail in other articles)-
Simple Queue
Circular Queue
Priority Queue
Some Applications of Queue Data Structure –
Queue is used when things but have to be processed in First In First Out order. Like –

CPU scheduling, Disk Scheduling.
Handling of interrupts in real-time systems. The interrupts are handled in the same order as they arrive,
First come first served.
In real life, Call Center phone systems will use Queues, to hold people calling them in an order,
until a service representative is free.
When data is transferred asynchronously between two processes. Queue is used for synchronization.


Program Code for Queue Data Structure in C++ Programming –*/

#include <iostream>
#include <string>

using namespace std;

class queue
{

private:
    int front, rear;
    int arr[5];

public:
    queue()
    {
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
        if (rear == 4)
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
            rear++;
            arr[rear] = val;
        }
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
            front++;
            return x;
        }
    }

    void count()
    {
        cout << "The number of item(s) in queue are : " << ((rear - front) + 1) << "\n\n";
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
    queue q;
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
