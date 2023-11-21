#include<fstream>
#include<string>
#include<iostream>
#include<cmath>
using namespace std;

class CentralPolygonalNumbers
{
    public:
        CentralPolygonalNumbers();
        CentralPolygonalNumbers(int nMax);
        ~CentralPolygonalNumbers();
        void display();
        bool save(std::string strFilename);

    private:
        int m_nMax;
        int* mp_iNumbers;

};

CentralPolygonalNumbers::CentralPolygonalNumbers()
{
    m_nMax = 0; 
    mp_iNumbers = new int[1];
}

CentralPolygonalNumbers::CentralPolygonalNumbers(int nMax)
{
    m_nMax = nMax;
    mp_iNumbers = new int[m_nMax + 1]; 
}

CentralPolygonalNumbers::~CentralPolygonalNumbers()
{
    delete[] mp_iNumbers;
    std::cout << "~CentralPolygonalNumbers called" << std::endl;
}

void CentralPolygonalNumbers::display()
{
    for (int i = 0; i <= m_nMax; i++) {
        std::cout << "n: " << i << ", maximum number of pieces: " << (pow(i, 2)+i+2)/2 << std::endl;
    }
}

bool CentralPolygonalNumbers::save(string strFilename)
{
    std::ofstream ofsNumbers(strFilename + ".txt");
    for (int i = 0; i <= m_nMax; i++) {
        ofsNumbers << "n: " << i << ", maximum number of pieces: " << (pow(i, 2)+i+2)/2 << std::endl;
    }
    ofsNumbers.close();
    return false; 
}

int main()
{
    CentralPolygonalNumbers cpn(10);
    cpn.display();
    cpn.save("CPN");
}