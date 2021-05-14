# Galutinio balo skaičiuoklė
#### Programos veikimas
Naudotojui įvedus studentų vardus, pavardes, namų darbų pažymius bei egzamino rezultatą, apskaičiuojami galutiniai balai.
## Naudojimas
* [Tekstinių duomenų failų generavimas](#tekstinių-duomenų-failų-generavimas)
* [Duomenų nuskaitymas iš failo](#duomenų-nuskaitymas-iš-failo)
* [Duomenų įvedimas rankiniu būdu](#duomenų-įvedimas-rankiniu-būdu)
### Tekstinių duomenų failų generavimas
```
Generuoti failus? | t/n
```

Pasirinkus generuoti duomenų failus, naudotojo paprašoma įvesti generuojamų pažymių skaičių (įskaitant ir egzamino pažymį):
```
Iveskite pazymiu skaiciu:
```

Naudotojui įvedus norimą skaičių, pasiteiraujama, kiek įrašų (studentų) turi būti sugeneruota.  
```
1. 1000 irasu
2. 10000 irasu
3. 100000 irasu
4. 1000000 irasu
5. 10000000 irasu
```

Pasirinkus įrašų kiekį, programa pradeda generuoti duomenų failą.
```
3
Generuojamas 100000 irasu failas...
Generavimas uztruko 2.62263 s
```

### Testavimas
```
Tikrinti programos veikimo sparta? | t/n
```
Programa, gavusi atsakymą, pradeda vykdyti testavimą iš tekstinio failo:
```
t
Skaitymas uztruko 0.671177s
Rusiavimas uztruko 0.079814s
Skirstymas uztruko 0.038897s
```

### Duomenų nuskaitymas iš failo
```
Nuskaityti is failo? | t/n
```
Jei naudotojas pasirenka duomenų nuskaitymą iš failo, programa automatiškai nuskaito duomenis, apskaičiuoja vidurkius ir komandinėje eilutėje atspausdina rezultatus.

### Duomenų įvedimas rankiniu būdu
Atsisakius vykdyti minėtas funkcijas, studentų duomenis bus prašoma įvesti rankiniu būdu – naudotojo bus prašoma įvesti studento vardą, pavardę bei pažymius:
```
Iveskite varda:
Vardas
Iveskite pavarde:
Pavarde
Ar pazymiu skaicius zinomas? | t/n
```
Jei naudotojas pasirenka t, prašoma įvesti pažymių skaičių:
```
Iveskite pazymiu skaiciu: 10
```
Paklausiama, ar generuoti atsitiktinius pažymius (jei naudotojas pasirenka negeneruoti pažymių, įveda juos pats):
```
Ar generuoti atsitiktinius pazymius? | t/n
t
Sugeneruoti pazymiai: 
5
7
8
3
3
5
7
5
6
8
```
Prašoma įvesti egzamino rezultatą, ir, gavus atsakymą, klausiama, ar naudotojas nori pridėti dar vieną studentą:
```
Iveskite egzamino rezultata: 6
Prideti dar viena studenta? | t/n
```
Pasirinkus t, vėl atliekami tie patys veiksmai. Pasirinkus n, programa atspausdina studento duomenis ir vidurkius:
```
n
Vardas              Pavarde             Galutinis (vid.)    Galutinis (med.)    
--------------------------------------------------------------------------------
Vardas              Pavarde             5.88                5.8
```
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
##
#### Programos įdiegimas ir naudojimas
1. Iš "Releases" atsisiųskite norimą programos versiją.
2. Išarchyvuokite failus.
3. Atsidarykite terminalą arba cmd (jeigu naudojate Windows).
4. Pakeiskite savo direktoriją į .cpp failo direktoriją. Jei failas yra C disko "Downloads" aplanke, komanda atrodytų taip:
```
cd C:/Users/<naudotojo vardas>/Downloads/galutinis
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

## Benchmark rezultatai
|               |     1000      |     10000     |     100000    |    1000000    |
| ------------- | ------------- | ------------- | ------------- | ------------- |
| Skaitymas     |     0.534662  |    0.55604    |    0.520638   |    5.35669    |
| Rūšiavimas    |    0.450794   |    0.031915   |    0.438333   |    5.49843    |
| Skirstymas    |    0.020945   |    0.001995   |    0.020944   |    0.213934   |
