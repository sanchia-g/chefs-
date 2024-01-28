#include "include/subsystems/chassis.hpp"
using namespace okapi::literals;

//ARBITRARY PORTS!!!!
const int8_t leftBack = 1; 
const int8_t leftMid = 2; 
const int8_t leftFront = 3;
const int8_t rightBack = -4;
const int8_t rightMid = -5; 
const int8_t rightFront = -6;
//these are just motor port vales, you never initialised actual motors

std::shared_ptr<okapi::ChassisController> chassis = okapi::ChassisControllerBuilder()
//make this odom       ^                                    ^
    .withMotors({leftBack, leftMid, leftFront}, {rightBack, rightMid, rightFront})
//                ^ cannot construct a motor group with integer values
    .withDimensions(okapi::AbstractMotor::gearset::blue, {{3.25_in, }, okapi::imev5BlueTPR}) //TODO: get wheel track
//are you using blue cartridges?                    ^                                ^
    .build();
//build with odom!!!


//where yo updateChassis function
