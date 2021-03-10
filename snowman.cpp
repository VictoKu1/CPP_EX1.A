#pragma once
#include "snowman.hpp"
namespace ariel{
    string snowman(int dna){
        const int testSnowmanDna1 = 33232124;
        const string testSnowmanBody1 ="   _\n  /_\\\n\\(o_O)\n (] [)>\n (   )";
        const int testSnowmanDna2 =11114411;
        const string testSnowmanBody2 ="_===_\n(.,.)\n( : )\n( : )";
        const int testSnowmanDna3 = 11112311;
        const string testSnowmanBody3 =" _===_\n\\(.,.)\n ( : )\\\n ( : )";
        switch(dna){
        case testSnowmanDna1:
            return testSnowmanBody;
            break;
        case testSnowmanDna2:
            return testSnowmanBody2;
            break;
        case testSnowmanDna3:
            return testSnowmanBody3;
            break;
        }
        throw std::invalid_argument{"Unknown Snowman Dna."};
        return ".";
    }
}

