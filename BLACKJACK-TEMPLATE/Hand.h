#pragma once

#include "Card.h"

class Hand {
public:
    void addCard(Card* card);
    void removeCard();
    std::vector<Card*> getCards() const;

    int getValue() const;

    void clear();

    bool canSplit() const;

private:
    std::vector<Card*> cards;
};