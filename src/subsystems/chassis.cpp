#include "include/subsystems/chassis.hpp"
using namespace okapi::literals;

//ARBITRARY PORTS!!!!
const int8_t leftBack = 1; 
const int8_t leftMid = 2; 
const int8_t leftFront = 3;
const int8_t rightBack = -4;
const int8_t rightMid = -5; 
const int8_t rightFront = -6;

std::shared_ptr<okapi::ChassisController> chassis = okapi::ChassisControllerBuilder()
    .withMotors({leftBack, leftMid, leftFront}, {rightBack, rightMid, rightFront})
    .withDimensions(okapi::AbstractMotor::gearset::blue, {{3.25_in, }, okapi::imev5BlueTPR}) //TODO: get wheel track
    .build();