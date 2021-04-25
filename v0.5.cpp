#include "funkcijos.h"
#include "timer.h"
#include "pasirinkduom.hpp"

using namespace std;

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

void pasirink2(int pasirinkimas2){
    std::cout<<"Pasirinkite konteineri: "<< std::endl;

    std::cout<<"1. Vector"<<std::endl;
    std::cout<<"2. List"<<std::endl;
    std::cout<<"3. Deque"<<std::endl;

    std::cin>>pasirinkimas2;

    switch (pasirinkimas2)
    {
        case 1:
        {
            std::vector<studentoinfo> studentai;
            std::vector<studentoinfo> laimingi;

            pasirinkduom(studentai);

            studentai.reserve(10000000);

            for(size_t i=0; i<studentai.size(); i++){
                skaiciuotivid(&studentai[i]);
            }

            for(size_t j=0; j<studentai.size(); j++){
                skaiciuotimed(&studentai[j]);
            }

            timer t;

            sort(studentai.begin(), studentai.end(), palyginimas);

            std::cout<<"Rusiavimas uztruko "<<t.elapsed()<<"s"<<std::endl;

            auto it=find_if(studentai.begin(), studentai.end(), yralaimingu);

            t.reset();

            laimingi.resize(studentai.end() - it);
            std::copy(it, studentai.end(), laimingi.begin());

            cout<<"Skirstymas uztruko "<<t.elapsed()<<"s"<<endl;

            std::string pavadinimas="laimingi_vector.txt";
            spausdinimasvector(laimingi, pavadinimas);

            std::string pavadinimas2="maziau_laimingi_vector.txt";
            spausdinimasvector(studentai, pavadinimas2);
            break;
            
        }

        case 2:
        {
            std::list<studentoinfo> studentai;
            std::list<studentoinfo> laimingi;

            pasirinkduom(studentai);

            for(std::list<studentoinfo>::iterator it=studentai.begin(); it!=studentai.end(); ++it){
                it->vid=0;
                it->galvid=0;
                    if(it->pazymiusk>0){
                        it->vid=rastividurki(it->pazymiai);
                        it->galvid=0.4*it->vid+0.6*it->egz;
                    }
            }

            for(std::list<studentoinfo>::iterator it=studentai.begin(); it!=studentai.end(); ++it){
                it->vid=0;
                it->galmed=0;
                    if(it->pazymiusk>0){
                        it->vid=rastimediana(it->pazymiai);
                        it->galmed=0.4*it->vid+0.6*it->egz;
                    }
            }

            timer t;

            studentai.sort(palyginimas);

            cout<<"Rusiavimas uztruko "<<t.elapsed()<<"s"<<endl;

            t.reset();

            auto it=find_if(studentai.begin(), studentai.end(), yralaimingu);

            laimingi.assign(it, studentai.end());

            studentai.erase(it, studentai.end());

            cout<<"Skirstymas uztruko "<<t.elapsed()<<"s"<<endl;

            t.reset();

            std::string pavadinimas="laimingi_list.txt";
            spausdinimaslist(laimingi, pavadinimas);

            std::string pavadinimas2="maziau_laimingi_list.txt";
            spausdinimaslist(studentai, pavadinimas2);

            cout<<"Spausdinimas uztruko "<<t.elapsed()<<"s"<<endl;

            break;
        }

        case 3:
        {
            std::deque<studentoinfo> studentai;
            std::deque<studentoinfo> laimingi;

            pasirinkduom(studentai);

            for(std::deque<studentoinfo>::iterator it=studentai.begin(); it!=studentai.end(); ++it){
                it->vid=0;
                it->galvid=0;
                    if(it->pazymiusk>0){
                        it->vid=rastividurki(it->pazymiai);
                        it->galvid=0.4*it->vid+0.6*it->egz;
                    }
            }

            for(std::deque<studentoinfo>::iterator it=studentai.begin(); it!=studentai.end(); ++it){
                it->vid=0;
                it->galmed=0;
                    if(it->pazymiusk>0){
                        it->vid=rastimediana(it->pazymiai);
                        it->galmed=0.4*it->vid+0.6*it->egz;
                    }
            }

            timer t;

            sort(studentai.begin(), studentai.end(), palyginimas);

            cout<<"Rusiavimas uztruko "<<t.elapsed()<<"s"<<endl;

            t.reset();

            auto it=find_if(studentai.begin(), studentai.end(), yralaimingu);

            laimingi.assign(it, studentai.end());

            studentai.erase(it, studentai.end());

            cout<<"Skirstymas uztruko "<<t.elapsed()<<"s"<<endl;

            t.reset();

            std::string pavadinimas="laimingi_deque.txt";
            spausdinimasdeque(laimingi, pavadinimas);

            std::string pavadinimas2="maziau_laimingi_deque.txt";
            spausdinimasdeque(studentai, pavadinimas2);

            cout<<"Spausdinimas uztruko "<<t.elapsed()<<"s"<<endl;

            break;
        }
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
        
        timer t;

        pasirink(pas);

        std::cout << "Generavimas uztruko " << t.elapsed() << " s\n";
        
        int pas2;
}
    if(klausimas("Tikrinti programos veikimo sparta?")){
        int pas2;
        pasirink2(pas2);
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
        std::cin>>st.vardas;
        cout<<"Iveskite pavarde: "<<endl;
        std::cin>>st.pavarde;
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
                std::cin>>pazymys;
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
            std::cin>>pazymys;
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
    std::cin>>st.egz;
    if((st.egz>pmax)||(st.egz<pmin)){
        cout<<"Rezultatas negali buti mazesnis uz "<<pmin<<" ir didesnis uz "<<pmax<<". Bandykite dar karta."<<endl;
        std::cin>>st.egz;
    }
    studentai.push_back(st);
    if(klausimas("Prideti dar viena studenta?")==false){
    baigta=true;
    break;
    }
    }
    }
    for(size_t i=0; i<studentai.size(); i++){
            skaiciuotivid(&studentai[i]);
            skaiciuotimed(&studentai[i]);
        }

    sort(studentai.begin(), studentai.end(), palyginimas);
    spausdinimas(studentai);

    }
    return 0;
}
