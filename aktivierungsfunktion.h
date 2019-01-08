#pragma once

#include "bibliotheken.h"

// Aktivierungsfunktion.
auto f(float x) {
	float b = pow(1 + exp(-x), -1);
	

}
// Ableitung der Aktivierungsfunktion.
auto fabl(float x) {
	float b = exp(-x) / pow(exp(-x) + 1, 2);
	

}
