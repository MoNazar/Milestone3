#include <iostream>
#include <math.h>
#include "neuron.h"
#include "weight.h"

using namespace std;


// the activation function used to calculate the output of a layer
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
    // neurons of the first layer
    neuron neuron1;
    neuron neuron2;

    // neurons of the second layer
    neuron neuron3;
    neuron neuron4;
    neuron neuron5;

    // set values of neurons of first layer
    neuron1.set_activation(0.333);
    neuron2.set_activation(0.666);

    // get the input value of the neuron
    double a = neuron1.get_activation();

    // applying function f to the input value of a neuron
    neuron1.set_activation_function(f(a));

    // get the value of the neuron after applying f
    double b = neuron1.get_activation();

    // object that holds the weights between two layers
    weight weight1;

    //set number of neurons in first layer as number of columns in a matrix
    weight1.set_size_1(2);

    // set number of neurons in second layer as number of rows in a matrix
    weight1.set_size_2(3);

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
    double activation = neuron1.get_activation();
    // --> hier jetzt die verbindung zu den vektoren mit den neuronen der einzelnen layer

    return 0;

}
