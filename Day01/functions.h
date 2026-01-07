#pragma once
#include <string>


int rotacije(int trenutna, char smer, int sprememba);
void parseRotation(const std::string& line, char& direction, int& value);
int processInput(std::istream& in);
