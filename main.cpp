using namespace std;
#include "Graph/Graph.hpp"

void showMenu()
{
    cout << "-------------------------------------" << endl;
    cout << "     TP2 de Grafos - Ciclo de Euler  " << endl;
    cout << "-------------------------------------" << endl;
    cout << "1 - Abrir arquivo e mostrar ciclo" << endl;
    cout << endl;
    cout << "9 - Sair" << endl;
    cout << "-------------------------------------" << endl;
 }

int main() 
{ 
    string filename;
    char selection = 'a';
    string selectionAux;
    Graph * graph;

    showMenu();

    while (1)
    {
        
        try
        {
            getline(cin, selectionAux, '\n');
            selection = selectionAux[0];
        }
        catch(const std::exception& e)
        {
            cout << "Digite um valor válido!" << endl;
        }
        
        switch (selection)
        {

        case '0':
            showMenu();
            break;

        case '1':
            cout << "Digite o nome do arquivo. Ele deve estar na pasta input:" << endl;

            try
            {
                getline(cin, filename, '\n');
                
                graph = new Graph(filename);

                if(graph->isEulerian()){
                    graph->printEulerTour();
                } else {
                    cout << "Grafo inserido nao euleriano!" << endl;
                }
            }
            catch(const std::exception& e)
            {
                cout << "Erro! Arquivo não existente!" << endl;
            }

            break;

        case '9':
            cout << "Obrigado por usar!" << endl;
            return 0;
            break;
        
        default:
            cout << "Digite um valor válido!" << endl;
            break;
        }

        cout << "Digite 0 para mostrar o menu novamente" << endl;
    }

    return 0; 
} 