#ifndef Sampler_h
#define Sampler_h

#include <inttypes.h>

#define MAX 10

class Sampler
{
 
public:
  Sampler();
  void sample(int value);
  double deviation();
  
private:
  int pointer;  
  long sum;
  
};

#endif
