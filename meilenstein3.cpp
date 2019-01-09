// meilenstein3.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#include <iostream>
#include "neuron.h"
#include "inputoutput.h"
#include "vektormatrix.h"
#include "functions.h"
#include <string>
using namespace std;


int main() {
	// Der Anfang des ganzen. 
	// Idee: Wir erstellen anfangs, ein Input Layer. Dazu erstellen wir eine offene Topologie mit 4 neuronen zu anfang. 
	neuron n1; neuron n2; neuron n3; neuron n4; neuron n5;
	n1.inputweight = 1.00; n2.inputweight = 0.00; n3.inputweight = 0.33; n4.inputweight = 0.66; 
	// Das Inputlayer wird nun aufgestellt
	//inputlayer il; ACHTUNG! FÜR DEN ERSTEN SCHRITT GILT DIE AKTIVIERUNGSFUNKTION NICHT. 
	il.push_back(n1.inputweight); il.push_back(n2.inputweight); il.push_back(n3.inputweight); il.push_back(n4.inputweight); 
	for (int i = 0; i < 4; i++) {
		cout << il[i] << endl;
	}
	//il ist nun das input layer. 



	




	system("pause");
	return 0;
}
