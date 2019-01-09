#include <iostream>
#include <math.h>
#include "neuron.h"
#include "weight.h"

using namespace std;

double f(double x) {
    double b = pow(1 + exp(-x), -1);
    return b;
}

int main() {
    neuron neuron1;
    neuron1.set_activation(0.333);      //set value of neuron
    double a = neuron1.get_activation();
    cout << "value of the neuron = " << a << endl;
    a = neuron1.set_activation_function(f(a));  //other activation functions can be defined and assigned to neuron
    cout << "output of neuron = " << a << endl;
    double b = neuron1.get_activation();

    weight weight1;  // object that holds the weights between two layers
    weight1.set_size_1(2);  //set number of neurons in first layer
    weight1.set_size_2(3);  // set number of neurons in second layer
    weight1.random_weights();  // assign random values as weights to matrix and print it
    weight1.set_weight(1,2, 0.123);  //update weight
    weight1.get_weight(1,2);



    return 0;

}
