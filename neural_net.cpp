#include "neural_net.h"

#include <iostream>
using namespace std;



// getter
int neural_net::get_number_of_hidden_layers() {
	return number_of_hidden_layers;
}

int neural_net::get_number_of_neurons_input_layer() {
	return number_of_neurons_input_layer;
}

int neural_net::get_number_of_neurons_hidden_layer() {
	return number_of_neurons_hidden_layer;
}

int neural_net::get_number_of_neurons_output_layer() {
	return number_of_neurons_output_layer;
}

// setter
void neural_net::set_number_of_hidden_layers(int number_of_hidden_layers) {
	this->number_of_hidden_layers = number_of_hidden_layers;
}

void neural_net::set_number_of_neurons_input_layer(int number_of_neurons_input_layer) {
	this->number_of_neurons_input_layer = number_of_neurons_input_layer;
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


void neural_net::generatelayer_inputlayer(inputlayer input) {
	for (int i = 0; i < number_of_neurons_input_layer; i++) {
		neurons_input_layer.push_back(input[i]);
		
	}
	//neuron bias;
	//neurons_input_layer.push_back(bias);
}

void neural_net::generatelayer_outputlayer(inputlayer input1) {
		for (int i = 0; i < number_of_neurons_output_layer; i++) {
			neurons_output_layer.push_back(input1[i]);

		}		
}

void neural_net::generatelayer_hiddenlayer(inputlayer input2) {
	for (int i = 0; i < number_of_neurons_hidden_layer; i++) {
		neurons_hidden_layer.push_back(input2[i]);
	}
	//neuron hiddenbias;
	//neurons_hidden_layer.push_back(hiddenbias);
}

void neural_net::getlayer_input() {
	for (int i = 0; i < neurons_input_layer.size(); i++) {
		cout << neurons_input_layer[i].get_activation() << endl;
		
	}
}

void neural_net::getlayer_hidden() {
	for (int i = 0; i < neurons_hidden_layer.size(); i++) {
		cout <<neurons_hidden_layer[i].get_activation() << endl;

	}
}
// Aufgabe 2.b
void neural_net::getlayer_output() {
	for (int i = 0; i < neurons_output_layer.size(); i++) {
		cout << neurons_output_layer[i].get_activation() << endl;

	}
}

void neural_net::generatematrix() {
	matrix_of_edgeweights_between_layers.set_size_1(neurons_input_layer.size());
	matrix_of_edgeweights_between_layers.set_size_2(neurons_hidden_layer.size());
	matrix_of_edgeweights_between_layers.random_weights();
}
void neural_net::connected() {
	float influence = 0.0;
	for (int j = 0; j < neurons_input_layer.size(); j++) {
		for (int i = 0; i < neurons_hidden_layer.size(); i++) {
			influence = influence + (neurons_input_layer[i].get_activation() * matrix_of_edgeweights_between_layers.get_weight(j, i));

		}
		neurons_hidden_layer[j].set_activation(influence);

	}
	influence = 0.0;
}
void neural_net::getmatrix() {
	for (int j = 0; j < neurons_input_layer.size(); j++) {
		for (int i = 0; i < neurons_hidden_layer.size(); i++) {
			
			cout << matrix_of_edgeweights_between_layers.get_weight(j, i) << endl;
        
		}
		printf("\n");
	}
}
void neural_net::generatematrix1() {
	matrix_of_edgeweights_between_hiddenlayer_and_outputlayer.set_size_1(neurons_hidden_layer.size());
	matrix_of_edgeweights_between_hiddenlayer_and_outputlayer.set_size_2(neurons_output_layer.size());
	matrix_of_edgeweights_between_hiddenlayer_and_outputlayer.random_weights();

}
void neural_net::connected1(){
	float influence = 0.0;
	for (int j = 0; j < neurons_hidden_layer.size(); j++) {
		for (int i = 0; i < neurons_output_layer.size(); i++) {
			influence = influence + (neurons_hidden_layer[i].get_activation() * matrix_of_edgeweights_between_hiddenlayer_and_outputlayer.get_weight(j, i));

		}
		neurons_output_layer[j].set_activation(influence);

	}
	influence = 0.0;
}




void neural_net::save(){

	ofstream myfile;                        // Openfile
	myfile.open ("output.txt");
	for (int j = 0; j < 3; j++) {
		if (j == 0) {
			myfile << save_input1+ " \n";
		}
		if (j == 1) {
			myfile << save_input2+ " \n";
		}
		if (j == 2) {
			myfile << save_input3+ " \n";
		}

	}
	myfile.close();
}

