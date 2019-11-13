#include "Graph.hpp"

Graph::Graph(int V)
{
    this->V = V; 
    adj = new list<int>[V];
}

Graph::~Graph()
{
    delete [] adj;
}

Graph::Graph(string filename)
{
    int swap0, swap1;
    fstream in(inputpath + filename);

    if (!in)
    {
        throw exception();
    }
    

    in >> this->V;
    adj = new list<int>[V];

    while (!in.eof())
    {
        in >> swap0;
        in >> swap1;

        addEdge((swap0-1), (swap1-1));
    }

    in.close();
    
}

void Graph::printEulerTour() 
{ 
    int u = 0; 
    for (int i = 0; i < V; i++) 
        if (adj[i].size() & 1) 
            { u = i; break; } 
 
    cout << (u+1) << " "; 
    printEulerUtil(u); 
    cout << endl; 
} 
 
void Graph::printEulerUtil(int u) 
{ 
    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = *i; 

        
        if (v != -1 && isValidNextEdge(u, v)) 
        {  
            cout << (v+1) << " "; 
            rmvEdge(u, v); 
            printEulerUtil(v); 
        } 
    } 
} 

bool Graph::isValidNextEdge(int u, int v) 
{ 
    int count = 0; 
    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        if (*i != -1) 
            count++; 
    if (count == 1) 
        return true; 

    bool visited[V]; 
    memset(visited, false, V); 
    int count1 = DFSCount(u, visited); 
 
    rmvEdge(u, v); 
    memset(visited, false, V); 
    int count2 = DFSCount(u, visited); 
 
    addEdge(u, v); 

    return (count1 > count2)? false: true; 
} 

void Graph::rmvEdge(int u, int v) 
{
    list<int>::iterator iv = find(adj[u].begin(), adj[u].end(), v); 
    *iv = -1; 

    list<int>::iterator iu = find(adj[v].begin(), adj[v].end(), u); 
    *iu = -1; 
} 

int Graph::DFSCount(int v, bool visited[]) 
{ 
    visited[v] = true; 
    int count = 1; 

    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (*i != -1 && !visited[*i]) 
            count += DFSCount(*i, visited); 

    return count; 
}

bool Graph::isEulerian()
{
    list<int>::iterator j; 
    int order;

    for (int i = 0; i < V; i++)
    {
        order = 0;
        for (j = adj[i].begin(); j != adj[i].end(); ++j) 
        {
            if (*j != -1) 
                order++; 
        }
        if(order%2!=0) return false;
    }

    return true;   
}