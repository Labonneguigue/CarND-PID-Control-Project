# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

[//]: # (Image References)

[pid]: images/pid.tiff "pid"
[sim]: images/sim.tiff "sim"

## PID Controller

A controller takes as input(s) sensor data and convert it/them into an output that is directly controlling an actuator to impact an object's position or state in the physical world.

In this case, I'm controlling a car in a simulator. Here is a capture of it:

![alt text][sim]

Input:
* Cross track error `cte` (distance of the car form the center of the road).

Output:
* Steering angle `st`

A PID controller has 3 components/gains that will be taken into account to calculate the output steering angle:
* proportional `Kp`
* differential `Kd`
* integral `Ki`

The formula is really simple:

```cpp
st = - Kp * cte
     - Kd * (cte - prev_cte)
     - Ki * sum(cte)
```

Where `prev_cte` is the cte at the previous iteration and sum is pseudo code for the sum of all the `cte`observed since the beginning of the simulation.

Here is a visualization of the incremental addition of the differential and integral gains.

![alt text][pid]

## Parameter tuning

I started with similar values as in the Udacity lessons for the 3 different gains:
```cpp
Kp = 0.3
Kd = 3
Ki = 0.004
```
I observed that even though the car would drive continuously, there was too much oscillation. By looking at the first figure, I concluded that the oscillation was due to a proportional gain being to high. Therefore I lowered it to `0.15`.

Then, I observed that the correction for an increase in the cross track error would overshoot and result on having the car bouncing on the other side of the road. I deduced that the integral component was the faulty one here. After a few tests, I obtained a value for the integral gain of `0.0008`.

I tried tweaking the differential gain without observable improvement.

### Final parameters

```cpp
Kp = 0.15       ///< proportional gain
Kd = 3          ///< differential gain
Ki = 0.0008     ///< integral gain
```

-------

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`.

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)
