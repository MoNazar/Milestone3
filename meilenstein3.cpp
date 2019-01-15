#include <iostream>
#include "neuron.h"
#include "weight.h"
#include <string>
#include "layer.h"
#include "neural_net.h"
using namespace std;

// Der Anfang des ganzen. 
// Idee: Wir erstellen anfangs, ein Input Layer. Dazu erstellen wir eine offene Topologie mit 4 neuronen zu anfang. 
// store layers as vectors



// the activation function we use to calculate the output of a layer
double fkt1(double x) {
	double b = pow(1 + exp(-x), -1);
	return b;
}

// derivative of the function f in order to calculate a minimum of the costs of a neural network as backpropagation
double fkt1abl(double x) {
	double b = exp(-x) / pow(exp(-x) + 1, 2);
	return b;
}


int main() {
	// Der Anfang des ganzen. 
	/*-----------Inputlayer----------------------------------*/
	inputlayer il;
	neuron n1; neuron n2; neuron n3; neuron n4; //Inputlayer
	/*-----------Hiddenlayer---------------------------------*/
	Hiddenlayer H1; // Layer 2 , nächstes Layer //Hiddenlayer
	neuron n5; neuron n6; neuron n7; neuron n8;
	/*-----------Outputlayer---------------------------------*/
	outputlayer ol; 
	neuron n9; neuron n10; neuron n11;

	
	// Idee: Wir erstellen anfangs, ein Input Layer. Dazu erstellen wir eine offene Topologie mit 4 neuronen zu anfang. 
	//neuron n1; neuron n2; neuron n3; neuron n4;
	// set values for neurons of input layer
	n1.set_activation(1.00);
	n2.set_activation(0.00);
	n3.set_activation(0.33);
	n4.set_activation(0.66);
	// Das Inputlayer wird nun aufgestellt
 //inputlayer il; ACHTUNG! FÜR DEN ERSTEN SCHRITT GILT DIE AKTIVIERUNGSFUNKTION NICHT. 

 // generate Inputlayer
	il.push_back(n1); il.push_back(n2); il.push_back(n3); il.push_back(n4);
 // generate Hiddenlayer
	H1.push_back(n5); H1.push_back(n6); H1.push_back(n7); H1.push_back(n8);
// generate Outputlayer 
	ol.push_back(n9); ol.push_back(n10); ol.push_back(n11);
	

	//-----------------------NeuronalNet-----------------------------------------------------------------

	neural_net ann;
	// topologie
	ann.set_number_of_neurons_input_layer(4);
	ann.set_number_of_neurons_hidden_layer(4);
	// generating layers of neural net 
	ann.generatelayer_inputlayer(il);
	ann.generatelayer_hiddenlayer(H1);
	ann.generatelayer_outputlayer(ol);
	// generate random matrix between input layer an hidden layer 
	ann.generatematrix();
	// get input layer activations
	ann.getlayer_input();
	printf("\n");
	// Connection Inputlayer -> Hiddenlayer
	ann.connected();
    // get hiddenlayer activations 
	ann.getlayer_hidden();
	printf("\n");
	// generate random matrix between hidden layer and output layer
	ann.generatematrix1();
	// Connection Hiddenlayer -> Outputlayer
	ann.connected1();
	// Get outputlayer
	ann.getlayer_output();


	

	system("pause");
	return 0;
}
