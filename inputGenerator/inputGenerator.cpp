#include "inputGenerator.hpp"

void inputGeneratorCreateNewGraph(unsigned int edg, unsigned int arr, string filename){
    ofstream out(inputpath + filename);
    unsigned int x, y;

    out << edg;

    srand(time(NULL));

    for (size_t i = 0; i < arr; i++) {
        x = rand() % edg +1;
        y = rand() % edg +1;

        out << endl << (x) << " " << (y);
        out << endl << (y) << " " << (x);
    }

    out.close();
}