#include <cmath>
#include "snowman.hpp"
#include "doctest.h"
#define INT_MAX 2147483647
using namespace ariel;
#include <string>
#include <stdexcept>
using namespace std;
using namespace std;
#include <iostream>
// To return char for a value. For example '2' 
// is returned for 2. 'A' is returned for 10. 'B' 
// for 11 
char reVal(int num) 
{ 
    if (num >= 0 && num <= 9) 
        return (char)(num + '0'); 
    else
        return (char)(num - 10 + 'A'); 
} 
  
// Utility function to reverse a string 
void strev(char *str) 
{ 
    int len = strlen(str); 
    int i; 
    for (i = 0; i < len/2; i++) 
    { 
        char temp = str[i]; 
        str[i] = str[len-i-1]; 
        str[len-i-1] = temp; 
    } 
} 
  
// Function to convert a given decimal number 
// to a base 'base' and 
int fromDeci(char res[], int base, int inputNum) 
{ 
    int index = 0;  // Initialize index of result 
  
    // Convert input number is given base by repeatedly 
    // dividing it by base and taking remainder 
    while (inputNum > 0) 
    { 
        res[index++] = reVal(inputNum % base); 
        inputNum /= base; 
    } 
    res[index] = '\0'; 
  
    // Reverse the result 
    strev(res); 
  
   return  atoi( res );
} 

TEST_CASE("Good snowman test 1 .") {
    CHECK(snowman(11114411) == ("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(snowman(33232124) == ("   _\n  /_\\\n\\(o_O)\n (] [)>\n (   )"));
    CHECK(snowman(11112311) == (" _===_\n\\(.,.)\n ( : )\\\n ( : )"));
}
TEST_CASE("Test if it throws an error for every input in [0,11111111).") {
    for (int i =10000000;i<11111111;i++){
        CHECK_THROWS(snowman(i));
    }
}
TEST_CASE("Test if the throwable exception for the most of the invalid inputs is invalid_argument .") {
    for (int i =10000000;i<11111111;i++){
        CHECK_THROWS_AS(snowman(i),invalid_argument);
    }
}
TEST_CASE("Test if it gives a valid value for a between 97656 in base 10 (11111111 in base 5) to 390624 in base 10 (44444444 in base 5) ."){
    for(int i=0;i<=65535;i++){ 
        char res[100];
        CHECK_NOTHROW(snowman(fromDeci(res, 4, i)+11111111));
    }
}
TEST_CASE("Test if throws an exception for most of the invalid inputs."){
    for(int i=44444445;i<(INT_MAX/10);i=i+11111111){
        CHECK_THROWS(snowman(i));
    }
}
TEST_CASE("Test if the throwable exception the for most of the invalid inputs is invalid_argument ."){
    for(int i=44444445;i<(INT_MAX/10);i=i+11111111){
        CHECK_THROWS_AS(snowman(i),invalid_argument);
    }
}
TEST_CASE("Test if the throwable exception messege for most of the invalid inputs is Unknown Snowman Dna ."){
    for(int i=44444445;i<(INT_MAX/10);i=i+11111111){
        CHECK_THROWS_WITH(snowman(i),"Unknown Snowman Dna.");
    }
}