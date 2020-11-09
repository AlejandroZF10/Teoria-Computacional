#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm> 
#include <string.h>
using namespace std;

void Information();
void InsertGram();
void Renomabramiento(vector<vector<string> > prod); 
void vacia (vector<vector<string> > prod, vector<int> eps);
void ImprimirGram (vector <vector<string> > prod);
void VaciaAux(vector <vector <string> > &prod, string cadena, int x, int indice);
void Inaccesible(vector <vector <string > > prod);


int main (){
	int opcion;
	cout << "Practica 5 - Alejandro Zepeda Flores\n" << endl;
	cout << "1.-  Lista de especificaciones" << endl;
	cout << "2.-  Nueva gramatica libre de contexto " << endl;
	cout << "3.-  Salir del programa " << endl;
	cout << "Opcion: " << endl;	cin  >> opcion;
	switch(opcion){
		case 1: Information(); break;
		case 2: InsertGram(); break;
		case 3: exit(0); break;
		default: main();
	}
	return 0;
}
void Information(){
	system("cls");
	int opcion;
	cout << "INFORMACION \n "<< endl;
	cout << "SOLO se aceptaran 4 proyecciones (S, A ,B ,C) con el siguiente formato:\n" << endl;
	cout << "\t" << "S => Aab | B | Csa" << endl;
	cout << "\t" << "A => aA | cb | ABc" << endl; 
	cout << "\t" << "B => CG | DC " << endl;
	cout << "\t" << "C => C\n" << endl;
	cout << "En caso de utilizar el operador ""|"" debe haber espacios"  << endl;
	cout << "Se utilizara "" E "" para denotar EPSILON \n" << endl;
	cout << "Presiona 1 para continuar  -> ";
	cin  >> opcion; system("cls");
	switch(opcion){
		case 1: main(); break;
		default: Information();
	}
}
void InsertGram(){
	system("cls");
	int cant, ind;
	cout << "Gramatica libre de contexto para limpiar"<< endl;
	string nueva;
	vector <vector<string> > prod;
	vector <int> eps;
	prod.push_back( vector <string> () );
	prod.push_back( vector <string> () );
	prod.push_back( vector <string> () );
	prod.push_back( vector <string> () );

// SE PREPARA EL PORGRAMA PARA INGRESAR TODAS LAS PRODUCCIONES DE S 
	cout << "\nPROYECCIONES PARA ""S""  " << endl;
	cout << "Numero de proyeciones :> ";  cin >> cant;
	for(int i =0; i< (cant+(cant-1)); i++){
		cin >> nueva;
		if (nueva != "|" &&  nueva != "E")
			prod[0].push_back(nueva);

		if (nueva == "E")
			prod[0].push_back(nueva);

	}
// SE PREPARA EL PORGRAMA PARA INGRESAR TODAS LAS PRODUCCIONES DE A
	cout << "\n\nPROYECCIONES PARA ""A""  " << endl;
	cout << "Numero de proyecciones :> ";  cin >> cant;
	for(int i =0; i< (cant+(cant-1)); i++){
		cin >> nueva;
		if (nueva != "|" &&  nueva != "E")
			prod[1].push_back(nueva);

		if (nueva == "E"){
			eps.push_back(1);
		}
	}
// SE PREPARA EL PORGRAMA PARA INGRESAR TODAS LAS PRODUCCIONES DE B 

	cout << "\n\nPROYECCIONES PARA ""B""  " << endl;
	cout << "Numero de proyecciones :> ";  cin >> cant;
	for(int i =0; i<(cant+(cant-1)); i++){
		cin >> nueva;
		if (nueva != "|" &&  nueva != "E")
			prod[2].push_back(nueva);
		if (nueva == "E"){
			eps.push_back(2);
		}
	}
// SE PREPARA EL PORGRAMA PARA INGRESAR TODAS LAS PRODUCCIONES DE C

	cout << "\n\nPROYECCIONES PARA ""C""  " << endl;
	cout << "Numero de proyecciones :> ";  cin >> cant;
	for(int i =0; i<(cant+(cant-1)); i++){
		cin >> nueva;
		if (nueva != "|" &&  nueva != "E")
			prod[3].push_back(nueva);

		if (nueva == "E"){
			eps.push_back(3);
		}
	}
if(eps.size() != 0)
vacia(prod,eps);
else
	Inaccesible(prod);
}
void Inaccesible(vector <vector <string > > prod){
	vector <int> visit (3,-1);
	int indice;
	cout << prod[0][1] << " " << strlen(prod[0][1].c_str()) << endl;
	int bandera;
	int cant;
	for(int i=0 ; i<prod.size(); i++)		
		for(int j=0; j<prod[i].size(); j++){
			bandera = 0;
			for(int k=0; k < strlen(prod[i][j].c_str()) ; k++){
				if(prod[i][j][k] >= 'D' && prod[i][j][k] <= 'Z' && prod[i][j][k] != 'S'){
					prod[i].erase(prod[i].begin()+j);
					j--;
					break;
				}
				if(prod[i][j][k] == 'A' || prod[i][j][k] == 'B' || prod[i][j][k] == 'C'  ){
					indice = (prod[i][j][k])-65;
					if(visit[indice] == -1)
						visit[indice] = 1;
				}
			}
		}
	if(visit[0] == -1)
		prod.erase(prod.begin()+1);
	if(visit[1] == -1)
		prod.erase(prod.begin()+2);
	if(visit[2] == -1)
		prod.erase(prod.begin()+3);
	
	Renomabramiento(prod);
}
void ImprimirGram (vector <vector <string> > prod){
	cout << "\n\nI M P R E S I O N   D E   L A    G  R  A  M  A  T  I  C  A    L I M P I A"<< endl;
	cout << "\n" << endl;
	for(int i=0; i<prod.size(); i ++){
		if(i == 0)
			cout << "S -> ";
		if(i == 1)
			cout << "A -> ";
		if(i == 2)
			cout << "B -> ";
		if(i == 3)
			cout << "C -> ";

		for(int j=0; j<prod[i].size(); j++){
			fflush(stdout);
			cout << prod[i][j] ;
			if(prod[i].size() > 1 && j != (prod[i].size()-1))
				cout << " | ";
		}
		cout << "\n" << endl;
	}
	system("pause"); system("cls"); main();
}
void vacia (vector <vector <string> > prod, vector <int> eps){
	int len = eps.size();
 	for (int i=0; i < len; i++){
 	 	for(int j=0; j<prod.size(); j++)
 			for (int k=0; k<prod[j].size(); k++)
 				VaciaAux (prod,prod[j][k], eps.back(),j);
 		eps.pop_back();
 	}
 	Renomabramiento(prod);
}
void VaciaAux(vector <vector <string> > &prod, string cadena, int x, int indice){
	string cadAux,cadAux1;
	int newindice = cadena.find(64+x);
	if(newindice <= strlen(cadena.c_str())){
		cadAux = cadena;
		cadAux.erase(cadAux.begin()+newindice);
		prod[indice].push_back(cadAux);
		cadAux = cadAux1;
	}	
}
void Renomabramiento(vector<vector<string> > prod){
	int indice;
	for(int i=0; i<prod.size(); i++){
		for(int j=0; j<prod[i].size(); j++){
			if(prod[i][j] == "A"  && strlen(prod[i][j].c_str()) == 1){
				prod[i].erase(prod[i].begin()+j);
				for(int k=0; k<prod[1].size(); k++)
					prod[i].push_back(prod[1][k]);
			}
			if(prod[i][j] == "B" && strlen(prod[i][j].c_str())== 1){
				prod[i].erase(prod[i].begin()+j);
				for(int k=0; k<prod[2].size(); k++)
					prod[i].push_back(prod[2][k]);
			}
			if(prod[i][j] == "C" && strlen(prod[i][j].c_str()) == 1){
				prod[i].erase(prod[i].begin()+j);
				for(int k=0; k<prod[3].size(); k++)
					prod[i].push_back(prod[3][k]);
			}
		}
	}
	if(prod[1].size() == 1 && prod[1][0][0] >= 97  && prod[1][0][0]<=122)
		prod.erase(prod.begin()+1);
	if(prod[2].size() == 1 && prod[2][0][0]>= 97  && prod[2][0][0]<=122)
		prod.erase(prod.begin()+2);
	if(prod[3].size() == 1 && prod[3][0][0] >= 97  && prod[3][0][0]<=122)
		prod.erase(prod.begin()+3);

	ImprimirGram(prod);
}

