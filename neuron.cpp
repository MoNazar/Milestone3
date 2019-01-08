#include "neuron.h"

double neuron::get_activation(){
    return activation;
}

double neuron::get_bias() {
    return bias;
}

void neuron::set_activation(double activation) {
    this -> activation = activation;
}

void neuron::set_bias(double bias) {
    this -> bias = bias;
}

double neuron::set_activation_function(double activation_function){
    this -> activation_function = activation_function;
}

