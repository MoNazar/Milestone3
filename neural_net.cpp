//
// Created by user on 12.01.19.
//
#include "neural_net.h"
using namespace std;


// getter
int neural_net::get_number_of_hidden_layers(){
    return number_of_hidden_layers;
};

int neural_net::get_number_of_neurons_input_layer(){
    return number_of_neurons_input_layer;
};

int neural_net::get_number_of_neurons_hidden_layer(){
    return number_of_neurons_hidden_layer;
};

int neural_net::get_number_of_neurons_output_layer(){
    return number_of_neurons_output_layer;
}

// setter
void neural_net::set_number_of_hidden_layers(int number_of_hidden_layers) {
    this -> number_of_hidden_layers = number_of_hidden_layers;
}

void neural_net::set_number_of_neurons_input_layer(int number_of_neurons_input_layer) {
    this -> number_of_neurons_input_layer = number_of_neurons_input_layer;
}

void neural_net::set_number_of_neurons_hidden_layer(int number_of_neurons_hidden_layer) {
    this->number_of_neurons_hidden_layer = number_of_neurons_hidden_layer;
}


void neural_net::set_number_of_neurons_output_layer(int number_of_neurons_output_layer) {
    this->number_of_neurons_output_layer = number_of_neurons_output_layer;
};

double f(double x) {
    double b = pow(1 + exp(-x), -1);
    return b;
}


// diese funktion weist einem vektor neuronen-objekte zu. als parameter kann ein inputlayer vektor gnommen werden
void neural_net::set_up_network(vector<double> input_values) {
    for(int a = 0; a < number_of_neurons_input_layer; a++){
        double activation = input_values[a];
        neurons_input_layer.push_back(neuron(activation, 1.0, f(activation)));

    }
}
