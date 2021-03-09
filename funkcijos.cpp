#include "funkcijos.h"
#include <iostream>
#include <random>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

void rez(studentoinfo* S){
    std::cout<<std::left<<std::setw(20)<<S->vardas;
    std::cout<<std::left<<std::setw(20)<<S->pavarde;
    std::cout<<std::left<<std::setw(20)<<std::setprecision(3)<<S->gal<<std::endl;
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
    S->gal=0;
    if(S->pazymiusk>0){
                S->vid=rastividurki(S->pazymiai);
                S->gal=0.4*S->vid+0.6*S->egz;
            }
}

void skaiciuotimed(studentoinfo* S){
    S->vid=0;
    S->gal=0;
    if(S->pazymiusk>0){
        S->vid=rastimediana(S->pazymiai);
            S->gal=0.4*S->vid+0.6*S->egz;
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
