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

Nodo *listaContrasenias = NULL;

void guardarDatosLista(Nodo *&, string, string, string);
string verTodo(Nodo *); 

int main()
{

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
