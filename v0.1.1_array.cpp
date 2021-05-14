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
    double med;
    double gal;
    int egz;
    int *P;
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

void skaiciuotivid(studentoinfo* S, int dydis){
    S->vid=0;
    S->gal=0;
    if(S->pazymiusk>0){
                S->vid=rastividurki(S->P, S->pazymiusk);
                S->gal=0.4*S->vid+0.6*S->egz;
            }
}

void skaiciuotimed(studentoinfo* S, int dydis){
    S->med=0;
    S->gal=0;
    if(S->pazymiusk>0)
            S->med=rastimediana(S->P, S->pazymiusk);
            S->gal=0.4*S->med+0.6*S->egz;
}

void rez(studentoinfo* S){
    cout<<left<<setw(20)<<S->vardas;
    cout<<left<<setw(20)<<S->pavarde;
    cout<<left<<setw(20)<<setprecision(3)<<S->gal<<endl;
}

void spausdinimas(studentoinfo* S, int n){
    cout<<left<<setw(20)<<"Vardas";
    cout<<left<<setw(20)<<"Pavarde";
    cout<<left<<setw(20)<<"Galutinis";
    cout<<endl<<string(50, '-')<<endl;
    for(int i=0; i<n; i++){
        rez(&S[i]);
    }
}

void sekantis(int *&A, int &s, int k){
    int *Naujas=new int[s+1];
    Naujas[s]=k;
    delete[] A;
    A=Naujas;
    s++;
}

void kopijuoti(int *A2, int *A1, int s){
    for(int i=0; i<s; i++){
        A1[i]=A2[i];
    }
}

void kitasstudentas(studentoinfo *&studentai, int &n, studentoinfo st){
    studentoinfo *Naujas=new studentoinfo[n+1];
    for(int i=0; i<n; i++){
        Naujas[i]=studentai[i];
    }
    Naujas[n]=st;
    delete[] studentai;
    studentai=Naujas;
    n++;
}

void atlaisvinimas(studentoinfo* studentai, int& n){
    for(int i=0; i<n; i++){
        delete[] studentai[i].P;
    }
    delete[] studentai;
}

int main()
{
    srand (time(NULL));
    int n=0;
    studentoinfo *S=new studentoinfo[n];
    studentoinfo st;
    bool baigta=false;
    while(!baigta){
        cout<<"Iveskite varda: "<<endl;
        cin>>st.vardas;
        cout<<"Iveskite pavarde: "<<endl;
        cin>>st.pavarde;
        bool inputend=false;
        if(klausimas("Ar pazymiu skaicius zinomas?")){
            st.pazymiusk=ivestipazymiusk();
            st.P=new int[st.pazymiusk];
            if(klausimas("Ar generuoti atsitiktinius pazymius?")){
                cout<<"Sugeneruoti pazymiai: "<<endl;
            for(int i=0; i<st.pazymiusk; i++){
                st.P[i]=atsitiktinis(pmin, pmax);
                cout<<st.P[i]<<endl;
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
                    st.P[i]=pazymys;
                    sekantis(st.P, st.pazymiusk, pazymys);
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
                sekantis(st.P, st.pazymiusk, pazymys);
            }
        }
    }
    cout<<"Iveskite egzamino rezultata: ";
    cin>>st.egz;
    if((st.egz>pmax)||(st.egz<pmin)){
        cout<<"Rezultatas negali buti mazesnis uz "<<pmin<<" ir didesnis uz "<<pmax<<". Bandykite dar karta."<<endl;
        cin>>st.egz;
    }
    kitasstudentas(S, n, st);
    if(klausimas("Prideti dar viena studenta?")==false){
    baigta=true;
    break;
    }
    }

    if(klausimas("Ar skaiciuoti vidurkius? (Jei ne, bus skaiciuojamos medianos)")){
        for(int i=0; i<n; i++){
            skaiciuotivid(&S[i], n);
        }
    }
    else{
        for(int i=0; i<n; i++){
            skaiciuotimed(&S[i], n);
        }
    }
    spausdinimas(S, n);
    atlaisvinimas(S, n);
    return 0;
}
