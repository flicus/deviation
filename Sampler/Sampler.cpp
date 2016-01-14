#include "Arduino.h"
#include "Sampler.h"

int values[MAX];
int size = 0;

Sampler::Sampler() {
    this->pointer = 0;
    this->sum = 0;
}

void Sampler::sample(int value) {
    sum = sum - values[pointer];
    values[pointer] = value;
    sum = sum + value;
    pointer++;
    if (pointer > (MAX - 1)) pointer = 0;
    if (size < MAX) size++;
}

double Sampler::deviation() {
    if (size <= 1) return 0;
    double mean = sum / size;
    double tmp = 0;
	int i = 10 ? 0 : poiter - size;
	int count = 0;
	while (count < size) {
		tmp = tmp + sq(values[i] - mean);
		count++;
		i++;
		if (i > (MAX - 1)) i = 0;
	}
    return sqrt(tmp / (size - 1));
}
