#include "reseaux.h"
#include< cmath >
reseaux::reseaux(){};
/// <summary>
/// en cours
/// </summary>
/// <param name="langeur"></param>
/// <param name="avant_lang"></param>
reseaux::reseaux(int langeur,int avant_lang)
{
    for (int i = 0; i < langeur; i++)
    {
        double val;
        matrice_.push_back(0);
        deltas.push_back(0);
        std::vector<double> ligne;
        for (int j = 0; j < avant_lang; j++)
        {
            val = rand();
            val = 1/val;
            ligne.push_back(val);
        }
        whts_.push_back(ligne);

      
    }

}
/// <summary>
/// fini
/// </summary>
/// <param name="langeur"></param>
/// <param name="whts"></param>
reseaux::reseaux(int langeur, std::vector<std::vector<double>> whts)
{

    for (int i = 0; i < langeur; i++)
    {
        matrice_.push_back(0);
    }
    whts_=whts;
};
/// <summary>
/// fini
/// </summary>
/// <param name="avant"></param>
/// <returns></returns>

reseaux& reseaux::calcule(const std::vector<double>& matrice)
{
    for (size_t i = 0; i < matrice_.size(); i++)
    {
        matrice_[i] = 0;
        for (size_t j = 0; j < matrice.size(); j++)
        {
            matrice_[i] += matrice[j] * whts_[i][j];
        }
        matrice_[i] = 1 / (1 + exp(-matrice_[i]));
    }
    return *this;
}
reseaux& reseaux::calcule(const reseaux& avant)
{
    for (size_t i = 0; i < matrice_.size(); i++)
    {
        matrice_[i] = 0;
        for (size_t j = 0; j < avant.matrice_.size(); j++)
        {
            matrice_[i] += avant.matrice_[j] * whts_[i][j];
        }
        matrice_[i] = 1 / (1 + exp(-matrice_[i]));
    }
    return *this;
}
reseaux& reseaux::setwht(double wht, int i, int j)
{
    whts_.at(i).at(j) = wht;
    return *this;
}
reseaux& reseaux::setwht(const std::vector<double>& matrice, const double& poid)
{
    for (size_t i = 0; i < matrice_.size(); i++)
    {
        for (size_t j = 0; j < matrice.size(); j++)
        {
            whts_.at(i).at(j) =whts_[i][j]+ poid * deltas[i] * matrice[j];
        }
    }
    return *this;
}
std::vector<double> reseaux::getmatrice()
{
    return matrice_;
}
double reseaux::getval(int position)
{
    return matrice_[position];
}
double reseaux::getwht(int position1, int position2)
{
    return whts_[position1][position2];
}
size_t reseaux::size()
{
    return matrice_.size();
}
reseaux& reseaux::setDelta(const reseaux& prochant)
{
    double delta;
    for (size_t i = 0; i < matrice_.size(); i++)
    {
        delta = 0;
        for (size_t j = 0; j < prochant.matrice_.size(); j++)
        {
            delta += prochant.deltas[j] * prochant.whts_[j][i];
        }
        deltas.at(i) = delta * (matrice_[i] * (1 - matrice_[i]));
    }
    return *this;
}
reseaux& reseaux::setDelta(std::vector<double> donnes)
{
    for (size_t i = 0; i < matrice_.size(); i++)
    {
        deltas.at(i) = donnes[i] - matrice_[i];
    }
    return *this;
}
/// <summary>
/// fini
/// </summary>


