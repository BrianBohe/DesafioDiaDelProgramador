#include <iostream>
#include <vector>
#include <set>
#include <string.h>

using namespace std;

// Ya se que la imagen es de 700x997 con pixeles de 8bitx
#define ancho 700
#define alto 997 
unsigned char imagen[alto][ancho];
int cant_apariciones_del_pixel_i[260];
int margen_izq,margen_sup;

void cantidad_de_pixeles_distintos(){
	for (int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++) {
			cant_apariciones_del_pixel_i[imagen[i][j]]++;
		}
	}
	int cantidad_distitnos = 0;
	
	int cant_apariciones_pixel_mas_frecuente=0;
	char pixel_mas_frecuente=0;

	for(int i = 0; i < 260; i++ ){
		if( cant_apariciones_del_pixel_i[i] ){

			if ( cant_apariciones_pixel_mas_frecuente < cant_apariciones_del_pixel_i[i] ){
				pixel_mas_frecuente = i;
				cant_apariciones_pixel_mas_frecuente = cant_apariciones_del_pixel_i[i];
			}

			cout << "pixel " << i <<  " veces " << cant_apariciones_del_pixel_i[i] << "\n";
			cantidad_distitnos++;
		}
	}
	cout << "Pixel más repetido " << (static_cast<int>(pixel_mas_frecuente) & 0xFF) << " cantidad " << cant_apariciones_pixel_mas_frecuente << "\n";
	cout << "Cantidad de pixeles distintos " <<  cantidad_distitnos << "\n";
}

void calcular_margen_sup_izq(){
	bool toque_algo_no_blanco=false;
	int i =0, j=0;
	for (; i < alto && !toque_algo_no_blanco; i++) {
		for (; j < ancho && !toque_algo_no_blanco; j++) {
			
			if ( !imagen[i][j] )
				toque_algo_no_blanco=true;

		}
	}
	margen_izq = j;
	margen_sup = i;
}

int calcular_margen_sup(){
	return margen_sup;
}
int calcular_margen_izq(){
	return margen_izq;
}

int main(){
	ios::sync_with_stdio(false);
	char pixel;
	int margen_izq=0,margen_der=0;

	for (int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++) {
			cin >> pixel;
			cout << (static_cast<unsigned int>(pixel) & 0xFF) << " ";
			imagen[i][j] = pixel;

			//cout << imagen[i][j] << " ";
		}
		cout << "\n";
	}

	//cantidad_de_pixeles_distintos();
	//calcular_margen_sup_izq();
	//cout << "margen_izq " << calcular_margen_izq() << "\n";
	//cout << "margen_izq " << calcular_margen_sup() << "\n";
	return 0;
}