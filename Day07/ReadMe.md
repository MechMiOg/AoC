Part one:
1. std::vector<std::string> readGrid je funkcija, ki iz input.txt datoteke prebere vrstice z znaki v vektor grid. 

2. long long countSplits(const std::vector<std::string>& grid) je funkcija, ki kot argument sprejme vektor grid in prešteje število razdelitev žarka. 
Najprej določi število vrstic in stolpcev, nato se postavi na zacetek vektorja in z dvema for zankama poišče začetno pozicijo 'S'. 
Vektorja std::vector<bool> beamsCur(W, false) in std::vector<bool> beamsNext(W, false) predstavljata žarek v trrenutni in naslednji vrstici. Nato se z for zanko premikamo po vrsticah in za vsako pogledamo, ali vsebuje žarek, če ga ni in naletimo na spliter nastavimo vrednosti inteksov ob spliterju v naslenji vrstci na true. Če v polju ni spliterja postavimo vrenosti istih indeksov kot v prejšnji vrstici na true. Nazadnje current beam zamenjamo za next beam in se s tem premaknemo v naslednjo vrstico.

Ti dve funkciji nato uporabimo v main.cpp

Part two:
Spet uporabimo isto funkcijo za branje imput.txt.

1.static long long dfsTimelines(
    const std::vector<std::string>& grid,
    int r,
    int c,
    std::vector<std::vector<long long>>& memo
)
Funkcija rešuje problem, če se žarek na določeni koordinati in gre navzdol, koliko časovnic bo nastalo. Na vsakem spliterju se razcepi na levo in desno možnost. Z spremenljivko memo preverimo, ali smo za določen položaj že izračunali koliko časovnic nastane, saj lahko več timelinov pripelje na isto mesto.

2. Funkcija long long countTimelines(const std::vector<std::string>& grid) spet na začetku poišče začetni položaj. Uporabi memo, da večkrat ne računa istih moznosti. Glavni klic funkcije je return dfsTimelines, ker začnemo s prvo vrstico pod 'S' in na začetnem stolpcu oz. indeksu. Funkcija sledi žarku in pri vsakem spliterju razdeli časovnico. 