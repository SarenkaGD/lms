Modu� magazynu handlowego dla LMS

demo: http://sarenka.mojasiec.com/lms/ l: demo h: Demo1234

autor - Krzysztof Michalski k.michalski(at)maxcon.pl poprawki - Grzegorz Cichowski gcichowski(at)gmail.com

Trzeba najpierw wprowadzi� grupy produkt�w, producent�w i produkty.
Dostawce towaru wprowadzamy jako klienta w naszej bazie.
Produkty do magazynu wprowadza sie poprzez dokument przyj�cia.
Po zapisaniu dokumentu przyjecia na magazyn wchodz� produkty a u dostawcy pojawia sie nadp�ata.
Rozliczenie dokumentu przyj�cia powoduje oznaczenie dokumentu jako zap�aconego, a u dostawcy pojawia si� ta kwota jako rozliczona
Sprzeda� produkt�w odbywa sie poprzez edycj� pozycji i wpisanie daty i ceny sprzeda�y lub poprzez wystawienie klientowi faktury na t� konkretn� sztuk� (modu� wyposa�ony w wyb�r pozycji z magazynu w czasie wystawiania dokumentu sprzeda�y).
Od wersji 20160401 system wyposa�ony w aktualizator dzia�aj�cy na wz�r (zupe�nie jak :P) aktualiator LMS`a.
Od wersji 20160520 istnieje mo�liwo�� importu pozycji dokumentu przyj�cia z pliku CSV - za��czony plik wzorcowy import.csv z komentarzem.

Znane problemy:
- obs�uga dokument�w koryguj�cych w zakresie stan�w magazynowych (edycja faktur w ko�cu dzia�a :)
- brak obs�ugi pozycji o krotno�ci > 1 w ramach jedenej pozycji magazynowej

TODO:
- kompletacja!

Plany na przysz�o��:
- wsparcie dla drukarek fiskalnych

Changelog:
20180307 - [BUGFIX] - poprawiono b��d przy dodawaniu do dokumentu przyj�cia pozycji o warto�ci < 1
20180220 - [FEATURE] - dodano raport zakup�w w podziale na kontrahenta (Magazyn -> Raporty)
201801?? - [FEATURE] - dodano wy�wiertlanie numeru dokumentu dla pozycji sprzedanych
