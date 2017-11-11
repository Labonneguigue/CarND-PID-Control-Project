#include "PID.h"


PID::PID()
: mKd(0.0F)
, mKi(0.0F)
, mKp(0.0F)
, mProportionalError(0.0F)
, mIntegralError(0.0F)
, mDerivativeError(0.0F)
{}

PID::~PID() {}

void PID::Init(float Kp, float Ki, float Kd) {
    mKp = Kp;
    mKi = Ki;
    mKd = Kd;
}

void PID::UpdateError(float cte) {

    mIntegralError = cte - mProportionalError;
    mProportionalError = cte;
    mDerivativeError += cte;

}

float PID::TotalError() {
    return ( - (mKp * mProportionalError)
             - (mKi * mIntegralError)
             - (mKd * mDerivativeError) );
}

