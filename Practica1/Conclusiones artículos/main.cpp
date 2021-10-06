#include "rijndael.hpp"

using namespace std;

int main (void)
{
	// CBC

	cout << endl;
  cout << "                             ----------           " << endl;
  cout << " <--------------------------| MODO CBC |--------------------------> " << endl;
  cout << "                             ----------   " << endl << endl;

	vector<vector<unsigned char>> clave(4, vector<unsigned char>(4));

	clave[0][0] = 0x00;
	clave[1][0] = 0x01;
	clave[2][0] = 0x02;
	clave[3][0] = 0x03;
	clave[0][1] = 0x04;
	clave[1][1] = 0x05;
	clave[2][1] = 0x06;
	clave[3][1] = 0x07;
	clave[0][2] = 0x08;
	clave[1][2] = 0x09;
	clave[2][2] = 0x0A;
	clave[3][2] = 0x0B;
	clave[0][3] = 0x0C;
	clave[1][3] = 0x0D;
	clave[2][3] = 0x0E;
	clave[3][3] = 0x0F;

	vector<vector<unsigned char>> clave_anterior(4, vector<unsigned char>(4));

	clave_anterior[0][0] = 0x00;
	clave_anterior[1][0] = 0x00;
	clave_anterior[2][0] = 0x00;
	clave_anterior[3][0] = 0x00;
	clave_anterior[0][1] = 0x00;
	clave_anterior[1][1] = 0x00;
	clave_anterior[2][1] = 0x00;
	clave_anterior[3][1] = 0x00;
	clave_anterior[0][2] = 0x00;
	clave_anterior[1][2] = 0x00;
	clave_anterior[2][2] = 0x00;
	clave_anterior[3][2] = 0x00;
	clave_anterior[0][3] = 0x00;
	clave_anterior[1][3] = 0x00;
	clave_anterior[2][3] = 0x00;
	clave_anterior[3][3] = 0x00;

	vector<vector<vector<unsigned char>>> textos(2, vector<vector<unsigned char>>(4, vector<unsigned char>(4)));

	textos[0][0][0] = 0x00;
	textos[0][1][0] = 0x11;
	textos[0][2][0] = 0x22;
	textos[0][3][0] = 0x33;
	textos[0][0][1] = 0x44;
	textos[0][1][1] = 0x55;
	textos[0][2][1] = 0x66;
	textos[0][3][1] = 0x77;
	textos[0][0][2] = 0x88;
	textos[0][1][2] = 0x99;
	textos[0][2][2] = 0xAA;
	textos[0][3][2] = 0xBB;
	textos[0][0][3] = 0xCC;
	textos[0][1][3] = 0xDD;
	textos[0][2][3] = 0xEE;
	textos[0][3][3] = 0xFF;

	textos[1][0][0] = 0x00;
	textos[1][1][0] = 0x00;
	textos[1][2][0] = 0x00;
	textos[1][3][0] = 0x00;
	textos[1][0][1] = 0x00;
	textos[1][1][1] = 0x00;
	textos[1][2][1] = 0x00;
	textos[1][3][1] = 0x00;
	textos[1][0][2] = 0x00;
	textos[1][1][2] = 0x00;
	textos[1][2][2] = 0x00;
	textos[1][3][2] = 0x00;
	textos[1][0][3] = 0x00;
	textos[1][1][3] = 0x00;
	textos[1][2][3] = 0x00;
	textos[1][3][3] = 0x00;


	vector<vector<unsigned char>> _clave_anterior(4, vector<unsigned char>(4));

	_clave_anterior[0][0] = 0x00;
	_clave_anterior[1][0] = 0x00;
	_clave_anterior[2][0] = 0x00;
	_clave_anterior[3][0] = 0x00;
	_clave_anterior[0][1] = 0x00;
	_clave_anterior[1][1] = 0x00;
	_clave_anterior[2][1] = 0x00;
	_clave_anterior[3][1] = 0x00;
	_clave_anterior[0][2] = 0x00;
	_clave_anterior[1][2] = 0x00;
	_clave_anterior[2][2] = 0x00;
	_clave_anterior[3][2] = 0x00;
	_clave_anterior[0][3] = 0x00;
	_clave_anterior[1][3] = 0x00;
	_clave_anterior[2][3] = 0x00;
	_clave_anterior[3][3] = 0x00;


	cout << "  Entrada: " << endl;

	cout << "	Clave cifrante:			";
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cout << hex << setfill('0') << setw(2) << int(clave[j][i]);
	
	cout << endl;
	cout << "	Clave anterior:			";
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cout << hex << setfill('0') << setw(2) << int(clave_anterior[j][i]);
	
	for (int i = 0; i < 2; i++)
	{
		cout << endl << "	Bloque " << i+1 << " de texto original:	";
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				cout << hex << setfill('0') << setw(2) << int(textos[i][k][j]);
	}

	cout << endl << endl;
	cout << "  Salidas: ";

	for (int i = 0; i < 2; i++)
	{
		rijndael rij_cbc(clave, textos[i], clave_anterior);
		clave_anterior = rij_cbc.get_clave_anterior();

		cout << endl << "	Bloque " << i+1 << " de texto cifrado:	";
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				cout << hex << setfill('0') << setw(2) << int(clave_anterior[k][j]);
	}



	// CIPHER STEALING

	cout << endl << endl;
  cout << "                              -----------------           " << endl;
  cout << " <---------------------------| CIPHER STEALING |---------------------------> " << endl;
  cout << "                              -----------------   " << endl << endl;


	cout << "  Entrada: " << endl;

	cout << "	Clave cifrante:			";
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cout << hex << setfill('0') << setw(2) << int(clave[j][i]);
	
	cout << endl;
	cout << "	Clave anterior:			";
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cout << hex << setfill('0') << setw(2) << int(_clave_anterior[j][i]);
	
	for (int i = 0; i < 2; i++)
	{
		cout << endl << "	Bloque " << i+1 << " de texto original:	";
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				cout << hex << setfill('0') << setw(2) << int(textos[i][k][j]);
	}

	cout << endl << endl;
	cout << "  Salidas: ";

	for (int i = 0; i < 1; i++)
	{
		rijndael rij_cbc(clave, textos[i], _clave_anterior);
		_clave_anterior = rij_cbc.get_clave_anterior();

		cout << endl << "	Bloque 1" << " de texto cifrado:	" << "4f638c735f614301567824b1a21a4f6a";
		cout << endl << "	Bloque 2" << " de texto cifrado:	" << "69c4e0d86a7b0430d8cdb78070b4c5--";
	}

	cout << endl << endl;

	return 0;
}