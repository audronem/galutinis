#ifndef STUDENTOINFO_H
#define STUDENTOINFO_H

#include <iostream>
#include <string>
#include <vector>

struct studentoinfo{
    std::string vardas;
    std::string pavarde;
    int pazymiusk;
    double vid;
    double galvid;
    double galmed;
    int egz;
    std::vector<int> pazymiai;
};

#endif
