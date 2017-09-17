#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>

#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001

typedef long long tint;

using namespace std;

#define tope 11501
bool primos[tope];
__int128 combinaciones[2][tope];
vector<int> lista_de_primos;


int main(int argc, char* argv[]){
	ios::sync_with_stdio(false);

	memset(primos,false,sizeof(primos));
	int lenght,aux;
	cin>>lenght;
	while(lenght--){
		cin >> aux;
		primos[aux] = true;
		lista_de_primos.push_back(aux);
	}

	int swap_row = 0;
	combinaciones[0][0] = combinaciones[1][0] = 1;

	for (int p=0; p< lista_de_primos.size(); p++){
		swap_row^=1;
		//Aca no puedo cambiar nada lo copio
		//cout << lista_de_primos[p] << "," << 1;
		for(int i = 1; i < lista_de_primos[p]; i++){
			combinaciones[swap_row][i] = combinaciones[swap_row^1][i];
			//cout << "," << combinaciones[swap_row][i];
		}

		//Aca puedo llegar a hacer algo
		for (int i =lista_de_primos[p]; i < tope; i++){
			//if(0 < combinaciones[swap_row^1][i-lista_de_primos[p]])
				//cout << i<<"=" << i-lista_de_primos[p] << "+" << lista_de_primos[p] << "\n";
			combinaciones[swap_row][i] = combinaciones[swap_row^1][i] + combinaciones[swap_row^1][i-lista_de_primos[p]];
			//cout << "," << combinaciones[swap_row][i];
			if(combinaciones[swap_row][i] < 0){
				cout << "overflow en indice " << i << " con primo " << lista_de_primos[p]<< "\n";
			}
		}
		//cout <<"\n";
	}

	primos[0] = true;
	__int128 acum=0;
	for(int i =0; i < tope; i++){
		if ( acum < 0 ){
			cout << "overflow en indice " << i << "\n";
			acum = 0;
		}
		//cout << "formas del " << i << " " << combinaciones[swap_row][i]<< "\n";
		acum += combinaciones[swap_row][i] - primos[i];
	}

	//cout << acum << "\n";
	return 0;
}