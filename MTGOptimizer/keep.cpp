#include "stdafx.h"

bool keep(std::vector<unsigned int> hand) {
	unsigned int lands = std::count(hand.begin(), hand.end(), 0);
	if (hand.size() == 7) {
		return (1 < lands < 6);
	}
	else if (hand.size() == 6) {
		return (1 < lands < 5);
	}
	else if (lands > 0) {
		return true;
	}
	else {
		return false;
	}
}
