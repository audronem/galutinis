#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include "studentai.h"

const int pmin=1;
const int pmax=10;

bool klausimas(std::string);

int ivestipazymiusk();

int atsitiktinis(int, int);

double rastividurki(std::vector<int>&);

double rastimediana(std::vector<int>&);

void skaiciuotivid(studentoinfo*);

void skaiciuotimed(studentoinfo*);

void rez(studentoinfo*);

void skaitymas(std::string&, std::vector<studentoinfo>&);

void spausdinimas(std::vector<studentoinfo>&);

double galutinis(studentoinfo);

void pasirink(int);

bool palyginimas(studentoinfo& a, studentoinfo& b);

bool yralaimingu(studentoinfo& a);

void spausdinimasvector(std::vector<studentoinfo>& studentai, std::string& pavadinimas);

void spausdinimaslist(std::list<studentoinfo>& studentai, std::string& pavadinimas);

void spausdinimasdeque(std::deque<studentoinfo>& studentai, std::string& pavadinimas);

template<typename T>
void nuskaitymas(T& studentai, std::string failopav){
    std::ifstream f2;

    try{
        f2.open (failopav);
        if(f2.fail()){
            throw "Klaida atidarant faila.";
        }
    }

    catch (std::string fail) {
        std::cout << fail << std::endl;
        exit(1);
    }

    int paz;
    std::string eil;
        while (getline(f2, eil)){
            studentoinfo st2;
            std::istringstream iss(eil);
            iss>>st2.vardas;
            iss>>st2.pavarde;
                while(iss>>paz){
                    st2.pazymiai.push_back(paz);
                }
            st2.pazymiai.pop_back();
            st2.egz=paz;
            studentai.push_back(st2);
        }
    f2.close();
}

#endif
