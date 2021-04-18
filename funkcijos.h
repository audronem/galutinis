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

#endif
