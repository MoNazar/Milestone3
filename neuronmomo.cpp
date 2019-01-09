#include "neuron.h"
#include "functions.h"
#include <iostream>
using namespace std;

void neuron::aktivate(float inputweight) {
	float aktivate1 = pow(1 + exp(-inputweight), -1);
	this->aktivate1 = aktivate1;
	

}
void neuron::setinputweight() {
	this->inputweight = inputweight;
	cout << inputweight << endl;
}
void neuron::setactive(float aktivate1) {
	this->aktivate1 = aktivate1;
}
void neuron::getactive() {
	//this->aktivate1 = aktivate1;
	cout << aktivate1 << endl;

}
