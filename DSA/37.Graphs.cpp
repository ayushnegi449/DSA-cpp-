#include <iostream>
#include <list>
#include <vector>
#include <iterator>

using namespace std;

class edge
{
public:
    int DestinationVertexID;
    int weight;

    edge()
    {
        DestinationVertexID = 0;
        weight = 0;
    }
    edge(int DestVID, int w)
    {
        DestinationVertexID = DestVID;
        weight = w;
    }

    void setDestinationVertexID(int DestVID)
    {
        DestinationVertexID = DestVID;
    }

    void setWeight(int w)
    {
        weight = w;
    }

    int getDestinationVertexID()
    {
        return DestinationVertexID;
    }

    int getWeight()
    {
        return weight;
    }
};

class Vertex
{
public:
    int state_ID;
    string state_name;
    list<edge> edgelist;

    Vertex()
    {
        state_ID = 0;
        state_name = "1";
    }
    Vertex(int SID, string sName)
    {
        state_ID = SID;
        state_name = sName;
    }

    void setStateID(int sID)
    {
        state_ID = sID;
    }
    void setStateName(string sName)
    {
        state_name = sName;
    }

    int getStateID()
    {
        return state_ID;
    }

    string getStateName()
    {
        return state_name;
    }

    list<edge> Getlist()
    {
        return edgelist;
    }
};

class Graph
{
public:
    vector<Vertex> vertices;

    bool checkID(int v)
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices.at(i).getStateID() == v)
            {
                return true;
            }
        }
        return false;
    }

    Vertex getVertexByID(int v)
    {
        Vertex temp;

        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices.at(i).getStateID() == v)
            {
                temp = vertices.at(i);
                return temp;
            }
        }
    }

    bool checkEdge(int v1, int v2)
    {
        Vertex v = getVertexByID(v1);
        list<edge> e;
        e = v.Getlist();

        for (auto el = e.begin(); el != e.end(); el++)
        {
            if (el->getDestinationVertexID() == v2)
            {
                return true;
            }
        }
        return false;
    }

    void addEdge(int fromV1, int toV2, int w)
    {

        bool check1 = checkID(fromV1);
        bool check2 = checkID(toV2);

        if (check1 && check2)
        {
            bool check3 = checkEdge(fromV1, toV2);

            if (fromV1 == toV2)
            {
                cout << "Cannot create a link between same vertex : " << fromV1 << endl;
            }

            else if (check3)
            {
                cout << "Edge already exists between Vertex : (" << getVertexByID(fromV1).getStateName() << "," << fromV1 << ") & " << getVertexByID(toV2).getStateName() << "," << toV2 << ")\n";
            }

            else
            {
                for (int i = 0; i < vertices.size(); i++)
                {
                    if (vertices.at(i).getStateID() == fromV1)
                    {
                        edge e1(toV2, w);
                        vertices.at(i).edgelist.push_back(e1);
                    }
                    else if (vertices.at(i).getStateID() == toV2)
                    {
                        edge e2(fromV1, w);
                        vertices.at(i).edgelist.push_back(e2);
                    }
                }
                cout << "Edge created between " << fromV1 << " and " << toV2 << endl;
            }
        }
        else
        {
            if (!check1)
            {
                cout << "Vertex : (" << fromV1 << ") does not exists!\n";
            }
            else if (!check2)
            {
                cout << "Vertex : (" << toV2 << ") does not exists!\n";
            }
        }
    }

    void addVertex(Vertex v)
    {
        if (checkID(v.getStateID()))
        {
            cout << "Same id exists!\n";
        }
        else
        {
            vertices.push_back(v);
            cout << "Vertex successfully added!\n";
        }
    }

    void printListElements(Vertex v)
    {
        cout << "[";
        for (auto i = v.edgelist.begin(); i != v.edgelist.end(); i++)
        {
            cout << i->getDestinationVertexID() << "(" << i->getWeight() << ") --> ";
        }
        cout << "]\n";
    }

    void printGraph()
    {

        for (int i = 0; i < vertices.size(); i++)
        {
            Vertex v;

            v = vertices.at(i);
            cout << v.getStateName() << " (" << v.getStateID() << ") --> ";
            printListElements(v);
        }
    }

    void updateEdge(int v1, int v2, int w)
    {
        if (checkEdge(v1, v2))
        {
            for (int i = 0; i < vertices.size(); i++)
            {
                if (vertices.at(i).getStateID() == v1)
                {
                    for (auto it = vertices.at(i).edgelist.begin(); it != vertices.at(i).edgelist.end(); it++)
                    {
                        if (it->getDestinationVertexID() == v2)
                        {
                            it->setWeight(w);
                            break;
                        }
                    }
                }
                else if (vertices.at(i).getStateID() == v2)
                {
                    for (auto it = vertices.at(i).edgelist.begin(); it != vertices.at(i).edgelist.end(); it++)
                    {
                        if (it->getDestinationVertexID() == v1)
                        {
                            it->setWeight(w);
                            break;
                        }
                    }
                }
            }
            cout << "Edge updated succesfully!\n";
        }
        else
        {
            cout << "Edge does not exist between : " << v1 << " and " << v2 << endl;
        }
    }

    void DeleteEdge(int v1, int v2)
    {
        if (checkEdge(v1, v2))
        {
            for (int i = 0; i < vertices.size(); i++)
            {
                if (vertices.at(i).getStateID() == v1)
                {
                    for (auto it = vertices.at(i).edgelist.begin(); it != vertices.at(i).edgelist.end(); it++)
                    {
                        if (it->getDestinationVertexID() == v2)
                        {
                            vertices.at(i).edgelist.erase(it);
                            break;
                        }
                    }
                }
                else if (vertices.at(i).getStateID() == v2)
                {
                    for (auto it = vertices.at(i).edgelist.begin(); it != vertices.at(i).edgelist.end(); it++)
                    {
                        if (it->getDestinationVertexID() == v1)
                        {
                            vertices.at(i).edgelist.erase(it);
                            break;
                        }
                    }
                }
            }
            cout << "Edge Deleted succesfully!\n";
        }
        else
        {
            cout << "Edge does not exist between : " << v1 << " and " << v2 << endl;
        }
    }

    void deleteVertex(int v)
    {

        int i = 0;
        for (int j = 0; j < vertices.size(); j++)
        {
            if (vertices.at(j).getStateID() == v)
            {
                i = j;
                break;
            }
        }

        int elem = vertices.at(i).edgelist.size();
        for (int l = 0; l < elem; l++)
        {
            auto it = vertices.at(i).edgelist.begin();
            DeleteEdge(v, it->getDestinationVertexID());
        }

        vertices.erase(vertices.begin() + i);
        cout << "vertex deleted successfully!\n";
    }

    void updateVertex(int v, string newname)
    {
        if (checkID(v))
        {
            for (auto it = vertices.begin(); it != vertices.end(); it++)
            {
                if (it->getStateID() == v)
                {
                    it->setStateName(newname);
                    break;
                }
            }
            cout << "Vertex Data changed successfully!\n";
        }
        else
        {
            cout<<"Vertex with ID : "<<v<<" does not exist!\n";
        }
    }

    void getAllNeigborsByID(int vid)
    {
        cout << getVertexByID(vid).getStateName() << " (" << getVertexByID(vid).getStateID() << ") --> ";
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices.at(i).getStateID() == vid)
            {
                cout << "[";
                for (auto it = vertices.at(i).edgelist.begin(); it != vertices.at(i).edgelist.end(); it++)
                {
                    cout << it->getDestinationVertexID() << "(" << it->getWeight() << ") --> ";
                }
                cout << "]";
            }
        }
    }
};
int main()
{
    Graph g;
    int stateID, option, fromV, toV, w;
    string state_name;
    Vertex v1;

    do
    {
        cout << "\nWhat operation do you want to perform? "
             << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Add Vertex" << endl;
        cout << "2. Update Vertex" << endl;
        cout << "3. Delete Vertex" << endl;
        cout << "4. Add Edge" << endl;
        cout << "5. Update Edge" << endl;
        cout << "6. Delete Edge" << endl;
        cout << "7. Check if 2 Vertices are Neigbors" << endl;
        cout << "8. Print All Neigbors of a Vertex" << endl;
        cout << "9. Print Graph" << endl;
        cout << "10. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cout << "Enter your option : ";
        cin >> option;
        cout << "\n";
        switch (option)
        {
        case 0:

            break;

        case 1:
        {
            cout << "Add vertex:\nEnter the State id:";
            cin >> stateID;
            cout << "Enter the state Name :";
            cin >> state_name;
            v1.setStateID(stateID);
            v1.setStateName(state_name);
            g.addVertex(v1);
        }

        break;

        case 2:
            cout << "Enter the vertex ID to change :";
            cin >> fromV;
            cout << "Enter the new Data : ";
            cin >> state_name;
            g.updateVertex(fromV, state_name);
            break;

        case 3:
            cout << "enter the id of the vertex to be deleted :";
            cin >> fromV;
            g.deleteVertex(fromV);

            break;

        case 4:
        {
            cout << "Enter the Source ID :\n";
            cin >> fromV;
            cout << "Enter the Destination ID :\n";
            cin >> toV;
            cout << "Enter the weight :\n";
            cin >> w;
            g.addEdge(fromV, toV, w);
            cout << "\n";

            break;
        }

        case 5:
        {
            cout << "Enter the source Id to be updated :";
            cin >> fromV;
            cout << "Enter the destination id to be updated :";
            cin >> toV;
            cout << "Enter the new edge distance : ";
            cin >> w;
            g.updateEdge(fromV, toV, w);
            cout << "\n";
            break;
        }

        case 6:
        {
            cout << "Enter the source id to be deleted :";
            cin >> fromV;
            cout << "Enter the destination id to be deleted :";
            cin >> toV;
            g.DeleteEdge(fromV, toV);

            break;
        }

        case 7:
        {
            cout << "Check if 2 Vertices are Neigbors -" << endl;
            cout << "Enter ID of Source Vertex(State): ";
            cin >> fromV;
            cout << "Enter ID of Destination Vertex(State): ";
            cin >> toV;
            bool check = g.checkEdge(fromV, toV);
            if (check == true)
            {
                cout << "Vertices are Neigbors (Edge exist)";
            }
            else
            {
                cout << "Vertices are NOT Neigbors (Edge does NOT exist)";
            }

            break;
        }
        case 8:
            cout << "Print All Neigbors of a Vertex -" << endl;
            cout << "Enter ID of Vertex(State) to fetch all Neigbors : ";
            cin >> fromV;
            g.getAllNeigborsByID(fromV);
            break;

        case 9:
            cout << "Printing graph :\n";
            g.printGraph();

            break;

        default:
            break;
        }
    } while (option != 0);

    return 0;
}