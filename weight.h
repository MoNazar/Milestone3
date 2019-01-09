//
// Created by user on 09.01.19.
//

#ifndef MILESTONE3_WEIGHT_H
#define MILESTONE3_WEIGHT_H
using namespace std;



class weight {
private:
    int size_1;  // number of columns of the matrix that holds all the weights
    int size_2;  // number of rows
    double weights_matrix[100][100];   // initialise a 2d array to store the weights


public:
    weight(); //constructor
    void set_size_1(int neurons_layer1);   // set number of neurons in first layer
    void set_size_2(int neurons_layer2);   // set number of neurons in second layer
    void random_weights();   // fill in random values to initialise the weight matrix
    double get_weight(int i, int j);
    void set_weight(int i, int j, double new_weight);

};


#endif //MILESTONE3_WEIGHT_H
