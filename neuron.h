#ifndef MILESTONE3_NEURON_H
#define MILESTONE3_NEURON_H

class neuron {
private:
    double activation;   // the state the neuron is in = its value
    double bias;
    double activation_function;

public:
    //getter
    double get_activation();
    double get_bias();

    //setter
    void set_activation(double activation);
    void set_bias(double bias);
    double set_activation_function(double activation_function);
    double set_derivative(double deviative);

};


#endif //MILESTONE3_NEURON_H
