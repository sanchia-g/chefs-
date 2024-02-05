#include "main.h"
bool checkifmoving(){}
    leftFront.getActualVelocity();
    rightFront.getActualVelocity(); 
    return (leftFront.getActualVelocity() + rightFront.getActualVelocity()) >= 4; 


void pid(double target){
    okapi::IterativePosPIDController pid = okapi::IterativeControllerFactory::podPID(Kp, Ki, Kd);
    pid.setTarget();
initialy = drive->getState().y.convert(okapi::foot);
initialx = drive->getState().x.convert(okapi::foot); 
    while(checkifmoving()){
            dy = drive->getState().y.convert(okapi::foot) - initialy;
            dx = drive->getState().x.convert(okapi::foot) - initialx; 
            displacement = std::sqrt(pow(dy, 2) + pow(dx, 2));

        double pidValue = pid.step(displacement)(); 
        left.setVelocity(pidValue);
        right.setVelocity(pidValue);
        motor.controllerSet()
        rate.delay(100.Hz)

    
    }

     } 

vod updateDriver() {
    con
}