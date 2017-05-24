#include "stdafx.h"

bool keep(std::vector<unsigned int> hand) {
	unsigned int lands = std::count(hand.begin(), hand.end(), 0);
	if (lands > 1 && hand.size() != lands) {
		return true;
	}
	else if (hand.size() == 1) {
		return true;
	}
	else {
		return false;
	}
}
