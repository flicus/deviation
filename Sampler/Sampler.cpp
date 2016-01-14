#include "Arduino.h"
#include "Sampler.h"



int values[MAX];
int size = 0;

Sampler::Sampler() {
    this->pointer = 0;
    this->sum = 0;
}

void Sampler::sample(int value) {
    sum -= values[pointer];
    values[pointer] = value;
    sum += value;
    pointer++;
    if (pointer > (MAX - 1)) pointer = 0;
    if (size < MAX) size++;
}

double Sampler::deviation() {
    if (size == 1) return 0;
    int mean = sum / size;
    int tmp = 0;
    for (int i = 0; i < size; i++) {
        tmp += sq(values[i] - mean);
    }
    return sqrt(tmp / (size - 1));
}
