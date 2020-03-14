#include <iostream>

using namespace std;

void UserMenu()
{
    int choice = 0;
    int numberOfElements = 1; //Se declara numero de elementos como 1 para no tener nunca un arbol vacio

    do
    {
        cout<<"1) Arbol AVL     2) Arbol B     3) Terminar Programa"<<endl;
        cin>>choice;
        if(choice == 3)
        {
            break;
        }
        cout<<"Introducir el numero de elementos deseados a ser manejados por el arbol: 10, 100, 1000, 10000, 100000, 1000000 o cualquier otro numero"<<endl;
        cin>>numberOfElements;
    }
    while(choice!=3);
}

int main()
{
    UserMenu();
    return 0;

}