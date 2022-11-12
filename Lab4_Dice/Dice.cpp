#include "Dice.h"

Dice::Dice(int dice, int face) :
	diceAmount(dice),
	faceAmount(face),
	//modifierOperation(' '),
	modifierNumber(0)
{}

Dice::Dice(int dice, int face,/* char operation,*/ int number) :
	diceAmount(dice),
	faceAmount(face),
	//modifierOperation(operation),
	modifierNumber(number)
{}

int Dice::getDiceAmount() {
	return this->diceAmount;
}

int Dice::getFaceAmount() {
	return this->faceAmount;
}

//char Dice::getModifierOperation() {
//	return this->modifierOperation;
//}

int Dice::getModifierNumber() {
	return this->modifierNumber;
}
