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
void verTodo(Nodo *); 

int main()
{
  menu();

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

    system("cls");

    switch (opcion)
    {
    case 1:
    fflush(stdin);
     cout << "Escriba el sitio:";
     getline(cin,SITIO);
     cout << endl << "Escriba usuario:";
     getline(cin,USUARIO);
     cout << endl << "Escriba contrasenia:";
     getline(cin,CONTRASENIA);

     guardarDatosLista(listaContrasenias,SITIO,USUARIO,CONTRASENIA);

    cout<<"\n";
   system("pause");
    break;
    
    case 2:
    verTodo(listaContrasenias);
    cout<<"\n"<<endl;
    system("pause");
    break;
    }

    }while(opcion != 3);
}



void guardarDatosLista(Nodo *&listaContrasenias, string SitiO, string UsuariO, string ContraseniA)
{
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->sitio = SitiO;
    nuevoNodo->usuario = UsuariO;
    nuevoNodo->contrasenia = ContraseniA;
    nuevoNodo->siguiente = NULL;

    Nodo *pem1 = listaContrasenias;
    Nodo *pem2;

    while(pem1!=NULL)
    {
      pem2 = pem1;
      pem1 = pem1->siguiente;
    }

     if(listaContrasenias == pem1){
  listaContrasenias = nuevoNodo;
 }
 
 else{
  pem2->siguiente = nuevoNodo;
 }
 nuevoNodo->siguiente = pem1;
  cout<<endl<<"El sitio, usuario y contrasenia se agregaron correctamente a la Lista."<<endl;
}

void verTodo(Nodo *listaContrasenias)
{
  Nodo *actual = listaContrasenias;

  while(actual!=NULL)
  {
   cout << "sitio:" << actual->sitio << endl;
   actual = actual->siguiente;
  }

}