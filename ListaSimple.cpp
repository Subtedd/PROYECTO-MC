#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>

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
string generarContraseniaAleatoria();
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
    int validacion;
    fflush(stdin);
     cout << "Escriba el sitio:";
     getline(cin,SITIO);
     cout << endl << "Escriba usuario:";
     getline(cin,USUARIO);
     cout << "Digite (1) si quiere una contrasenia manual y Digite (2) para una aleatoria" << endl;
    cin >>  validacion;
    if (validacion == 1)
    {
      fflush(stdin);
      cout << endl << "Escriba contrasenia:";
     getline(cin,CONTRASENIA);
    }
    else if(validacion == 2)
    {
      fflush(stdin);
      CONTRASENIA = generarContraseniaAleatoria();
    }
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

string generarContraseniaAleatoria()
{
  int numeroAleatorio;
  char letra;
  string contraseniaAleatoria;

   srand(time(0));

   numeroAleatorio = 6+(rand() % 10);

   for(int i=0; i<= numeroAleatorio; i++)
   {
    for(int j=0; i<= numeroAleatorio; i++)
    {
      letra = 97 + rand() % (122-97);
      contraseniaAleatoria += letra;
    }
   }
   
   return contraseniaAleatoria;
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
