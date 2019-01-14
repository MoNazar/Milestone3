// meilenstein3.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include "neuron.h"
#include "weight.h"
#include layer.h
#include "connections.h"

using namespace std;
	
	
// Der Anfang des ganzen. 
// Idee: Wir erstellen anfangs, ein Input Layer. Dazu erstellen wir eine offene Topologie mit 4 neuronen zu anfang. 


// creating a vector to store the values of the input layer
inputlayer il;
	
// the activation function we use to calculate the output of a layer
double f(double x) {
    double b = pow(1 + exp(-x), -1);
    return b;
}

// derivative of the function f in order to calculate a minimum of the costs of a neural network as backpropagation
double derivative_f(double x){
    double b = exp(-x) / pow(exp(-x) + 1, 2);
    return b;
}

int main() {

   // Der Anfang des ganzen. 
	// Creating neurons
	/*-----------Inputlayer----------------------------------*/
	inputlayer il;
	neuron n1; neuron n2; neuron n3; neuron n4; //Inputlayer
	/*-----------Hiddenlayer---------------------------------*/
	Hiddenlayer H1; // Layer 2 , nächstes Layer //Hiddenlayer
	neuron n5; neuron n6; neuron n7; neuron n8;
	/*-----------Outputlayer---------------------------------*/
	outputlayer ol; 
	neuron n9; neuron n10; neuron n11;
	
	//creating layers
	
	 // inputlayer 
	il.push_back(n1); il.push_back(n2); il.push_back(n3); il.push_back(n4);
        // Hiddenlayer
	H1.push_back(n5); H1.push_back(n6); H1.push_back(n7); H1.push_back(n8);
	
	/*----------------Matrix von Inputlayer -> Hiddenlayer */
	// object that holds the weights between two layers:
	weight weight1;
	// set number of neurons in first layer as number of columns in a matrix
	weight1.set_size_1(il.size());
	// set number of neurons in second layer as number of rows in a matrix
	weight1.set_size_2(H1.size());
	// assign random values as weights to a matrix and print it
	weight1.random_weights();
	
	
	// create neuronal net with certain topology
	neural_net an;
	an.neurons_input_layer ilnetwork; //inputlayer of network
	an.neurons_hidden_layer hidnetworkt; // hiddenlayer of network

	an.generatelayer_inputlayer(il);
	an.generatelayer_hiddenlayer(H1);
	
	// Connect ilnetwork with hidnetwork 
	connect(an.neurons_input_layer ilnetwork,matrix_of_edgeweights_between_layers ,an.neurons_input_layer hidnetwork)
	
	
	printf("\n");
	
	
	
	
	
	
	
	
   
   
		
    system("pause");
    return 0;
}
