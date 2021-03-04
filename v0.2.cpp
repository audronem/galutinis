#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <random>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const int pmin=1;
const int pmax=10;

struct studentoinfo{
    string vardas;
    string pavarde;
    int pazymiusk;
    double vid;
    double gal;
    int egz;
    vector<int> pazymiai;
};

bool klausimas(string kl){
    string t="taip", n="ne", ats;
    cout<<kl<<" | "<<t<<"/"<<n<<endl;
    cin>>ats;
    if(ats==t){
        return true;
    }
    else if(ats==n){
        return false;
    }
    else{
        cout<<"Klaidinga ivestis. Bandykite dar karta"<<endl;
        cin>>ats;
    }
}

int ivestipazymiusk(){
    int pazsk;
    cout<<"Iveskite pazymiu skaiciu: ";
    cin>>pazsk;

    while(pazsk<=0){
        cout<<"Klaidinga ivestis."<<endl;
        cin>>pazsk;
    }
    return pazsk;
}

int atsitiktinis(int pmin, int pmax){
    return pmin+rand()%((pmax+1)-pmin);
}

double rastividurki(vector<int> &skaiciai){
    int sum=0;
    int dydis=skaiciai.size();
    for(int i=0; i<dydis; i++){
        sum+=skaiciai[i];
    }
    return (double)sum/(double)dydis;
}

double rastimediana(vector<int> &skaiciai){
    sort(skaiciai.begin(), skaiciai.end());
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

void rez(studentoinfo* S){
    cout<<left<<setw(20)<<S->vardas;
    cout<<left<<setw(20)<<S->pavarde;
    cout<<left<<setw(20)<<setprecision(3)<<S->gal<<endl;
}

void spausdinimas(vector<studentoinfo>& studentai){
    cout<<left<<setw(20)<<"Vardas";
    cout<<left<<setw(20)<<"Pavarde";
    cout<<left<<setw(20)<<"Galutinis";
    cout<<endl<<string(50, '-')<<endl;
    for(size_t i=0; i<studentai.size(); i++){
        rez(&studentai[i]);
    }
}

bool palyginimas(studentoinfo& a, studentoinfo& b){
    return a.vardas < b.vardas;
}

void skaitymas(string &failopav, vector<studentoinfo>& studentai){
    ifstream f;
    f.open(failopav);
    if(f.fail()){
    cout<<"Klaida!"<<endl;
    exit(1);
    }
    int pazymys;
    string eilute;
    getline(f, eilute);
    while(getline(f, eilute)){
        studentoinfo st;
        istringstream iss(eilute);
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

int main()
{
    srand (time(NULL));
    vector<studentoinfo> studentai;
    bool baigta=false;
    string failopav="kursiokai.txt";
    if(klausimas("Nuskaityti is failo?")){
            skaitymas(failopav, studentai);
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
