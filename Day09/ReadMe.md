Part one:

1. std::vector<Point> readPoints(std::istream& in)
Funkcija prebere input in glede na vejico loči števili ter ju zapiše v x in y koordinato. 

2. long long rectangleArea(const Point& a, const Point& b)
Funkcija izračuna razdaljo med x in y koordinatama  in vrne njun zmnožek, ki predstavlja površino pravokotnika. 

3. long long largestRectangleArea(const std::vector<Point>& pts)
Funkcija se z dvema for zankama sprehodi po vseh koordinatah, uporabi funkcijo rectangleArea in primerja površini ter shrani večjo. 



