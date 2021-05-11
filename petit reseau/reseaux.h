#pragma once
#include <memory>
#include <vector>
#include<ostream>
#include"Relations.cpp"

class reseaux
{
public:
	reseaux();
	reseaux(int langeur,int langeur_avant);////////////////////////////
	reseaux(int langeur, std::vector<std::vector<double>> whts);/////////////////////////
	reseaux& calcule(const std::vector<double>& matrice_);
	reseaux& calcule(const reseaux& avant);
	reseaux& setwht(double wht, int i, int j);
	reseaux& setwht(const std::vector<double>& matrice, const double& poid);
	std::vector<double> getmatrice();
	double getval(int position);
	double getwht(int position1,int position2);
	size_t size();
	reseaux& setDelta(const reseaux& prochant);
	reseaux& setDelta(std::vector<double> donnes);

private:
	std::vector<double> matrice_ ;
	std::vector<std::vector<double>> whts_ ;
	std::vector<double>deltas;
};

