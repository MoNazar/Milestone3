//
// Creates a neural network based on a given topology.
// stores neurons in vectors for every layer of the network.
//

#ifndef MILESTONE3_NEURAL_NET_H
#define MILESTONE3_NEURAL_NET_H

#include <vector>
#include <math.h>
#include "neuron.h"
#include "weight.h"
using namespace std;


class neural_net {
private:
    vector<neuron> neurons_input_layer;
    vector<neuron> neurons_hidden_layer;
    vector<neuron> neurons_output_layer;

    int number_of_hidden_layers;
    int number_of_neurons_input_layer;
    int number_of_neurons_hidden_layer;
    int number_of_neurons_output_layer;

    weight matrix_of_edgeweights_between_layers;

public:

    // getter
    int get_number_of_hidden_layers();
    int get_number_of_neurons_input_layer();
    int get_number_of_neurons_hidden_layer();
    int get_number_of_neurons_output_layer();

    // setter
    void set_number_of_hidden_layers(int number_of_hidden_layers);
    void set_number_of_neurons_input_layer(int number_of_neurons_input_layer);
    void set_number_of_neurons_hidden_layer(int number_of_neurons_hidden_layer);
    void set_number_of_neurons_output_layer(int number_of_neurons_output_layer);

    void set_up_network(vector<double> input_values);
    
    //generate Layer while using tpology
	void generatelayer_inputlayer(inputlayer input);
	void generatelayer_hiddenlayer(inputlayer input); 
	void generatelayer_outputlayer(inputlayer input);

};


#endif //MILESTONE3_NEURAL_NET_H
