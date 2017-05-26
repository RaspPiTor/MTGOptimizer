#include "stdafx.h"

void print_vector(std::vector<unsigned int> v) {
	for (unsigned int i = 0; i < v.size(); i++) {
		std::cout << v.at(i) << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<unsigned int> deck (24, 0);
	for (int i = 0; i < 10; i++) {
		deck.push_back(1);
	}
	for (int i = 0; i < 10; i++) {
		deck.push_back(2);
	}
	for (int i = 0; i < 10; i++) {
		deck.push_back(3);
	}
	for (int i = 0; i < 5; i++) {
		deck.push_back(4);
	}
	print_vector(deck);
	float result = test_deck(deck, 5, 10000, false);
	std::cout << result << std::endl;
	return 0;
}

