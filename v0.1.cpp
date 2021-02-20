#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::setprecision;
using std::setw;

const int pmin=1;
const int pmax=10;

struct studentoinfo{
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egz;
    double vidurkis;
    double mediana;
    double galutinis;
};

void vardaspavarde(studentoinfo s){
    cout<<"Iveskite studento varda: ";
    cin>>s.vardas;
    cout<<"Iveskite studento pavarde: ";
    cin>>s.pavarde;
}

bool klausimas(string kl){
    string t="taip", n="ne", ats;
    cout<<kl<<" | "<<t<<"/"<<n<<endl;
    cin>>ats;
    if(ats==t){
        return true;
    }
    else {
        return false;
    }
}

double rastividurki(vector<int> &skaiciai){
    int dydis=skaiciai.size();
    double sum=0;
    for(int i=0; i<dydis; i++){
        sum+=skaiciai[i];
    }
    return (double)sum/dydis;
}

double rastimediana(vector<int> &skaiciai){
    sort(skaiciai.begin(), skaiciai.end());
    int dydis=skaiciai.size();
    if(dydis%2!=0){
        return (double)skaiciai[dydis/2];
    }
    else{
        return (double)skaiciai[dydis/2]+skaiciai[(dydis/2)-1]/2;
    }
}

int generuotiatsitiktini(int pmin, int pmax){
    srand(time(NULL));
    return pmin+rand()%((pmax+1)-pmin);
}

void rez(studentoinfo studentas){
    cout<<studentas.vardas;
    cout.width(20);cout<<studentas.pavarde;
    cout.width(20);cout<<setprecision(2)<<studentas.galutinis<<endl;
}

void spausdinimas(vector<studentoinfo> studentai, studentoinfo studentas){
    cout<<"Vardas";
    cout.width(20); cout<<"Pavarde";
    cout.width(20); cout<<"Galutinis";
    cout<<endl<<string(50, '-')<<endl;

    int n=studentai.size();
    for(int i=0; i<n; i++){
        rez(studentai[i]);
    }
}

double galutinis(studentoinfo studentas){
    double gal=(0.4*studentas.vidurkis)+(0.6*studentas.egz);
    return gal;
}

int main()
{
    vector<studentoinfo> studentai;
    studentoinfo studentas;
    int pazymys;
    int pazsk;
    bool baigta=false;
    while(!baigta){
    vardaspavarde(studentas);
    bool inputend=false;
    if(klausimas("Ar pazymiu skaicius yra zinomas?")){
            cout<<"Iveskite pazymiu skaiciu: ";
            cin>>pazsk;
            if(klausimas("Ar generuoti atsitiktinius pazymius?")){
                for(int i=0; i<pazsk; i++){
                    pazymys=generuotiatsitiktini(pmin, pmax);
                    studentas.pazymiai.push_back(pazymys);
                }
            }
            else{
                for(int i=0; i<pazsk; i++){
                cin>>pazymys;
                studentas.pazymiai.push_back(pazymys);
                }
            }
            }
    else{
        while(!inputend){
            cout<<"Iveskite pazymius (0, jei norite sustabdyti): ";
            cin>>pazymys;
            if(pazymys==0){
                inputend=true;
                break;
            }
            else{
                studentas.pazymiai.push_back(pazymys);
            }
        }
    }
    cout<<"Iveskite egzamino rezultata: ";
    cin>>studentas.egz;
    studentas.galutinis=galutinis(studentas);
    if(klausimas("Prideti dar viena studenta?")==false)
    {
        baigta=true;
        break;
    }
    else{
     studentai.push_back(studentas);
    }
    }
    if(klausimas("Skaiciuoti vidurkius? (Jei ne, bus skaiciuojamos medianos)")){
        studentas.vidurkis=rastividurki(studentas.pazymiai);
    }
    else{
        studentas.mediana=rastimediana(studentas.pazymiai);
    }
    spausdinimas(studentai, studentas);
    return 0;
}
