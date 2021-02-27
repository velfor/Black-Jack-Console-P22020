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

	deckInit(deck);//������� ������
	deckShuffle(deck, deckSize);//������ ������
	//printDeck(deck, deckSize);
	//����� �������� �����
	int currentCardIndex = 0;
	int playerScore;
	playerScore = playerTurn(deck, playerHand, 
		currentCardIndex);
	if (playerScore == 21) cout << "Player won!\n";
	else
		if (playerScore > 21) cout << "Player lose\n";
		else {
			//dealer play, ������ �����
			int dealerHandIndex = 0;
			int dealerScore;
			do {
				//����� ���� �����, take one card
				dealerTakeOneCard(deck,dealerHand,
					currentCardIndex, dealerHandIndex);
				
				//������������ ����� �����, calculate dealer score
				dealerScore = calculateDealerScore(dealerHand,
					dealerHandIndex);
				//if dealer score >= 21 - break loop
				//���� ���� ������ ��� ����� 21 - �������� ����
				if (dealerScore >= 21) break;
				//if dealer score less or equal 17 - continue
			} while (dealerScore <= 17);
			//������� ����, print dealer hand
			printDealerHand(dealerHand, dealerHandIndex);
			//������� ���� , print dealer score
			cout << "Dealer score is " << dealerScore << endl;
			if (dealerScore == 21) {
				cout << "\nDealer score is " << dealerScore << endl;
				cout << "Dealer won!\n"; 
			}
			else
				if (dealerScore > 21) cout << "Dealer lose\n"; 
				else {
					//both have less 21
					//� ����� ������ 21
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



