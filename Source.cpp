#include <iostream>
#include "func.h"
using namespace std;
//==================================
int main() {
	const int deckSize = 52;
	Card deck[deckSize];

	const int handSize = 8;
	Card playerHand[handSize];
	Card dealerHand[handSize];

	deckInit(deck);//создаем колоду
	deckShuffle(deck, deckSize);//тасуем колоду
	//printDeck(deck, deckSize);
	//игрок набирает карты
	int currentCardIndex = 0;
	int playerScore;
	playerScore = playerTurn(deck, playerHand, 
		currentCardIndex);
	if (playerScore == 21) cout << "Player won!\n";
	else
		if (playerScore > 21) cout << "Player lose\n";
		else {
			//dealer play, играет дилер
			int dealerHandIndex = 0;
			int dealerScore;
			do {
				//взять одну карту, take one card
				dealerTakeOneCard(deck,dealerHand,
					currentCardIndex, dealerHandIndex);
				
				//подсчитываем сумму очков, calculate dealer score
				dealerScore = calculateDealerScore(dealerHand,
					dealerHandIndex);
				//if dealer score >= 21 - break loop
				//если счет больше или равен 21 - прервать цикл
				if (dealerScore >= 21) break;
				//if dealer score less or equal 17 - continue
			} while (dealerScore <= 17);
			//вывести руку, print dealer hand
			printDealerHand(dealerHand, dealerHandIndex);
			//вывести очки , print dealer score
			cout << "Dealer score is " << dealerScore << endl;
			if (dealerScore == 21) {
				cout << "\nDealer score is " << dealerScore << endl;
				cout << "Dealer won!\n"; 
			}
			else
				if (dealerScore > 21) cout << "Dealer lose\n"; 
				else {
					//both have less 21
					//у обоих меньше 21
					//player score greater - player win
					if (playerScore > dealerScore) cout << "Player won!\n";
					else
						//dealer score greater - dealer win
						if (dealerScore > playerScore) cout << "Dealer won!\n";
						//equal - draw
						else cout << "Draw!\n";
				}
		}
	cout << "Game stop\n";
	return 0;
}



