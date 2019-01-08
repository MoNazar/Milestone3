#include <iostream>
#include <math.h>
#include "neuron.h"
using namespace std;

double f(double x) {
    double b = pow(1 + exp(-x), -1);
    return b;
}

int main() {
    neuron neuron1;
    neuron1.set_activation(0.333);
    double a = neuron1.get_activation();
    cout << "value of the neuron = " << a << endl;
    a = neuron1.set_activation_function(f(a));  //other activation functions can be defined and assigned to neuron
    cout << "neuron after applying activation function f = " << a << endl;

    return 0;

}
