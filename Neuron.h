#pragma once

/* eine Klasse für ein Neuron. Dabei soll die Aktivierungsfunktion und deren Ableitung variabel gesetzt werden können. */


// Aktivieirungsfunktion und die ableitung f(x) = (1+e^-x)^-1 


#include "bibliotheken.h"



class neuron {
private:
	float activation;   // the state the neuron is in = its value
	float bias; 	// Neuron hat ein BIAS
	float activation_function;
	// Eingangswerte
	// Ein Vektor importieren in das Neuron 
	
public:
	void getelements(vector<float> &inputvalues); // Werte des Vektors auslesen  
	void berechnegewicht(float x); // aktivierungsfunktion  
	void aktivierungsfunktion(float x); // Neuron hat eine Ausgabe 
	void ableitung(float x);

	// Neuron hat eingehende Kanten 
	
	//getter
	double get_activation();
	double get_bias();

	//setter
	void set_activation(float activation); 
	void set_bias(float bias);
	double set_activation_function(float activation_function);
	


	
};
