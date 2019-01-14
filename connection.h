#include "neuron.h"
#include "layer.h"
#include "weight.h"
#include <vector>

// Connect neurons of one layer with neurons of the next layer

void connect(inputlayer input, weight w1, Hiddenlayer nextlayer) {
	float influence = 0.0;
	for (int j = 0; j < input.size(); j++) {
		for (int i = 0; i < input.size(); i++) {
			influence = influence + (input[i].get_activation() * w1.get_weight(j, i));
			
		}
		nextlayer[j].set_activation(influence);
		
	}
	influence = 0.0;
}
