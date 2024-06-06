#define CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
enum Culoare { C_ROSU, C_NEGRU,C_ALB,C_ALBASTRU};
enum RAM{RAM_2,RAM_4,RAM_8,RAM_16};
class Dispozitiv {
	static int nrDispozitive;
	const int id;
	const int dimensiune;
	string tipDevice;
	string anLansare;
	string procesor;
	unsigned char sticker;
	char* marca;
	double varstaDevice;
	double anDeLaLansare;
	float pret;
	bool functioneaza;
	Culoare culoare;
	RAM ram;
	int* vanzariAnuale;
public:
	//constructor default
	Dispozitiv():id(nrDispozitive++), dimensiune(6)
	{
		this->tipDevice = "Smartphone";
		this->anLansare = "2019";
		this->procesor = "Apple A13";
		this->marca = new char[strlen("Apple") + 1];
		strcpy_s(this->marca, strlen("Apple") + 1, "Apple");
	    sticker=100;
		this->varstaDevice = 0;
		this->anDeLaLansare = 3;
		this->pret = 3500;
		this->functioneaza = true;
		this->culoare = C_NEGRU;
		this->ram = RAM_4;
		this->vanzariAnuale = new int[this->anDeLaLansare];
		for (int i = 0; i < anDeLaLansare; i++)
		{
			this->vanzariAnuale[i] = 200000;
		}
	}
	//constrctor cu toti parametrii
	Dispozitiv(string tipDevice, string anLansare, string procesor,const char* marca,
		unsigned char sticker, double varstaDevice, double anDeLaLansare, float pret,
		bool functioneaza, Culoare culoare, RAM ram,int*vanzariAnuale, int dimensiune) :id(nrDispozitive++), dimensiune(dimensiune)
	{
		this->tipDevice = tipDevice;
		this->anLansare = anLansare;
		this->procesor = procesor;
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
		this->sticker = sticker;
		this->varstaDevice = varstaDevice;
		this->anDeLaLansare = anDeLaLansare;
		this->pret = pret;
		this->functioneaza = functioneaza;
		this->culoare = culoare;
		this->ram = ram;
		this->vanzariAnuale = new int[this->anDeLaLansare];
		for (int i = 0; i < anDeLaLansare; i++)
		{
			this->vanzariAnuale[i] = vanzariAnuale[i];
		}
	}
	//constructor cu trei parametrii
	Dispozitiv(string tipDevice,const char* marca, float pret) :id(nrDispozitive++), dimensiune(6)
	{
		this->tipDevice = tipDevice;
		this->anLansare = "2018";
		this->procesor = "Apple A13";
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
		sticker = 100;
		this->varstaDevice = 0;
		this->anDeLaLansare = 3;
		this->pret = pret;
		this->functioneaza = true;
		this->culoare = C_NEGRU;
		this->ram = RAM_4;
		this->vanzariAnuale = new int[this->anDeLaLansare];
		for (int i = 0; i < anDeLaLansare; i++)
		{
			this->vanzariAnuale[i] = 200000;
		}
	}
	//constructor cu doi parametrii
	Dispozitiv(double varstaDevice, double anDeLaLansare) :id(nrDispozitive++), dimensiune(6)
	{
		this->tipDevice = "Smartphone";
		this->anLansare = "2019";
		this->procesor = "Apple A13";
		this->marca = new char[strlen("Apple") + 1];
		strcpy_s(this->marca, strlen("Apple") + 1, "Apple");
		sticker = 100;
		this->varstaDevice = varstaDevice;
		this->anDeLaLansare = anDeLaLansare;
		this->pret = 3500;
		this->functioneaza = true;
		this->culoare = C_ROSU;
		this->ram = RAM_4;
		this->vanzariAnuale = new int[this->anDeLaLansare];
		for (int i = 0; i < anDeLaLansare; i++)
			this->vanzariAnuale[i] = 200000;
	}
	//constructor de copiere

	Dispozitiv(const Dispozitiv& d):id(nrDispozitive++),dimensiune(d.dimensiune)
	{
		this->tipDevice = d.tipDevice;
		this->anLansare = d.anLansare;
		this->procesor = d.procesor;
		this->marca = new char[strlen(d.marca) + 1];
		strcpy_s(this->marca, strlen(d.marca) + 1, d.marca);
		sticker = d.sticker;
		this->varstaDevice = d.varstaDevice;
		this->anDeLaLansare = d.anDeLaLansare;
		this->pret = d.pret;
		this->functioneaza = d.functioneaza;
		this->culoare = d.culoare;
		this->ram = d.ram;
		this->vanzariAnuale = new int[this->anDeLaLansare];
		for (int i = 0; i < anDeLaLansare; i++)
		{
			this->vanzariAnuale[i] = d.vanzariAnuale[i];
		}
	}
	//supraincarcarea operatorului =
	Dispozitiv operator=(const Dispozitiv& original)
	{
		this->tipDevice = original.tipDevice;
		this->anLansare = original.anLansare;
		this->procesor = original.procesor;
		if (this->marca != nullptr)
			delete[] this->marca;
		this->marca = new char[strlen(original.marca) + 1];
		strcpy_s(this->marca, strlen(original.marca) + 1, original.marca);
		sticker = original.sticker;
		this->varstaDevice = original.varstaDevice;
		this->anDeLaLansare = original.anDeLaLansare;
		this->pret = original.pret;
		this->functioneaza = original.functioneaza;
		this->culoare = original.culoare;
		this->ram = original.ram;
		if (this->vanzariAnuale != nullptr)
			delete[] this->vanzariAnuale;
		this->vanzariAnuale = new int[this->anDeLaLansare];
		for (int i = 0; i < anDeLaLansare; i++)
		{
			this->vanzariAnuale[i] = original.vanzariAnuale[i];
		}
		return *this;
	}
	//destructor
	~Dispozitiv()
	{
		delete[] this->marca;
		delete[] this->vanzariAnuale;
	}
	//setteri
	void setTipDevice(string td)
	{
		this->tipDevice = td;
	}
	void setAnLansare(string al)
	{
		this->anLansare = al;
	}
	void setProcesor(string p)
	{
		this->procesor = p;
	}
	void setMarca(const char* m)
	{
		if (this->marca != nullptr)
			delete[] this->marca;
		this->marca = new char[strlen(m) + 1];
		strcpy_s(this->marca, strlen(m) + 1, m);
	}
	void setSticker(unsigned char sc)
	{
		this->sticker = sc;
	}
	void setVarstaDevice(double vd)
	{
		this->varstaDevice = vd;
	}
	void setAnDeLaLAnsare(double adll)
	{
		this->anDeLaLansare = adll;
	}
	void setPret(float pret)
	{
		this->pret = pret;
	}
	void setFunctioneaza(bool f)
	{
		this->functioneaza = f;
	}
	void setVanzariAnuale(int* va, double adll)
	{
		if (this->vanzariAnuale != nullptr)
			delete[] this->vanzariAnuale;
		setAnDeLaLAnsare(adll);
		this->vanzariAnuale = new int[this->anDeLaLansare];
		for (int i = 0; i < anDeLaLansare; i++)
		{
			this->vanzariAnuale[i] = va[i];
		}
	}
	void setCuloare(Culoare c)
	{
		this->culoare = c;
	}
	void setRam(RAM r)
	{
		this->ram= r;
	}
	//getteri
	string getTipDevice()
	{
		return this->tipDevice;
	}
	string getProcesor()
	{
		return this->procesor;
	}
	string getAnLansare()
	{
		return this->anLansare;
	}
	char* getMarca()
	{
		return this->marca;
	}
	const int GetID()
	{
		return id;
	}
	const int GetDimensiune()
	{
		return dimensiune;
	}
	static int getNrDispozitive()
	{
		return nrDispozitive;
	}
	unsigned char getSticker()
	{
		return this->sticker;
	}
	double getVarstaDevice()
	{
		return this->varstaDevice;
	}
	double getAnDeLaLansare()
	{
		return this->anDeLaLansare;
	}
	float getPret()
	{
		return this->pret;
	}
	bool getFunctioneaza()
	{
		return this->functioneaza;
	}
	int* getVanzariAnuale()
	{
		return this->vanzariAnuale;
	}
	int getVanzariAnualeIndex(int pozitie)
	{
		if (pozitie >= 0 && pozitie < anDeLaLansare)
			return this->vanzariAnuale[pozitie];
		else
			throw("Secventa de cod nu este valida");
	}
	Culoare getCuloare()
	{
		return this->culoare;
	}
	RAM getRam()
	{
		return this->ram;
	}
};
//metoda de afisare a campurilor
void Afisare(Dispozitiv &dis)
{
	cout << endl << "Device-ul cu ID " << dis.GetID() << " , dimensiune " << dis.GetDimensiune() << " de la compania " << dis.getMarca();
	cout << endl << " ,este un " << dis.getTipDevice() << " ,lansat in anul " << dis.getAnLansare() << " si are procesor " << dis.getProcesor();
	cout << endl << " stickerul are forma de " << dis.getSticker() << " device-ul si are pretul egal cu " << dis.getPret();
	cout << endl << "Au trecut " << dis.getAnDeLaLansare() << " ani si utilizatorul il are de " << dis.getVarstaDevice() << " ani";
	if (dis.getFunctioneaza() == true)
	{
		cout << endl << "Acesta functioneaza perfect";
	}
	else
	{
		cout << endl << "Este defect";
	}
	if (dis.getCuloare() == Culoare::C_ROSU)
	{
		cout << " si are culoarea rosie"<<endl;
	}
	else
		if (dis.getCuloare() == Culoare::C_NEGRU)
		{
			cout << " si are culoarea neagra"<<endl;
		}
		else
			if (dis.getCuloare() == Culoare::C_ALB)
			{
				cout << " si are culoarea alba"<<endl;
			}
			else
				if (dis.getCuloare() == Culoare::C_ALBASTRU)
				{
					cout << " si are culoarea albastra"<<endl;
				}
	if (dis.getRam() == RAM::RAM_2)
	{
		cout << "Device-ul are 2 GB RAM";
	}
	else
		if (dis.getRam() == RAM::RAM_4)
		{
			cout << "Device-ul are 4 GB RAM";
		}
		else
			if (dis.getRam() == RAM::RAM_8)
			{
				cout << "Device-ul are 8 GB RAM";
			}
			else
				if (dis.getRam() == RAM::RAM_16)
				{
					cout << "Device-ul are 16 GB RAM";
				}
	for (int i = 0; i < dis.getAnDeLaLansare(); i++)
	{
		cout << endl << "A fost vandut in anul " << i + 1 << " in numar de " << dis.getVanzariAnualeIndex(i);
	}
}
//metoda de calculare medie
float calculareMediePreturi(Dispozitiv** dis)
{
	float med;
	med = 0;
	for (int i = 0; i < 10; i++)
	{
		med = med + dis[i]->getPret();
	}
	med = med / 10;
	return med;
}
int Dispozitiv::nrDispozitive = 1;
int main()
{
	Dispozitiv** dd = new Dispozitiv * [10];
	for (int i = 0; i < 10; i++)
	{
		if (i == 1 || i == 3)
			dd[i] = new Dispozitiv();
		if (i % 2 == 0&&i<8)
			dd[i] = new Dispozitiv(3, 4);
		if (i == 5)
			dd[i] = new Dispozitiv("Calculator", "LG", 6000);
		if (i == 7)
			dd[i] = new Dispozitiv("Smartphone", "2020", "Snapdragon", "HTC", 101, 1, 2, 1950, true, C_ALB, RAM_8, new int[2] {70000, 45000}, 7);
		if (i == 9)
			dd[i] = dd[7];
		if (i == 8)
			dd[i] = new Dispozitiv(*dd[2]);
	}	
	cout << calculareMediePreturi(dd) << endl;
	dd[2]->setProcesor("Snapdragon");
	cout << endl << dd[2]->getProcesor();
	dd[2]->setAnLansare("2020");
	cout << endl << dd[2]->getAnLansare();
	dd[2]->setCuloare(C_ALBASTRU);
	cout << endl << "Device-ul 2 are culoarea albastra " << dd[2]->getCuloare();
	dd[2]->setAnDeLaLAnsare(2);
	cout << endl << dd[2]->getAnDeLaLansare();
	dd[2]->setSticker(110);
	cout << endl << "Sticker cu forma de " << dd[2]->getSticker();
	cout << endl << dd[2]->GetDimensiune();
	dd[3]->setFunctioneaza(false);
	cout << endl << "Nu functioneaza " << dd[3]->getFunctioneaza();
	dd[3]->setRam(RAM_8);
	cout << endl << "Device-ul 3 are " << dd[3]->getRam() << " adica 8GB RAM.";
	dd[4]->setMarca("HTC");
	cout << endl << dd[4]->getMarca();
	dd[4]->setPret(2650);
	cout << endl << dd[4]->getPret();
	dd[4]->setVarstaDevice(2);
	cout << endl << dd[4]->getVarstaDevice();
	dd[4]->setVanzariAnuale(new int[4] {100000, 270000, 9000, 7000}, 4);
	for (int i = 0; i < 4; i++)
	{
		cout << endl << dd[4]->getVanzariAnualeIndex(i);
	}
	cout << endl << dd[4]->getVanzariAnuale();
	dd[5]->setTipDevice("Laptop");
	cout << endl << dd[5]->getTipDevice();
	for (int i = 0; i < 10; i++)
		cout << endl << dd[i]->GetID();
	dd[1] = dd[2];
	Afisare(*dd[1]);
	Afisare(*dd[7]);
	for (int i = 0; i <= 9; i++)
	{
		dd[i] = nullptr;
		delete[] dd[i];
}
	delete[] dd;
}
//nice