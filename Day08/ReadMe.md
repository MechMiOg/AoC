Part one:
1. Point in Connections sta strukturi. Class DSU je class, ki vsebuje uporabne funkcije find, unite in size. 

2. std::vector<Point> read_points(std::istream &file) 
Funkcija sprejme vrstico iz input.txt in jo prepiše v vektor points v treh koordinatah. 

3. long long distance_squared(const Point &a, const Point &b)
Funkcija iz koordinat ustvari razdalje dx, dy in dz ter vrne seštevek kvadratov razdalj. 

4. std::vector<Connection> build_all_connections(const std::vector<Point> &points)
Funkcija kot argument sprejme vektor points. V spremenljivko n shrani število točk. S for zanko za vsak par točk v prostoru izračuna razdaljo in jo zapiše v vektor connections. V vektor se zapišejo indekci točke iz vektorja points. 

5. long long solve_circuits(const std::vector<Point> &points, int pairs_to_connect)
Funkcija v n shrani število točk. Nato uporabi funkcijo build_all_connections. Nato sortira povezave po velikosti. Nato pripravi DSU za število n škatel. Nastavimo limit z manjšo izmed številk med connections in pairs_to_connect. dsu.unite združi s for zanko za prve najkrajše povezave. Komponenti združi, če sta različni. 
Pripravi vektor comp_sizes za seznam velikosti povezav in vektor is_first za indek komponent, ki smo jih že zabeležili. Z for zanko potujemo po vseh točkah in poiščemo komponente v katerih je i. Zanka torej pregleda vsako vozlišče, ugotovi, v katerem circuitu je in doda velikost tega circuit-a v comp_sizes, ampak samo enkrat na komponento. Nato sortiramo vektor comp_sizes. Največje tri comp_sizes zmnožimo. 



Part two

1. long long solve_last_connection_product(const std::vector<Point> &points)
Funkcija v n shrani število točk. Nato uporabi funkcijo build_all_connections, da zgradi vse možne povezave med točkami. Povezave sortira od najkrajše do najdaljše. Nato pripravi DSU za n škatel, kjer je na začetku vsaka škatla v svojem circuitu, in spremenljivko components nastavi na n (toliko komponent imamo na začetku).
V for zanki gre čez vse povezave po vrsti. Za vsako povezavo pokliče dsu.unite(a, b). Če sta bili škatli v različnih komponentah, dsu.unite vrne true in components zmanjšamo za 1. Hkrati si zapomnimo indeksa zadnje povezave (last_a, last_b), ki je dejansko združila dve različni komponenti. Ko components postane enak 1, pomeni, da so vse škatle povezane v en sam circuit; takrat je trenutna povezava zadnja, ki je bila potrebna, da se je mreža popolnoma povezala, in zanko prekinemo.
Na koncu funkcija vzame X koordinate točk z indeksoma last_a in last_b, ju zmnoži in vrne produkt.
