# TeamProject
# https://www.sfml-dev.org/files/SFML-2.4.2-windows-vc14-32-bit.zip
*Pobieramy, rozpakowujemy gdzies na komputerze. W konfiguracji projektu w zakładce All configurations:
C/C++->General->Additional Include podajemy ścieżkę gdzie rozpakowalismy SFML-a i do folderu include
to samo robimy w zakładce Linker->General->Additional Library Directories podajemy sciezke do folderu lib*
# Visual Studio 2017 + GIT
# Product Owner -> Grzegorz Rosiak
# Scrum Master -> Michał Miłek
# Developer team -> reszta
# Source Tree - łączymy się ze swoim repozytorium. File->Clone/new->w SourcePath podajemy sciezke do repozytorium projektu->w drugiej rubryczce okreslamy gdzie to ma sie zapisać na PC. I pracujemy w VS17 na tych plikach z tego sklonowanego repo. W zakładce *BRANCHES* wchodzimy na SWÓJ Branch i jak chcemy coś zaktualizować to:
Uncommited changes (wyswietli sie pogrubione na gorze) -> Przenosimy na górną zakładkę pliki które chcesz wrzucić (juz nie ma sensu wrzucać całego projektu tylko te pliki nasze) -> Commit -> Piszemy co dodalismy/odjelismy itp. -> Push na nasz branch (origin/Grzajko) przykładowo.
Jak chcemy zaktualizować swoje lokalne pilki to PULL-ujemy z repozytorium. Merge robi tylko Grzesiek, bo to ogarnie ;)
#Zasady pisania kodu (wspólny dla każdego):
*Każda klasa ma mieć .hpp i .cpp;
Klamerki stawiamy w taki sposób: int main(){
kod kod kod kod kod
}
Nie używamy namespace dla STD oraz SF :) *
# Klasy zaczynamy z Wielkiej litery, mają być "samoopisujące się", zmienne od małej (samoopisujące się nie żadne x,y a b c (no chyba, że dla zmiennych uzytych tylko RAZ i są skrótem np. i - iterator, t- temp ), metody też zaczynamy od małej literki i też samoopisujące się :)
