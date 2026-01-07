Part one 

1. Range parseRange(const std::string& s)
Funkcija sprejme vrstico in v r.from ter r.to shrani začetek in konec razpona svežih sestavin.

2. bool contains(const Range& r, long long id) 
Funkcija preveri ali velja da je id med števili r.from in r.to

3.  bool isFresh(long long id, const std::vector<Range>& ranges)
Funkcija z uporabo contains funkcije preveri ali je id v razponu. 

4. int countFreshIDs(const std::vector<long long>& availableIDs, const std::vector<Range>& ranges)
Funkcija s for zanko za vse id s funkcijo isfresh preveri ali je sestavina sveža ali ne, če je poveča count za ena. 


Part two

1. long long countFreshFromRanges(std::vector<Range> ranges)
Funkcija najprej uredi začetke intervalov po velikosti. Nato s for zanko gremo čez vse intervale in jih združimo.
Kot zadnji razpon izračunamo razliko med najmnanjšo začetno in največjo končno številko. 

V main.cpp preberemo podatke iz input.txt za part one v dveh delih in za part two samo prvi del datoteke. 