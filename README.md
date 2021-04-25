# Galutinio balo skaičiuoklė
#### Programos veikimas
Naudotojui įvedus studentų vardus, pavardes, namų darbų pažymius bei egzamino rezultatą, apskaičiuojami galutiniai balai.
##
#### Versijos
- [v0.1](https://github.com/audronem/galutinis/tree/v0.1)
- [v0.1.1](https://github.com/audronem/galutinis/tree/v0.1.1)
- [v0.2](https://github.com/audronem/galutinis/tree/v0.2)
  - Suteikta galimybė nuskaityti duomenis iš tekstinio failo.
  - Studentai ir jų galutiniai rezultatai atspausdinami abėcėlės tvarka (pagal vardą).
- [v0.3](https://github.com/audronem/galutinis/tree/v0.3)
  - Pridėtas išimčių valdymas.
- [v0.3.1](https://github.com/audronem/galutinis/tree/v0.3)
  - Pataisytas išimčių valdymas.
- [v0.4](https://github.com/audronem/galutinis/tree/v0.4)
  - Pridėta galimybė generuoti tekstinius duomenų failus.
  - Studentai suskirstomi į dvi atskiras grupes pagal galutinį balą.
  - Testavimo laiko skaičiavimas.
- [v0.5](https://github.com/audronem/galutinis/tree/v0.4)
  - Pridėti du nauji konteineriai testavimui – *list* ir *deque*.
##
#### Programos įdiegimas ir naudojimas
#### 1 būdas:
1. Iš "Releases" atsisiųskite norimą programos versiją.
2. Išarchyvuokite failus.
3. Atsidarykite terminalą arba cmd (jeigu naudojate Windows).
4. Pakeiskite savo direktoriją į .cpp failo direktoriją. Jei failas yra C disko "Downloads" aplanke, komanda atrodytų taip:
```
cd 'C:/Users/<naudotojo vardas>/Downloads'
```
5. Sukompiliuokite failą naudojant g++:
```
g++ -o <programos pavadinimas> <cpp failo pavadinimas>.cpp
```
6. Paleiskite programą:
```
./<programos pavadinimas>
```
7. Paleidus programą, sekite jos nurodymus.
8. Suvedus visus reikiamus duomenis, ekrane bus atspausdinti rezultatai.

#### 2 būdas (nuo v0.5):
1. Iš "Releases" atsisiųskite norimą programos versiją.
2. Išarchyvuokite failus.
3. Atsidarykite terminalą arba cmd (jeigu naudojate Windows).
4. Pakeiskite savo direktoriją į .cpp failo direktoriją. Jei failas yra C disko "Downloads" aplanke, komanda atrodytų taip:
```
cd 'C:/Users/<naudotojo vardas>/Downloads'
```
5. Komandinėje eilutėje parašykite:
```
make
```
5. Paleiskite programą:
```
./programa
```
6. Paleidus programą, sekite jos nurodymus.
7. Suvedus visus reikiamus duomenis, ekrane bus atspausdinti rezultatai.
