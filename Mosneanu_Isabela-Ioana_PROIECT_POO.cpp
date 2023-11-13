//Domeniu:IT
//Obiecte:  Servere, Software, Laptopuri

#include<iostream>
#include<cstring>

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
			this->dimensiuneZonaStocare = new int[nrStocari]{20, 21, 22};
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

	

	SmartPhones(const SmartPhones& p):codFabricatie(p.codFabricatie) {
		this->nrStocari = p.nrStocari;
		this->dimensiuneZonaStocare = new int[nrStocari];
		this->marca = p.marca;
	}

	SmartPhones operator=(const SmartPhones& p) {
		if (this != &p)
		{
			if (dimensiuneZonaStocare != NULL) delete[]dimensiuneZonaStocare;
			this->nrStocari = p.nrStocari;
			this->dimensiuneZonaStocare = new int[nrStocari];
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
		afiseaza << "Codul de fabricatie:" << smartphones.codFabricatie << ". Anul fabricatiei:" << smartphones.anulFabricatiei << ". Numarul de stocari este de: " << smartphones.nrStocari << " gb. Dimensiunile fiind de: ";
		for (int i = 0; i < smartphones.nrStocari; i++) {
			afiseaza << smartphones.dimensiuneZonaStocare[i] << ", ";
		}
		afiseaza << ". Marca este: "<<smartphones.marca;
		return afiseaza;
	}



	//const int codFabricatie;
	//static int anulFabricatiei;
	//int nrStocari;
	//int* dimensiuneZonaStocare;
	//string marca;

	//op cin
	friend istream& operator>>(istream& citeste, SmartPhones& smartphones) {
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
		cout << "Marca noului smartphone: ";
		citeste >> smartphones.marca;
		return citeste;
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



	////constr copiere:
	//Laptops(const Laptops& l) :codFabricatie(codFabricatie) {
	//	dimensiuneEcran = l.dimensiuneEcran;
	//	marca = new char[strlen(l.marca) + 1];
	//	strcpy_s(marca, strlen(l.marca) + 1, l.marca);
	//	esteTouchscreen = l.esteTouchscreen;
	//}


	////op egal:
	//Laptops operator=(const Laptops& l) {
	//	if (this != &l) {
	//		if (marca != NULL)
	//			delete[]marca;
	//		dimensiuneEcran = l.dimensiuneEcran;
	//		marca = new char[strlen(l.marca) + 1];
	//		strcpy_s(marca, strlen(l.marca) + 1, l.marca);
	//		esteTouchscreen = l.esteTouchscreen;
	//	}
	//	return *this;
	//}

	///*const int codFabricatie;
	//static int anulFabricatiei;
	//float dimensiuneEcran;
	//char* marca;
	//bool esteTouchscreen;*/

	////getters:

	//const int getCodFabricatie() {
	//	return Laptops::codFabricatie;
	//}
	//static int getanulFabricatiei() {
	//	return Laptops::anulFabricatiei;
	//}
	//float getDimensiuneEcran() {
	//	return this->dimensiuneEcran;
	//}
	//char* getMarca() {
	//	return this->marca;
	//}
	//bool getEsteTouchscreen() {
	//	return this->esteTouchscreen;
	//}

	//void setAnulFabricatiei(static int anulFabricatieiNou)
	//{
	//	this->anulFabricatiei = anulFabricatieiNou;
	//}
	//void setDimensiuneEcran(float dimensiuneEcranNoua) {
	//	this->dimensiuneEcran = dimensiuneEcranNoua;
	//}
	//void setMarca(const char* marcaNoua) {
	//	if (marca != NULL) delete[]marca;
	//	marca = new char[strlen(marcaNoua) + 1];
	//	strcpy_s(marca, strlen(marcaNoua) + 1, marcaNoua);
	//}
	//void setEsteTouchscreen(bool esteTouchscreenNou) {
	//	esteTouchscreen = esteTouchscreenNou;
	//}


	////op cout
	//friend ostream& operator<<(ostream& afisare, const Laptops& laptops) {
	//	afisare<< "Cod fabricatie:" << laptops.codFabricatie << ". Anul fabricatiei:" << laptops.anulFabricatiei << ". Dimensiunea ecranului:" << laptops.dimensiuneEcran << ". Marca:" << laptops.marca << ". " << (laptops.esteTouchscreen ? " Este touchscreen." : " Nu este touchscreen.") << endl;
	//	return afisare;
	//}

	//
	//~Laptops() {
	//	if (marca != NULL) delete[]marca;
	//}
	/*const int codFabricatie;
	static int anulFabricatiei;
	int nrProfiluri;
	int* nrAccesari;
	string marca;*/
	void afisare() {
		cout << "Cod fabricatie " << codFabricatie << "Anul fabr " << anulFabricatiei << "Nr profiluri " << nrProfiluri << "Marca: " << marca << "Nr accesari: ";
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
	//cout << servers3;              //aici am pus cout in loc de void afisare
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

	//SmartPhones sp5;
	//cin >> sp5;
	//cout << sp5;
	//


	cout << endl;
	Laptops laptops;
	laptops.afisare();
	cout << endl;
	Laptops laptops1(1);
	laptops1.afisare();
	cout << endl;
	Laptops laptops2(2, "Samsung");
	laptops2.afisare();

	//Laptops laptops1(1);
	//Laptops laptops2(19.29 , "Samsung");
	//cout << laptops;
	//cout << laptops1;
	//cout << laptops2;
	//Laptops laptops3(laptops1);
	//
	////getters
	//cout <<"Pt laptops3:    "<< laptops3.getCodFabricatie() << " " << laptops3.getanulFabricatiei() << " " << laptops3.getDimensiuneEcran() << " " << laptops3.getMarca() << " " << (laptops3.getEsteTouchscreen() ? " Este touchscreen " : " Nu este touchscreen ") << endl;
	//
	////setters
	//laptops3.setAnulFabricatiei(2024);
	//laptops3.setDimensiuneEcran(10.4);
	//laptops3.setMarca("Motorola");
	//laptops3.setEsteTouchscreen(false);
	//cout << laptops3;


}
