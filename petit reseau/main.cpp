#include"GestRes.h"
#include<vector>
#include<iostream>
#include<cstdlib>

int main()
{ 
	double nbcoup;
	int temp;
	std::vector<int> dimention; 
	std::cout << "saisire la structure en suite puis -1 pour arrecter:";
	std::cin >> temp;
	while (temp>0)
	{
		dimention.push_back(temp);
		std::cin >> temp;
	}
	std::cout << "saisire le nombre de coup:";
	std::cin >> nbcoup;
	GestRes EA(dimention);
	std::vector<std::vector<std::vector<double>>> info;
	for (size_t i = 0; i < nbcoup; i++)
	{
		std::vector<double> donne;
		std::vector<double> reussi;
		std::vector<std::vector<double>> unite;
		temp= rand();
		if ((temp % 2)==0)
		{
			donne.push_back(1);
			donne.push_back(2);
			reussi.push_back(1);
		}
		else
		{
			donne.push_back(2);
			donne.push_back(1);
			reussi.push_back(0);
		}
		unite.push_back(donne);
		unite.push_back(reussi);
		info.push_back(unite);
	}
	EA.learn(info);

}