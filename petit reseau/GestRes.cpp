#include "GestRes.h"
#include <iostream>
#include <fstream>
GestRes::GestRes(std::vector<int> dimentions)
{
	for (size_t i = 1; i < dimentions.size(); i++)
	{
		ResNauro.push_back(reseaux(dimentions[i], dimentions[i - 1]));
	};
};

GestRes& GestRes::activat(std::vector<double> donnes)
{
	ResNauro[0].calcule(donnes);
	
	for (size_t  i = 1; i < ResNauro.size(); i++)
	{
		ResNauro[i].calcule(ResNauro[i - 1]);
	}
	return *this;
}

GestRes& GestRes::learn(std::vector<std::vector<std::vector<double>>> info)
{
	for (size_t i = 0; i < info.size(); i++)
	{

		activat(info[i][0]);
		std::cout << info[i][0][0];
		std::cout << info[i][1][0];
		deltas(info[i][1]);
		whts(info[i][1]);
		
		for (size_t j = 0; j < ResNauro[ResNauro.size() - 1].size(); j++)
		{
			std::cout << ResNauro[ResNauro.size() - 1].getmatrice()[j] << "::" << info[i][1][j];
		}

		std::cout  <<  std::endl << "Test n=" << i << std::endl;
	}
	return *this;
}

GestRes& GestRes::whts(const std::vector<double>& info)
{
	ResNauro[0].setwht(info,1000);
	for (size_t i = 1; i < ResNauro.size(); i++)
	{
		ResNauro[i].setwht(ResNauro[i - 1].getmatrice(), 0.1);
	}
	return *this;
}

GestRes& GestRes::deltas(const std::vector<double>& donnes)
{
	std::size_t size = ResNauro.size()-1;
	ResNauro[size].setDelta(donnes);
	size_t i = size-1;
	while (i > 0)
	{
		ResNauro[i].setDelta(ResNauro[i + 1]);
		i--;
	}
	return *this;
};
