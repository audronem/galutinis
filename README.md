# Galutinio balo skaičiuoklė
#### Programos veikimas
Naudotojui įvedus studentų vardus, pavardes, namų darbų pažymius bei egzamino rezultatą, apskaičiuojami galutiniai balai.
##
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
**1TB SSD**

## Programos įdiegimas ir naudojimas
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
