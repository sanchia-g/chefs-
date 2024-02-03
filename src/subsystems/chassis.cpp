#include "subsystems/chassis.hpp"
using namespace okapi::literals;

okapi::Motor rightFront(6, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor rightMid(5, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor rightBack(4, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor leftFront(3, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor leftMid(2, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
okapi::Motor leftBack(1, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);

okapi::MotorGroup leftDrive({leftFront, leftMid, leftBack});
okapi::MotorGroup rightDrive({rightFront, rightMid, rightBack});

std::shared_ptr<okapi::OdomChassisController> chassis = okapi::ChassisControllerBuilder()
//make this odom       ^                             
    .withMotors({leftBack, leftMid, leftFront}, {rightBack, rightMid, rightFront})
//                ^ cannot construct a motor group with integer values
    .withDimensions(okapi::AbstractMotor::gearset::blue, {{3.25_in, }, okapi::imev5BlueTPR * (36/60.)}) //TODO: get wheel track
    .withOdometry()
    .buildOdometry();