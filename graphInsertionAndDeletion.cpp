// API to add elements  and list out the graph elements
// Author : Amit Sagar
// Dated: 01/05/2018
#include <iostream>
#include <map>
#include<vector>
using namespace std;

class Vertex
{
    public:
    Vertex(int d)
    {
        data = d;
    }
    int data;
};
template <class T>
class Graph
{
    map<T* , vector<T*>> m;
    bool m_isOrderedGraph;
    bool addEdgeForOrderedMap(T* v1 , T* v2)
    {
        if(v1 && v2)
        {
            m[v1].push_back(v2);
            return true;
        }
        return false;
    }
    bool addEdgeForUnOrderedMap(T* v1 , T* v2)
    {
        if(v1 && v2)
        {
            m[v1].push_back(v2);
            m[v2].push_back(v1);
            return true;
        }
        return false;
    }
public:
    Graph(bool orderedGraph = true): m_isOrderedGraph(orderedGraph)
    {
    }
    bool addEdgeBetween(T* v1, T* v2)
    {
        if(m_isOrderedGraph)
            return addEdgeForOrderedMap(v1,v2);
        else
            return addEdgeForUnOrderedMap(v1,v2);
    }
    void printGraph();
};

template<class T>
void Graph<T>::printGraph()
{
        // To Do: Need to use BFS or DFS
        typename map<T*,vector<T*>>::iterator t;
        t = m.begin();
        while(t != m.end())
        {
            cout<< "origin _vertex " <<static_cast<Vertex*>(t->first)->data;
            vector<T*> tmp = t->second;
            typename vector<T*>::iterator it2 = tmp.begin();
            cout<< " and child vertex ";
            while(it2 != tmp.end())
            {
                cout<< (*it2)->data << " ";
                it2++;
            }
            cout<<endl;
            t++;
        }
}

int main()
{
    Graph<Vertex> g1;
    Vertex v1(10);
    Vertex v2(20);
    Vertex v3(30);
    Vertex v4(40);
    Vertex v5(50);
    Vertex v6(60);
    Vertex v7(70);
    Vertex v8(80);
    Vertex v9(90);
    Vertex v10(95);
    g1.addEdgeBetween(&v1,&v2);
    g1.addEdgeBetween(&v2,&v3);
    g1.addEdgeBetween(&v3,&v4);
    g1.addEdgeBetween(&v5,&v6);
    g1.addEdgeBetween(&v7,&v8);
    g1.addEdgeBetween(&v9,&v10);
    g1.addEdgeBetween(&v7,&v9);
    g1.addEdgeBetween(&v1,&v6);
    g1.addEdgeBetween(&v1,&v7);
    g1.addEdgeBetween(&v7,&v10);
    g1.addEdgeBetween(&v3,&v5);
    g1.printGraph();
}
