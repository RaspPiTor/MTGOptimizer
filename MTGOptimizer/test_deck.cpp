#include "stdafx.h"


float test_deck(std::vector<unsigned int> deck, unsigned int turns,
	unsigned int number, bool ondraw) {
	float results = 0.0;
	std::default_random_engine dre;
	std::uniform_int_distribution<unsigned int> di(0, deck.size());
	for (unsigned int i = 0; i <= number; i++) {
		for (unsigned int turn = 1; turn <= turns; turn++) {
			unsigned int hsize = 7;
			bool keeping = false;
			std::vector<unsigned int> cdeck(deck);
			std::vector<unsigned int> hand;
			while (!keeping && hsize > 2) {
				for (int card = 0; card < hand.size(); card++) {
					cdeck.push_back(hand.at(card));
				}
				hand.resize(0);
				for (int card = 0; card < hsize; card++) {
					unsigned int n = cdeck.size() + 1;
					while (n >= cdeck.size()) {
						n = di(dre);
					}
					hand.push_back(cdeck.at(n));
					cdeck.erase(cdeck.begin() + n);
				}
				keeping = keep(hand);
				
			}
			print_vector(hand);
		}
	}
	return results / turns / number;
}