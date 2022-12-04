#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <fstream>

using namespace std;

//Declarqacion de la clase nodo
class Nodo
{ 
 public:   
  Nodo *siguiente;
  string sitio;
  string usuario;
  string contrasenia;
};

//variabels que intereactuan con el nodo y las funciones
string SITIO;
string USUARIO;
string CONTRASENIA;


Nodo *listaContrasenias = NULL;//declaracion de lista
int contadorUsuarios;//contador para saber si hay mas de un usuario en ese sitio

//Declaramos la Funciones
void menu();
void guardarDatosLista(Nodo *&, string, string, string);
string generarContraseniaAleatoria();
void verTodo(Nodo *); 
void consultarSitio(Nodo *);
void serializarLista();

//Solo esta el menu en el main
int main()
{
  menu();
}

void menu()
{
    int opcion;
    
    do
    {
      //El menu que se despliega
    system("cls");
    cout << "\t                                       GESTOR DE CONTRASENIAS\n";
    cout << "\nDigite (1) para guardar datos en la lista" << endl;
    cout << "\nDigite (2) para ver todo" << endl;
    cout << "\nDigite (3) para consultar sitio" << endl;
    cout << "\nDigite (4) para serializar la lista" << endl;

    cin >> opcion;

   
    //Se que se quiere hacer con la lista
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
    //En esta parte almacena los datos ingresados a la lista
    guardarDatosLista(listaContrasenias,SITIO,USUARIO,CONTRASENIA);

    contadorUsuarios ++;

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

    case 4:

    int verificacion;
    cout << "seguro que desea serializar la lista?" << endl << "1.SI" << endl << "2.NO" << endl << ":";

    cin >> verificacion;

      if(verificacion == 1)
      {
         serializarLista();
      }
      else
      {
       return menu();
      }
      
    break;
    //En caso de que no exista la opcion, aparecera este mensaje
    default:
    cout << "opcion invalida" << endl;
    }
    } while(opcion != 5);
}



//En cada funcion insertamos lo que resive y el comportamiento de cada uno.
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
//En esta parte del código se generan las contraseñas aleatorias de longitud variable.
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
//Muestra todos los elemetnos que haya en la lista.
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
//En esta funcion se muestra el usuario y contrasenia de un sitio en concreto y cambiar la contrasenia del mismo, ademas de tener validaciones en caso de que haya mas de un usuario
void consultarSitio(Nodo *listaContrasenias)
{
  system("cls");
  fflush(stdin);
    
  string sitioespecifico,comparacion;
   int opcion, validacion;

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
  cout << "\n" << endl;
  cout << "\tMODIFICAR CONTRASEMIA?" << endl;
  cout << "Digite (1) para si Y Digite (2) para no" << endl << ":";

  cin >> opcion;

    if (opcion == 1)
    {
      if (contadorUsuarios > 1)
      {
        fflush(stdin);
        cout << "A que usuario le va a cambiar la contrasenia?" << endl << ":";
        getline(cin,comparacion);

        while(actual!=NULL)
        {
          if(comparacion == actual->usuario)
          {
               cout << "Digite (1) si quiere una contrasenia manual y Digite (2) para una aleatoria" << endl;
               cin >>  validacion;

               if (validacion == 1)
                {
                 fflush(stdin);
                  cout << endl << "Escriba contrasenia:";
                  getline(cin,CONTRASENIA);
                  actual->contrasenia = CONTRASENIA;
                 cout << "contrasenia modificada "<< endl;
                 }

                else if(validacion == 2)
                 {
                  fflush(stdin);
                 actual->contrasenia = (CONTRASENIA = generarContraseniaAleatoria()) ;
                  cout << "contrasenia modificada "<< endl;
                 }
                actual = actual->siguiente;
          }

          else
          {
            cout << "Usuario no encontrado" << endl;
            return menu();
          }

        }

      }

      else
      {
               cout << "Digite (1) si quiere una contrasenia manual y Digite (2) para una aleatoria" << endl;

               cin >>  validacion;

               if (validacion == 1)
                {
                 fflush(stdin);
                  cout << endl << "Escriba contrasenia:";
                 getline(cin,CONTRASENIA);
                 actual->contrasenia = CONTRASENIA;
                 }
                else if(validacion == 2)
                 {
                  fflush(stdin);
                  actual->contrasenia = (CONTRASENIA = generarContraseniaAleatoria());
                 }
                 cout << "contrasenia modificada "<< endl;

                 return menu();

      }
     
    } 

    else 
    {
      return menu();
    }

     actual = actual->siguiente;
   }
   else
   {  
    cout << "Sitio no encontrado" << endl;
    actual = actual->siguiente;
   }
  }

}
//En esta parte empieza la serializacion de la lista
void serializarLista()
{
   char *buf;
	string SITIO = "abababab";
	string USUARIO= "wjwjwjwjwjwj";
	string CONTRASENIA = "vivivivivivivivi";

	int size1 = (SITIO.size());
	int size2 = (USUARIO.size());
	int size3 = (CONTRASENIA.size());

	ofstream output ("output.txt", ios::app | ios::binary);
	if (!output)
	{
		cout << "can't open file" << endl;
		exit(1);
	}

	output.write(reinterpret_cast<char *>(&size1), sizeof(int));
	output.write(SITIO.c_str(), size1);

	output.write(reinterpret_cast<char *>(&size2), sizeof(int));
	output.write(USUARIO.c_str(), size2);

	output.write(reinterpret_cast<char *>(&size3), sizeof(int));
	output.write(CONTRASENIA.c_str(), size3);

	SITIO = USUARIO = CONTRASENIA = "";
	size1 = size2 = size3 = 0;

	output.flush();
	output.close();
	//=======================================================================
	ifstream input("output.txt", ios::in | ios::binary);
	if (!output)
	{
		cout << "can't open file" << endl;
		exit(1);
	}

	input.read(reinterpret_cast<char *>(&size1), sizeof(int));
	buf = new char[size1];
	input.read( buf, size1);
	SITIO = "";
	SITIO.append(buf, size1);

	input.read(reinterpret_cast<char *>(&size2), sizeof(int));
	buf = new char[size2];
	input.read(buf, size2);
	USUARIO = "";
	USUARIO.append(buf, size2);

	input.read(reinterpret_cast<char *>(&size3), sizeof(int));
	buf = new char[size3];
	input.read(buf, size3);
	CONTRASENIA = "";
	CONTRASENIA.append(buf, size3);

	cout << SITIO << endl << USUARIO << endl << CONTRASENIA << endl << endl;
}