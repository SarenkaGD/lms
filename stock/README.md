Modu³ magazynu handlowego dla LMS

demo: http://sarenka.mojasiec.com/lms/ l: demo h: Demo1234

autor - Krzysztof Michalski k.michalski(at)maxcon.pl poprawki - Grzegorz Cichowski gcichowski(at)gmail.com

Trzeba najpierw wprowadziæ grupy produktów, producentów i produkty.
Dostawce towaru wprowadzamy jako klienta w naszej bazie.
Produkty do magazynu wprowadza sie poprzez dokument przyjêcia.
Po zapisaniu dokumentu przyjecia na magazyn wchodz± produkty a u dostawcy pojawia sie nadp³ata.
Rozliczenie dokumentu przyjêcia powoduje oznaczenie dokumentu jako zap³aconego, a u dostawcy pojawia siê ta kwota jako rozliczona
Sprzeda¿ produktów odbywa sie poprzez edycjê pozycji i wpisanie daty i ceny sprzeda¿y lub poprzez wystawienie klientowi faktury na t± konkretn± sztukê (modu³ wyposa¿ony w wybór pozycji z magazynu w czasie wystawiania dokumentu sprzeda¿y).
Od wersji 20160401 system wyposa¿ony w aktualizator dzia³aj±cy na wzór (zupe³nie jak :P) aktualiator LMS`a.
Od wersji 20160520 istnieje mo¿liwo¶æ importu pozycji dokumentu przyjêcia z pliku CSV - za³±czony plik wzorcowy import.csv z komentarzem.

Znane problemy:
- obs³uga dokumentów koryguj±cych w zakresie stanów magazynowych (edycja faktur w koñcu dzia³a :)
- brak obs³ugi pozycji o krotno¶ci > 1 w ramach jedenej pozycji magazynowej

TODO:
- kompletacja!

Plany na przysz³o¶æ:
- wsparcie dla drukarek fiskalnych

Changelog:
20180307 - [BUGFIX] - poprawiono b³±d przy dodawaniu do dokumentu przyjêcia pozycji o warto¶ci < 1
20180220 - [FEATURE] - dodano raport zakupów w podziale na kontrahenta (Magazyn -> Raporty)
201801?? - [FEATURE] - dodano wy¶wiertlanie numeru dokumentu dla pozycji sprzedanych
