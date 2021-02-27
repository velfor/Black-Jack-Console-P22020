#include "func.h"
#include <iostream>
#include <ctime>
using namespace std;
void deckInit(Card* fdeck) {
	int currentCard = 0;
	for (int i = 0; i < SUIT_SIZE; i++) {
		for (int j = 0; j < RANK_SIZE; j++) {
			fdeck[currentCard].m_suit = static_cast<CardSuit>(i);
			fdeck[currentCard].m_rank = static_cast<CardRank>(j);
			currentCard++;
		}
	}
}
//===========================
void printCard(Card fCard) {
	switch (fCard.m_rank) {
	case RANK_2: cout << 2; break;
	case RANK_3: cout << 3; break;
	case RANK_4: cout << 4; break;
	case RANK_5: cout << 5; break;
	case RANK_6: cout << 6; break;
	case RANK_7: cout << 7; break;
	case RANK_8: cout << 8; break;
	case RANK_9: cout << 9; break;
	case RANK_10: cout << 10; break;
	case RANK_J: cout << 'J'; break;
	case RANK_Q: cout << 'Q'; break;
	case RANK_K: cout << 'K'; break;
	case RANK_A: cout << 'A'; break;
	}
	switch (fCard.m_suit) {
	case SPADES:cout << "S "; break;
	case HEARTS:cout << "H "; break;
	case DIAMONDS:cout << "D "; break;
	case CLUBS:cout << "C "; break;
	}
}
//===========================
void printDeck(Card* fdeck, const int fsize) {
	for (int i = 0; i < fsize; i++) {
		printCard(fdeck[i]);
		cout << endl;
	}
}
//===========================
void deckShuffle(Card* fdeck, const int fsize) {
	srand(time(nullptr));
	//тасуем колоду 10 раз
	const int shuffleQty = 10;
	for (int k = 0; k < shuffleQty; k++) {
		//идем по всем картам колоды и обмениваем текущую карту
		//с картой со случайным номером
		int randomIndex = 0;
		for (int i = 0; i < fsize; i++) {
			randomIndex = rand() % 52;
			Card temp = fdeck[i];
			fdeck[i] = fdeck[randomIndex];
			fdeck[randomIndex] = temp;
		}
	}
}
//===========================
void playerTakeOneCard(Card* fdeck, Card* fhand,
	int& fCurrentCardIndex, int& fPlayerHandIndex) {
	//взять одну карту, take one card
	//переложить из колоды в руку, from deck to hand
	fhand[fPlayerHandIndex] = fdeck[fCurrentCardIndex];
	//увеличили индесы на 1, add 1 to both indexes
	fPlayerHandIndex++;
	fCurrentCardIndex++;
}
//===========================

void printPlayerHand(Card* fhand, int fHandSize) {
	//вывести руку игрока, print player hand
	for (int i = 0; i < fHandSize; i++) {
		printCard(fhand[i]);
	}
	cout << endl;
}
int getCardScore(Card fCard) {
	switch (fCard.m_rank) {
	case RANK_2:return 2;
	case RANK_3:return 3;
	case RANK_4:return 4;
	case RANK_5:return 5;
	case RANK_6:return 6;
	case RANK_7:return 7;
	case RANK_8:return 8;
	case RANK_9:return 9;
	case RANK_10:
	case RANK_J:
	case RANK_Q:
	case RANK_K:return 10;
	case RANK_A:return 11;
	default: return 0;
	}
}
int calculatePlayerScore(Card* fhand, int fHandSize) {
	int sum = 0;
	for (int i = 0; i < fHandSize; i++) {
		sum = sum + getCardScore(fhand[i]);
	}
	return sum;
}
//========================================================
int playerTurn(Card* fdeck, Card* fhand,
	int& currentCardIndex) {
	int playerHandIndex = 0;
	char choice;
	int playerScore;
	do {
		playerTakeOneCard(fdeck, fhand, currentCardIndex,
			playerHandIndex);
		printPlayerHand(fhand, playerHandIndex);
		playerScore = calculatePlayerScore(fhand,
			playerHandIndex);
		cout << "Your score is " << playerScore << endl;
		if (playerScore >= 21) break;
		cout << "More card? (yes - y, no - any character) ";
		cin >> choice;
	} while (choice == 'y');
	return playerScore;
}
void dealerTakeOneCard(Card* fdeck, Card* fhand,
	int& fCurrentCardIndex, int& fDealerHandIndex) {
	//из колоды в руку, from deck to hand
	fhand[fDealerHandIndex] = fdeck[fCurrentCardIndex];
	//увеличили индесы на 1, add 1 to both indexes
	fDealerHandIndex++;
	fCurrentCardIndex++;
}
void printDealerHand(Card* fhand, int fHandSize) {
	for (int i = 0; i < fHandSize; i++) {
		printCard(fhand[i]);
	}
	cout << endl;
}
int calculateDealerScore(Card* fhand, int fHandSize) {
	int sum = 0;
	for (int i = 0; i < fHandSize; i++) {
		sum = sum + getCardScore(fhand[i]);
	}
	return sum;
}