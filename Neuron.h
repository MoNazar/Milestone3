#pragma once

/* eine Klasse für ein Neuron. Dabei soll die Aktivierungsfunktion und deren Ableitung variabel gesetzt werden können. */


// Aktivieirungsfunktion und die ableitung f(x) = (1+e^-x)^-1 


class neuron {
private:
	//float bias = 1.0;
	float aktivate1;
	//float inputweight;

public:
	float bias ;
	float inputweight; // Gewicht der Eingangskante. Dies ist der Einfluss der Neuronen aus dem vorherigen Layer auf ein einzelnes Neuron im neuen Layer.
	void aktivate(float inputweight); // Sigmond funktion. Nimmt als Argument das Gewicht der Eingangskante.
	void setinputweight(); // kantengewicht kann variabel gesetzt werden.
	void setactive(float value); // xi kann variabel gesetzt werden.
	void getactive(); // aktivierter Wert des Neurons. 

	


};
