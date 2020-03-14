#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class AVLTree
{

};

class AVLNode
{

};

class BTree
{

};
template <class Number>
class UserMenu
{
    public:
        int choiceMainMenu = 0;
        int choiceOptionMenu = 0;
        int numberOfElements = 1; //Se declara numero de elementos como 1 para no tener nunca un arbol vacio
        vector<Number> numbers;

        void UserInteraction()
        {
            do
            {
                cout<<"1) Arbol AVL     2) Arbol B     3) Terminar Programa"<<endl;
                cin>>choiceMainMenu;
                if(choiceMainMenu == 3)
                {
                    break;
                }
                cout<<"Introducir el numero de elementos deseados a ser manejados por el arbol: 10, 100, 1000, 10000, 100000, 1000000 o cualquier otro numero"<<endl;
                cin>>numberOfElements;
                for(int i = 0; i<numberOfElements; i++)
                {
                    int numberToBeAdded = rand() % 10000000 + 1;
                    numbers.push_back(numberToBeAdded);
                }
                do
                {
                    cout<<"1) Buscar Elemento en arbol     2) Eliminar completamente el arbol      3) Regresar a Menu Principal"<<endl;
                    cin>>choiceOptionMenu;
                }
                while(choiceOptionMenu!=3);
            }
            while(choiceMainMenu!=3);  
        }
};

int main()
{
    UserMenu <int> uS;
    //uS.UserInteraction();
    return 0;
}