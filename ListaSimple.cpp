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
