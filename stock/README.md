Modu³ magazynu handlowego dla LMS

demo: http://sarenka.mojasiec.com/lms/ l: demo h: demo

autor - Krzysztof Michalski k.michalski(at)maxcon.pl poprawki - Grzegorz Cichowski gcichowski(at)gmail.com

Trzeba najpierw wprowadziæ grupy produktów, producentów i produkty.
Dostawce towaru wprowadzamy jako klienta w naszej bazie.
Produkty do magazynu wprowadza sie poprzez dokument przyjêcia.
Po zapisaniu dokumentu przyjecia na magazyn wchodz± produkty a u dostawcy pojawia sie nadp³ata.
Rozliczenie dokumentu przyjêcia powoduje oznaczenie dokumentu jako zap³aconego, a u dostawcy pojawia siê ta kwota jako rozliczona
Sprzeda¿ produktów odbywa sie poprzez edycjê pozycji i wpisanie daty i ceny sprzeda¿y lub poprzez wystawienie klientowi faktury na t± konkretn± sztukê (modu³ wyposa¿ony w wybór pozycji z magazynu w czasie wystawiania dokumentu sprzeda¿y).
Od  wersji 20160401 system wyposa¿ony w aktualizator dzia³aj±cy na wzór (zuep³nie jak :P) aktualiator LMS`a.

Znane problemy:
- edycja dokuementu przyjêcia
- obs³uga dokumentów koryguj±cych
- brak obs³ugi pozycji o krotno¶ci > 1 w ramach jedenej pozycji magazynowej
- w przypadku zmiany dostawcy rozliczonego dokumentu przyjêcia rozliczenie nie jest przepisywane do nowego dostawcy
- na listach grup wy¶wietlane s± tylko pozycje z aktywnymi pozycjami w magazynie
- przy zmianie grupy produktu zmianie nie ulegap rzypianie pozycji magazynowych do grup

TODO:
- zablokowanie mo¿liwo¶ci wprowadzenia dwóch produktów o tym smaym numerze EAN
- filtrowanie listy produktów w ramach producenta
- szybkie zaznaczenia produktu jako sprzedanego
- mo¿liwo¶æ dodania producenta i grupy z poziomu dodawania nowej pozycji magazynowej
- przy w³±czonym wy¶wietlaniu listy pozycji sprzedanych wy¶wietlanie informacji dot. dokuemntu sprzeda¿y (dane dokumentu - numer + data, dane klienta - nazwa + id)
- kompletacja!

Plany na przysz³o¶æ:
- wsparcie dla drukarek fiskalnych
