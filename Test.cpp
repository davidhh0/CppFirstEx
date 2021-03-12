/**
 * Demo program for snowman exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-02
 */
//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "snowman.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include "doctest.h"

using namespace ariel;
using namespace std;

/* 
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}
 */


TEST_CASE("Bad snowman code") {
     //less than 8 digits
     CHECK_THROWS(snowman(1234567));
	 
     //zero's than one
	 CHECK_THROWS(snowman(00000001));
	 
	//more than 8 digits
     CHECK_THROWS(snowman(123456789));

     //one of the digits greater than 4
     CHECK_THROWS(snowman(12341235));

     //one of the digits less than 1
     CHECK_THROWS(snowman(12345670));

     //the number is negative
     CHECK_THROWS(snowman(-12345678));
	 
	 //zero 
	 CHECK_THROWS(snowman(0));
	
 }

TEST_CASE("Good snowman code"){
	// My own built snowmen
	CHECK((snowman(11114411)) == string("_===_\n(.,.)\n( : )\n( : )"));
	
	CHECK((snowman(12341234)) == string(" _===_\n (O.-)/\n<(> <)\n (   )"));
	
	CHECK((snowman(11111111)) == string(" _===_\n (.,.)\n<( : )>\n ( : )"));
	
	
	//got from the internet 
	// copies each line without any spaces and put \n between
	CHECK((snowman(12333321)) == string(" _===_\n (O.O)\n/(] [)\\\n ( : )"));
	
	// Left arm is up
	CHECK((snowman(11112311)) == string(" _===_\n\\(.,.)\n ( : )\\\n ( : )"));
	// Left arm is disable
	CHECK((snowman(44444444)) == string(" ___\n(_*_)\n(- -)\n(   )\n(   )"));
	//Left arm is on but not disable
	CHECK((snowman(31333342)) == string("   _\n  /_\\\n (O,O)\n/(   )\\\n (\" \")"));
	
	CHECK((snowman(43232122)) == string("  ___\n (_*_)\n\\(o_O)\n (] [)>\n (\" \")"));
	
	CHECK((snowman(12344321)) == string("_===_\n(O.-)\n(] [)\\\n( : )"));
	
	CHECK((snowman(23232223)) == string("  ___\n .....\n\\(o_O)/\n (] [)\n (___)"));
	
	CHECK((snowman(22222222)) == string("  ___\n .....\n\\(o.o)/\n (] [)\n (\" \")"));
	
	CHECK((snowman(33333333)) == string("   _\n  /_\\\n (O_O)\n/(> <)\\\n (___)"));
	
	CHECK((snowman(44114432)) == string(" ___\n(_*_)\n(. .)\n(> <)\n(\" \")"));
	}
