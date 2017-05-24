#include "stdafx.h"


float test_deck(std::vector<unsigned int> deck, unsigned int turns,
	unsigned int number, bool ondraw) {
	float results = 0.0;
	unsigned int decksize = deck.size();
	std::default_random_engine dre;
	std::uniform_int_distribution<unsigned int> di(0, decksize);
	for (unsigned int i = 0; i <= number; i++) {
		for (unsigned int turn = 1; turn <= turns; turn++) {
			unsigned int hsize = 7;
			bool keeping = false;
			std::vector<unsigned int> cdeck(deck);
			std::vector<unsigned int> hand;
			while (!keeping & hsize > 2) {
				unsigned int n = decksize + 1;
				while (n > decksize) {
					unsigned int n = di(dre);
				}
				
			}
		}
	}
	return results / turns / number;
}