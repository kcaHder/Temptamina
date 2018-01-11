#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <typeinfo>

using namespace std;


//Template che restituisce il tipo dell'oggetto passato come argomento
template <class X> void TypeSorter(X x, bool b = 0)
{
	const char *types[  ] { "int", "unsigned int", "double", "float", "char", "bool", "puntatore a "};
	if(!b) std::cout << "Vorrei ricevere un input di tipo ";
	switch(typeid(x).name(  )[b])
	{
		case 'i':
		{
			std::cout << types[0]; // o qualsiasi altro uso intelligente
			break;
		}
		case 'j':
		{
			std::cout << types[1];
			break;
		}
		case 'd':
		{
			std::cout << types[2];
			break;
		}
		case 'f':
		{
			std::cout << types[3];
			break;
		}
		case 'c':
		{
			std::cout << types[4];
			break;
		}
		case 'b':
		{
			std::cout << types[5];
			break;
		}
		case 'P':
		{
			std::cout << types[6];
			TypeSorter(x, 1);
			break;
		}
		default: std::cout << "\nTorna a casa\n";
	}
	std::cout << std::endl;
}

// Template per la gestione degli errori di input
template <class X> X InputCheck()
{
	X Input;
	do
	{
		char c;
		if((c = std::cin.get()) == '\n') return 0;
		else std::cin.putback(c);
		std::cin >> Input;
		if(std::cin.fail())
		{
			std::cin.clear();
			char c;
			do; while((c = std::cin.get()) != '\n');
			std::cout << "\a";
			std::cout << "Perchè mi fai questo? Riprova con un input valido.\n";
			TypeSorter(Input);
			continue;
		}

		if((std::cin.get()!='\n'))
		{
			std::cout << "\a";
			std::cout << "Non inserire spazi o caratteri, per piacere.. Ti ho chiesto un input valido\n";
			char c;
			do;
			while((c=std::cin.get())!='\n');
			continue;
		}
		else break;
	} while(true);
	return Input;
}


class Matrice
{
	public:
	int righe;
	int colonne;
	double **m;
/////////////////////Costruttori
	Matrice (int rig, int col) 
	{
		righe = rig;
		colonne = col;
		m = new double* [righe];
		cout << "Che valori ci vuoi mettere?" << '\n';
		for (int i = 0; i < righe; ++i)
		{
			m[i] = new double [colonne];
		}
		
		for (int i = 0; i < righe; ++i) 
		{
			for (int j = 0; j < colonne; ++j)
			{
				cout << "Riga " << i+1 << " colonna " << j+1 << ": "; 

				m[i][j] = InputCheck<int>() ;
			}
		}
		
	}
	Matrice (int rig, int col, double a) 
	{
		righe = rig;
		colonne = col;
		m = new double *[righe];
		for (int i = 0; i < righe; ++i)
		{
			m[i] = new double [colonne];
		}
		for (int i = 0; i < righe; ++i) 
		{
			for (int j = 0; j < colonne; ++j)
			{
				m[i][j] = a ;
			}
		}

	}



	Matrice (int rig) 
	{
		righe = rig;
		colonne = 2*rig;
		m = new double *[righe];
		for (int i = 0; i < colonne; ++i)
		{
			m[i] = new double [colonne];
		}
		cout << "Che valori ci vuoi mettere?" << '\n';
		for (int i = 0; i < righe; ++i) 
		{
			for (int j = 0; j < righe; ++j)
			{
				cout << "Riga " << i+1 << " colonna " << j+1 << ": "; 
				m[i][j] = InputCheck<double>() ;
			}
		}
		
		for (int i = 0; i < righe; ++i) 
		{
			for (int j = righe; j < colonne; ++j)
			{
				if ( i != j-righe) m[i][j] = 0;
				else m[i][j] = 1;
			}
		};
		
	}

	Matrice() {}
/////////////////////Operatori



	friend ostream & operator << (ostream &, Matrice );
	Matrice operator = (Matrice mat2)
	{	
 			
 		if (this->colonne==mat2.colonne && this->righe == mat2.righe)
 		{
 			Matrice matass(this->righe, mat2.colonne, 0.);
 			for (int i = 0; i < mat2.colonne; ++i)
 			{	
 				for (int j = 0; j < mat2.righe; ++j)
 				{
 				matass.m[i][j] = mat2.m[i][j];
 				}
 			}	
 			return matass;
 		}

 	}
	Matrice operator + (Matrice mat2)
	{	
		Matrice matsum(this->righe, mat2.colonne, 0);
 		if (this->colonne==mat2.colonne && this->righe == mat2.righe)
 		{
 			for (int i = 0; i < mat2.colonne; ++i)
 			{	
 				for (int j = 0; j < mat2.righe; ++j)
 				{
 				matsum.m[i][j] = this->m[i][j] + mat2.m[i][j];
 				}
 			}	
 			return matsum;
 		}
 		else 
 		{
 			cout << "Operazione non consentita\n";
 			return matsum;
 		}
 		

 	}
	
	Matrice operator - (Matrice mat2)
	{	
 		Matrice matsub(this->righe, mat2.colonne, 0 );
 		if(this->colonne==mat2.colonne && this->righe == mat2.righe) 	
 		{	
 			for (int i = 0; i < mat2.colonne; ++i)
 			{	
 				for (int j = 0; j < mat2.righe; ++j)
 				{
 				matsub.m[i][j] = this->m[i][j] - mat2.m[i][j];
 				}
 			}	
 			return matsub;
 		}	
 		else 
 		{
 			cout << "Operazione non consentita\n";
 			return matsub;
 		}
 		
	}

	Matrice operator * (double a)
	{	
 		Matrice matmulti(this->righe, this->colonne, 0.);
 			for (int i = 0; i < this->colonne; ++i)
 			{	
 				for (int j = 0; j < this->righe; ++j)
 				{
 				matmulti.m[i][j] = this->m[i][j] * a;
 				}
 			}	
 		return matmulti;	
	}

	Matrice operator / (double a)
	{	
 		Matrice matdiv(this->righe, this->colonne, 0.);
 			for (int i = 0; i < this->colonne; ++i)
 			{	
 				for (int j = 0; j < this->righe; ++j)
 				{
 				matdiv.m[i][j] = this->m[i][j] / a;
 				}
 			}	
 		return matdiv;	
	}

	Matrice operator * (Matrice mat2)
	{
		Matrice matmulti(this->righe, mat2.colonne, 0.);
		double *a = new double [this->righe];
		double b = 0;
 		for(int i = 0; i < this->righe; ++i)
 		{ 
        	for(int j = 0; j < mat2.colonne; ++j)
        	{
            	for(int k = 0; k < this->colonne; ++k)
            	{
                	matmulti.m[i][j] += this->m[i][k] * mat2.m[k][j];
            	}
            }
        }
       

    	return matmulti;
	}

/////////////////////Output per l'inversione

	void Anteprima()
	{
		cout << "Ecco la matrice che hai inserito: " << "\n\n";
		
		for (int i = 0; i < this->righe; ++i)
		{
			for (int j = 0; j < this->colonne/2; ++j)
			{

				cout << setprecision(6) << setw(9) << this->m[i][j] << "  ";

			}
			cout << '\n';
		}
		cout << '\n';
	}
	void Risultato()
	{
		cout << "Questa è l'inversa della tua matrice: " << "\n\n";
		
		for (int i = 0; i < this->righe; ++i)
		{
			for (int j = righe; j < this->colonne; ++j)
			{
				if(this->m[i][j] == -0) cout << setprecision(6) << setw(11) << '0' << setw(3) << ' ';

				else cout << setprecision(6) << setw(11) << this->m[i][j] << setw(3) << ' ';

			}
			cout << "\n\n";
		}
		cout << '\n';
	}

	
};

/////////////////////Funzioni per operazioni permesse nell'algoritmo di Gauss

void scambia(double* &a, double* &b, int n)
{
	double* c = new double[2*n];
	c = a;
	a = b;
	b = c;
}


void dividi(double* &a, double b, int n)
{
	if(b != 0 && b != 1)
	{
		for(int j=0; j<2*n; ++j) 
		{
			a[j] /= b;
		}
	}
}


void sottrai(double* a, double* &b, int n, double k) //sostituisce riga b con (riga b - (riga a)*k)
{
	double* c = new double[2*n];
	
	for(int j=0; j<2*n; ++j) c[j] = k*a[j];
	
	
	{	
		for(int j=0; j<2*n; ++j)
		{
			b[j] -= c[j];
		}
	}

}

ostream & operator << (ostream &os, Matrice mat)
	{
		os << "Ecco la tua matrice: " << "\n\n";
		
		for (int i = 0; i < mat.righe; ++i)
		{
			for (int j = 0; j < mat.colonne; ++j)
			{

				os << setprecision(6) << setw(9) << mat.m[i][j] << "  ";

			}
			os << '\n';
		}
		os << '\n';
	}	


int main ()
{	
	bool again = 1;
	cout << "Questo programma è stato scritto per calcolare la matrice inversa\ndi una matrice quadrata utilizzando l'algoritmo di Gauss.\n\n\n";

	do
	{
		cout << "Qual'è la dimensione della matrice che vuoi invertire?\n";
		int righe, colonne;
		righe = InputCheck<int>();
		colonne = righe;
		if (righe <= 0)
		{
			cout <<"Non creare una matrice di dimensione 0 o negativa per favore! Riprova!\n";
			continue;
		}
		
		if (righe >= 20)
		{
			cout << "Sei proprio sicuro di volere una matrice così grande?\nSe sei sicuro abbi il coraggio di ridirmelo a tuo rischio e pericolo.\n";
			colonne = InputCheck<unsigned int>();
		} 
		//righe = colonne;
		Matrice mat(righe);
		do
		{
			mat.Anteprima();
		
			if(!mat.m[0][0]) //se il primo elemento è nullo, scambio la prima riga
			{
				int conta = righe-1;
				for(int i=1; i<righe; ++i)
				{
					if(mat.m[i][0])
					{
						scambia(mat.m[0], mat.m[i], righe);
						break;
					}	
					else --conta;
				}
				if (!conta) 
				{
					cout << "Determinante = 0. Purtroppo l'inversa non esiste! Riprova.\n";
					
				}
				else break;
			}
			else break;
		}
		while (true);

	for(int i=0; i<righe; ++i) // per ottenere l'identità a sinistra
		{
			dividi(mat.m[i], mat.m[i][i], righe); //riga i-esima divisa per elemento i-esimo
			
			for(int k=0; k<righe; ++k)
			{
				if (k!=i) sottrai(mat.m[i], mat.m[k], righe, mat.m[k][i]); //sottrazione
			}
		}

	int conta = righe;
	
	for(int k=1; k<=righe; ++k) // per verificare su ogni riga
	{	
		for(int i=0; i<righe; ++i) //se tutti gli elementi sono nulli
		{
			if(!mat.m[righe-k][i]) --conta;
		}
		if(!conta)
		{
			cout << "Determinante = 0. Purtroppo l'inversa non esiste!\n";
			k = righe + 1; // Per uscire dal for.
		} 
		
		else conta = righe;
	}
	if(!conta) 
		{
		cout << "Premere 1 per usare di nuovo il programma, 0 altrimenti.\n";
		again = InputCheck<bool>();
			continue;
		}
		
	mat.Risultato();

	cout << "Premere 1 per usare di nuovo il programma, 0 altrimenti.\n";
	again = InputCheck<bool>();
	}

	while(again);
	cout << "\n\nArrivederci.\n\n";
		

	return 0;

}
