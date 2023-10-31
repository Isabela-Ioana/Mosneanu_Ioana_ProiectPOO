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
	int index;

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

	void setSistemOperare(const char* sistemOperareNou){
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


	Servers():id(0){
		this->stocare =100.3;
		this->sistemOperare = new char[strlen("Windows") + 1];
		strcpy_s(this->sistemOperare, strlen("Windows") + 1, "Windows");
		this->esteSecurizat = false;
	}
	
	Servers(float stocareNoua):id(1){
		this->stocare = stocareNoua;
		this->sistemOperare = new char[strlen("Windows") + 1];
		strcpy_s(this->sistemOperare, strlen("Windows") + 1, "Windows");
		esteSecurizat = true;
	}

	Servers(const int idnou, const char* sistemOperareNou):id(idnou){
		this->stocare = 300.78;
		this->sistemOperare=new char[strlen(sistemOperareNou) + 1];
		strcpy_s(this->sistemOperare, strlen(sistemOperareNou) + 1, sistemOperareNou);
		esteSecurizat = false;
	}


	//constr de copiere:
	Servers(const Servers& s) :id(s.id){
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

	~Servers() {
		if (this->sistemOperare != NULL) delete[]this->sistemOperare;
	}

	void afisare() {
		cout << "id-" << id << " Gradul de populare minim: " << gradPopulare << ". Stocarea: " << stocare << ". Sistemul de operare folosit: " << sistemOperare << (esteSecurizat?". Serverul este securizat.":". Serverul nu este securizat.")<<endl;
	}	
};
int Servers::gradPopulare = 20;

class SmartPhones {

private:
	const int codFabricatie;
	static int anulFabricatiei;
	int stocare;
	float dimensiuneEcran;
	char* marca;

public:


	SmartPhones() :codFabricatie(1000) {
		this->stocare = 64;
		this->dimensiuneEcran = 22;
		this->marca = new char[strlen("Samsung")+1];
		strcpy_s(marca, strlen("Samsung") + 1, "Samsung");
	}

	SmartPhones(int stocareNoua) :codFabricatie(1001) {
		this->stocare = stocareNoua;
		this->dimensiuneEcran = 14;
		this->marca = new char[strlen("Iphone") + 1];
		strcpy_s(marca, strlen("Iphone") + 1, "Iphone");
	}

	SmartPhones(const int codFabricatieNou, int stocareNoua, float dimensiuneEcranNoua) :codFabricatie(codFabricatieNou) {
		this->stocare = stocareNoua;
		this->dimensiuneEcran = dimensiuneEcranNoua;
		this->marca = new char[strlen("Xiaomi") + 1];
		strcpy_s(marca, strlen("Xiaomi") + 1, "Xiaomi");
	}



	SmartPhones(const SmartPhones& p):codFabricatie(p.codFabricatie) {
		this->stocare = p.stocare;
		this->dimensiuneEcran = p.dimensiuneEcran;
		this->marca = new char[strlen(p.marca) + 1];
		strcpy_s(marca, strlen(p.marca) + 1, p.marca);
	}

	SmartPhones operator=(const SmartPhones& p) {
		if (this != &p)
		{
			if (marca != NULL) delete[]marca;
			this->stocare = p.stocare;
			this->dimensiuneEcran = p.dimensiuneEcran;
			this->marca = new char[strlen(p.marca) + 1];
			strcpy_s(marca, strlen(p.marca) + 1, p.marca);
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
	int getStocare() {
		return this->stocare;
	}
	float getDimensiuneEcran() {
		return this->dimensiuneEcran;
	}
	char* getMarca() {
		return this->marca;
	}

	//setters

	static void setAnulFabricatiei(int AnFabNou)
	{
		anulFabricatiei = AnFabNou;
	}
	
	void setStocare(int stocareNoua) {
		stocare = stocareNoua;
	}

	void setDimensiuneEcran(float dimensiuneEcranNoua) {
		
		dimensiuneEcran =dimensiuneEcranNoua;
	}

	void setMarca(const char* marcaNoua) {
		marca = new char[strlen(marcaNoua) + 1];
		strcpy_s(marca, strlen(marcaNoua) + 1, marcaNoua);
	}
	

	~SmartPhones() {
		if (marca != NULL) delete[]this->marca;
	}
	
	void afisare() {
		cout << "Codul de fabricatie:" << codFabricatie << ". Anul fabricatiei:" << anulFabricatiei << ". Stocarea este de:" << stocare << " gb. Dimensiunea ecranului fiind de " << dimensiuneEcran << " cm, iar marca este " << marca << "." << endl;
	}


};
int SmartPhones::anulFabricatiei = 2022;

class Laptops {
private:
	const int codFabricatie;
	static int anulFabricatiei;
	float dimensiuneEcran;
	char* marca;
	bool esteTouchscreen;

public:

	Laptops() :codFabricatie(0) {
		this->dimensiuneEcran = 22.4;
		this->marca = new char[strlen("Lenovo") + 1];
		strcpy_s(this->marca, strlen("Lenovo") + 1, "Lenovo");
		this->esteTouchscreen = false;
	}

	Laptops(const int codFabricatieNou) :codFabricatie(codFabricatieNou) {
		this->dimensiuneEcran = 33.5;
		this->marca = new char[strlen("Asus") + 1];
		strcpy_s(this->marca, strlen("Asus") + 1, "Asus");
		this->esteTouchscreen = true;
	}

	Laptops(float dimensiuneEcranNoua, const char* marcaNoua) :codFabricatie(2) {
		this->dimensiuneEcran = dimensiuneEcranNoua;
		this->marca = new char[strlen(marcaNoua) + 1];
		strcpy_s(this->marca, strlen(marcaNoua) + 1, marcaNoua);
		this->esteTouchscreen = false;
	}



	//constr copiere:
	Laptops(const Laptops& l) :codFabricatie(codFabricatie) {
		dimensiuneEcran = l.dimensiuneEcran;
		marca = new char[strlen(l.marca) + 1];
		strcpy_s(marca, strlen(l.marca) + 1, l.marca);
		esteTouchscreen = l.esteTouchscreen;
	}


	//op egal:
	Laptops operator=(const Laptops& l) {
		if (this != &l) {
			if (marca != NULL)
				delete[]marca;
			dimensiuneEcran = l.dimensiuneEcran;
			marca = new char[strlen(l.marca) + 1];
			strcpy_s(marca, strlen(l.marca) + 1, l.marca);
			esteTouchscreen = l.esteTouchscreen;
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
	float getDimensiuneEcran() {
		return this->dimensiuneEcran;
	}
	char* getMarca() {
		return this->marca;
	}
	bool getEsteTouchscreen() {
		return this->esteTouchscreen;
	}

	void setAnulFabricatiei(static int anulFabricatieiNou)
	{
		this->anulFabricatiei = anulFabricatieiNou;
	}
	void setDimensiuneEcran(float dimensiuneEcranNoua) {
		this->dimensiuneEcran = dimensiuneEcranNoua;
	}
	void setMarca(const char* marcaNoua) {
		if (marca != NULL) delete[]marca;
		marca = new char[strlen(marcaNoua) + 1];
		strcpy_s(marca, strlen(marcaNoua) + 1, marcaNoua);
	}
	void setEsteTouchscreen(bool esteTouchscreenNou) {
		esteTouchscreen = esteTouchscreenNou;
	}


	
	~Laptops() {
		if (marca != NULL) delete[]marca;
	}

	void afisare() {
		cout << "Cod fabricatie:" << codFabricatie << ". Anul fabricatiei:" << anulFabricatiei << ". Dimensiunea ecranului:" << dimensiuneEcran << ". Marca:" << marca << ". " << (esteTouchscreen ? " Este touchscreen." : " Nu este touchscreen.")<<endl;
		}

};
int Laptops::anulFabricatiei = 2023;

void main() {
	
	Servers servers;
	Servers servers1(200.8);
	Servers servers2(2,"Linux");
	servers.afisare();
	servers1.afisare();
	servers2.afisare();
	Servers servers3(servers1);



	//setteri:
	servers3.setGradPopulare(10000);
	servers3.setStocare(500.55);
	servers3.setSistemOperare("Linux");
	servers3.setEsteSecurizat(false);
	servers3.afisare();
	cout << endl;



	//getteri:
	cout << "Id servers3: " << servers3.getId() << endl;
	cout << "GradPopulare servers3: " << servers3.getGradPopulare() << endl;
	cout << "Stocare servers3: " << servers3.getStocare() << endl;
	cout << "SistemOperare servers3: " << servers3.getSistemOperare() << endl;
	cout << (servers3.getEsteSecurizat() ? "Este securizat servers3 " : "Nu e securizat servers3") << endl;
	cout << endl;








	SmartPhones smartphones;
	SmartPhones smartphones2(128);
	SmartPhones smartphones3(1002, 256, 33);
	smartphones.afisare();
	smartphones2.afisare();
	smartphones3.afisare();
	SmartPhones sp4(smartphones2);


	//setters
	sp4.setAnulFabricatiei(2023);
	sp4.setStocare(32);
	sp4.setDimensiuneEcran(20);
	sp4.setMarca("Lenovo");
	sp4.afisare();
	cout << endl;
	
	
	//getters
	cout <<"Cod fabricatie smartphone4: " << sp4.getCodFabricatie() << endl;
	cout << "Anul fabricatiei smartphone4: " << sp4.getAnulFabricatiei() << endl;
	cout << "Stocare smartphone4: " << sp4.getStocare()<< endl;
	cout << "Dimensiune ecran smartphone4: " << sp4.getDimensiuneEcran() << endl;
	cout << "Marca smartphone4: " << sp4.getMarca() << endl;
	cout << endl;

	



	Laptops laptops;
	Laptops laptops1(1);
	Laptops laptops2(19.29 , "Samsung");
	laptops.afisare();
	laptops1.afisare();
	laptops2.afisare();
	Laptops laptops3(laptops1);
	//getters
	cout << laptops3.getCodFabricatie() <<" "<< laptops3.getanulFabricatiei() << " " << laptops3.getDimensiuneEcran() << " " << laptops3.getMarca() << " " << (laptops3.getEsteTouchscreen()?" Este touchscreen ":" Nu este touchscreen ")<<endl;
	//setters
	laptops3.setAnulFabricatiei(2024);
	laptops3.setDimensiuneEcran(10.4);
	laptops3.setMarca("Motorola");
	laptops3.setEsteTouchscreen(false);
	laptops3.afisare();


}
