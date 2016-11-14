#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define minimumBet 5.0

double getWallet(void);
double makeBet(double remainingMoney);
double playRound(double betMoney);

int rollDice(void);
int rollDie(void);
double rollforPoint(int SUM_OF_DICE, double betMoney);

int goodbye(double remainingMoney);
int doAgain(void);



int main (void){
	double remainingMoney, betMoney, indication;
	
	remainingMoney = getWallet();
 
	do{
		betMoney = makeBet(remainingMoney);
		remainingMoney += playRound(betMoney);
		indication = goodbye(remainingMoney);

	}while(indication);

	printf("\n");
	system("PAUSE");
	return 0;
 }


double getWallet(void){
	double initialMoney, remainingMoney;

	printf("How much money do you want to play with? \n");
	scanf("%lf", &initialMoney);

	while(initialMoney < minimumBet){
		printf("The money is not enough for the minimum bet, try again.\n");
		printf("How much money do you want to play with?\n");
		scanf("%lf", &initialMoney);
	}
	remainingMoney = initialMoney;

	return remainingMoney;
}   


double makeBet(double remainingMoney){
	double betMoney;

	// improve the loop

	printf("\nYou have $%.2f in your wallet.\n", remainingMoney);
	printf("Place your bet (minimum $%.2f) : ", minimumBet);
	scanf("%lf", &betMoney);


	while(betMoney < minimumBet || betMoney > remainingMoney){
		if(betMoney < minimumBet){
			printf("Your bet is below the minimum of $%.2f, try again.\n\n", minimumBet);
		}else{
			printf("You have bet more than you have in your wallet, try again.\n\n");
		}

		printf("\nYou have $%.2f in your wallet.\n", remainingMoney);
		printf("Place your bet (minimum $%.2f) : ", minimumBet);
		scanf("%lf", &betMoney);
	}

	return betMoney;
}


double playRound(double betMoney){
	int SUM_OF_DICE;
	double moneyGet;

	SUM_OF_DICE = rollDice();

	printf("You rolled a %d.\n", SUM_OF_DICE);
	
	if(SUM_OF_DICE == 2 || SUM_OF_DICE == 3 || SUM_OF_DICE == 12){
		printf("You lose :-( \n");
		moneyGet =  -betMoney;
	}else if(SUM_OF_DICE == 7 || SUM_OF_DICE == 11){
		printf("You win :-) \n");
		moneyGet = betMoney;
	}else{
		printf("\n");
		moneyGet = rollforPoint(SUM_OF_DICE, betMoney);
		printf("\n");
	}
	
	return moneyGet;
}

int rollDice(void){
	int num1, num2, sum;

	num1 = rollDie();
	num2 = rollDie();

	sum = num1 + num2;


	return sum;
}

int rollDie(void){
	int num;

	do{
		num = rand() % 7;
	}
	while(num == 0);

	return num;
}

double rollforPoint(int SUM_OF_DICE, double betMoney){
	int point;
	double moneyGet;

	point = SUM_OF_DICE;

	printf("Rolling for point: %d...\n", SUM_OF_DICE);

	do{
		SUM_OF_DICE = rollDice();
		printf("You rolled a %d.\n", SUM_OF_DICE);
	}
	while( !(SUM_OF_DICE == 7 || SUM_OF_DICE == point) );

	if(SUM_OF_DICE == 7){
		printf("You lose :-( ");
		moneyGet = -betMoney;
	}else{
		printf("You win :-) ");
		moneyGet = betMoney;
	}

	return moneyGet;
}

int goodbye(double remainingMoney){
	int indication;

	if(remainingMoney < minimumBet){
		indication = 0;
		printf("\nSorry, you don't have enough money to make a bet.");
	}else{
		indication = doAgain();

		if(indication == 0){
			printf("\nYou have $%.2f in your wallet. Goodbye!", remainingMoney);
		}

	}

	return indication;
}

int doAgain(void){
	int indication;

	printf("\nEnter 1 to play, 0 to quit: \n");
	scanf("%d", &indication);

	while(indication != 1 && indication != 0){
		printf("Sorry, invalid command, try again.\n");
		printf("\nEnter 1 to play, 0 to quit: \n");
		scanf("%d", &indication);
	}
	return indication;
}

