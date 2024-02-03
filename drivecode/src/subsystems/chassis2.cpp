#include "subsystems/chassis2.hpp"
using namespace okapi;

Motor leftFront(1, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees); 
Motor leftMiddle(2, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor leftBack(3, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees); 

Motor rightFront(4, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees); 
Motor rightMiddle(5, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor rightBack(6, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees); 

MotorGroup leftDrive({leftFront, leftMiddle, leftBack});
MotorGroup rightDrive({rightFront, rightMiddle, rightBack});

okapi::IterativePosPIDController pid = okapi::IterativeControllerFactory::podPID(Kp, Ki, Kd); 

std::shared_ptr<okapi::OdomChassisController> chassis = okapi::ChassisControllerBuilder()
    .withMotors({leftFront, leftMiddle, leftBack}, {rightFront, rightMiddle, rightBack})
    .withDimensions(okapi::AbstractMotor::gearset::blue, {{3.25_in, }, okapi::imev5BlueTPR})
    .withOdometry()
    .buildOdometry();