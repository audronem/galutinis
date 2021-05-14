# Galutinio balo skaičiuoklė
#### Programos veikimas
Naudotojui įvedus studentų vardus, pavardes, namų darbų pažymius bei egzamino rezultatą, apskaičiuojami galutiniai balai.
### Duomenų nuskaitymas iš failo
```
Nuskaityti is failo? | t/n
```
Jei naudotojas pasirenka duomenų nuskaitymą iš failo, programa automatiškai nuskaito duomenis, apskaičiuoja vidurkius ir komandinėje eilutėje atspausdina visų studentų rezultatus.

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
