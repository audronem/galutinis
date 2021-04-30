## Turinys
* [Galutinio balo skaičiuoklė](#galutinio-balo-skaičiuoklė)  
* [Programos įdiegimas](#programos-įdiegimas)  
* [Naudojimas](#naudojimas)  
* [Versijos](#versijos)  
* [Benchmark rezultatai](#benchmark-rezultatai-naudojant-skirtingus-konteinerius-sekund%C4%97mis)
* [Testavimo sistemos parametrai](#testavimo-sistemos-parametrai)  

# Galutinio balo skaičiuoklė
Naudotojui įvedus studentų vardus, pavardes, namų darbų pažymius bei egzamino rezultatą, apskaičiuojami galutiniai balai.
## Programos įdiegimas
#### 1 būdas:
1. Iš "Releases" atsisiųskite norimą programos versiją.
2. Išarchyvuokite failus.
3. Atsidarykite komandinę eilutę.
4. Pakeiskite savo direktoriją į .cpp failo direktoriją. Jei failas yra C disko "Downloads" aplanke, komanda atrodytų taip:
```
cd 'C:/Users/<naudotojo vardas>/Downloads'
```
5. Jei pasirinkta versija turi kelis .cpp failus, sukompiliuokite objektinius kodus ir sulinkinkite juos:
```
g++ -c <cpp failo pavadinimas>.cpp <antro cpp failo pavadinimas>.cpp
```
6. Sukompiliuokite failą naudojant g++:
```
g++ -o <programos pavadinimas> <objektinio failo pavadinimas>.o <antro objektinio failo pavadinimas>.o
```
7. Paleiskite programą:
```
./<programos pavadinimas>
```

#### 2 būdas (nuo v0.5, jei turite GNU make):
1 būdo 1-4 žingsniai;  
5. Komandinėje eilutėje parašykite:
```
make
```
6. Paleiskite programą:
```
./programa
```
## Naudojimas
Paleidus programą, naudotojo paklausiama, kokią funkciją atlikti:
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

## Versijos
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
- [v0.5](https://github.com/audronem/galutinis/tree/v0.5)
  - Pridėti du nauji konteineriai testavimui – *list* ir *deque*.
- [v1.0](https://github.com/audronem/galutinis/tree/v1.0)
  - Testavimui naudojamos dvi strategijos: 1 – bendras konteineris rūšiuojamas i du naujus to paties tipo konteinerius, 2 – bendras konteineris rūšiuojamas tik į vieną naują to paties tipo konteinerį.

## Benchmark rezultatai naudojant skirtingus konteinerius (sekundėmis)
### 1000 elementų
|               |     Vector    |     List      |     Deque     |
| ------------- | ------------- | ------------- | ------------- |
| Skaitymas     |     0.00798   |    0.00696    |    0.00798    |
| Rūšiavimas    |    0.001994   |    0.000997   |    0.002992   |

### 10000 elementų
|               |     Vector    |     List      |     Deque     |
| ------------- | ------------- | ------------- | ------------- |
| Skaitymas     |    0.073832   |    0.066853   |    0.066852   |
| Rūšiavimas    |    0.030917   |    0.005984   |    0.03391    |

### 100000 elementų
|               |     Vector    |     List      |     Deque     |
| ------------- | ------------- | ------------- | ------------- |
| Skaitymas     |    0.686167   |    0.650292   |    0.627353   |
| Rūšiavimas    |    0.420902   |    0.078817   |    0.461766   |

### 1000000 elementų
|               |     Vector    |     List      |     Deque     |
| ------------- | ------------- | ------------- | ------------- |
| Skaitymas     |    7.13096    |    6.71811    |     6.6223    |
| Rūšiavimas    |    5.47138    |    1.00631    |     5.82801   |

### 10000000 elementų
|               |     Vector    |     List      |     Deque     |
| ------------- | ------------- | ------------- | ------------- |
| Skaitymas     |    **N/A**    |    63.6528    |    61.9378    |
| Rūšiavimas    |    **N/A**    |    13.0058    |    70.0549    |

## Testavimo sistemos parametrai
**CPU:** Intel Core i5-10600K @ 4.80GHz  
**RAM:** DDR4 2x8GB @ 3000MHz  
**1TB M.2 SSD**
