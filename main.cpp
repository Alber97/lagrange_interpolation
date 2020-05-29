#include <iostream>
#include <vector>
#include <math.h>

std::vector <double> x;
std::vector <double> y;
int xNumber, yNumber;
double buff = 0;
double polyVector[2];

void loadVectorsXY()
{
    std::cout << "Podaj ilosc wartosci X: ";
    std::cin >> xNumber;
    std::cout << "Podaj ilosc wartosci Y: ";
    std::cin >> yNumber;
    std::cout << "Podaj wartosci X:" << std::endl;
    for(int i = 0; i < xNumber; i++) std::cin >> buff; x.push_back(buff);
    std::cout << "Podaj wartosci Y:" << std::endl;
    for(int i = 0; i < yNumber; i++) std::cin >> buff; y.push_back(buff);
}

void polyFunction(double x)
{
    polyVector[1] = 1;
    polyVector[0] = (-1)* x * polyVector[1];
}

double *convFunction(double firstPoly[], double secondPoly[], int cNumber)
{
    double *resultPoly = new double[cNumber];
    for(int i = 0; i < cNumber; i++) resultPoly[i] = 0;
    for(int i = 0; i < cNumber; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            resultPoly[i + j] += firstPoly[i] * secondPoly[j];
        }
    }
    return resultPoly;
}

void coefficientTable()
{
    double * lMatrix = new double[xNumber * xNumber];
    double * vVector = new double[xNumber];
    double * cVector = new double[xNumber];
    std::cout << "Tabela L: " << std::endl;
    for(int k = 0; k < xNumber; k++)
    {
        for(int i = 0; i < xNumber; i++) vVector[i] = 0;
        vVector[0] = 1;
        for(int j = 0; j < xNumber; j++)
        {
            if(k != j)
            {
                polyFunction(x[j]);
                vVector = polyVector;
                if(j > 0)
                {
                    vVector = convFunction(vVector, polyVector, j + 1);
                    for(int i = 0; i < xNumber; i++) vVector[i] /= (x[k] - x[j]);
                }
            }
        }
        for(int i = 0; i < xNumber; i++)
        {
            lMatrix[i * xNumber + k] = vVector[i];
            std::cout << lMatrix[i * xNumber + k] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Wektor C: " << std::endl;
    for(int i = 0; i < xNumber; i++)
    {
        for(int j = 0; j < xNumber; j++)
        {
            cVector[i] += y[j] * lMatrix[j * xNumber + i];
        }
        std::cout << cVector[i] << " ";
    }
}

int main()
{
    loadVectorsXY();
    coefficientTable();
}
