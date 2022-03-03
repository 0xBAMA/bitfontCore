#ifndef LETTER
#define LETTER

#include <vector>
#include <random>
#include <fstream>
#include <iostream>

#include "json.h"
using json = nlohmann::json;

class letter {
public:
	bool flaggedForRemoval = false;
	std::vector<std::vector<unsigned char>> data;
	void buildrow(int r, std::string s) {
		std::vector<unsigned char> ints;
		for(unsigned int i = 0; i < s.size(); i++) {
			if(s[i] == '.'){
				ints.push_back(0);
			}else if(s[i] == '@'){
				ints.push_back(1);
			}else{
				nfg = true;
				break;
			}
		}
		data[r]=ints;
	}
	bool nfg=false;

	void print() {
		for(auto row : data) {
			for(auto elem : row) {
				std::cout << (int)elem;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	float fill () {
		float fillp = 0.0;
		for(auto row : data) {
			for(auto elem : row) {
				fillp += (int)elem;
			}
		}
		return fillp / float( data.size() * data[ 1 ].size() );
	}


	bool check() {
		unsigned int firstrow = data.empty() ? 0 : data[0].size();
		if(!firstrow) return false;
		for(unsigned int i = 0; i < data.size(); i++)
			if(data[i].size() != firstrow)
				return false;
		return true;
	}

	friend bool operator== (const letter& l1, const letter& l2){
		if(l1.data.size()!=l2.data.size()) return false; // y dim doesn'nt match
		if(l1.data[0].size()!=l2.data[0].size()) return false; // x dim doesn't match
		for(unsigned int i = 0; i < l1.data.size(); i++)
		for(unsigned int j = 0; j < l1.data[0].size(); j++)
			if(l1.data[i][j]!=l2.data[i][j])
				return false;
		return true;
	}
};

#endif
