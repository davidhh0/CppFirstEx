#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

const int TEN = 10;
const int NUMBER_OF_DIGITSs = 8;
const int HAT_DIGIT=7;
const int NOSE_DIGIT=6;
const int LEFT_EYE_DIGIT=5;
//#include "snowman.hpp"

using namespace std;
using std::string;

// Checking each digits in [1,4]
int checkDigits(int n) {
    while (n != 0) {
        int temp = n % TEN;
        if (temp < 1 || temp > 4) {
            return 0;
        }
        n = n / TEN;
    }
    return 1;
}
// Return number of digits
int countDigit(int n) {
    int count = 0;
    while (n != 0) {
        n = n / TEN;
        ++count;
    }
    return count;
}
// Return digits at index
int digitsInIndex(int n, int index) {
    int ten = pow(TEN, index);
    int number = n / ten;
    return number % TEN;
}

namespace ariel {

    namespace hat {
        const char *const one = " _===_\n";
        const char *const two = "  ___\n .....\n";
        const char *const three = "   _\n  /_\\\n";
        const char *const four = "  ___\n (_*_)\n";
    }
    namespace hatwithleftarmdisabled {
        const char *const one = "_===_\n";
        const char *const two = " ___\n.....\n";
        const char *const three = "   _  \n  /_\\ \n";
        const char *const four = " ___\n(_*_)\n";
    }

    namespace nose {
        const char *const one = ",";
        const char *const two = ".";
        const char *const three = "_";
        const char *const four = " ";
    }
    namespace lefteye {
        const char *const one = "(.";
        const char *const two = "(o";
        const char *const three = "(O";
        const char *const four = "(-";
    }
    namespace righteye {
        const char *const one = ".)";
        const char *const two = "o)";
        const char *const three = "O)";
        const char *const four = "-)";
    }

    namespace leftarm {
        const char *const one = "<";
        const char *const two = "\\";
        const char *const three = "/";
        const char *const four = "";
    }

    namespace rightarm {
        const char *const one = ">\n";
        const char *const two = "/\n";
        const char *const three = "\\\n";
        const char *const four = "\n";
    }

    namespace torso {
        const char *const one = "( : )";
        const char *const two = "(] [)";
        const char *const three = "(> <)";
        const char *const four = "(   )";
    }

    namespace base {
        const char *const one = "( : )";
        const char *const three = "(___)";
        const char *const four = "(   )";
    }

    string snowman(int n) {
        int numberOfDigits = countDigit(n);
        int tempN = n;
        string invalidString = "Invalid code " + to_string(n);
        if (numberOfDigits < NUMBER_OF_DIGITSs) {
            throw std::invalid_argument(invalidString);
        }if (numberOfDigits > NUMBER_OF_DIGITSs) {
            throw std::invalid_argument(invalidString);
        } if (n < 0) {
            throw std::invalid_argument(invalidString);
        } if (checkDigits(n) == 0) {
            throw std::invalid_argument(invalidString);
        }
        bool isLeftArm = (digitsInIndex(n, 3) == 4);
		
        std::string toReturn;
		

        // switch for hat
        switch (digitsInIndex(n, HAT_DIGIT)) {
            case 1:
                if (isLeftArm){
                    toReturn += hatwithleftarmdisabled::one;
				}
                else{
                    toReturn += hat::one;
				}
                break;
            case 2:
                if (isLeftArm){
                    toReturn += hatwithleftarmdisabled::two;
				}
                else{
                    toReturn += hat::two;
				}
                break;
            case 3:
                if (isLeftArm){
                    toReturn += hatwithleftarmdisabled::three;
				}
                else{
                    toReturn += hat::three;
				}
                break;
            case 4:
                if (isLeftArm){
                    toReturn += hatwithleftarmdisabled::four;
				}
                else{
                    toReturn += hat::four;
				}
                break;
            default:
                break;
        }
        // Left arm check for up arm
		// digitsInIndex(n, 3) == 2 -> there is a char up
        if (digitsInIndex(n, 3) == 2) {
            toReturn += leftarm::two;
        } else if (!isLeftArm) { // Meaning that there is an hand
            toReturn += " ";
        }
        // Left eye full check
        switch (digitsInIndex(n, LEFT_EYE_DIGIT)) {
            case 1:
                toReturn += lefteye::one;
                break;
            case 2:
                toReturn += lefteye::two;
                break;
            case 3:
                toReturn += lefteye::three;
                break;
            case 4:
                toReturn += lefteye::four;
                break;
            default:
                break;
        }
        // Nose full check
        switch (digitsInIndex(n, NOSE_DIGIT)) {
            case 1:
                toReturn += nose::one;
                break;
            case 2:
                toReturn += nose::two;
                break;
            case 3:
                toReturn += nose::three;
                break;
            case 4:
                toReturn += nose::four;
                break;
            default:
                break;
        }


        // Right eye full check
        switch (digitsInIndex(n, 4)) {
            case 1:
                toReturn += righteye::one;
                break;
            case 2:
                toReturn += righteye::two;
                break;
            case 3:
                toReturn += righteye::three;
                break;
            case 4:
                toReturn += righteye::four;
                break;
            default:
                break;
        }

        if (digitsInIndex(n, 2) == 2) { // digitsInIndex(n, 3) == 2 -> there is a char up
            toReturn += rightarm::two;
        } else{
            toReturn += "\n";
		}
        //Left arm part check
        switch (digitsInIndex(n, 3)) {
            case 1:
                toReturn += leftarm::one;
                break;
            case 2:
                toReturn += " ";
                break;
            case 3:
                toReturn += leftarm::three;
                break;
            case 4:
                toReturn += leftarm::four;
                break;
            default:
                break;
        }
        // Torso full check
        switch (digitsInIndex(n, 1)) {
            case 1:
                toReturn += torso::one;
                break;
            case 2:
                toReturn += torso::two;
                break;
            case 3:
                toReturn += torso::three;
                break;
            case 4:
                toReturn += torso::four;
                break;
            default:
                break;
        }

        //Right arm part check
        switch (digitsInIndex(n, 2)) {
            case 1:
                toReturn += rightarm::one;
                break;
            case 2:
                toReturn += "\n";
                break;
            case 3:
                toReturn += rightarm::three;
                break;
            case 4:
                toReturn += rightarm::four;
                break;
            default:
                break;
        }

        if (!isLeftArm) {
            toReturn += " ";
        }


        //Full base check
        switch (digitsInIndex(n, 0)) {
            case 1:
                toReturn += base::one;
                break;
            case 2:
                toReturn += "(\" ";
                toReturn += "\")";
                break;
            case 3:
                toReturn += base::three;
                break;
            case 4:
                toReturn += base::four;
                break;
            default:
                break;
        }
        return toReturn;
    }


}