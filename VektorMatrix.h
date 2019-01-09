#pragma once
#include "bibliotheken.h"

#include "inputoutput.h"
#include "neuron.h"

// layers
typedef vector<float> Hiddenlayer;
typedef vector<float> inputlayer;
typedef vector <float> outputlayer;

inputlayer il;

using namespace std;

class vektormatrix {
	void kantengewichte(); // Eine Matrix als eingabe und ein Outputvektor (Layer). Die Matrix wird mit dem Layer multipliziert und es entsteht ein neues Inputvector 
};
