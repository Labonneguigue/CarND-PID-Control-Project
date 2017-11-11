#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(float Kp, float Ki, float Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(float cte);

  /*
  * Calculate the total PID error.
  */
  float TotalError();

private:
    /*
     * Coefficients
     */
    float mKp;
    float mKi;
    float mKd;
    
    /*
     * Errors
     */
    float mProportionalError;
    float mIntegralError;
    float mDerivativeError;

};

#endif /* PID_H */
