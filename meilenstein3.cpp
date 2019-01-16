#include <iostream>
#include "neuron.h"
#include "weight.h"
#include <fstream>
#include <string>
#include <sstream>
#include "layer.h"
#include "neural_net.h"
using namespace std;

// Der Anfang des ganzen. 
// Idee: Wir erstellen anfangs, ein Input Layer. Dazu erstellen wir eine offene Topologie mit 4 neuronen zu anfang. 
// store layers as vectors

int readfile () {
	string line;
	ifstream myfile ("output.txt");
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			cout << line << '\n';
		}
		myfile.close();


	}

	else cout << "Unable to open file";

	return 0;
}

// the activation function we use to calculate the output of a layer
double fkt1(double x) {
	double b = pow(1 + exp(-x), -1);
	return b;
}

// derivative of the function f in order to calculate a minimum of the costs of a neural network as backpropagation
double fkt1abl(double x) {
	double b = exp(-x) / pow(exp(-x) + 1, 2);
	return b;
}


int main() {
	// Der Anfang des ganzen. 
	/*-----------Inputlayer----------------------------------*/
	inputlayer il;
	neuron n1; neuron n2; neuron n3; neuron n4; //Inputlayer
	/*-----------Hiddenlayer---------------------------------*/
	Hiddenlayer H1; // Layer 2 , nächstes Layer //Hiddenlayer
	neuron n5; neuron n6; neuron n7; neuron n8;
	/*-----------Outputlayer---------------------------------*/
	outputlayer ol; 
	neuron n9; neuron n10; neuron n11;

	// Konsole Programm
	cout << "**------------------------------**" << endl;
    cout << "**--------- Neural Net ---------**" << endl;
	cout << "**------------------------------**" << endl;
	cout << "**------ 1 Create ANN ----------**" << endl;
	cout << "**------------------------------**" << endl;
	cout << "**------ 2 Read File -----------**" << endl;
	cout << "**------------------------------**" << endl;
	cout << "**------ 3 Import File ---------**" << endl;
	cout << "**------------------------------**" << endl;
	int menu ;
	cin >> menu;

	if (menu == 1) {
		cout << "**------ Input Layer Neurones :";
		int x ;
		cin >> x; // x Anzahl von Input Neuronen
		cout << "**------ Hidden Layer Neurones :";
		int y ;
		cin >> y; // y Anzahl von Hidden Neuronen
		cout << "**------ Output Layer Neurones :";
		int z ;
		cin >> z; // z Anzahl von Output Neuronen
		double set_activation1;
		double set_activation2;
		double set_activation3;
		double set_activation4;
		for (int i = 0; i<x;i++){

			if (i == 0){
				cout << "**------ Set values for neuron 1 of input layer :";
				cin >> set_activation1; }

			if (i == 1){
				cout << "**------ Set values for neuron 2 of input layer :";
				cin >> set_activation2; }
			if (i == 2){
				cout << "**------ Set values for neuron 3 of input layer :";
				cin >> set_activation3; }
			if (i == 3){
				cout << "**------ Set values for neuron 4 of input layer :";
				cin >> set_activation4; }





		}
		//inputlayer il; ACHTUNG! FÜR DEN ERSTEN SCHRITT GILT DIE AKTIVIERUNGSFUNKTION NICHT.
		n1.set_activation(set_activation1);
		n2.set_activation(set_activation2);
		n3.set_activation(set_activation3);
		n4.set_activation(set_activation4);

		il.push_back(n1); il.push_back(n2); il.push_back(n3); il.push_back(n4);
		// generate Hiddenlayer
		H1.push_back(n5); H1.push_back(n6); H1.push_back(n7); H1.push_back(n8);
       // generate Outputlayer
		ol.push_back(n9); ol.push_back(n10); ol.push_back(n11);

		//-----------------------NeuronalNet-----------------------------------------------------------------

		neural_net ann;
		// topologie
		ann.set_number_of_neurons_input_layer(x);
		ann.set_number_of_neurons_hidden_layer(y);
		ann.set_number_of_neurons_output_layer(z);
		// generating layers of neural net
		ann.generatelayer_inputlayer(il);
		ann.generatelayer_hiddenlayer(H1);
		ann.generatelayer_outputlayer(ol);
		// generate random matrix between input layer an hidden layer
		ann.generatematrix();
		// get input layer activations
		ann.getlayer_input();
		printf("\n");
		// Connection Inputlayer -> Hiddenlayer
		ann.connected();
		// get hiddenlayer activations
		ann.getlayer_hidden();
		printf("\n");
		// generate random matrix between hidden layer and output layer
		ann.generatematrix1();
		// Connection Hiddenlayer -> Outputlayer
		ann.connected1();
		// Get outputlayer
		ann.getlayer_output();
		    // to calculate the gradient between the layers, we first establish a vector of the known output.
    // parameters are one integer of the index of the neuron that should have an output == 1,
    // and a vector of the output layer.
    double eta = 0.1;
    double alpha = 0.5;
    vector<int> target = target_values(2, ann.getlayer_output());

    vector<double> hidden = ann.getlayer_hidden();
    vector<double> input = ann.getlayer_input();
    vector<double> output = ann.getlayer_output();
    vector<double> weights;

    for (int j = 0; j < ann.get_number_of_neurons_output_layer(); j++){
        for(int i = 0; i < ann.get_number_of_neurons_hidden_layer(); i++){
            weights.emplace_back(ann.matrix_of_edgeweights_between_hiddenlayer_and_outputlayer.get_weight(j, i));
            }
        }

    for (int i = 0; i < weights.size(); i++) {
            cout << weights[i] << endl;
    }



    weights = back(target, hidden, input, weights, output, eta, alpha);
    for (int i = 0; i < weights.size(); i++){
        for(int j = 0; j < ann.get_number_of_neurons_output_layer(); j++){
            cout << ann.matrix_of_edgeweights_between_hiddenlayer_and_outputlayer.get_weight(i, j);
            ann.matrix_of_edgeweights_between_hiddenlayer_and_outputlayer.set_weight(i, j, weights[i*j]);
            cout << ann.matrix_of_edgeweights_between_hiddenlayer_and_outputlayer.get_weight(i, j);
        }
    cout << endl;
    }
		ann.save();
		main();
	}

	else if ( menu == 2 ){
		printf("\n");
		cout << "**------------------------------------------------------------**" << endl;
		cout << "**------------------------ output.txt ------------------------**" << endl;
		cout << "**------------------------------------------------------------**" << endl;
		readfile();
		cout << "**------------------------------------------------------------**" << endl;
		cout << "**------------------------------------------------------------**" << endl;

		printf("\n");
		printf("\n");
		main();
	}

	else{
		std::string file_name;
		std::string line;
		double set_activation_string1;
		double set_activation2_string2;
		double set_activation3_string3;
		double set_activation4_string4;

		cout << "**------ File Name for Import (.txt) :";
		cin >> file_name;
		ifstream myfile1;
		neural_net ann1;
		myfile1.open (file_name);
		int i = 0;
		if (myfile1.is_open())

		{
			while ( getline (myfile1,line) ){
				if (i == 0 ){

					std::string str2 = line.substr (0,1);
					std::string str2_gewicht1 = line.substr (26,8);
					std::string str2_gewicht2 = line.substr (38,8);
					std::string str2_gewicht3 = line.substr (50,8);
					std::string str2_gewicht4 = line.substr (62,8);

					stringstream geek(str2);
					double t = std::stod (str2_gewicht1);
					double t1 = std::stod (str2_gewicht2);
					double t2 = std::stod (str2_gewicht3);
					double t3 = std::stod (str2_gewicht4);
					int a = 0;
					n1.set_activation(t);
					n2.set_activation(t1);
					n3.set_activation(t2);
					n4.set_activation(t3);
					geek >> a;
					cout << "Input Neuron 1 : ";
					cout << t << endl;
					cout << "Input Neuron 2 : ";

					cout << t1 << endl;
					cout << "Input Neuron 3 : ";

					cout << t2 << endl;
					cout << "Input Neuron 4 : ";

					cout << t3 << endl;
					il.push_back(n1); il.push_back(n2); il.push_back(n3); il.push_back(n4);
					// generate Hiddenlayer
					H1.push_back(n5); H1.push_back(n6); H1.push_back(n7); H1.push_back(n8);
					// generate Outputlayer
					ol.push_back(n9); ol.push_back(n10); ol.push_back(n11);


					ann1.set_number_of_neurons_input_layer(a);

				}
				if (i == 1 ){


					std::string str3 = line.substr (0,1);
					stringstream geek(str3);
					int b = 0;
					geek >> b;
					cout << b << endl;

					ann1.set_number_of_neurons_hidden_layer(b);


					}
				if (i == 2 ){

					std::string str4 = line.substr (0,1);
					stringstream geek(str4);
					int c = 0;
					geek >> c;
					cout << c << endl;
					ann1.set_number_of_neurons_output_layer(c);

					}
				i = i+1;



			}

			ann1.generatelayer_inputlayer(il);
			ann1.generatelayer_hiddenlayer(H1);
			ann1.generatelayer_outputlayer(ol);
			// generate random matrix between input layer an hidden layer
			ann1.generatematrix();
			// get input layer activations
			ann1.getlayer_input();
			printf("\n");
			// Connection Inputlayer -> Hiddenlayer
			ann1.connected();
			// get hiddenlayer activations
			ann1.getlayer_hidden();
			printf("\n");
			// generate random matrix between hidden layer and output layer
			ann1.generatematrix1();
			// Connection Hiddenlayer -> Outputlayer
			ann1.connected1();
			// Get outputlayer
			ann1.getlayer_output();
			ann1.save();
			main();
			myfile1.close();

			   }






	}

	


	return 0;
}
