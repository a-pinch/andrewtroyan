#pragma once

#include "Circle.h"
#include "Bolt.h"

class Robot : public Circle {
public:
	Robot(double init_x, double init_y)
		: Circle(init_x, init_y, robot_speed, energy) {};

	void makeDecision();

	void shoot(double target_x, double target_y, int energy) {
		new Bolt(x, y, target_x, target_y, energy);
		// add it to array
	}

	static const double robot_speed; // pixels / sec
	static const double robot_radius; //pixels
	static const int    robot_energy; // initial energy
};
