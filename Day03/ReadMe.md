1. int maxPairValue(const std::string &s)
Funkcija kot argument sprejeme vrstico iz input.txt. Inicializira spremenljivki bestPair in maxRight. Nato s for zanko potuje skozi vsa števila od desne proti levi in preverja ali je trenutna številka večja od prej shranjene največje desne. Če je trenutna večja, jo nastavi kot največjo desno in potuje naprej. Shranjeni števili sestavimo v par in z if stavkom preverimo ali je sedanji sestavljen par večji od prejšnjega. 

2. std::string maxTwelveDigits(const std::string &s)
Funkcija definira konstantno število K, ki pove, da na koncu želimo število z 12 števkami. V številu n je shranjeno število znakov v vrstici iz input.txt, število toRemove pove koliko znakov lahko odstranimo. S for zanko pod pogoji, da sklad šrevk še ni prazen, je število to remove še vedno večje od 0 in je zadnja števka manjša od trenutne, števko odstranimo. Če ti pogoji niso izpolnjeni števko iz for zanke dodamo v sklad. Če po zanki ostane preveč znakov, ker so vile števke prevelike, string zmanjšamo na 12 znakov.

V main.cpp najprej preberemo vrstice iz input.txt, nato pa jih uporabimo v funkcijah.