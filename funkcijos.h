#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <iostream>
#include <string>
#include <vector>
#include "studentai.h"

inline bool klausimas(std::string);

inline int ivestipazymiusk();

inline int atsitiktinis(int, int);

inline double rastividurki(std::vector<int>&);

inline double rastimediana(std::vector<int>&);

inline void skaiciuotivid(studentoinfo*);

inline void skaiciuotimed(studentoinfo*);

inline void rez(studentoinfo*);

void skaitymas(std::string&, std::vector<studentoinfo>&);

void spausdinimas(std::vector<studentoinfo>&);

inline double galutinis(studentoinfo);

#endif
