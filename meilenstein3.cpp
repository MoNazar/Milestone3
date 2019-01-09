// meilenstein3.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#include "inputoutput.h"
#include "vektormatrix.h"
#include "functions.h"
#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include "neuron.h"
#include "weight.h"

using namespace std;
	
	
// Der Anfang des ganzen. 
// Idee: Wir erstellen anfangs, ein Input Layer. Dazu erstellen wir eine offene Topologie mit 4 neuronen zu anfang. 
// store layers as vectors
typedef vector<double> Hiddenlayer;
typedef vector<double> inputlayer;
typedef vector <double> outputlayer;

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

    // neurons of the input layer
    neuron neuron1;
    neuron neuron2;
    neuron neuron3;
    neuron neuron4;

    // set values for neurons of input layer
    neuron1.set_activation(1.00);
    neuron2.set_activation(0.00);
    neuron3.set_activation(0.33);
    neuron4.set_activation(0.66);
	
    // Das Inputlayer wird nun aufgestellt
    //inputlayer il; ACHTUNG! FÜR DEN ERSTEN SCHRITT GILT DIE AKTIVIERUNGSFUNKTION NICHT. 
    // store the values of the input layer in a vector
    il.push_back(neuron1.get_activation()); il.push_back(neuron2.get_activation());
    il.push_back(neuron3.get_activation()); il.push_back(neuron4.get_activation());
    for (int i = 0; i < 4; i++) {
        cout << il[i] << endl;
    }
    //il ist nun das input layer. 
	
    // object that holds the weights between two layers:
    weight weight1;

    // set number of neurons in first layer as number of columns in a matrix
    weight1.set_size_1(4);

    // set number of neurons in second layer as number of rows in a matrix
    weight1.set_size_2(4);

    // assign random values as weights to a matrix and print it
    weight1.random_weights();

    // update weight
    weight1.set_weight(1,2, 0.123);

    // first int = index of neuron in layer 1, second int = index of neuron in layer 2
    weight1.get_weight(1,2);

    // the connection between one neuron of a layer to all the neurons of the following
    // layer is its activation value and the first column of the matrix containing all the weights
    // of edges between the two layers. the following describes the connection between
    // the first neuron of the first layer to all the neurons in layer 2:
    double z = neuron1.get_activation();

    // weight from neuron1 to first neuron in second layer
    double w00 = weight1.get_weight(0,0);

    // weight from neuron1 to second neuron in second layer
    double w01 = weight1.get_weight(0,1);

    // weight from neuron1 to third neuron in second layer
    double w02 = weight1.get_weight(0,2);

    // weight from neuron1 to fourth neuron in second layer
    double w03 = weight1.get_weight(0,3);
	

    // get the input value of the neuron
    double a = neuron1.get_activation();

    // applying function f to the input value of a neuron
    neuron1.set_activation_function(f(a));
		
    system("pause");
    return 0;
}
