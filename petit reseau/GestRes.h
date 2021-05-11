#pragma once
#include "reseaux.h"
#include <vector>
class GestRes : private reseaux
{
public:
	GestRes(std::vector<int> dimentions) ;
	//GestRes(std::ostream& fich);
	GestRes& activat(std::vector<double> donnes);
	friend std::ostream& operator<<(std::ostream& cout,const GestRes& gest) {};
	GestRes& learn(std::vector<std::vector<std::vector<double>>> info);
	

private:
	GestRes& whts(const std::vector<double>& info);
	GestRes& deltas(const std::vector<double>& attendu);
	std::vector<reseaux> ResNauro;
};

