#include <vector>
#include <math.h>
#include "neuron.h"
#include "weight.h"
#include "layer.h"
//#include "connection.h"

#include <iostream>
using namespace std;


class neural_net {
private:

	int number_of_hidden_layers;
	int number_of_neurons_input_layer;
	int number_of_neurons_hidden_layer;
	int number_of_neurons_output_layer;

	

public:
	inputlayer neurons_input_layer;
	Hiddenlayer neurons_hidden_layer;
    outputlayer neurons_output_layer;
	weight matrix_of_edgeweights_between_layers;
	weight matrix_of_edgeweights_between_hiddenlayer_and_outputlayer;

	std::string save_input1 = "";
	std::string save_input2 = "";
	std::string save_input3 = "";
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

	//generate Layer while using tpology
	void generatelayer_inputlayer(inputlayer input);
	void generatelayer_hiddenlayer(inputlayer input); 
	void generatelayer_outputlayer(inputlayer input);

	//get Layer 
	void getlayer_input();
	void getlayer_hidden();
	void getlayer_output(); // returns all results of outputlayer, Aufgabe 2.b

	//Connection of neurons
	void generatematrix();
	void connected(); // connection input_layer -> hidden_layer
	void connected1(); // connection hidden_layer -> outputlayer
	void generatematrix1();
	void getmatrix();
		//Save in file
	void save();


};
