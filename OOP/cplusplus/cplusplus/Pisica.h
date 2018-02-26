#pragma once
#include<string>
#include<iostream>


class Pisica
{
private:
	std::string rasa;
	int varsta;
	int nrMediuPui;
public:
	Pisica();
	Pisica(std::string ras, int var, int nrmp);
	
	void print();

	bool operator>(Pisica &a);
	void operator-=(int x);
	friend void rasaDiff(Pisica& a, Pisica lista[], int len);

	std::string getRasa() { return rasa; } 
	int getVarsta() { return varsta; }
	int getNrMPui() { return nrMediuPui; }

	void setRasa(std::string ras) { rasa = ras; }
	void setVarsta(int var) { varsta = var; }
	void setNrMPui(int nrmp) { nrMediuPui = nrmp; }
};

