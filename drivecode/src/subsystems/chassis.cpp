#include "include/subsystems/chassis.hpp"
using namespace okapi::literals;

//ARBITRARY PORTS!!!!
const int8_t left1 = 1; 
const int8_t left2 = -2; //neg bc the middle motor is reversed
const int8_t left3 = 3;
const int8_t right1 = -4;
const int8_t right2 = 5; //pos bc the middle motor is reversed
const int8_t right3 = -6;

std::shared_ptr<okapi::ChassisController> chassis = okapi::ChassisControllerBuilder()
    .withMotors({left1, left2, left3}, {right1, right2, right3})
    .withDimensions(okapi::AbstractMotor::gearset::blue, {{3.25_in, }, okapi::imev5BlueTPR}) //TODO: get wheel track
    .build();