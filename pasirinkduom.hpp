#include <vector>

template<typename T>
void pasirinkduom(T& studentai){
    std::cout<<"Pasirinkite duomenu dydi:"<<std::endl;
    std::cout<<"1. 1000 elementu"<<std::endl;
    std::cout<<"2. 10000 elementu"<<std::endl;
    std::cout<<"3. 100000 elementu"<<std::endl;
    std::cout<<"4. 1000000 elementu"<<std::endl;
    std::cout<<"5. 10000000 elementu"<<std::endl;

    int atsakymas;
    std::cin>>atsakymas;

    if(atsakymas==1){
        std::string failopav="sugeneruotas1000.txt";
        timer t;
        nuskaitymas(studentai, failopav);
        std::cout<<"Skaitymas uztruko "<<t.elapsed()<<"s"<<std::endl;
    }

    else if(atsakymas==2){
        std::string failopav="sugeneruotas10000.txt";
        timer t;
        nuskaitymas(studentai, failopav);
        std::cout<<"Skaitymas uztruko "<<t.elapsed()<<"s"<<std::endl;
    }

    else if(atsakymas==3){
        std::string failopav="sugeneruotas100000.txt";
        timer t;
        nuskaitymas(studentai, failopav);
        std::cout<<"Skaitymas uztruko "<<t.elapsed()<<"s"<<std::endl;
    }

    else if(atsakymas==4){
        std::string failopav="sugeneruotas1000000.txt";
        timer t;
        nuskaitymas(studentai, failopav);
        std::cout<<"Skaitymas uztruko "<<t.elapsed()<<"s"<<std::endl;
    }

    else if(atsakymas==5){
        std::string failopav="sugeneruotas10000000.txt";
        timer t;
        nuskaitymas(studentai, failopav);
        std::cout<<"Skaitymas uztruko "<<t.elapsed()<<"s"<<std::endl;
    }
}
