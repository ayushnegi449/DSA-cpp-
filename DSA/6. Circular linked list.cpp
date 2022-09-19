/*Circular Linked List Data Structure all Operations | C++ Program to Implement Circular Linked List

Singly linked list is a type of Linked List Data structure which behaves
like a one way list/chain. The reason it is called a one way list or one way chain
is because we can only traverse this list in one direction, start from the head node
to the end. However unlike Singly Linked List in this type of linked list we can
traverse from the last node to the first in a circular one directional pattern.

WORKING
Each node object has 1 data field & 1 pointer field.
The data field contains the actual data where as the pointer field(next pointer)
points to the next node in the singly linked list.Since the nodes are not stored in
contiguous memory locations, this extra pointer field assists in locating the
next node in memory. As we have only one pointer pointing to the next node,
we can only traverse in one direction starting from the head node to the end.
However unlike singly linked list, the last node in this circular linked list is
storing address of the first head node. Thus you can traverse back from the last
node to the first node.

Following are the standard Circular Linked List Operations –
1.Traverse – Iterate through the nodes in the linked list starting from the head node.
2.Append – Attach a new node (to the end) of a list
3.Prepend – Attach a new node (to the beginning) of the list
4.Insert – attach a new node to a specific position on the list
5.Delete – Remove/Delink a node from the list
6.Count – Returns the no of nodes in linked list


C++ Program to Implement Circular Linked List – */

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key, data;
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
    }
};

class CircularLinkedList
{
public:
    Node *head;

    CircularLinkedList()
    {
        head = NULL;
    }

    CircularLinkedList(Node *n)
    {
        head = n;
    }

    // 1.Checking if the node exists with the key value entered by the user
    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;

        if (ptr == NULL)
        {
            return temp;
        }
        else
        {
            do
            {
                if (ptr->key == k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            } while (ptr != head);

            return temp;
        }
    }

    // 2.Appending node
    void appendNode(Node *new_node)
    {
        if (nodeExists(new_node->key) != NULL)
        {
            cout << "Node exists with the same key " << new_node->key
                 << " please try again with a different key "
                 << endl;
        }
        else
        {
            // appending as head
            if (head == NULL)
            {
                head = new_node;
                new_node->next = head;
                cout << "Node succesfully appended as head" << endl;
            }   

            // appending other than head
            else
            {
                Node *ptr = head;

                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = new_node;
                new_node->next = head;

                cout << "Node Appended!" << endl;
            }
        }
    }

    // 3. Prepend Node - Atach node at he starting of the node
    void prependNode(Node *new_node)
    {
        if (nodeExists(new_node->key) != NULL)
        {
            cout << "Node exists with the same key " << new_node->key
                 << " please try again with a different key "
                 << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = new_node;
                new_node->next = head;
                cout << "Node succesfully prepended as head" << endl;
            }
            else
            {
                Node *ptr = head;

                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }

                ptr->next = new_node;
                new_node->next = head;
                head = new_node;
                cout << "Node succesfully prepended" << endl;
            }
        }
    }

    // 4. Insert a Node after a particular node in the list
    void insertNodeAfter(int k, Node *new_node)
    {
        Node *ptr = nodeExists(k);

        if (ptr == NULL)
        {
            cout << "No Node exists with the key value : " << k << endl;
        }
        else
        {
            if (nodeExists(new_node->key) != NULL)
            {
                cout << "Node already exists with the key value : " << new_node->key
                     << " , Please append another node with different key value!"
                     << endl;
            }
            else
            {
                if (ptr->next == head)
                {
                    new_node->next = head;
                    ptr->next = new_node;
                    cout << "Node inserted at the end" << endl;
                }
                else
                {
                    new_node->next = ptr->next;
                    ptr->next = new_node;
                    cout << "Node successfully inserted in between" << endl;
                }
            }
        }
    }

    // 5. Delete node by unique key
    void deleteNodeByKey(int k)
    {
        Node *ptr = nodeExists(k);

        if (ptr == NULL)
        {
            cout << "The key your entered does not exist, please try again with a different key" << endl;
        }
        else
        {
            if (ptr == head)
            {
                if (head->next == head)
                {
                    head = NULL;
                    cout << "Head node successfully unlinked ! Key value : " << k << endl;
                }
                else
                {
                    Node *ptr1 = head;
                    while (ptr1->next != head)
                    {
                        ptr1 = ptr1->next;
                    }
                    ptr1->next = head->next;
                    head = head->next;

                    cout << "Node successfully unlinked ! Key value : " << k << endl;
                }
            }
            else
            {
                Node *temp = NULL;
                Node *prevptr = head;
                Node *currentptr = head->next;
                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                prevptr->next = temp->next;
                cout << "Node Unlinked with key value : " << k << endl;
            }
        }
    }

    void updateNodeByKey(int k, int d)
    {
        Node *ptr = nodeExists(k);

        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Data successfully updated at key value " << k << endl;
        }
        else
        {
            cout << "No node exits with such key value , please try again with a different key " << endl;
        }
    }
    // void updateNodeByKey(int k, int d)
    // {
    //     Node *ptr = nodeExists(k);
    //     if (head == NULL)
    //     {
    //         cout << "linked list is empty"<<endl;
    //     }
    //     else
    //     {
    //         if (ptr == NULL)
    //         {
    //             cout << "No data exists for key value : "<<K<<endl;
    //         }
    //         else
    //         {
    //             ptr->data = d;
    //             cout<<"data updated successfully"<<endl;
    //         }
    //     }
    // }

    void printList()
    {
        if (head == NULL)
        {
            cout << "Circular linked list is empty!" << endl;
        }
        else
        {
            cout << "Circular Linked List head address " << head << " and values : " << endl;

            Node *temp = head;
            do
            {
                cout << "(" << temp->key << "," << temp->data << "," << temp->next << ") --> ";
                temp = temp->next;
            } while (temp != head);
        }
    }
};

int main()
{

    CircularLinkedList obj;
    int option;
    int key1, k1, data1;
    do
    {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. updateNodeByKey()" << endl;
        cout << "6. print()" << endl;
        cout << "7. Clear Screen" << endl
             << endl;

        cin >> option;
        Node *n1 = new Node();
        // Node n1;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.appendNode(n1);
            // cout<<n1.key<<" = "<<n1.data<<endl;
            break;

        case 2:
            cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.prependNode(n1);
            break;

        case 3:
            cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
            cin >> k1;
            cout << "Enter key & data of the New Node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;

            obj.insertNodeAfter(k1, n1);
            break;

        case 4:

            cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
            cin >> k1;
            obj.deleteNodeByKey(k1);

            break;
        case 5:
            cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
            cin >> key1;
            cin >> data1;
            obj.updateNodeByKey(key1, data1);

            break;
        case 6:
            obj.printList();

            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}
