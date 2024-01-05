//Domeniu:IT
//Obiecte:  Servere, Smartphone-uri, Laptop-uri

#include<iostream>
#include<fstream>
#include<string>
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
	friend ostream& operator<<(ostream& monitor, Servers& servers) {
		monitor << " Id- " << servers.id << " Gradul de populare minim: " << servers.gradPopulare << ". Stocarea: " << servers.stocare << ". Sistemul de operare folosit: " << servers.sistemOperare << (servers.esteSecurizat ? ". Serverul este securizat. " : ". Serverul nu este securizat.");
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

	void serializare() {
		ofstream f("servers.bin", ios::binary);
		f.write((char*)&id, sizeof(id));
		f.write((char*)&gradPopulare,sizeof(gradPopulare));
		string mystr=to_string(stocare);
		int length = mystr.length();
		f.write((char*)&mystr, sizeof(mystr));
		f.write((char*)&sistemOperare, sizeof(sistemOperare));
		f.write((char*)&esteSecurizat, sizeof(esteSecurizat));
		f.close();
	}

	void deseralizare() {
		ifstream f("servers.bin", ios::binary);
		f.read((char*)&id, sizeof(id));
		f.read((char*)&gradPopulare, sizeof(gradPopulare));
		f.read((char*)&stocare, sizeof(stocare));
		f.read((char*)&esteSecurizat, sizeof(esteSecurizat));
		f.close();
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
	SmartPhones operator++(int) {
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
		for (i = 0; i < nrStocari; i++) cout << dimensiuneZonaStocare[i] << ", ";
		cout << endl;
	}

	
	void serializare() {
		ofstream f("fisier.bin", ios::binary);
		f.write((char*)&nrStocari, sizeof(nrStocari));
		for (int i = 0; i < nrStocari; i++) {
			f.write((char*)&dimensiuneZonaStocare[i], sizeof(dimensiuneZonaStocare[i]));
		}
		int length = marca.length();
		f.write((char*)&length, sizeof(length));
		f.close();
	}

	void deseralizare() {
		ifstream f("fisier.bin", ios::binary);
		f.read((char*)&nrStocari, sizeof(nrStocari));
		if (dimensiuneZonaStocare != NULL) delete[]dimensiuneZonaStocare;
		dimensiuneZonaStocare = new int[nrStocari];
		for (int i = 0; i < nrStocari; i++) {
			f.read((char*)&dimensiuneZonaStocare[i], sizeof(dimensiuneZonaStocare[i]));
		}
		int length = 0;
		f.read((char*)&length, sizeof(length));
		char* buffer = new char[length+1];
		f.read(buffer, length);
		//buffer[length] = '\0';
		//marca = string(buffer);
		string myString(marca);
		delete[]buffer;
		f.close();
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
		this->marca = "Lenovo";

	}

	Laptops(const int codFabricatieNou) :codFabricatie(codFabricatieNou) {
		this->nrProfiluri = 2;
		this->nrAccesari = new int[nrProfiluri] {12, 22};
		this->marca = "Asus";
	}

	Laptops(const int codFabricatieNou, string marcaNoua) :codFabricatie(codFabricatieNou) {
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
		for (int i = 0; i < laptops.nrProfiluri; i++) afisare << laptops.nrAccesari[i] << ", ";
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
		if (laptops.nrAccesari != NULL) delete[]laptops.nrAccesari;
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
		for (int i = 0; i < nrProfiluri; i++)
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


	//const int codFabricatie;
	//static int anulFabricatiei;
	//int nrProfiluri;
	//int* nrAccesari;
	//string marca;
	
	//scriere in fisier << 
	friend ofstream& operator<<(ofstream& scrie, const Laptops& l) {
		scrie <<"Cod fabricatie: "<< l.codFabricatie;
		scrie << ". Anul fabricatiei: " << l.anulFabricatiei;
		scrie << ", Nr de profiluri: " << l.nrProfiluri;
		for (int i = 0; i < l.nrProfiluri; i++) {
			scrie << " accesari versiune " << i + 1 << " este: " << l.nrAccesari[i] << ", ";
		}
		scrie << l.marca;
		return scrie;
	}

	//citire din fisier
	friend ifstream& operator>>(ifstream& citeste, Laptops& l) {
		//citeste >> l.codFabricatie;
		citeste >> l.anulFabricatiei;
		citeste >> l.nrProfiluri;
		if (l.nrAccesari != NULL) delete[]l.nrAccesari;
		l.nrAccesari = new int[l.nrProfiluri];
		for (int i = 0; i < l.nrProfiluri; i++) {
			citeste >> l.nrAccesari[i];
		}
		return citeste;
	}


	void afisare() {
		cout << "Cod fabricatie " << codFabricatie << ". Anul fabr " << anulFabricatiei << ". Marca: " << marca << ". Nr profiluri:" << nrProfiluri << ". Nr accesari pt fiecare profil: ";
		for (int i = 0; i < nrProfiluri; i++)
			cout << nrAccesari[i] << ", ";
	}
};
int Laptops::anulFabricatiei = 2023;

class ComponenteExterne {
private:
	Laptops laptops2;
	int nrVersiuni;            //fiecare versiune va avea pret diferit
	int* pretFiecareVersiune;
	string denumireComponenta;
public:

	ComponenteExterne() {
		this->nrVersiuni = 2;
		this->pretFiecareVersiune = new int [nrVersiuni] {200, 210};
		this->denumireComponenta = "Mouse";
	}

	ComponenteExterne(int nrVersiuniNou, int* preturiNoi, string denumireNoua, Laptops laptops2) {
		this->nrVersiuni = nrVersiuniNou;
		this->pretFiecareVersiune = new int[nrVersiuniNou];
		for (int i = 0; i < nrVersiuniNou; i++) {
			this->pretFiecareVersiune[i] = preturiNoi[i];
		}
		this->denumireComponenta = denumireNoua;
		this->laptops2 = laptops2;
	}

	//constr copiere 
	ComponenteExterne(const ComponenteExterne& c) {
		this->nrVersiuni = c.nrVersiuni;
		this->pretFiecareVersiune = new int[c.nrVersiuni];
		for (int i = 0; i <= c.nrVersiuni; i++) {
			pretFiecareVersiune[i] = c.pretFiecareVersiune[i];
		}
		this->denumireComponenta = c.denumireComponenta;
		this->laptops2 = c.laptops2;
	}

	//op egal
	ComponenteExterne operator=(const ComponenteExterne& c) {
		if (this != &c) {
			if (pretFiecareVersiune != NULL) delete[]pretFiecareVersiune;
			this->nrVersiuni = c.nrVersiuni;
			this->pretFiecareVersiune = new int[nrVersiuni];
			for (int i = 0; i < c.nrVersiuni; i++) {
				this->pretFiecareVersiune[i] = c.pretFiecareVersiune[i];
			}
			this->denumireComponenta = c.denumireComponenta;
			this->laptops2 = c.laptops2;
		}
		return *this;
	}

	//getters
	int getNrVersiuni() {
		return this->nrVersiuni;
	}
	int getPretFiecareVersiune(int index) {
		return this->pretFiecareVersiune[index];
	}
	string getDenumireComponenta() {
		return this->denumireComponenta;
	}
	Laptops getLaptops2() {
		return this->laptops2;
	}

	//setters
	void setNrVersiuni(int nrNouVersiuni, int* preturiNoi) {
		this->nrVersiuni = nrNouVersiuni;
		if (pretFiecareVersiune != NULL) delete[]pretFiecareVersiune;
		pretFiecareVersiune = new int[nrNouVersiuni];
		for (int i = 0; i < nrNouVersiuni; i++) {
			this->pretFiecareVersiune[i] = preturiNoi[i];
		}
	}
	void setDenumireComponenta(string dennoua) {
		this->denumireComponenta = dennoua;
	}


	//op cout
	friend ostream& operator<<(ostream& comex, const ComponenteExterne& comp) {
		comex << endl << comp.laptops2;
		comex << " Nr versiuni: " << comp.nrVersiuni << ", cu preturile :";
		for (int i = 0; i < comp.nrVersiuni; i++) {
			comex << " pt versiunea " << i + 1 << " este " << comp.pretFiecareVersiune[i] << ", ";
		}
		comex << " Nume componenta: " << comp.denumireComponenta;
		comex << endl;
		return comex;
	}


	//op cin
	friend istream& operator>>(istream& citeste, ComponenteExterne& comp) {
		cout << endl;
		citeste >> comp.laptops2;
		cout << " Nume componenta: ";
		citeste >> comp.denumireComponenta;
		cout << "Nr de versiuni: ";
		citeste >> comp.nrVersiuni;
		cout << "Preturile pt fiecare versiune: ";
		if (comp.pretFiecareVersiune != NULL) delete[]comp.pretFiecareVersiune;
		comp.pretFiecareVersiune = new int[comp.nrVersiuni];
		for (int i = 0; i < comp.nrVersiuni; i++) {
			citeste >> comp.pretFiecareVersiune[i];
		}

		return citeste;
	}

	//op preincrementare - intai aduna si dupa egaleaza
	ComponenteExterne operator++() {
		for (int i = 0; i < nrVersiuni; i++) {
			pretFiecareVersiune[i]++;
		}
		return *this;
	}

	//scriere in fisier << 
	friend ofstream& operator<<(ofstream& scrie,const ComponenteExterne& c) {
		scrie<< c.laptops2;
		scrie <<" Numele componentei: "<< c.denumireComponenta;
		scrie << ", Nr de versiuni: "<<c.nrVersiuni<<"-";
		for (int i = 0; i < c.nrVersiuni; i++) {
			scrie <<" pret versiunea"<<i+1<<" este: "<< c.pretFiecareVersiune[i]<<", ";
		}
		return scrie;
	}
	
	//citire din fisier

	friend ifstream& operator>>(ifstream& citeste, ComponenteExterne& c) {
		citeste >> c.laptops2;
		citeste >> c.nrVersiuni;
		if (c.pretFiecareVersiune != NULL) delete[]c.pretFiecareVersiune;
		c.pretFiecareVersiune = new int[c.nrVersiuni];
		for (int i = 0; i < c.nrVersiuni; i++) {
			citeste>>c.pretFiecareVersiune[i];
		}
		return citeste;
	}

	~ComponenteExterne() {
		if (pretFiecareVersiune != NULL) delete[]pretFiecareVersiune;
	}

};

class SmartPhonesCuCamera4k :public SmartPhones {
private:
	float pretTelefon4k;
	int nrCamere;
	int* megapixeli;
public:
	SmartPhonesCuCamera4k() :SmartPhones() {
		this->pretTelefon4k = 2499.99;
		this->nrCamere = 2;
		this->megapixeli = new int[nrCamere] {120,130};
	}
	
	SmartPhonesCuCamera4k(float pretNou, int camereNou, int* megapixeliNou) :SmartPhones() {
		this->pretTelefon4k = pretNou;
		this->nrCamere = camereNou;
		this->megapixeli = new int[camereNou];
		for (int i = 0; i < camereNou; i++) {
			this->megapixeli[i] = megapixeliNou[i];
		}
	}
	
	//constr copiere
	SmartPhonesCuCamera4k(const SmartPhonesCuCamera4k& s4) :SmartPhones(s4) {
		this->pretTelefon4k = s4.pretTelefon4k;
		this->nrCamere = s4.nrCamere;
		this->megapixeli = new int[s4.nrCamere];
		for (int i = 0; i < s4.nrCamere; i++) {
			this->megapixeli[i] = s4.megapixeli[i];
		}
	}

	//op=
	SmartPhonesCuCamera4k operator=(const SmartPhonesCuCamera4k& s4) {
		if (this != &s4) {
			SmartPhones::operator=(s4);
			this->pretTelefon4k = s4.pretTelefon4k;
			this->nrCamere = s4.nrCamere;
			if (megapixeli != NULL) delete[]megapixeli;
			this->megapixeli = new int[s4.nrCamere];
			for (int i = 0; i < s4.nrCamere; i++) {
				this->megapixeli[i] = s4.megapixeli[i];
			}
		}
		return *this;
	}

	//getters
	float getPretTelefon4k() {
		return this->pretTelefon4k;
	}
	int getNrCamere() {
		return this->nrCamere;
	}
	int getMexapixeli(int index) {
		return this->megapixeli[index];
	}
	string getMarca() {
		return SmartPhones::getMarca();
	}
	int getCateStocari() {
		return SmartPhones::getNrStocari();
	}

	//setters
	void setPretTelefon4k(float pretNou) {
		this->pretTelefon4k = pretNou;
	}
	void setNrCamere(int nrCamNou, int* megapixeliNoi) {
		this->nrCamere = nrCamNou;
		if (megapixeli != NULL) delete[]megapixeli;
		megapixeli = new int[nrCamNou];
		for (int i = 0; i < nrCamNou; i++) {
			this->megapixeli[i] = megapixeliNoi[i];
		}
	}
	
	void setMarca(string marcaIar) {
		SmartPhones::setMarca(marcaIar);
	}

	//op cout
	friend ostream& operator<<(ostream& scrie, const SmartPhonesCuCamera4k& sp) {
		scrie << (SmartPhones)sp;
		scrie << ". Pretul telefonului: " << sp.pretTelefon4k;
		scrie << ". Telefonul are " << sp.nrCamere << " camere cu ";
		for (int i = 0; i < sp.nrCamere; i++) {
			scrie << sp.megapixeli[i] << ", ";
		}
		scrie << " megapixeli. ";
		return scrie;
	}
	
	~SmartPhonesCuCamera4k() {
		if (megapixeli != NULL) delete[]megapixeli;
	}


};

class LaptopTouchscreen :public Laptops {
private:
	bool nevoieDePixSpecial;
	int nrMaximDeAmprentePrimite;
	int* deCateOriAFostFolositaFiecareAmprenta;
public:
	LaptopTouchscreen():Laptops(2,"Samsung") {
		this->nevoieDePixSpecial = 1;
		this->nrMaximDeAmprentePrimite = 2;
		this->deCateOriAFostFolositaFiecareAmprenta = new int[nrMaximDeAmprentePrimite] {1303, 1310};
	}
	
	LaptopTouchscreen(bool nevNoua,int maximNou,int* folositNou) :Laptops(2, "Samsung") {
		this->nevoieDePixSpecial = nevNoua;
		this->nrMaximDeAmprentePrimite = maximNou;
		this->deCateOriAFostFolositaFiecareAmprenta = new int[maximNou];
		for (int i = 0; i < maximNou; i++) {
			this->deCateOriAFostFolositaFiecareAmprenta[i] = folositNou[i];
		}
	}
	//getters
	bool getPix() {
		return nevoieDePixSpecial;
	}
	int getNrAmprMaxim() {
		return nrMaximDeAmprentePrimite;
	}
	int getDeCateOriFol(int index) {
		return deCateOriAFostFolositaFiecareAmprenta[index];
	}
	string getMarcaLaptop() {
		return Laptops::getMarca();
	}
	//setters
	void setPix(bool pixNou) {
		this->nevoieDePixSpecial = pixNou;
	}
	void setNrAmprMaxim(int nrAmprNou,int* deCateOriFAmpr) {
		this->nrMaximDeAmprentePrimite = nrAmprNou;
		this->deCateOriAFostFolositaFiecareAmprenta = new int[nrAmprNou];
		for (int i = 0; i < nrAmprNou; i++) {
			deCateOriAFostFolositaFiecareAmprenta[i] = deCateOriFAmpr[i];
		}
	}

	//op cout
	friend ostream& operator<<(ostream& scrie, const LaptopTouchscreen& lt) {
		scrie << (Laptops)lt;
		scrie << ". Are nevoie de pix special? " << (lt.nevoieDePixSpecial ? " Are nevoie " : " Nu are nevoie ") << ". Cate amprente poate inregistra maxim? " << lt.nrMaximDeAmprentePrimite << ". De cate ori a fost folosita fiecare amprenta?";
		for (int i = 0; i < lt.nrMaximDeAmprentePrimite; i++) {
			scrie<<" amprenta "<<i+1 << " de " << lt.deCateOriAFostFolositaFiecareAmprenta[i] << " ori,";
		}
		return scrie;
	}


};
 

void main() {

	Servers servers;
	Servers servers1(200.8);
	Servers servers2(2,"Linux");
	cout << servers;
	cout << servers1;
	cout << servers2;
	Servers servers3(servers1);



	setteri:
	servers3.setGradPopulare(10000);
	servers3.setStocare(500.55);
	servers3.setSistemOperare("Linux");
	servers3.setEsteSecurizat(false);
	cout << servers3;             
	cout << endl;



	getteri:
	cout << "Id servers3: " << servers3.getId() << endl;
	cout << "GradPopulare servers3: " << servers3.getGradPopulare() << endl;
	cout << "Stocare servers3: " << servers3.getStocare() << endl;
	cout << "SistemOperare servers3: " << servers3.getSistemOperare() << endl;
	cout << (servers3.getEsteSecurizat() ? "Este securizat servers3 " : "Nu e securizat servers3") << endl;
	cout << endl;

	Servers servers4;
	cin >> servers4;
	cout << servers4; 
	cout << endl;

	float stocaretotala;
	stocaretotala = (float)servers1;
	cout <<"Stocarea serverului 1 este: "<< stocaretotala;







	SmartPhones smartphones;
	cout << smartphones << endl;
	SmartPhones smartphones2("Iphone");
	cout<<smartphones2 << endl;
	SmartPhones smartphones3(1002, "Lenovo");
	cout << smartphones3<<endl;
	SmartPhones sp4(smartphones2);
	cout << sp4 << endl;


	//setters
	sp4.setAnulFabricatiei(2023);
	int dimnoi[] = { 16,32,64,124,256 };
	sp4.setNrStocari(5, dimnoi);
	sp4.setMarca("Lenovo");
	cout << sp4;
	cout << endl;
	
	
	

	//getters
	cout << "Cod fabricatie smartphone4: " << sp4.getCodFabricatie();
	cout << ". Anul fabricatiei smartphone4: " << sp4.getAnulFabricatiei();
	cout << ". Nr stocari smartphone4: " << sp4.getNrStocari();
	cout << ". Dimensiuni zone stocare smartphone4: ";
	for (int i = 0; i < sp4.getNrStocari(); i++) {
		cout << sp4.getDimensiuneZonaStocare(i)<<", ";
	}
	cout << ". Marca smartphone4: " << sp4.getMarca();
	cout << endl;

	SmartPhones sp5;
	cin >> sp5;
	cout << sp5;
	string denumire;
	denumire = (string)smartphones2;
	cout <<endl << "Denumirea smartphoneului 2 este: " << denumire;
	
	float dimensiunipesmartphone;
	dimensiunipesmartphone = (float)sp4;
	cout << "Dimensiunea medie a smartphoneului 4 este: " << dimensiunipesmartphone;

	//preincr
	SmartPhones sp6;
	sp6 = ++sp4;
	cout << endl;
	cout << endl<<"-----Preincrementarea: " << sp6 << " SIII " << sp4 << endl;
	 
	//postincr
	SmartPhones sp7;
	sp7 = sp4++;
	cout << endl << "-----Postincrementarea: " << sp7 << " SIII " << sp4 << endl;


	cout << endl;
	Laptops laptops;
	cout << laptops << endl;

	Laptops laptops1(1);
	cout << laptops1<< endl;

	Laptops laptops2(2, "Samsung");
	cout << laptops2 << endl;

	Laptops laptops3(laptops2);
	cout<<laptops3 << endl;

	//getters
	cout << "Pt laptops3:    " << laptops3.getCodFabricatie() << " " << laptops3.getanulFabricatiei() << " " << laptops3.getMarca() << " " << laptops3.getNrProfiluri();
	for (int i = 0; i < laptops3.getNrProfiluri(); i++) {
		cout <<" "<< laptops3.getNrAccesari(i);
	}
	cout << endl;
	
	//setters
	laptops3.setAnulFabricatiei(2024);
	laptops3.setMarca("Motorola");
	int accesarinoi[] = { 17,18,19,20,21 };
	laptops3.setNrProfiluri(5, accesarinoi);
	cout<<laptops3;

	Laptops laptops4;
	cin >> laptops4;
	cout << laptops4;

	string den;
	den = (string)laptops4;
	cout << endl<<"Denumirea laptopului 4 este: " << den;

	float nrmediuaccesari;
	nrmediuaccesari = (float)laptops3;
	cout <<endl<< "Nr mediu de accesari la profilurile laptopului 3 este de: " << nrmediuaccesari;


	//preincrem
	Laptops laptops5;
	laptops5 = ++laptops3;
	cout <<endl<< "-----Preincrementarea: " << laptops5 << "SIIIIIIIIi" << laptops3;
	//postincrem
	Laptops laptops6;
	laptops6 = laptops3++;
	cout << endl << "-----Postincrementarea: " << laptops6 << "SIIIIIIIIi" << laptops3;




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

	ComponenteExterne comp1;
	cout << endl << "COMP 1 ESTE" << comp1;
	int preturinoi[] = { 900,901,902 };
	ComponenteExterne comp2(3, preturinoi, " Mousepad", laptops2);
	cout << "COMP 2 ESTE " << comp2;
	ComponenteExterne comp3(comp2);
	cout << "COMP 3 ESTE " << comp3;

	//getters
	cout << "Getter: " << comp3.getLaptops2();
	cout << "Nr versiuni: " << comp3.getNrVersiuni() << " : ";
	for (int i = 0; i < comp3.getNrVersiuni(); i++) {
		cout << "versiunea" << i + 1 << " are pretul " << comp3.getPretFiecareVersiune(i) << ", ";
	}
	cout << " Denumirea componentei: " << comp3.getDenumireComponenta();

	int nrvers[] = { 123,456,789,159 };
	cout << " Componenta 3 dupa update: ";
	comp3.setNrVersiuni(4, nrvers);
	cout << comp3;

	ComponenteExterne comp4;
	cin >> comp4;

	ComponenteExterne comp5;
	comp5 = ++comp2;
	cout << "COMP 5 ESTE" << comp5;

	

	ofstream file("fisier.txt", ios::out);
	file << comp2;

	ifstream citire("fisier.txt", ios::in);
	ComponenteExterne comp10;
	cin >> comp10;
	file << comp10;              //mi a pus in fisier tot ce citisem de la tast

	/*ofstream filee("daaa.txt", ios::out);
	filee << laptops2;

	Laptops laptops10;
	cin >> laptops10;
	filee << laptops10;

	ifstream citeste("daaa.txt");
	Laptops laptopCitit;

	if (citeste)
	{
		cout << "Datele pacientului din fisierul text: " << endl;
		citeste >> laptopCitit;
		cout << laptopCitit << endl;
		citeste.close();
		cout << "Datele au fost citite cu succes!" << endl;
	}
	else
	{
		cout << "Fisierul text nu s-a putut deschide." << endl;
	}*/

	smartphones3.serializare();
	cout<< smartphones3;

	SmartPhones sp10;
	sp10.deseralizare();
	cout << sp10;

	servers2.serializare();
	cout << servers2;
	
	Servers servers10;
	servers10.deseralizare();
	cout<< servers10;
	
	SmartPhonesCuCamera4k su;
	cout << su; 
	cout << endl;
	int mega[] = { 99,100,101 };
	SmartPhonesCuCamera4k su2(3299.99, 3, mega);
	cout << su2;
	cout << endl;
	SmartPhonesCuCamera4k su3(su2);
	cout << su3;


	//getters
	cout << endl << "Marca telefonului " << su3.getMarca() << ". Nr stocari al telefonului: " << su3.getCateStocari()<< ". Pret telefon " << su3.getPretTelefon4k() << " Nr camere " << su3.getNrCamere() << " cu nr de megapixeli: ";
	for (int i = 0; i < su3.getNrCamere(); i++) {
		cout << su3.getMexapixeli(i)<<", ";
	}

	//setters
	su3.setPretTelefon4k(4999.99);
	int pixeli[] = { 200,201,202,203 };
	su3.setNrCamere(4, pixeli);
	su3.setMarca("Lovolk");
	cout<<endl << su3;

	LaptopTouchscreen lt;
	cout <<endl<<"Laptop cu touchscreen 1:" <<lt;
	int folosit[] = { 123,456,789,101 };
	LaptopTouchscreen lt1(0, 4, folosit);
	cout <<endl<<"Laptop cu touchscreen 2:"<< lt1;
	
	//getters
	cout << endl << " Are nev de pix? " << (lt1.getPix() ? "da" : "nu") << " Marca laptop: " << lt1.getMarcaLaptop() << " Nr maxim de utilizatori care pot seta o amprenta: " << lt1.getNrAmprMaxim() << " De cate ori si-a folosit fiecare utilizator amprenta: ";
	for (int i = 0; i < lt1.getNrAmprMaxim(); i++) {
		cout << " utilizatorul " << i + 1 << " a folosit de " << lt1.getDeCateOriFol(i) << " ori.";
	}

	//setters
	lt1.setPix(0);
	int ampr[] = { 12,14,15,15,71 };
	lt1.setNrAmprMaxim(5, ampr);
	cout <<endl<<" Specificatiile si informatiile laptopului 2 cu touchscreen au fost actualizate: " << lt1;

}
