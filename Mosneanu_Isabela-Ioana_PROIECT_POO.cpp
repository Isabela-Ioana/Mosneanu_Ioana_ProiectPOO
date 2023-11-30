//Domeniu:IT
//Obiecte:  Servere, Smartphone-uri, Laptop-uri

#include<iostream>
#include<cstring>
#include <vector>

using namespace std;




class Servers {

private:
	const int id;
	static int gradPopulare;         //minimul obligatoriu, in procente
	float stocare;
	char* sistemOperare;
	bool esteSecurizat;
public:

	const int getId() {
		return this->id;
	}

	static int getGradPopulare() {
		return Servers::gradPopulare;
	}

	static void setGradPopulare(int grad) {
		if (grad > 0) {
			Servers::gradPopulare = grad;
		}
	}

	float getStocare() {
		return this->stocare;
	}

	void setStocare(float stocare) {
		if (stocare > 0) {
			this->stocare = stocare;
		}
	}

	char* getSistemOperare() {
		return this->sistemOperare;
	}

	void setSistemOperare(const char* sistemOperareNou) {
		if (this->sistemOperare != NULL)
			delete[]this->sistemOperare;
		sistemOperare = new char[strlen(sistemOperareNou) + 1];
		strcpy_s(sistemOperare, strlen(sistemOperareNou) + 1, sistemOperareNou);
	}

	bool getEsteSecurizat() {
		return this->esteSecurizat;
	}

	void setEsteSecurizat(bool estesec) {
		this->esteSecurizat = estesec;
	}


	Servers() :id(0) {
		this->stocare = 100.3;
		this->sistemOperare = new char[strlen("Windows") + 1];
		strcpy_s(this->sistemOperare, strlen("Windows") + 1, "Windows");
		this->esteSecurizat = false;
	}

	Servers(float stocareNoua) :id(1) {
		this->stocare = stocareNoua;
		this->sistemOperare = new char[strlen("Windows") + 1];
		strcpy_s(this->sistemOperare, strlen("Windows") + 1, "Windows");
		esteSecurizat = true;
	}

	Servers(const int idnou, const char* sistemOperareNou) :id(idnou) {
		this->stocare = 300.78;
		this->sistemOperare = new char[strlen(sistemOperareNou) + 1];
		strcpy_s(this->sistemOperare, strlen(sistemOperareNou) + 1, sistemOperareNou);
		esteSecurizat = false;
	}


	//constr de copiere:
	Servers(const Servers& s) :id(s.id) {
		stocare = s.stocare;
		this->sistemOperare = new char[strlen(s.sistemOperare) + 1];
		strcpy_s(sistemOperare, strlen(s.sistemOperare) + 1, s.sistemOperare);
		esteSecurizat = s.esteSecurizat;
	}

	//op egal:
	Servers operator=(const Servers& s) {
		if (this != &s) {
			if (sistemOperare != NULL)
			{
				delete[]sistemOperare;
			}
			stocare = s.stocare;
			sistemOperare = new char[strlen(sistemOperare) + 1];
			strcpy_s(s.sistemOperare, strlen(sistemOperare) + 1, sistemOperare);
			esteSecurizat = s.esteSecurizat;
		}
		return*this;
	}


	//op cout
	friend ostream& operator<<(ostream& monitor,  Servers& servers) {
		monitor << " Id- "<< servers.id << " Gradul de populare minim: " << servers.gradPopulare << ". Stocarea: " << servers.stocare << ". Sistemul de operare folosit: "<< servers.sistemOperare<< (servers.esteSecurizat? ". Serverul este securizat. ": ". Serverul nu este securizat.");
		monitor << endl;
		return monitor;
	}

	//op cin
	friend istream& operator>>(istream& citeste, Servers& servers) {
		cout << "Stocarea noului server:";
		citeste >> servers.stocare;
		cout << "Sistemul de operare folosit de noul server:: ";
		char aux[100];
		citeste >> aux;
		if (servers.sistemOperare != NULL) delete[]servers.sistemOperare;
		servers.sistemOperare = new char[strlen(aux) + 1];
		strcpy_s(servers.sistemOperare, strlen(aux) + 1, aux);
		cout << "Este securizat noul server:? 1-da, 0-nu";
		citeste >> servers.esteSecurizat;
		cout << endl;
		return citeste;
	}


	~Servers() {
		if (this->sistemOperare != NULL) delete[]this->sistemOperare;
	}

	void afisare() {
		cout << "id-" << id << " Gradul de populare minim: " << gradPopulare << ". Stocarea: " << stocare << ". Sistemul de operare folosit: " << sistemOperare << (esteSecurizat ? ". Serverul este securizat." : ". Serverul nu este securizat.") << endl;
	}

	//op float                             //calculez stocarea totala
	explicit operator float() {
		float aux = 0;
		aux = stocare;
		return aux;
	}
};
int Servers::gradPopulare = 20;


class SmartPhones {

private:
	const int codFabricatie;
	static int anulFabricatiei;
	int nrStocari;
	int* dimensiuneZonaStocare;
	string marca;

public:


	SmartPhones() :codFabricatie(1000) {
		this->nrStocari = 3;
		if (nrStocari != 0) {
			this->dimensiuneZonaStocare = new int[nrStocari] {20, 21, 22};
		}
		this->marca = "Samsung";

	}

	SmartPhones(string marcaNoua) :codFabricatie(1001) {
		this->nrStocari = 0;
		this->dimensiuneZonaStocare = NULL;
		this->marca = marcaNoua;
	}

	SmartPhones(const int codFabricatieNou, string marcaNoua) :codFabricatie(codFabricatieNou) {
		this->nrStocari = 0;
		this->dimensiuneZonaStocare = NULL;
		this->marca = marcaNoua;
	}


	//constr copiere
	SmartPhones(const SmartPhones& p) :codFabricatie(p.codFabricatie) {
		this->nrStocari = p.nrStocari;
		this->dimensiuneZonaStocare = new int[nrStocari];
		for (int i = 0; i < p.nrStocari; i++) {
			dimensiuneZonaStocare[i] = p.dimensiuneZonaStocare[i];
		}
		this->marca = p.marca;
	}


	//op egal
	SmartPhones operator=(const SmartPhones& p) {
		if (this != &p)
		{
			if (dimensiuneZonaStocare != NULL) delete[]dimensiuneZonaStocare;
			this->nrStocari = p.nrStocari;
			this->dimensiuneZonaStocare = new int[nrStocari];
			for (int i = 0; i < p.nrStocari; i++) {
				dimensiuneZonaStocare[i] = p.dimensiuneZonaStocare[i];
			}
			this->marca = p.marca;
		}
		return *this;
	}


	//getters

	const int getCodFabricatie() {
		return SmartPhones::codFabricatie;
	}
	static int getAnulFabricatiei() {
		return SmartPhones::anulFabricatiei;
	}
	int getNrStocari() {
		return this->nrStocari;
	}

	int getDimensiuneZonaStocare(int index) {
		return this->dimensiuneZonaStocare[index];
	}
	string getMarca() {
		return this->marca;
	}

	//setters

	static void setAnulFabricatiei(int AnFabNou)
	{
		anulFabricatiei = AnFabNou;
	}

	void setNrStocari(int nrStocariNou, int* dimensiuniZoneStocareNoi) {

		this->nrStocari = nrStocariNou;
		if (dimensiuneZonaStocare != NULL) delete[]dimensiuneZonaStocare;
		this->dimensiuneZonaStocare = new int[nrStocari];
		for (int i = 0; i < nrStocariNou; i++) {
			dimensiuneZonaStocare[i] = dimensiuniZoneStocareNoi[i];
		}
	}

	void setMarca(string marcaNoua) {
		marca = marcaNoua;
	}



	//op cout
	friend ostream& operator<<(ostream& afiseaza, const SmartPhones& smartphones) {
		afiseaza << "Codul de fabricatie:" << smartphones.codFabricatie << ". Anul fabricatiei:" << smartphones.anulFabricatiei << ". Marca este: " << smartphones.marca << ". Numarul de stocari este de: " << smartphones.nrStocari << " gb. Dimensiunile fiind de: ";
		for (int i = 0; i < smartphones.nrStocari; i++) {
			afiseaza << smartphones.dimensiuneZonaStocare[i] << ", ";
		}
		return afiseaza;
	}



	//op cin
	friend istream& operator>>(istream& citeste, SmartPhones& smartphones) {
		cout << "Marca noului smartphone: ";
		citeste >> smartphones.marca;
		cout << "Nr stocari pt noul smartphone: ";
		citeste >> smartphones.nrStocari;
		cout << " Stocarile noului smartphone fiind: ";
		if (smartphones.dimensiuneZonaStocare != NULL) delete[]smartphones.dimensiuneZonaStocare;
		if (smartphones.nrStocari > 0) {
			smartphones.dimensiuneZonaStocare = new int[smartphones.nrStocari];
			for (int i = 0; i < smartphones.nrStocari; i++)
			{
				citeste >> smartphones.dimensiuneZonaStocare[i];
			}
		}

		return citeste;
	}
	//op string
	operator string() {
		return this->marca;
	}

	//op float
	explicit operator float() {
		float aux = 0;
		for (int i = 0; i < nrStocari; i++)
		{
			aux = aux + dimensiuneZonaStocare[i];
		}
		aux = aux / nrStocari;
		return aux;
	}

	//op preincr      (intai se aduna si dupa se egaleaza- o sa aiba aceleasi valori)
	SmartPhones operator++() {
		for (int i = 0; i < this->nrStocari; i++)
		{
			this->dimensiuneZonaStocare[i]++;
		}
		return *this;
	}
	
	//op postincr     (intai se egaleaza si dupa se aduna- o sa aiba val diferite)
	SmartPhones operator++(int){
		SmartPhones aux = *this;
		for (int i = 0; i < nrStocari; i++)
		{
			dimensiuneZonaStocare[i]++;
		}
		return aux;
	}


	~SmartPhones() {
		if (dimensiuneZonaStocare != NULL) delete[]dimensiuneZonaStocare;
	}

	void afisare() {
		int i;
		cout << "Cod fabr: " << codFabricatie << ". An fabr: " << anulFabricatiei << ". Nr stocari " << nrStocari << ". Marca " << marca << ". Dim zone: ";
		for (i = 0; i < nrStocari; i++) cout << dimensiuneZonaStocare[i]<<", ";
		cout << endl;
	}


};
int SmartPhones::anulFabricatiei = 2022;

class Laptops {
private:
	const int codFabricatie;
	static int anulFabricatiei;
	int nrProfiluri;
	int* nrAccesari;
	string marca;

public:

	Laptops() :codFabricatie(0) {
		this->nrProfiluri = 0;
		this->nrAccesari = NULL;
		this->marca ="Lenovo";
		
	}

	Laptops(const int codFabricatieNou) :codFabricatie(codFabricatieNou) {
		this->nrProfiluri = 2;
		this->nrAccesari = new int[nrProfiluri] {12, 22};
		this->marca =  "Asus";
		}

	Laptops(const int codFabricatieNou,string marcaNoua) :codFabricatie(codFabricatieNou) {
		this->nrProfiluri = 3;
		this->nrAccesari = new int[nrProfiluri] {100, 101, 102};
		this->marca = marcaNoua;
	}



	//constr copiere:
	Laptops(const Laptops& l) :codFabricatie(codFabricatie) {
		nrProfiluri = l.nrProfiluri;
		nrAccesari = new int[l.nrProfiluri];
		for (int i = 0; i < l.nrProfiluri; i++) {
			nrAccesari[i] = l.nrAccesari[i];
		}
		marca = l.marca;
	}


	//op egal:
	Laptops operator=(const Laptops& l) {
		if (this != &l) {
			if (nrAccesari != NULL)
				delete[]nrAccesari;
			nrProfiluri = l.nrProfiluri;
			nrAccesari = new int[l.nrProfiluri];
			for (int i = 0; i < l.nrProfiluri; i++) {
				nrAccesari[i] = l.nrAccesari[i];
			}
			marca = l.marca;
		}
		return *this;
	}



	//getters:

	const int getCodFabricatie() {
		return Laptops::codFabricatie;
	}
	static int getanulFabricatiei() {
		return Laptops::anulFabricatiei;
	}
	int getNrProfiluri() {
		return this->nrProfiluri;
	}

	int getNrAccesari(int index) {
		return this->nrAccesari[index];
	}
	string getMarca() {
		return this->marca;
	}



	//setters 
	void setAnulFabricatiei(static int anulFabricatieiNou)
	{
		this->anulFabricatiei = anulFabricatieiNou;
	}


	void setNrProfiluri(int nrProfiluriNou, int* nrAccesariNou) {
		this->nrProfiluri = nrProfiluriNou;
		if (nrAccesari != NULL) delete[]nrAccesari;
		this->nrAccesari = new int[nrProfiluri];
		for (int i = 0; i < nrProfiluriNou; i++) {
			this->nrAccesari[i] = nrAccesariNou[i];
		}
	}
	

	void setMarca(string marcanoua) {
		this->marca = marcanoua;
	}


	//op cout
	friend ostream& operator<<(ostream& afisare, const Laptops& laptops) {
		afisare << "Cod fabricatie:" << laptops.codFabricatie << ". Anul fabricatiei:" << laptops.anulFabricatiei << ". Marca:" << laptops.marca << ". Nr profiluri:" << laptops.nrProfiluri << ". Nr accesari pt fiecare profil: ";
		for (int i = 0; i < laptops.nrProfiluri; i++) afisare << laptops.nrAccesari[i]<<", ";
		return afisare;
	}

	//op cin
	friend istream& operator>>(istream& citeste, Laptops& laptops) {
		cout << endl;
		cout << "Anul fabricatiei: ";
		citeste >> laptops.anulFabricatiei;
		cout << "Marca:";
		citeste >> laptops.marca;
		cout << "Nr profiluri: ";
		citeste >> laptops.nrProfiluri;
		cout << "Nr accesari pt fiecare profil: ";
		laptops.nrAccesari = new int[laptops.nrProfiluri];
		for (int i = 0; i < laptops.nrProfiluri; i++)
		{
			citeste >> laptops.nrAccesari[i];
		}
		return citeste;
	}

	//op string
	operator string() {
		return this->marca;
	}

	//op float
	explicit operator float() {
		float aux = 0;
		for (int i = 0; i < nrProfiluri; i++) {
			aux = aux + nrAccesari[i];
		}
		aux = aux / nrProfiluri;
		return aux;
	}

	//op preincrementare - intai aduna si dupa egaleaza
	Laptops operator++() {
		for (int i = 0; i <nrProfiluri; i++)
		{
			nrAccesari[i]++;
		}
		return *this;
	}

	//op postincrem - intai egaleaza si dupa aduna, n au val la fel
	Laptops operator++(int) {
		Laptops aux = *this;
		for (int i = 0; i < nrProfiluri; i++) {
			nrAccesari[i]++;
		}
		return aux;
	}

	~Laptops() {
		if (nrAccesari != NULL) delete[]nrAccesari;
	}

	void afisare() {
		cout << "Cod fabricatie " << codFabricatie << ". Anul fabr " << anulFabricatiei << ". Marca: " << marca <<". Nr profiluri:" << nrProfiluri<< ". Nr accesari pt fiecare profil: ";
		for (int i = 0; i < nrProfiluri; i++)
			cout << nrAccesari[i] << ", ";
	}
};
int Laptops::anulFabricatiei = 2023;

void main() {
	
	//Servers servers;
	//Servers servers1(200.8);
	//Servers servers2(2,"Linux");
	//cout << servers;
	//cout << servers1;
	//cout << servers2;
	//Servers servers3(servers1);



	////setteri:
	//servers3.setGradPopulare(10000);
	//servers3.setStocare(500.55);
	//servers3.setSistemOperare("Linux");
	//servers3.setEsteSecurizat(false);
	//cout << servers3;             
	//cout << endl;



	////getteri:
	//cout << "Id servers3: " << servers3.getId() << endl;
	//cout << "GradPopulare servers3: " << servers3.getGradPopulare() << endl;
	//cout << "Stocare servers3: " << servers3.getStocare() << endl;
	//cout << "SistemOperare servers3: " << servers3.getSistemOperare() << endl;
	//cout << (servers3.getEsteSecurizat() ? "Este securizat servers3 " : "Nu e securizat servers3") << endl;
	//cout << endl;

	//Servers servers4;
	//cin >> servers4;
	//cout << servers4; 
	//cout << endl;

	//float stocaretotala;
	//stocaretotala = (float)servers1;
	//cout <<"Stocarea serverului 1 este: "<< stocaretotala;







	//SmartPhones smartphones;
	//cout << smartphones << endl;
	//SmartPhones smartphones2("Iphone");
	//cout<<smartphones2 << endl;
	//SmartPhones smartphones3(1002, "Lenovo");
	//cout << smartphones3<<endl;
	//SmartPhones sp4(smartphones2);
	//cout << sp4 << endl;


	////setters
	//sp4.setAnulFabricatiei(2023);
	//int dimnoi[] = { 16,32,64,124,256 };
	//sp4.setNrStocari(5, dimnoi);
	//sp4.setMarca("Lenovo");
	//cout << sp4;
	//cout << endl;
	//
	//
	//

	////getters
	//cout << "Cod fabricatie smartphone4: " << sp4.getCodFabricatie();
	//cout << ". Anul fabricatiei smartphone4: " << sp4.getAnulFabricatiei();
	//cout << ". Nr stocari smartphone4: " << sp4.getNrStocari();
	//cout << ". Dimensiuni zone stocare smartphone4: ";
	//for (int i = 0; i < sp4.getNrStocari(); i++) {
	//	cout << sp4.getDimensiuneZonaStocare(i)<<", ";
	//}
	//cout << ". Marca smartphone4: " << sp4.getMarca();
	//cout << endl;

	///*SmartPhones sp5;
	//cin >> sp5;
	//cout << sp5;*/
	//string denumire;
	//denumire = (string)smartphones2;
	//cout <<endl << "Denumirea smartphoneului 2 este: " << denumire;
	//
	//float dimensiunipesmartphone;
	//dimensiunipesmartphone = (float)sp4;
	//cout << "Dimensiunea medie a smartphoneului 4 este: " << dimensiunipesmartphone;

	////preincr
	//SmartPhones sp6;
	//sp6 = ++sp4;
	//cout << endl;
	//cout << endl<<"-----Preincrementarea: " << sp6 << " SIII " << sp4 << endl;
	// 
	////postincr
	//SmartPhones sp7;
	//sp7 = sp4++;
	//cout << endl << "-----Postincrementarea: " << sp7 << " SIII " << sp4 << endl;


	//cout << endl;
	//Laptops laptops;
	//cout << laptops << endl;

	//Laptops laptops1(1);
	//cout << laptops1<< endl;

	//Laptops laptops2(2, "Samsung");
	//cout<< laptops2<<endl;

	//Laptops laptops3(laptops2);
	//cout<<laptops3 << endl;
	//
	////getters
	//cout << "Pt laptops3:    " << laptops3.getCodFabricatie() << " " << laptops3.getanulFabricatiei() << " " << laptops3.getMarca() << " " << laptops3.getNrProfiluri();
	//for (int i = 0; i < laptops3.getNrProfiluri(); i++) {
	//	cout <<" "<< laptops3.getNrAccesari(i);
	//}
	//cout << endl;
	//
	////setters
	//laptops3.setAnulFabricatiei(2024);
	//laptops3.setMarca("Motorola");
	//int accesarinoi[] = { 17,18,19,20,21 };
	//laptops3.setNrProfiluri(5, accesarinoi);
	//cout<<laptops3;

	//Laptops laptops4;
	//cin >> laptops4;
	//cout << laptops4;

	//string den;
	//den = (string)laptops4;
	//cout << endl<<"Denumirea laptopului 4 este: " << den;

	//float nrmediuaccesari;
	//nrmediuaccesari = (float)laptops3;
	//cout <<endl<< "Nr mediu de accesari la profilurile laptopului 3 este de: " << nrmediuaccesari;


	////preincrem
	//Laptops laptops5;
	//laptops5 = ++laptops3;
	//cout <<endl<< "-----Preincrementarea: " << laptops5 << "SIIIIIIIIi" << laptops3;
	////postincrem
	//Laptops laptops6;
	//laptops6 = laptops3++;
	//cout << endl << "-----Postincrementarea: " << laptops6 << "SIIIIIIIIi" << laptops3;




	vector<Servers> vectorServers;
	vector<SmartPhones> vectorSmartPhones;
	vector<Laptops> vectorLaptops;



	Servers server1;
	cin >> server1;
	vectorServers.push_back(server1);

	for (const auto& server : vectorServers) {
		cout<<server1;
	}




	SmartPhones phone1;
	cin >> phone1;
	vectorSmartPhones.push_back(phone1);

	for (const auto& phone : vectorSmartPhones) {
		cout << phone1;
	}
	



	Laptops laptop1;
	cin >> laptop1;
	vectorLaptops.push_back(laptop1);

	for (const auto& laptop : vectorLaptops) {
		cout << laptop1;
	}


	const int rows = 2;
	const int cols = 2;
	Servers matrixServers[rows][cols];

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cin >> matrixServers[i][j];
		}
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << matrixServers[i][j];
		}
	}

}
