#pragma once
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#include <stdexcept>
#include <stdio.h>
#include <string.h>
#include <string>
namespace ariel {
std::string snowman(int dna);
}
bool isBase3(int num);
//*Following code were taken and editted from
//https://www.geeksforgeeks.org/convert-base-decimal-vice-versa/ to convert base
//10 number to a given base.
char reVal(int num);
void strev(char *str);
int fromDeci(char res[], int base, int inputNum);
