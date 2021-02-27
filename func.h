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
void deckInit(Card*);//���������� ������ �������
void printCard(Card);//������ ����� �����
void printDeck(Card*, const int);//������ ������ ��� �������
void deckShuffle(Card*, const int);//������� ������
int getCardScore(Card);//���������� ���-�� ����� ����� �����
//������� ������
void playerTakeOneCard(Card*, Card*, int&, int&);
void printPlayerHand(Card*, int);
int calculatePlayerScore(Card*, int);
int playerTurn(Card*, Card*, int&);
//������� ������
void dealerTakeOneCard(Card*, Card*, int&, int&);
void printDealerHand(Card*, int);
int calculateDealerScore(Card*, int);
//#endif
