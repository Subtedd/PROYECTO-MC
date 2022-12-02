#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

struct Nodo{
 Nodo *siguiente;
 int dato;
};


Nodo *lista = NULL;
int dato;
void menu();
void insertarlista(Nodo *&,int);
void eliminarnodo(Nodo *&,int);
void buscarlista(Nodo *,int);
void mostrarlista(Nodo *);
void eliminarlista(Nodo *&,int &);

int main(){
 
 menu();
 
 getch();
 return 0;
}

void menu(){
 int opc;
 do{
  cout<<"\t.:MENU:.\n";
  cout<<"\n1. Insertar Dato."<<endl;
  cout<<"\n2. Buscar un Dato."<<endl;
  cout<<"\n3. Mostrar todos los Datos."<<endl;
  cout<<"\n4. Eliminar un Dato."<<endl;
  cout<<"\n5. Eliminar todos los Datos."<<endl;
  cout<<"\n6. Salir.\n"<<endl;
  cin>>opc;
  
  system("cls");
  
  switch(opc){
   case 1: cout<<"Escriba un Dato: ";
   cin>>dato;
   insertarlista(lista,dato);
   cout<<"\n";
   system("pause");
   break;
   
   case 2: cout<<"Escriba el Dato que desea buscar: ";
   cin>>dato;
   buscarlista(lista,dato);
   cout<<"\n";
   system("pause");
   break;
   
   case 3: cout<<"Mostrando los Datos de la lista\n"<<endl;
   mostrarlista(lista);
   cout<<"\n"<<endl;
   system("pause");
   break;
   
   case 4: cout<<"Escriba el Dato que quiere eliminar de la lista: ";
   cin>>dato;
   eliminarnodo(lista,dato);
   cout<<"\n";
   system("pause");
   break;
   
   case 5: eliminarlista(lista,dato);
   cout<<"\n";
   system("pause");
   break;
   
   case 6: break;
   }
  system("cls");
  }while(opc != 6);
 }

void insertarlista(Nodo *&lista,int n){
 Nodo *nuevo_nodo = new Nodo();
  nuevo_nodo->dato = n;
  nuevo_nodo->siguiente = NULL;
 
  Nodo *pem1 = lista;
  Nodo *pem2 ;
 
 while((pem1!=NULL)&&(pem1->dato<n)){
  pem2 = pem1;
  pem1 = pem1->siguiente;
  }
 
 if(lista == pem1){
  lista = nuevo_nodo;
 }
 
 else{
  pem2->siguiente = nuevo_nodo;
 }
 
  nuevo_nodo->siguiente = pem1;
  cout<<endl<<"El Dato: "<<n<<" se agrego a la Lista."<<endl;
}

void eliminarnodo(Nodo *&lista,int n){
 if(lista!=NULL){
  cout<<endl<<"El Dato se borro de la Lista"<<endl;
   Nodo *pem_borrar;
   Nodo *anterior = NULL;
    pem_borrar = lista;
  
  while((pem_borrar!=NULL)&&(pem_borrar->dato != n)){
   anterior = pem_borrar;
    pem_borrar =pem_borrar->siguiente;
  }
  
  if(pem_borrar == NULL){
   cout<<endl<<"EL Dato no se encuentra en la Lista"<<endl;
  }
  
  else if(anterior == NULL){
   lista =lista->siguiente;
   delete pem_borrar;
  }
  
  else{
   anterior->siguiente = pem_borrar->siguiente;
   delete pem_borrar; 
  }
 }
}

void buscarlista(Nodo *lista,int n){
 Nodo *actual = new Nodo();
 actual = lista;
 bool band = false;
 
 while((actual!=NULL)&&(actual->dato <= n)){
  if(actual->dato == n){
   band = true;
  }
  
  actual = actual->siguiente;
 }
if(band == true){
  cout<<endl<<"El Dato "<<n<<" se encuentra en la Lista."<<endl;
 }
 
 else{
  cout<<endl<<"El Dato "<<n<<" NO se encuentra en la lista."<<endl;
 }
}

void mostrarlista(Nodo *lista){
 Nodo *actual = lista;
 
 while(actual!=NULL){
  cout<<actual->dato<<" -> ";
  actual = actual->siguiente;
 }
}

void eliminarlista(Nodo *&lista,int &n){
 char opc;
 
 cout<<"Esta seguro de eliminar todos los Datos de la lista (Y/N): ";
 cin>>opc;
 
 if(((opc == 'Y')||(opc == 'y')))
 
 while(lista != NULL){
 Nodo *pem = lista;
 n = pem->dato;
 lista = pem->siguiente;
 delete pem;
 }
 
 if(((opc == 'Y')||(opc == 'y'))){
  cout<<endl<<"Todos los Datos de la lista han sido eliminados.\n"<<endl;
 }
 
 else{
  cout<<endl<<"Volviendo al Menu.\n"<<endl;
 }
}