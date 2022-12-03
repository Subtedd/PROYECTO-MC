#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <string.h>

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
void consultarSitio(Nodo *);


int main()
{
  menu();

}

void menu()
{
    int opcion;
    
    do
    {
    system("cls");
    cout << "\t                                       GESTOR DE CONTRASENIAS\n";
    cout << "\nDigite (1) para guardar datos en la lista" << endl;
    cout << "\nDigite (2) para ver todo" << endl;
    cout << "\nDigite (3) para consultar sitio" << endl;

    cin >> opcion;

   

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
   cout << "sitio,usuario y contrasenia guardados" << endl;
    cout<<"\n";
   system("pause");
    break;
    
    case 2:
    verTodo(listaContrasenias);
    cout<<"\n"<<endl;
    system("pause");
    break;
    
    case 3:
    consultarSitio(listaContrasenias);
    cout << "\n" << endl;
    system ("pause");
    break;
    }
    } while(opcion != 4);
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

  if(listaContrasenias == pem1)
  {
  listaContrasenias = nuevoNodo;
  }
 
 else
 {
  pem2->siguiente = nuevoNodo;
 
 nuevoNodo->siguiente = pem1;
 }
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
  system("cls");
  Nodo *actual = listaContrasenias;
  
  if(actual == NULL)
  {
   cout << "No hay elemntos para mostrar" << endl; 
  }
  else
  {
   while(actual!=NULL)
   {
   cout << "sitio:" << actual->sitio << endl;
   actual = actual->siguiente;
   }
  }
  
  
}

void consultarSitio(Nodo *listaContrasenias)
{
  system("cls");
    fflush(stdin);
    string sitioespecifico;
    cout << "Escribe el nombre del sitio para saber el usuario y contrasenia:" << endl;
    getline (cin, sitioespecifico);

    Nodo *actual = listaContrasenias;

  while(actual!=NULL)
  {
   if (sitioespecifico == actual->sitio)
   {
    cout << "SITIO ENCONTRADO" << endl;
    cout <<"Los datos del sitio son:" << endl;
    cout << "usuario:" << actual->usuario << endl;
    cout << "contrasenia:" << actual->contrasenia << endl;
    actual = actual->siguiente;
    cout << endl; 
   }
   else
   {  
    cout << "Sitio no encontrado" << endl;
    actual = actual->siguiente;
   }
  }

}