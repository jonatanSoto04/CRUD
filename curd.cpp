#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
  int numero;
  struct nodo *sgte;
};

typedef struct nodo *tlista;

void insertInicio(tlista &lista, int valor){
    tlista q;
    q = new(struct nodo);
    q->numero = valor;
    q->sgte = lista;
    lista = q;
}

void buscarElemento(tlist &lista, int valor){
    tlista q = lista;
    int i = 0, band = 0;
    while(q!=NULL){
        if(q->numero==valor){
            cout<<i<<endl;
            band = 1;
        }
        q = q->sgte;
        i++;
    }
    if(band == 0){
        cout<<"el valor no fue encontrado"<<endl;
    }
}
void eliminarNodo(tlista &lista, int valor) {
  tlista aux = lista;
  tlista anterior = NULL;
  while (aux != NULL && aux->numero != valor) {
    anterior = aux;
    aux = aux->sgte;
  }
  if (aux != NULL) {
    if (anterior == NULL) {
      lista = aux->sgte;
    } else {
      anterior->sgte = aux->sgte;
    }
    free(aux);
  }
}
void actualizarNodo(tlista &lista, int valor, int nuevoValor) {
  tlista aux = lista;
  while (aux != NULL && aux->numero != valor) {
    aux = aux->sgte;
  }
  if (aux != NULL) {
    aux->numero = nuevoValor;
  }
}
int main() {
    tlist list;
    int _dato, innumero;
    
    while(accion != 0){
        cout<<"Que accion desea hacer"<<endl;
        cout<<" 1. Eliminar"<<endl;
        cout<<" 2. Actualizar"<<endl;
        cout<<" 3. Insertar"<<endl;
        cout<<" 4. Buscar"<<endl;
        cout<<" 0. Salir"<<endl;
        cout<<"NOTA: ingrese un valor numerico valido"<<endl;
        cin >> accion;
        if(accion != 0){
            if(accion == 1){
                cout<<"Que numero desea eliminar: "<<endl; cin>>innumero;
                eliminarNodo(lista, inumero);
            }else if(accion == 2){
                cout<<"Que numero desea actualizar: "<<endl; cin>>innumero;
                int canum;
                cout<<"Por cual numero lo desea cambiar: "<<endl; cin>>canum;
                actualizarNodo(lista, innumero, canum);
            }else if(accion == 3){
                cout<<"Que numero desea  insertar: "<<endl; cin>>innumero;
                    insertInicio(lista, innumero);
            }else if(accion == 4){
                cout<<"Que numero desea buscar: "<<endl; cin>>innumero;
                buscarElemento(lista, innumero);
            }else{
                cout<<"La opcion selecionada no existe"<<endl; 
            }
        }
        
    }
        
    return 0;
}
