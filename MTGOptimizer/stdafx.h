#pragma once

#include <random>
#include <vector>
#include <iostream>
#include <algorithm>

bool keep(std::vector<unsigned int> hand);

float test_deck(std::vector<unsigned int> deck, unsigned int turns,
	unsigned int number, bool ondraw);