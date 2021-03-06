#include "stdafx.h"


float test_deck(std::vector<unsigned int> deck, unsigned int turns,
	unsigned int number, bool ondraw) {
	float results = 0.0;
	std::default_random_engine dre;
	std::uniform_int_distribution<unsigned int> di(0, deck.size());
	for (unsigned int game = 0; game <= number; game++) {
		unsigned int hsize = 7;
		bool keeping = false;
		std::vector<unsigned int> cdeck(deck);
		std::vector<unsigned int> hand;
		while (!keeping && hsize > 2) {
			for (unsigned int card = 0; card < hand.size(); card++) {
				cdeck.push_back(hand.at(card));
			}
			hand.resize(0);
			for (unsigned int card = 0; card < hsize; card++) {
				unsigned int n = cdeck.size() + 1;
				while (n >= cdeck.size()) {
					n = di(dre);
				}
				hand.push_back(cdeck.at(n));
				cdeck.erase(cdeck.begin() + n);
			}
			keeping = keep(hand);
			hsize--;
		}
		unsigned int lands = 0;
		for (unsigned int turn = 1; turn <= turns; turn++) {
			if (turn != 1 || ondraw) {
				unsigned int n = cdeck.size() + 1;
				while (n >= cdeck.size()) {
					n = di(dre);
				}
				hand.push_back(cdeck.at(n));
				cdeck.erase(cdeck.begin() + n);
			}
			for (unsigned int card = 0; card < hand.size(); card++) {
				if (hand.at(card) == 0) {
					lands += 1;
					hand.erase(hand.begin() + card);
					break;
				}
			}
			std::sort(hand.begin(), hand.end());
			std::reverse(hand.begin(), hand.end());
			unsigned int mana = lands;
			for (unsigned int card = 0; card < hand.size(); card++) {
				unsigned int cmc = hand.at(card);
				if (cmc <= lands) {
					mana -= cmc;
					card--;
					hand.erase(hand.begin() + card);
				}
			}
			std::cout << lands << " " << mana << " " << turn << std::endl;
			results += (lands - mana) / turn;
			//auto l = std::count(hand.begin(), hand.end(), 0u);
			//std::cout << "L: " << hand.at(l) << std::endl;
		}
	}
	return results / turns / number;
}