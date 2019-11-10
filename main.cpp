#include "Graph/Graph.hpp"

// Driver program to test above function 
int main() 
{ 
    // Let us first create and test graphs shown in above figure 
    Graph g1(5);

    g1.addEdge(0, 1);
    g1.addEdge(1, 1);  
    g1.addEdge(1, 2); 
    g1.addEdge(1, 4); 
    g1.addEdge(1, 2);
    g1.addEdge(4, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    g1.addEdge(0, 4);
    
    g1.printEulerTour(); 

    return 0; 
} 