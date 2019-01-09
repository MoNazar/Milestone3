#include <iostream>
#include <math.h>
#include <vector>
#include "neuron.h"
#include "weight.h"

using namespace std;

// layers
typedef vector<double> Hiddenlayer;
typedef vector<double> inputlayer;
typedef vector <double> outputlayer;

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

    // creating a vector to store the values of the input layer
    inputlayer il;

    // neurons of the input layer
    neuron neuron1;
    neuron neuron2;
    neuron neuron3;
    neuron neuron4;

    // set values of neurons of input layer
    neuron1.set_activation(1.00);
    neuron2.set_activation(0.00);
    neuron3.set_activation(0.33);
    neuron4.set_activation(0.66);

    // store the values of the input layer in a vector
    il.push_back(neuron1.get_activation()); il.push_back(neuron2.get_activation());
    il.push_back(neuron3.get_activation()); il.push_back(neuron4.get_activation());
    for (int i = 0; i < 4; i++) {
        cout << il[i] << endl;
    }

    // get the input value of the neuron
    double a = neuron1.get_activation();

    // applying function f to the input value of a neuron
    neuron1.set_activation_function(f(a));

    // get the value of the neuron after applying f
    double b = neuron1.get_activation();

    // object that holds the weights between two layers
    weight weight1;

    //set number of neurons in first layer as number of columns in a matrix
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
    double z = (il[0] * weight1.get_weight(0, 0)) + (il[1] * weight1.get_weight(1, 0))
            + (il[2] * weight1.get_weight(2, 0)) + (il[3] * weight1.get_weight(3, 0));

    double output = f(z);
    cout << output;

    return 0;
}
