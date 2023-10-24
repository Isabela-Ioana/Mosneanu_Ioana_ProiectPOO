//Domeniu:IT
//Obiecte:  Servere, Software, Laptopuri

#include<iostream>
#include<cstring>

using namespace std;




class Servers {
public:
	const int id;
	static int gradPopulare;         //minimul obligatoriu, in procente
	float stocare;
	char* sistemOperare;
	bool esteSecurizat;

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

	~Servers() {
		if (this->sistemOperare != NULL) delete[]this->sistemOperare;
	}

	void afisare() {
		cout << "id-" << id << " Gradul de populare minim: " << gradPopulare << ". Stocarea: " << stocare << ". Sistemul de operare folosit: " << sistemOperare << (esteSecurizat?". Serverul este securizat.":". Serverul nu este securizat.")<<endl;
	}	
};
int Servers::gradPopulare = 20;

class SmartPhones {
public:
	const int codFabricatie;
	static int anulFabricatiei;
	int stocare;
	float*dimensiuneEcran;
	string marca;

	SmartPhones():codFabricatie(1000) {
		this->stocare = 64;
		this->dimensiuneEcran = new float[1];
		this->dimensiuneEcran[0] = 22;
		this->marca = "Samsung";
	}

	SmartPhones(int stocareNoua):codFabricatie(1001) {
		this->stocare = stocareNoua;
		this->dimensiuneEcran = new float[1];
		this->dimensiuneEcran[0] = 14;
		this->marca = "Iphone";
	}

	SmartPhones(const int codFabricatieNou, int stocareNoua, float dimensiuneEcranNoua) :codFabricatie(codFabricatieNou) {
		this->stocare = stocareNoua;
		this->dimensiuneEcran = new float[1];
		this->dimensiuneEcran[0] = dimensiuneEcranNoua;
		this->marca = "Xiaomi";
	}


	~SmartPhones() {
		if (dimensiuneEcran != NULL) delete[]this->dimensiuneEcran;
	}
	
	void afisare() {
		cout << "Codul de fabricatie:" << codFabricatie << ". Anul fabricatiei:" << anulFabricatiei << ". Stocarea este de:" << stocare << " gb. Dimensiunea ecranului fiind de " << dimensiuneEcran[0] << " cm, iar marca este " << marca << "." << endl;
	}


};
int SmartPhones::anulFabricatiei = 2022;

class Laptops {
public:
	const int codFabricatie;
	static int anulFabricatiei;
	float dimensiuneEcran;
	char* marca;
	bool esteTouchscreen;

	Laptops():codFabricatie(0){
		this->dimensiuneEcran = 22.4;
		this->marca = new char[strlen("Lenovo")+1];
		strcpy_s(this->marca, strlen("Lenovo")+1, "Lenovo");
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
	
	~Laptops() {
		if (marca != NULL) delete[]marca;
	}

	void afisare() {
		cout << "Cod fabricatie:" << codFabricatie << ". Anul fabricatiei:" << anulFabricatiei << ". Dimensiunea ecranului:" << dimensiuneEcran << ". Marca:" << marca << ". " << (esteTouchscreen ? " Este touchscreen." : " Nu este touchscreen.")<<endl;
		}

};
int Laptops::anulFabricatiei = 2022;

void main() {
	
	Servers servers;
	Servers servers1(200.8);
	Servers servers2(2,"Linux");
	servers.afisare();
	servers1.afisare();
	servers2.afisare();
	cout << endl;



	SmartPhones smartphones;
	SmartPhones smartphones2(128);
	SmartPhones smartphones3(1002, 256, 33);
	smartphones.afisare();
	smartphones2.afisare();
	smartphones3.afisare();
	cout << endl;



	Laptops laptops;
	Laptops laptops1(1);
	Laptops laptops2(19.29 , "Samsung");
	laptops.afisare();
	laptops1.afisare();
	laptops2.afisare();
}