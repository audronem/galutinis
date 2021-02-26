#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <random>

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
    int *P;
};

void vardaspavarde(studentoinfo S){
    cout<<"Iveskite varda: ";
    cin>>S.vardas;
    cout<<"Iveskite pavarde: ";
    cin>>S.pavarde;
}

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
        cout<<"Klaidinga ivestis.";
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
    srand(time(NULL));
    return pmin+rand()%((pmax+1)-pmin);
}

double rastividurki(int* A, int dydis){
    int sum=0;
    for(int i=0; i<dydis; i++){
        sum+=A[i];
    }
    return (double)sum/(double)dydis;
}

double rastimediana(int* A, int dydis){
    sort(A, A+dydis);
    if(dydis%2!=0){
        return(double)A[dydis/2];
    }
    return (double(A[(dydis-1)/2]+A[dydis/2])/2.0);
}

void skaiciavimas(studentoinfo* S, int dydis){
    S->vid=0;
    S->gal=0;
    if(klausimas("Skaiciuoti vidurkius? (Jei ne, bus skaiciuojamos medianos")){
            if(S->pazymiusk>0){
                S->vid=rastividurki(S->P, dydis);
                S->gal=0.4*S->vid+0.6*S->egz;
            }
        else{
            if(S->pazymiusk>0)
            S->vid=rastimediana(S->P, dydis);
        }
    }

}

double galutinis(studentoinfo studentas){
    double gal=(0.4*studentas.vid)+(0.6*studentas.egz);
    return gal;
}

void rez(studentoinfo* S){
    cout<<S->vardas;
    cout.width(20);cout<<S->pavarde;
    cout.width(20);cout<<setprecision(2)<<S->gal<<endl;
}

void spausdinimas(studentoinfo* S, int n){
    cout<<"Vardas";
    cout.width(20); cout<<"Pavarde";
    cout.width(20); cout<<"Galutinis";
    cout<<endl<<string(50, '-')<<endl;
    for(int i=0; i<n; i++){
        rez(&S[i]);
    }
}

void atlaisvinimas(studentoinfo* studentai, int& n){
    for(int i=0; i<n; i++){
        delete[] studentai[i].P;
    }
    delete[] studentai;
}

int main()
{
    int sk=0;
    studentoinfo *S=new studentoinfo[sk];
    studentoinfo studentas;
    bool baigta=false;
    int n=sizeof(&studentas.P)/sizeof(&studentas.P[0]);
    while(!baigta){
        vardaspavarde(studentas);
        bool inputend=false;
        if(klausimas("Ar pazymiu skaicius zinomas?")){
            studentas.pazymiusk=ivestipazymiusk();
            studentas.P=new int[studentas.pazymiusk];
            if(klausimas("Ar generuoti atsitiktinius pazymius?")){
            for(int i=0; i<studentas.pazymiusk; i++){
                studentas.P[i]=atsitiktinis(pmin, pmax);
            }
            }
            else{
            int pazymys;
            cout<<"Iveskite pazymius: ";
            for(int i=0; i<studentas.pazymiusk; i++){
                cin>>pazymys;
                if(pazymys>pmax||pazymys<pmin){
            cout<<"Pazymys negali buti mazesnis uz "<<pmin<<" ir didesnis uz "<<pmax;
            }
                else{
                    studentas.P[i]=pazymys;
                }
            }
            }
        }
     else{
        while(!inputend){
            cout<<"Iveskite pazymius (0, jei norite sustabdyti): ";
            int a=0, pazymys;
            cin>>pazymys;
            if(pazymys==0){
                inputend=true;
                break;
            }
            else{
                studentas.P[a]=pazymys;
                a++;
            }
        }
    }
    cout<<"Iveskite egzamino rezultata: ";
    cin>>studentas.egz;
    studentas.gal=galutinis(studentas);

    if(klausimas("Prideti dar viena studenta?")==false){
    baigta=true;
    break;
    }
    }


     if(klausimas("Skaiciuoti vidurkius? (Jei ne, bus skaiciuojamos medianos)")){
        studentas.vid=rastividurki(studentas.P, n);
    }
    else{
        studentas.vid=rastimediana(studentas.P, n);
    }
    spausdinimas(S, n);
    atlaisvinimas(S, n);
    return 0;
}
