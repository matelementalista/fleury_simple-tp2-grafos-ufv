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

    class Graph 
    { 
        private:
            unsigned int V;
            list<int> *adj; 
        public:  
            Graph(string filename); 
            ~Graph();

            void addEdge(int u, int v);
            void rmvEdge(int u, int v); 
            void printEulerTour(); 
            void printEulerUtil(int s); 
            int DFSCount(int v, bool visited[]); 
            bool isValidNextEdge(int u, int v); 
            bool isEulerian();
    };

#endif