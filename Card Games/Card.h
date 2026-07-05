#pragma once 
#include <iostream>
#include <string>

class Card {
	friend std::ostream& operator << (std::ostream& os , const Card& x);
	
	private :
		std::string suite;
		int number;
	public : 
		bool operator == (const int &b);
		bool operator > (const int &x);
		bool operator == (const std::string &b);
		int getNumber(){
			return this-> number;
		}
		std::string getSuite(){
			return this-> suite;
		}
        Card(){

        }
	    Card(std::string suite , int number){
		    this->number = number;
		    this->suite = suite;
	    }
};


