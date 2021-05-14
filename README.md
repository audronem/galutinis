# Galutinio balo skaičiuoklė
#### Programos veikimas
Naudotojui įvedus studentų vardus, pavardes, namų darbų pažymius bei egzamino rezultatą, apskaičiuojami galutiniai balai.
### Duomenų įvedimas rankiniu būdu
Studentų duomenis prašoma įvesti rankiniu būdu – būtina įvesti studento vardą, pavardę:
```
Iveskite varda:
Vardas
Iveskite pavarde:
Pavarde
```
Tuomet paklausiama, ar naudotojas žino pažymių skaičių:
```
Ar pazymiu skaicius zinomas? | taip/ne
```
Jei naudotojas pasirenka ne, prašoma vesti pažymius ir įvesti 0, kai įvedimas bus baigtas:
```
Iveskite pazymius (0, jei norite sustabdyti): 8
Iveskite pazymius (0, jei norite sustabdyti): 6
Iveskite pazymius (0, jei norite sustabdyti): 5
Iveskite pazymius (0, jei norite sustabdyti): 7
Iveskite pazymius (0, jei norite sustabdyti): 5
Iveskite pazymius (0, jei norite sustabdyti): 3
Iveskite pazymius (0, jei norite sustabdyti): 3
Iveskite pazymius (0, jei norite sustabdyti): 8
Iveskite pazymius (0, jei norite sustabdyti): 7
Iveskite pazymius (0, jei norite sustabdyti): 5
Iveskite pazymius (0, jei norite sustabdyti): 0
```
Jei naudotojas pasirenka taip, prašoma įvesti pažymių skaičių:
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
Prideti dar viena studenta? | taip/ne
```
Pasirinkus taip, vėl atliekami tie patys veiksmai. Pasirinkus ne, programa paklausia, skaičiuoti pažymių vidurkį ar medianą:
```
Ar skaiciuoti vidurkius? (Jei ne, bus skaiciuojamos medianos)
```
Jei naudotojas pasirenka taip, atspausdinamas galutinis vidurkis, jei ne – galutinė mediana.
```
taip
Vardas              Pavarde             Galutinis   
-------------------------------------------------------
Vardas              Pavarde             5.88       
```
##
#### Versijos
- [v0.1](https://github.com/audronem/galutinis/tree/v0.1)
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
