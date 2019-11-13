using namespace std;
#include "Graph/Graph.hpp"
#include "inputGenerator/inputGenerator.hpp"

void showMenu()
{
    cout << "--------------------------------------------------" << endl;
    cout << "          TP2 de Grafos - Ciclo de Euler          " << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "1 - Abrir arquivo e mostrar ciclo" << endl;
    cout << "2 - Gerar grafo euleriano aleatorio em arquivo" << endl;
    cout << endl;
    cout << "9 - Sair" << endl;
    cout << "--------------------------------------------------" << endl;
 }

int main() 
{ 
    string filename;
    char selection = 'a';
    string selectionAux;
    Graph * graph;
    unsigned int edg, arr;

    showMenu();

    while (1)
    {
        
        while(1){
            try
            {
                getline(cin, selectionAux, '\n');
                selection = selectionAux[0];
                break;
            }
            catch(const std::exception& e)
            {
                cout << "Digite um valor válido!" << endl;
            }
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

        case '2':
            cout << "Digite o nome do arquivo. Ele ficara na pasta input:" << endl;
            getline(cin, filename, '\n');

            cout << "Digite a quantidade de vertices:" << endl;

            while(1){
                try
                {
                    getline(cin, selectionAux, '\n');
                    edg = stoul(selectionAux);
                    break;
                }
                catch(const std::exception& e)
                {
                    cout << "Digite um valor válido!" << endl;
                }
            }

            cout << "Digite a quantidade de arestas (precisa ser um numero par):" << endl;
            while(1) {
                try
                {
                    getline(cin, selectionAux, '\n');
                    arr = stoul(selectionAux)/2;
                    break;
                }
                catch(const std::exception& e)
                {
                    cout << "Digite um valor válido!" << endl;
                }
            }

            inputGeneratorCreateNewGraph(edg, arr, filename);
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