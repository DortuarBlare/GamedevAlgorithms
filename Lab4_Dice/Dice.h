#pragma once

class Dice {
private:
	int diceAmount;
	int faceAmount;
	//char modifierOperation;
	int modifierNumber;

public:
	Dice(int dice, int face);
	Dice(int dice, int face,/* char,*/ int modifierNumber);

	int getDiceAmount();
	int getFaceAmount();
	//char getModifierOperation();
	int getModifierNumber();
};

