#if !defined(GRAPH)
#define GRAPH

    // A C++ program print Eulerian Trail in a given Eulerian or Semi-Eulerian Graph 
    #include <iostream>
    #include <fstream>
    #include <string.h> 
    #include <algorithm> 
    #include <exception>
    #include <list> 

    #include "../constants.hpp"

    using namespace std; 

    // A class that represents an undirected graph 
    class Graph 
    { 
        private:
            int V; // No. of vertices 
            list<int> *adj; // A dynamic array of adjacency lists 
        public: 
        
            // Simple Constructor and destructor 
            Graph(int V); 
            ~Graph(); 

            // Constructor for fileread
            Graph(string filename);

            // functions to add and remove edge 
            void addEdge(int u, int v) { adj[u].push_back(v); adj[v].push_back(u); } 
            void rmvEdge(int u, int v); 

            // Methods to print Eulerian tour 
            void printEulerTour(); 
            void printEulerUtil(int s); 

            // This function returns count of vertices reachable from v. It does DFS 
            int DFSCount(int v, bool visited[]); 

            // Utility function to check if edge u-v is a valid next edge in 
            // Eulerian trail or circuit 
            bool isValidNextEdge(int u, int v); 

            // Check if is eulerian
            bool isEulerian();
    };

#endif // GRAPH