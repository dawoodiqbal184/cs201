#pragma once 
#include <iostream>
#include <string>

class Card {
	private :
		std::string suite;
		int number;
	public : 
		friend std::ostream& operator << (std::ostream& os , const Card& x);
        Card(){

        }
	    Card(std::string suite , int number){
		    this->number = number;
		    this->suite = suite;
	    }
};


