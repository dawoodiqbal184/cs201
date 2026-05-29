#pragma once 
#include <iostream>
#include <string>

class Card {
	friend std::ostream& operator << (std::ostream& os , const Card& x);
	friend bool operator == (const Card &b);
	private :
		std::string suite;
		int number;
	public : 
		
        Card(){

        }
	    Card(std::string suite , int number){
		    this->number = number;
		    this->suite = suite;
	    }
};


