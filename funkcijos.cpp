#include "funkcijos.h"
#include <iostream>
#include <random>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

void rez(studentoinfo* S){
    std::cout<<std::left<<std::setw(20)<<S->vardas;
    std::cout<<std::left<<std::setw(20)<<S->pavarde;
    std::cout<<std::left<<std::setw(20)<<std::setprecision(3)<<S->galvid<< std::setw(20)<<S->galmed<<std::endl;
}

int ivestipazymiusk(){
    int pazsk;
    std::cout<<"Iveskite pazymiu skaiciu: ";
    std::cin>>pazsk;

    while(pazsk<=0){
        std::cout<<"Klaidinga ivestis."<<std::endl;
        std::cin>>pazsk;
    }
    return pazsk;
}

inline int atsitiktinis(int pmin, int pmax){
    return pmin+rand()%((pmax+1)-pmin);
}

double rastividurki(std::vector<int> &skaiciai){
    int sum=0;
    int dydis=skaiciai.size();
    for(int i=0; i<dydis; i++){
        sum+=skaiciai[i];
    }
    return (double)sum/(double)dydis;
}

double rastimediana(std::vector<int> &skaiciai){
    std::sort(skaiciai.begin(), skaiciai.end());
    int dydis=skaiciai.size();
    if(dydis%2!=0){
        return(double)skaiciai[dydis/2];
    }
    return (double(skaiciai[(dydis-1)/2]+skaiciai[dydis/2])/2.0);
}

double galutinis(studentoinfo studentas){
    double gal=(0.4*studentas.vid)+(0.6*studentas.egz);
    return gal;
}

void skaiciuotivid(studentoinfo* S){
    S->vid=0;
    S->galvid=0;
    if(S->pazymiusk>0){
                S->vid=rastividurki(S->pazymiai);
                S->galvid=0.4*S->vid+0.6*S->egz;
            }
}

void skaiciuotimed(studentoinfo* S){
    S->vid=0;
    S->galmed=0;
    if(S->pazymiusk>0){
        S->vid=rastimediana(S->pazymiai);
            S->galmed=0.4*S->vid+0.6*S->egz;
    }
}

bool klausimas(std::string kl){
    std::string t="taip", n="ne", ats;
    std::cout<<kl<<" | "<<t<<"/"<<n<<std::endl;
    std::cin>>ats;
    if(ats==t){
        return true;
    }
    else if(ats==n){
        return false;
    }
    else{
        std::cout<<"Klaidinga ivestis. Bandykite dar karta"<<std::endl;
        std::cin>>ats;
    }
}

void pasirink(int pasirinkimas){
    int pskaicius;
    std::cout<<"Iveskite pazymiu skaiciu: ";
    std::cin>>pskaicius;

    std::cout<<"1. 1000 irasu"<<std::endl;
    std::cout<<"2. 10000 irasu"<<std::endl;
    std::cout<<"3. 100000 irasu"<<std::endl;
    std::cout<<"4. 1000000 irasu"<<std::endl;
    std::cout<<"5. 10000000 irasu"<<std::endl;
    std::cin>>pasirinkimas;

    switch (pasirinkimas)
    {
        case 1:
        {
            std::ofstream isvedimas("sugeneruotas1000.txt");
            std::cout << "Generuojamas 1000 irasu failas...\n";
            for(int i=1; i<=1000; i++){
                isvedimas<<"Vardas"<<i<<" Pavarde"<<i<<" ";
                for(int j=0; j<pskaicius+1; j++){
                    isvedimas<<atsitiktinis(pmin, pmax)<<" ";
                }
                isvedimas<<std::endl;
            }
            break;
        }
        case 2:
        {
            std::ofstream isvedimas("sugeneruotas10000.txt");
            std::cout << "Generuojamas 10000 irasu failas...\n";
            for(int i=1; i<=10000; i++){
                isvedimas<<"Vardas"<<i<<" Pavarde"<<i<<" ";
                for(int j=0; j<pskaicius+1; j++){
                    isvedimas<<atsitiktinis(pmin, pmax)<<" ";
                }
                isvedimas<<std::endl;
            }
            break;
        }
        case 3:
        {
            std::ofstream isvedimas("sugeneruotas100000.txt");
            std::cout << "Generuojamas 100000 irasu failas...\n";
            for(int i=1; i<=100000; i++){
                isvedimas<<"Vardas"<<i<<" Pavarde"<<i<<" ";
                for(int j=0; j<pskaicius+1; j++){
                    isvedimas<<atsitiktinis(pmin, pmax)<<" ";
                }
                isvedimas<<std::endl;
            }
            break;
        }
        case 4:
        {
            std::ofstream isvedimas("sugeneruotas1000000.txt");
            std::cout << "Generuojamas 1000000 irasu failas...\n";
            for(int i=1; i<=1000000; i++){
                isvedimas<<"Vardas"<<i<<" Pavarde"<<i<<" ";
                for(int j=0; j<pskaicius+1; j++){
                    isvedimas<<atsitiktinis(pmin, pmax)<<" ";
                }
                isvedimas<<std::endl;
            }
            break;
        }
        case 5:
        {
            std::ofstream isvedimas("sugeneruotas10000000.txt");
            std::cout << "Generuojamas 10000000 irasu failas...\n";
            for(int i=1; i<=10000000; i++){
                isvedimas<<"Vardas"<<i<<" Pavarde"<<i<<" ";
                for(int j=0; j<pskaicius+1; j++){
                    isvedimas<<atsitiktinis(pmin, pmax)<<" ";
                }
                isvedimas<<std::endl;
            }
            break;
        }

        default:
        std::cout << "Netinkamas pasirinkimas. \n";
        std::cout << "Rinkites dar karta.\n";
        std::cin >> pasirinkimas;
        break;
    }
}
