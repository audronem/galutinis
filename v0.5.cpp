#include "funkcijos.h"
#include "timer.h"

using namespace std;

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



void skaitymas(vector<studentoinfo> studentai){
    std::string failopav;
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
            
    for(int i=0; i<studentai.size(); i++){
        skaiciuotivid(&studentai[i]);
    }
    for(int j=0; j<studentai.size(); j++){
        skaiciuotimed(&studentai[j]);
    }

    sort(studentai.begin(), studentai.end(), palyginimas);

    auto it=find_if(studentai.begin(), studentai.end(), yralaimingu);
    
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

            string failopav="sugeneruotas1000.txt";
        
            ifstream f2;
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

            for(size_t i=0; i<studentai.size(); i++){
            skaiciuotivid(&studentai[i]);
            }
            for(size_t j=0; j<studentai.size(); j++){
            skaiciuotimed(&studentai[j]);
            }

            sort(studentai.begin(), studentai.end(), palyginimas);

            auto it=find_if(studentai.begin(), studentai.end(), yralaimingu);

            timer t;

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

            string failopav="sugeneruotas1000.txt";
        
            ifstream f2;
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

            //for(int i=0; i<studentai.size(); i++){
            //skaiciuotivid(studentai[i]);
            //}
            //for(int j=0; j<studentai.size(); j++){
            //skaiciuotimed(studentai[j]);
            //}

            sort(studentai.begin(), studentai.end(), palyginimas);

            auto it=find_if(studentai.begin(), studentai.end(), yralaimingu);

            std::list<studentoinfo>::iterator it;

            it=find_if(studentai.begin(), studentai.end(), yralaimingu);

            timer t;

            laimingi.assign(it, studentai.end());

            cout<<"Skirstymas uztruko "<<t.elapsed()<<"s"<<endl;

            std::string pavadinimas="laimingi_list.txt";
            spausdinimaslist(laimingi, pavadinimas);

            std::string pavadinimas2="maziau_laimingi_list.txt";
            spausdinimaslist(studentai, pavadinimas2);
            break;
        }

        case 3:
        {
            std::deque<studentoinfo> studentai;
            std::deque<studentoinfo> laimingi;

            string failopav="sugeneruotas1000.txt";
        
            ifstream f2;
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

            for(size_t i=0; i<studentai.size(); i++){
            skaiciuotivid(&studentai[i]);
            }
            for(size_t j=0; j<studentai.size(); j++){
            skaiciuotimed(&studentai[j]);
            }

            sort(studentai.begin(), studentai.end(), palyginimas);

            std::deque<studentoinfo>::iterator it=find(studentai.begin(), studentai.end(), yralaimingu);

            timer t;

            laimingi.assign(it, studentai.end());

            cout<<"Skirstymas uztruko "<<t.elapsed()<<"s"<<endl;

            std::string pavadinimas="laimingi_deque.txt";
            spausdinimasdeque(laimingi, pavadinimas);

            std::string pavadinimas2="maziau_laimingi_deque.txt";
            spausdinimasdeque(studentai, pavadinimas2);
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
        
        auto start = std::chrono::high_resolution_clock::now();

        pasirink(pas);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Generavimas uztruko " << elapsed.count() << " s\n";
        
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
