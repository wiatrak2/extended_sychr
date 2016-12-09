
# Rozszerzony problem producenta i konsumenta

Tomasz Nanowski

Wojciech Pratkowiecki

Projekt w ramach przedmiotu Systemy Operacyjne, smestr zimowy 2016/17, II UWr

Oryginalne repozytorium: https://github.com/AThom0x7cc/SO-P1

## Opis problemu

Klasyczny problem producenta i konsumenta opiera się na dwóch rodzajach procesów - producencie i konsumencie. Producent wytwarza określony produkt, który następnie jest konsumowany przez konsumenta. Łącznikiem pomiędzy nimi jest bufor mogący pomieścić określoną ilość jednostek. Jeżeli bufor jest pusty konsument musi zaczekać na pojawienie się nowych produktów. W sytuacji przepełnionego bufora to producent musi zawiesić swoją pracę do momentu pobrania produktów od konsumenta. Problemem synchronizacji jest doprowadzenie do sytuacji, kiedy żadna z powyższych sytuacji nie nastąpi.

## Wersja rozszerzona

W wersji rozszerzonej chcemy przeprowadzić prostą symulację restauracji. Składać się ona będzie z 3 rodzajów procesów (dostawca, kelner, kucharz), 2 rodzajów obiektów (dania, składniki) oraz 3 buforów (magazyn na składniki, lista dań do przygotowania, lista dań do wydania). Każde danie będzie wymagało określonej liczby składników.

Zadania poszczególnych procesów:

* Zadaniem dostawcy będzie dostarczanie losowych składników do magazynu
* Zadaniem kelnera będzie dostarczanie losowych zamówień do wykonania oraz odbieranie gotowych dań
* Zadaniem kucharza będzie odebranie zamówienia, a następnie skompletowanie potrzebnych do niego składników i wydanie gotowego dania

Żeby zwiększyć trochę emocje, za każde wydane danie restauracja będzie otrzymywać określoną liczbę punktów, które będą wydawane na składniki. Symulacja kończy się, gdy restauracja zbankrutuje.
