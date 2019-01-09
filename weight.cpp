//
// Created by user on 09.01.19.
//

#include "weight.h"
#include <random>
#include <iostream>

using namespace std;

weight::weight() {
    //constructor
}


// fills out the matrix that holds all the weights with random numbers with normal distributive behaviour. prints it.
void weight::random_weights() {

    default_random_engine generator;
    normal_distribution<double> distribution(0.0,1.0);  // normal distribution with mean = 0.0 and deviation = 1.0

    for(int i = 0; i < size_2; i++){
        for(int j = 0; j < size_1; j++){
            weights_matrix[i][j] = distribution(generator);
            cout << weights_matrix[i][j] << "   ";
        }
        cout <<endl;
    }
}


// to get a specific weight of index i,j
double weight::get_weight(int i, int j) {
    cout <<  weights_matrix[i][j];
    return weights_matrix[i][j];
}


// to update the value of one specific weight. parameters: indices i and j as integers; new weight as double
void weight::set_weight(int i, int j, double new_weight) {
    this -> weights_matrix[i][j] = new_weight;
}


// to set the size of the matrix, represents the number of neurons in the first layer
void weight::set_size_1(int neurons_layer1){
    this -> size_1 = neurons_layer1;
}

// to set the size of the matrix, represents the number of neurons in the first layer
void weight::set_size_2(int neurons_layer1){
    this -> size_2 = neurons_layer1;
}
