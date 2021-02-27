#pragma once
//#ifndef FUNC_HEADER
//#define FUNC_HEADER
enum CardSuit { SPADES, HEARTS, DIAMONDS, CLUBS, SUIT_SIZE };
enum CardRank {
	RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8,
	RANK_9, RANK_10, RANK_J, RANK_Q, RANK_K, RANK_A, RANK_SIZE
};
struct Card {
	CardSuit m_suit;
	CardRank m_rank;
};
void deckInit(Card*);//заполнение колоды картами
void printCard(Card);//печать одной карты
void printDeck(Card*, const int);//печать колоды для отладки
void deckShuffle(Card*, const int);//тасовка колоды
int getCardScore(Card);//возвращает кол-во очков одной карты
//функции игрока
void playerTakeOneCard(Card*, Card*, int&, int&);
void printPlayerHand(Card*, int);
int calculatePlayerScore(Card*, int);
int playerTurn(Card*, Card*, int&);
//функции дилера
void dealerTakeOneCard(Card*, Card*, int&, int&);
void printDealerHand(Card*, int);
int calculateDealerScore(Card*, int);
//#endif
