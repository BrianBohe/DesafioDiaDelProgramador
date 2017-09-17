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
int combinaciones[tope][tope];
vector<int> lista_de_primos;

void criba(){
	memset(primos, true, sizeof(primos) );

	primos[0] = primos[1] = false;

	for (int i = 4; i < tope; i+=2)
		primos[i] = false;

	for (int i = 3; i*i <= tope; i+=2){
		if(primos[i]){
			for (int p = i*i; p < tope; p+=2*i)
				primos[p] = false;
		}
	}

	for(int i = 0; i < tope; i++)
		if (primos[i]) lista_de_primos.push_back(i);
}



int main(int argc, char* argv[]){
	ios::sync_with_stdio(false);

	criba();

	for(int x : lista_de_primos)
		cout << x << "\n";

	return 0;
}