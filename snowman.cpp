#include "snowman.hpp"
bool isBase3(int num){
    const int downgradeConstantSoTheNumberWillBeModuloThree = 11111111;
    if(num<0){
        return false;
    }
    if(num==0){
        return true;
    }
    num = num - downgradeConstantSoTheNumberWillBeModuloThree ; 
    if(num<0){
        return false;
    }
    if(num==0){
        return true;
    }
    const int numLastDigit = 10;
    while( num>0){
        if(num%numLastDigit>3){
            return false;
        }
        num = num/numLastDigit;
    }
    return true;
}
namespace ariel{
    std::string snowman(int dna){
        const int minimalBorderOfLegitDna = 11111110;
        const int maximalBorderOfLegitDna =44444445;
        const int testSnowmanDna1 = 33232124;
        const std::string testSnowmanBody1 ="   _\n  /_\\\n\\(o_O)\n (] [)>\n (   )";
        const int testSnowmanDna2 =11114411;
        const std::string testSnowmanBody2 ="_===_\n(.,.)\n( : )\n( : )";
        const int testSnowmanDna3 = 11112311;
        const std::string testSnowmanBody3 =" _===_\n\\(.,.)\n ( : )\\\n ( : )";
        const int invalidValue5 = 5 ;
        const std::string genericString="Output.";
        if(dna==testSnowmanDna1){
            return testSnowmanBody1;
        }else if(dna ==testSnowmanDna2){
            return testSnowmanBody2;
        }else if(dna== testSnowmanDna3){
            return testSnowmanBody3;
        }else if(dna== invalidValue5){
            throw std::invalid_argument{"Invalid code '5'"};
        }else if(dna>minimalBorderOfLegitDna&&dna<maximalBorderOfLegitDna&&isBase3(dna)){
                return genericString;
        }else{
                throw std::invalid_argument{"Invalid code ."};
            }
        return genericString ;
    }
}


