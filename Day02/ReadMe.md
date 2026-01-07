1. void parseRanges(const std::string& line, std::vector<std::pair<long long, long long>>& ranges)
Funkcija kot argument sprejme vrstico iz input.txt in vektor, ki ga polnemo s števili  začetka in konca razpona števil. 
Funkcija z while zanko poišče znak '-', ki ločuje začetno in končno stevilko. Začetni in končni številki nato prebere in ju pretvori v tip long long. 

2. std::vector<long long> collectInvalid(
    const std::vector<std::pair<long long, long long>>& ranges)
Funkcija kot argument sprejme vektor razponov števil. Z dvema for zankama za vsak razpon in nato za vsako število v razponu preveri ali je število veljavno z isValid funkcijo. 

3. long long sumAll( std::vector<long long>& nums)
Sprejme vektor števil in jih z for zanko sešteje. 


Part one 

1. bool isInvalid(long long num)
Funkcija kot argument sprejme število. Število pretvori v string, preveri, če je dolžina stringa deljiva z dva. Če je deljiva ga rezdeli na dve polovici in primerja ali sta enaki. 

Part two

2. bool isInvalid(long long num)
Funkcija sprejme število kot atgument. S for zanko preveri ali je število deljivo s števili med 1 in polovica dolžine števila. Če je deljivo ga razdelji na število delov s katerim je bila dolžina string deljiva. Prej definiramo en blok/del stringa in nato ostale dele striga preverjamo, če so enaki prvemu.