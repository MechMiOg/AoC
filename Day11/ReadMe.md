Part one:

1. static long long dfs(const std::string &u) 
Funkcija `dfs(u)` izračuna, koliko različnih poti vodi iz vozlišča `u` do vozlišča `out`. Če je `u` že `out`, vrne 1, ker smo našli eno veljavno pot. Če smo za to vozlišče rezultat že prej izračunali, ga vzamemo iz slovarja `memo`, da se izognemo ponovnemu računskemu delu. Sicer za vsakega naslednika vozlišča `u` rekurzivno pokličemo `dfs` in seštejemo število poti, ki vodijo naprej. Nato dobljeni rezultat shranimo v `memo` in ga vrnemo. Tako DFS preišče vse možne poti v globino, memoizacija pa poskrbi, da se vsako vozlišče izračuna samo enkrat.

Funkcijo sem našla na strani https://www.geeksforgeeks.org/dsa/depth-first-search-or-dfs-for-a-graph/

2. void solve()
Funkcija prebere podatke iz input.txt in jih loči na začetek in ostalo ter podatke shrani v from in rest. Nato koda zgradi seznam izhodnih povezav za posamezno napravo. Najprej iz niza rest, ki vsebuje imena naprav na desni strani vrstice, naredi std::stringstream, iz katerega nato bere besede eno po eno. V zanki while (ss >> to) se vsako ime naprave shrani v spremenljivko to; branje uspe dokler v nizu ostajajo še elementi, ločeni s presledki. Za vsako tako ime doda povezavo v graf: izraz g[from] vrne (ali po potrebi ustvari) vektor sosedov za napravo from, push_back(to) pa vanj doda novo ciljno napravo. Tako se za vsak vhodni zapis zgradi seznam vseh naprav, do katerih lahko podatki tečejo iz dane naprave.



