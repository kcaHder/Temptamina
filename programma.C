#include <iostream>
#include <iomanip>
using namespace std;


struct Matrice
{
	double** matrice;
	Matrice(double** d)
	{matrice = d;
//	clog << "sono costruttore di matrice per valore (double**)\n\n";
	}
	
//	void scrivi(int n)
//	{
//		for(int i=0; i<n; ++i)
//		{
//			for(int j=0; j<(2*n); ++j)
//			{
//				clog <<setprecision(5)<< setw(12) << matrice[i][j] << ' ';
//			}
//			clog << "\n\n";
//		}
//		clog << "\n\n";
//	}
	
	void inserita(int n)
	{
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				if(matrice[i][j] != -0) cout << setprecision(5) << setw(12) << matrice[i][j] << ' ';
				else cout << setprecision(5) << setw(12) << "0" << ' ';
			}
			cout << "\n\n";
		}
		cout << "\n\n";
	}
	
	void inversa(int n)
	{
		for(int i=0; i<n; ++i)
		{
			for(int j=n; j<(2*n); ++j)
			{
				if(matrice[i][j] == -0) cout << setprecision(5) << setw(10) << '0' << setw(5) << ' ';
			
				
				else cout << setprecision(5) << setw(10) << matrice[i][j] << setw(5) << ' ';
			}
			cout << "\n\n";
		}
		cout << "\n\n";
	}
	
	
	
}; //fine della definizione della classe Matrice


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
//			clog << "diviso\n";
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
//			clog << "sottratto\n";
		}
	}

}






int main()
{	
bool ancora = 1; //inizializzata a 1 per fare rieseguire il programma dopo l'uscita dal ciclo della riga 323

	int n; //numero di righe
	cout << "\nQuesto programma utilizza l'Algoritmo di Gauss per calcolare l'inversa di una matrice (quadrata, ovviamente).\n";
do // per fare decidere, alla fine, se rieseguire il programma
{	
	int proviamo;
	cout << "Digita il numero di righe (o di colonne, ovviamente).\n";
	
	do // gestione errori input
	{
		
		cin >> n; //input numero di righe
		
		if(cin.fail()) //lettura fallita
		{
			cin.clear();
			char c;
			do; while(c = cin.get() != '\n');
			cout << "Per favore, riprova con un intero positivo.\n(ed evita un numero gigante, sappiamo entrambi che non vuoi inserire\nun numero di elementi pari al suo quadrato)\n";
			continue;
			
		}
		
		if((cin.get()!='\n')) //se non c'è '\n' dopo il primo input letto
          {
          	cout << "Non inserire spazi, caratteri o numeri non naturali, per piacere.. Ti ho chiesto un intero positivo.\n";
        		char c;
            	do;
               while((c=cin.get())!='\n'); 
               continue;
          }
		
		try //gestione eccezioni
		{
		if(n<1) throw 'a';
		if(n==1) throw 1.0;
		else if(n>10 && n<46341) throw n;
		else if(n>46340) throw "Troppo grande.. ";
		}
		catch(int n)
		{
			
			cout << "Davvero vuoi inserire " << n*n << " numeri? Beh, lo farai con un altro programma,\nio non ho così tanto tempo da perdere, nè quella potenza di calcolo...\nDigita un numero più piccolo!\n";
			continue;
		}
		
		catch(double)
		{
			double determinante;
			cout << "Come sei fortunato! In questo caso ti saprò dire addirittura il determinante della matrice che inserirai!\nDigita la \"matrice\" fortunella.\n";
		do // gestione errori input
		{	
			cin >> determinante;
			
			if(cin.fail()) 
			{
				cin.clear();
				char c;
				do; while(c = cin.get() != '\n');
				cout << "Anche per questo semplice calcolo vuoi farmi soffrire?" << '\n';
				continue;
			}
		
			if((cin.get()!='\n'))
          	{
          		cout<<"Non inserire spazi o caratteri, per piacere.. Ti ho chiesto un numero reale\n";
        			char c;
            		do;
               	while((c=cin.get())!='\n'); 
               	continue;
          	}
         		else break;
		} while(true);
			
			if(determinante)
			{
				cout << "L'inversa della tua matrice è " << double(1/determinante) << " (1/" << determinante << ") e il suo determinante è proprio...(rullo di tamburi)....\n\n" << determinante << "\n\nChe sorpresa!\nOra che ci siamo divertiti, passiamo alle cose serie.\nDigita il numero di righe(o di colonne, ovviamente).\n";
				continue;
			}
			else
			{
				cout << "L'inversa purtroppo non esiste (per ovvi motivi). Il determinante, invece, è proprio...(rullo di tamburi)....\n\n" << determinante << "\n\nChe sorpresa!\nOra che ci siamo divertiti, passiamo alle cose serie.\nDigita il numero di righe(o di colonne, ovviamente).\n";
				continue;
			}
		}
		catch(char)
		{
			cout << "Non avrai pensato di potere poi inserire qualcosa!\nTi do l'opportunità di riprovare.\n";
			continue;
		}
		catch(const char*)
		{
			cout << "Mi dispiace, il numero inserito è per me ingestibile anche soltanto per farne il quadrato...\nRiprova con un numero più piccolo.\n";
			continue;
		}
		
		if(cin.good()) break;
		
	} while(true);

	double* a[n]; // dichiarazione array di puntatori (righe)
	for (auto &x:a) x = new double[2*n]; //allocazione di ogni riga
	
	
	for(int i=0; i<n; ++i) // ciclo per riempire le righe
	{
		for(int j=0; j<n; ++j) // ciclo per inserire i valori di ogni riga
		{
			cout << "Digita il valore " << setw(2) << j+1 << " della riga " << setw(2) << i+1 << ": ";
			do // gestione errori input
			{
				cin >> a[i][j];
				if(cin.fail())
				{
					cin.clear();
					char c;
					do; while(c = cin.get() != '\n');
					cout << "Perchè mi fai questo? Riprova con un numero reale.\n";
					continue;
				}
				
				if((cin.get()!='\n'))
          		{
          			cout << "Non inserire spazi o caratteri, per piacere.. Ti ho chiesto un numero reale\n";
        				char c;
            			do;
               		while((c=cin.get())!='\n'); 
               		continue;
          		}
				else break;
			} while(true);
		}
		
		for (int k=n; k<(2*n); ++k) // creazione matrice identità a destra
		{
			if((k-i)==n) a[i][k] = 1;
			else a[i][k] = 0;
		 }
	}
	
	cout << "\n\n\n";
	
	
	Matrice m = a;
	cout << "Ecco la matrice da te inserita\n\n";
	m.inserita(n);
	
try
{	
	
	if(!a[0][0]) //se il primo elemento è nullo, scambio la prima riga
	{
		int conta = n-1;
		for(int i=1; i<n; ++i)
		{
			if(a[i][0])
			{
				scambia(a[0], a[i], n);
				break;
			}	
			else --conta;
		}
		if (!conta) throw "Determinante = 0. Purtroppo l'inversa non esiste!\n";
	}
}	
	
catch(const char* noncalcolabile)
	{
		
		cout << noncalcolabile << "Ne proviamo un'altra? Digita 1 per rispondere sì, 0 per uscire dal programma.\n";
	do // gestione errori input
	{
		
		cin >> proviamo;
		
		if(cin.fail()) 
		{
			cin.clear();
			char c;
			do; while(c = cin.get() != '\n');
			cout << "Difficile sbagliarsi, o 1 o 0... Riprova, suvvia.\n";
			continue;
		}
		
		if((cin.get()!='\n'))
          {
          	cout<<"Non inserire spazi o caratteri, per piacere...\n";
        		char c;
            	do;
               while((c=cin.get())!='\n'); 
               continue;
          }
          
		else if(proviamo==1) break;
		else if(!proviamo)
		{
			cout << "Programma terminato senza errori.\n";
			return 0;
		}
		
		else
		{
			cout << "Ti ho detto: o 0, o 1.\n";
			continue;
		}
	} while(true);
		
	if(proviamo == 1) continue;
	}
	
	
//	m.scrivi(n); // clog di controllo


	
	for(int i=0; i<n; ++i) // per ottenere l'identità a sinistra
	{
		dividi(a[i], a[i][i], n); //riga i-esima divisa per elemento i-esimo
		
		for(int k=0; k<n; ++k)
		{
			if (k!=i) sottrai(a[i], a[k], n, a[k][i]); //sottrazione
		}
//		m.scrivi(n); // clog di controllo
	}



try //gestione eccezioni
{
	int conta = n;
	for(int k=1; k<=n; ++k) // per verificare su ogni riga
	{	
		for(int i=0; i<n; ++i) //se tutti gli elementi sono nulli
		{
			if(!a[n-k][i]) --conta;
		}
		if(!conta) throw "Determinante = 0. Purtroppo l'inversa non esiste!\n";
		else conta = n;
	}


}

catch(const char* noncalcolabile)
	{
		
		cout << noncalcolabile << "Ne proviamo un'altra? Digita 1 per rispondere sì, 0 per uscire dal programma.\n";
	do // gestione errori input
	{
		
		cin >> proviamo;
		
		if(cin.fail()) 
		{
			cin.clear();
			char c;
			do; while(c = cin.get() != '\n');
			cout << "Difficile sbagliarsi, o 1 o 0... Riprova, suvvia.\n";
			continue;
		}
		
		if((cin.get()!='\n'))
          {
          	cout<<"Non inserire spazi o caratteri, per piacere...\n";
        		char c;
            	do;
               while((c=cin.get())!='\n'); 
               continue;
          }
          
		else if(proviamo==1) break;
		else if(!proviamo)
		{
			cout << "Programma terminato senza errori.\n";
			return 0;
		}
		
		else
		{
			cout << "Ti ho detto: o 0, o 1.\n";
			continue;
		}
	} while(true);
		
	if(proviamo == 1) continue;
	}

	
//	m.scrivi(n); // clog di controllo
	
	cout << "Ecco l'inversa della tua matrice.\n\n";
	
	m.inversa(n);
	

	cout << "Per calcolare l'inversa di un'altra matrice, digitare 1.\nPer uscire dal programma, digitare 0.\n";
	
	do // gestione errori input
	{
		cin >> ancora;
		if(cin.fail())
		{
			cin.clear();
			char c;
			do; while(c = cin.get() != '\n');
			cout << "Siamo alla fine del programma e ancora non hai capito come funzionano le cose? Ti ho detto 0 o 1, suvvia.\n";
			continue;
		}
		if((cin.get()!='\n'))
          {
          	cout<<"Non inserire spazi o caratteri, per piacere...\n";
        		char c;
            	do;
               while((c=cin.get())!='\n'); 
               continue;
          }
		else break;
	} while(true);
	
	
} while(ancora);	

cout << "Programma terminato senza errori.\n";
return 0;
	
}
