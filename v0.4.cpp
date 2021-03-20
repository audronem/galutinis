#include <iostream>
#include <algorithm>
#include <string>
#include <random>
#include <vector>
#include <string>
#include <time.h>
#include <fstream>
#include <chrono>
#include <sstream>

#include "funkcijos.cpp"

using namespace std;

bool palyginimas(studentoinfo& a, studentoinfo& b)
{
    return a.galvid < b.galvid;
}

bool yralaimingu(studentoinfo& a){
    return a.galvid>=5;
}

void skaitymas(std::string &failopav, std::vector<studentoinfo>& studentai){
    std::ifstream f;
    if(f.fail()){
        cout<<"Klaida!"<<endl;
        exit(1);
    }
    int pazymys;
    std::string eilute;
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
    std::cout<<std::left<<std::setw(20)<<"Galutinis (vid.)";
    std::cout<<std::left<<std::setw(20)<<"Galutinis (med.)";
    std::cout<<std::endl<<std::string(80, '-')<<std::endl;
    for(size_t i=0; i<studentai.size(); i++){
        rez(&studentai[i]);
    }
}

void spausdinimasifaila(vector<studentoinfo>& studentai, string& pavadinimas){
    ofstream s(pavadinimas);
    s<<std::left<<std::setw(20)<<"Vardas";
    s<<std::left<<std::setw(20)<<"Pavarde";
    s<<std::left<<std::setw(20)<<"Galutinis (vid.)";
    s<<std::left<<std::setw(20)<<"Galutinis (med.)";
    s<<std::endl<<std::string(80, '-')<<std::endl;
    for(size_t i=0; i<studentai.size(); i++){
        s<<std::left<<std::setw(20)<<studentai[i].vardas;
        s<<std::left<<std::setw(20)<<studentai[i].pavarde;
        s<<std::left<<std::setw(20)<<std::setprecision(3)<<studentai[i].galvid<< std::setw(20)<<studentai[i].galmed<<std::endl;
    }
}

int main()
{
    srand (time(NULL));
    vector<studentoinfo> studentai;
    string failopav;
    bool baigta=false;
    if(klausimas("Generuoti failus?")){
        int pas;
        
        auto start = std::chrono::high_resolution_clock::now();

        pasirink(pas);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Generavimas uztruko " << elapsed.count() << " s\n";


        failopav="sugeneruotas1000.txt";
        ifstream f2;

        auto start2 = std::chrono::high_resolution_clock::now();
            try{
                f2.open (failopav);
                    if(f2.fail()){
                    throw "Klaida atidarant faila."s;
                    }
            }
            catch (string fail) {
            cout << fail <<endl;
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
            auto end2 = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed2 = end2 - start2;
            std::cout << "Skaitymas uztruko " << elapsed2.count() << " s\n";

            for(size_t i=0; i<studentai.size(); i++){
            skaiciuotivid(&studentai[i]);
            }
            for(size_t j=0; j<studentai.size(); j++){
            skaiciuotimed(&studentai[j]);
            }
        auto start3 = std::chrono::high_resolution_clock::now();

        sort(studentai.begin(), studentai.end(), palyginimas);

        auto end3 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed3 = end3 - start3;
        std::cout << "Rusiavimas uztruko " << elapsed3.count() << " s\n";

        auto start4 = std::chrono::high_resolution_clock::now();
        auto it=find_if(studentai.begin(), studentai.end(), yralaimingu);

        vector<studentoinfo> laimingi(studentai.end()-it);
        copy(it, studentai.end(), laimingi.begin());

        auto end4 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed4 = end4 - start4;
        std::cout << "Laimingu ieskojimas ir kopijavimas uztruko " << elapsed4.count() << " s\n";

        studentai.resize(it - studentai.begin());

        auto start5 = std::chrono::high_resolution_clock::now();

        string pavadinimas="laimingi.txt";
        spausdinimasifaila(laimingi, pavadinimas);

        string pavadinimas2="maziau_laimingi.txt";
        spausdinimasifaila(studentai, pavadinimas2);

        auto end5 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed5 = end5 - start5;
        std::cout << "Irasymas i failus uztruko " << elapsed5.count() << " s\n";

        std::chrono::duration<double> praejolaiko = elapsed+elapsed2+elapsed3+elapsed4+elapsed5;
        std::cout << "Testo laikas: " << praejolaiko.count() << " s\n";

}

    else{
        if(klausimas("Nuskaityti is failo?")){
            studentoinfo st;
            failopav="studentai10000.txt";
            ifstream f;
            try{
                f.open (failopav);
                    if(f.fail()){
                    throw "Klaida atidarant faila."s;
                    }
            }
            catch (string fail) {
            cout << fail <<endl;
            exit(1);
            }
            int pazymys;
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

    }

    
    return 0;
}
