#include <iostream>
#include <stdlib.h>

using namespace std;

class Nodo
{
 public:   
  Nodo *siguiente;
  string sitio;
  string usuario;
  string contrasenia;
};

string SITIO;
string USUARIO;
string CONTRASENIA;


Nodo *listaContrasenias = NULL;

void menu();
void guardarDatosLista(Nodo *&, string, string, string);
string verTodo(Nodo *); 

int main()
{

}

void menu()
{
    int opcion;
    
    do
    {
    cout << "\t                                       GESTOR DE CONTRASENIAS\n";
    cout << "\n1.Guardar datos en la lista" << endl;
    cout << "\n2.Ver todo" << endl;
    cin >> opcion;

    }while(opcion != 3);

    system("cls");

    switch (opcion)
    {
    case 1:
     cout << "Escriba el sitio:";
     cin >> SITIO;
     cout << endl << "Escriba usuario:";
     cin >> USUARIO;
     cout << endl << "Escriba contrasenia:";
     cin >> CONTRASENIA;

     guardarDatosLista(listaContrasenias,SITIO,USUARIO,CONTRASENIA);

    cout<<"\n";
   system("pause");
    break;
    
    default:
        break;
    }
}



void guardarDatosLista(Nodo *&listaContrasenias, string SitiO, string UsuariO, string ContraseniA)
{
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->sitio = SitiO;
    nuevoNodo->usuario = UsuariO;
    nuevoNodo->contrasenia = ContraseniA;
    nuevoNodo->siguiente = NULL;
}

string verTodo(Nodo *listaContrasenias)
{
  Nodo *actual = listaContrasenias;

  while(actual!=NULL)
  {
   cout << "sitio:" << actual->sitio << endl;
   actual = actual->siguiente;
  }

}