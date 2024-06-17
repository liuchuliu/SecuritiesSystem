#include "pch.h"
#include "CSecurity.h"

CSecurity::CSecurity()
{
}

CSecurity::CSecurity(string ssmbol, string nname, double pprice, double cchangePercentage, int vvolume)
{
	this->symbol = ssmbol;
	this->name = nname;
	this->price = pprice;
	this->changePercentage = cchangePercentage;
	this->volume = vvolume;
}

void CSecurity::Load(ifstream& in)
{
	in >> symbol;
	in >> name;
	in >> price;
	in >> changePercentage;
	in >> volume;
}

void CSecurity::Save(ofstream& out)
{
	out << symbol << "\t" << name << "\t" << price << "\t" << changePercentage << "\t" << volume << endl;
}


