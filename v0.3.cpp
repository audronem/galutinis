#include <iostream>
#include <algorithm>
#include <string>
#include <random>
#include <vector>
#include <string>
#include <time.h>
#include <fstream>

#include "funkcijos.cpp"

using namespace std;

const int pmin=1;
const int pmax=10;

bool palyginimas(studentoinfo& a, studentoinfo& b)
{
    return a.vardas < b.vardas;
}

void skaitymas(std::string &failopav, std::vector<studentoinfo>& studentai){
    int pazymys;
    std::ifstream f;
    if(f.fail()){
        cout<<"Klaida!"<<endl;
        exit(1);
    }
    std::string eilute;
    getline(f, eilute);
    while(getline(f, eilute)){
            studentoinfo st;
            std::istringstream iss(eilute);
            iss>>st.vardas;
            iss>>st.pavarde;
            while(iss>>pazymys){
                st.pazymiai.push_back(pazymys);
            }
            st.pazymiai.pop_back();
            st.egz=pazymys;
            studentai.push_back(st);
        }
        f.close();
}

void spausdinimas(std::vector<studentoinfo>& studentai){
    std::cout<<std::left<<std::setw(20)<<"Vardas";
    std::cout<<std::left<<std::setw(20)<<"Pavarde";
    std::cout<<std::left<<std::setw(20)<<"Galutinis";
    std::cout<<std::endl<<std::string(50, '-')<<std::endl;
    for(size_t i=0; i<studentai.size(); i++){
        rez(&studentai[i]);
    }
}

int main()
{
    srand (time(NULL));
    vector<studentoinfo> studentai;
    bool baigta=false;
    string failopav="dgdfg.txt";
    if(klausimas("Nuskaityti is failo?")){
            ifstream f;
            f.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
            try {
                int pazymys;
                f.open (failopav);
                std::string eilute;
                getline(f, eilute);
                while (getline(f, eilute)){
                    studentoinfo st;
                    std::istringstream iss(eilute);
                    iss>>st.vardas;
                    iss>>st.pavarde;
                    while(iss>>pazymys){
                    st.pazymiai.push_back(pazymys);
                }
                st.pazymiai.pop_back();
                st.egz=pazymys;
                studentai.push_back(st);
                }
                f.close();
                }
            catch (ifstream::failure e) {
            std::cerr << "Klaida nuskaitant faila."<<endl;
            exit(1);
            }
        }

    else{
        while(!baigta){
        studentoinfo st;
        cout<<"Iveskite varda: "<<endl;
        cin>>st.vardas;
        cout<<"Iveskite pavarde: "<<endl;
        cin>>st.pavarde;
        bool inputend=false;
        if(klausimas("Ar pazymiu skaicius zinomas?")){
            st.pazymiusk=ivestipazymiusk();
            if(klausimas("Ar generuoti atsitiktinius pazymius?")){
                cout<<"Sugeneruoti pazymiai: "<<endl;
            for(int i=0; i<st.pazymiusk; i++){
                int pazymys=atsitiktinis(pmin, pmax);
                cout<<pazymys<<endl;
                st.pazymiai.push_back(pazymys);
            }
            }
            else{
            int pazymys;
            cout<<"Iveskite pazymius: ";
            for(int i=0; i<st.pazymiusk; i++){
                cin>>pazymys;
                if((pazymys>pmax)||(pazymys<pmin)){
            cout<<"Pazymys negali buti mazesnis uz "<<pmin<<" ir didesnis uz "<<pmax<<endl;
            }
                else{
                    st.pazymiai.push_back(pazymys);
                }
            }
            }
        }

     else{
            while(!inputend){
            cout<<"Iveskite pazymius (0, jei norite sustabdyti): ";
            int pazymys;
            cin>>pazymys;
            if(pazymys==0){
                inputend=true;
                break;
            }
            else if((pazymys>pmax)||(pazymys<pmin)){
                cout<<"Pazymys negali buti mazesnis uz "<<pmin<<" ir didesnis uz "<<pmax<<endl;
            }
            else{
                st.pazymiai.push_back(pazymys);
            }
        }
        }
    cout<<"Iveskite egzamino rezultata: ";
    cin>>st.egz;
    if((st.egz>pmax)||(st.egz<pmin)){
        cout<<"Rezultatas negali buti mazesnis uz "<<pmin<<" ir didesnis uz "<<pmax<<". Bandykite dar karta."<<endl;
        cin>>st.egz;
    }
    studentai.push_back(st);
    if(klausimas("Prideti dar viena studenta?")==false){
    baigta=true;
    break;
    }
    }
    }

    if(klausimas("Ar skaiciuoti vidurkius? (Jei ne, bus skaiciuojamos medianos)")){
        for(size_t i=0; i<studentai.size(); i++){
            skaiciuotivid(&studentai[i]);
        }
    }
    else{
        for(size_t i=0; i<studentai.size(); i++){
            skaiciuotimed(&studentai[i]);
        }
    }
    sort(studentai.begin(), studentai.end(), palyginimas);
    spausdinimas(studentai);
    return 0;
}
