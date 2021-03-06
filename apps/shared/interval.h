#ifndef SHARED_VALUES_INTERVAL_H
#define SHARED_VALUES_INTERVAL_H

namespace Shared {

class Interval {
public:
  Interval();
  // Delete the implicit copy constructor: the object is heavy
  Interval(const Interval&) = delete;
  int numberOfElements();
  void deleteElementAtIndex(int index);
  double element(int i);
  double start();
  double end();
  double step();
  void setStart(double f);
  void setEnd(double f);
  void setStep(double f);
  void setElement(int i, double f);
  // TODO: decide the max number of elements after optimization
  constexpr static int k_maxNumberOfElements = 100;
private:
  void computeElements();
  int m_numberOfElements;
  double m_intervalBuffer[k_maxNumberOfElements];
  double m_start;
  double m_end;
  double m_step;
  bool m_needCompute;
};

typedef void (Interval::*SetterPointer)(double);
typedef double (Interval::*GetterPointer)();

}

#endif
