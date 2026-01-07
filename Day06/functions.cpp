#include "functions.h"



// Izračuna vrednost ENE naloge (en stolpec)
long long computeColumnValue(const std::vector<std::vector<long long>>& numberLines,
                             const std::vector<char>& operators,
                             std::size_t columnIndex)
{
    char op = operators[columnIndex];

    // Nastavimo začetno vrednost glede na operator
    long long result;
    if (op == '+') {
        result = 0; // nevtralni element za seštevanje
    } else if (op == '*') {
        result = 1; // nevtralni element za množenje
    }

    // Gremo čez VSE vrstice in vzamemo element na indeksu columnIndex
    for (const auto& row : numberLines) {
        long long value = row[columnIndex];

        if (op == '+') {
            result += value;
        } else { // op == '*'
            result *= value;
        }
    }

    return result;
}

// Izračuna vsoto vseh nalog (vseh stolpcev)
long long computeGrandTotal(const std::vector<std::vector<long long>>& numberLines,
                            const std::vector<char>& operators)
{
    std::size_t columns = operators.size();    

    long long total = 0;

    // Za vsak stolpec posebej pokličemo computeColumnValue in prištevamo v total
    for (std::size_t col = 0; col < columns; ++col) {
        total += computeColumnValue(numberLines, operators, col);
    }

    return total;
}



//part two



long long computeGrandTotalPart2(const std::vector<std::string>& lines)
{
    if (lines.empty()) return 0;

    int H = (int)lines.size();   // število vrstic (zadnja = operatorji)

    // Največja širina vrstice
    int W = 0;
    for (const auto& row : lines) {
        if ((int)row.size() > W) W = (int)row.size();
    }

    // Naredimo "grid" z enako širino – dopolnimo kratke vrstice s presledki
    std::vector<std::string> grid = lines;
    for (auto& row : grid) {
        if ((int)row.size() < W) {
            row.append(W - row.size(), ' ');
        }
    }

    int lastRow = H - 1; // indeks zadnje vrstice (operatorji)

    // Stolpec je separator, če je VSAK znak v njem presledek
    auto isSeparatorColumn = [&](int col) {
        for (int r = 0; r < H; ++r) {
            if (grid[r][col] != ' ') return false;
        }
        return true;
    };

    long long total = 0;

    // Gremo od desnega stolpca proti levemu
    int col = W - 1;
    while (col >= 0) {
        // preskočimo prazne/separatorske stolpce
        while (col >= 0 && isSeparatorColumn(col)) {
            --col;
        }
        if (col < 0) break; // ni več nalog

        // Poiščemo levo mejo trenutne naloge
        int problemRight = col;
        int problemLeft = col;
        while (problemLeft - 1 >= 0 && !isSeparatorColumn(problemLeft - 1)) {
            --problemLeft;
        }

        // Poiščemo operator v spodnji vrstici v tem bloku
        char op = '?';
        for (int c = problemLeft; c <= problemRight; ++c) {
            char ch = grid[lastRow][c];
            if (ch == '+' || ch == '*') {
                op = ch;
                break;
            }
        }

        // Zberemo vsa števila – VSAK stolpec (tudi tisti z operatorjem!) = eno število
        std::vector<long long> nums;

        for (int c = problemLeft; c <= problemRight; ++c) {

            std::string digits;
            // gledamo vrstice 0 .. lastRow-1 (operator vrstico ignoriramo)
            for (int r = 0; r < lastRow; ++r) {
                char ch = grid[r][c];
                if (ch >= '0' && ch <= '9') {
                    digits.push_back(ch);
                }
            }

            if (!digits.empty()) {
                long long value = std::stoll(digits);
                nums.push_back(value);
            }
        }

        // Izračun vrednosti naloge
        long long value;
        if (op == '+') {
            value = 0;
            for (long long v : nums) value += v;
        } else { // op == '*'
            value = 1;
            for (long long v : nums) value *= v;
        }

        total += value;

        // Nadaljujemo z nalogo levo od trenutne
        col = problemLeft - 1;
    }

    return total;
}
