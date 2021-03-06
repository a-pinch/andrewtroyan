#include "Robot.h"
#include "Bolt.h"
#include "GlobalVariables.h"
#include <cmath>
#include <cstdlib>
#include <typeinfo>

const double Robot::robot_speed = 10; 
const double Robot::robot_radius = 10;
const int Robot::robot_energy = 1000;

void Robot::makeDecision() {
	double safeDestForBolts = 3.0 / FPS, safeDestForRobots = robot_radius;
	bool to_move_random = true;

	for (auto it : objectStorage) {
		// if this object is a robot
		if (typeid(it) == typeid(Robot*)) {
			double destination = hypot(x - it->x, y - it->y);
			if (destination < safeDestForRobots) {
				//we're going to shoot

				//evaluating energy to shoot
				int energy_to_shoot;
				if (destination <= safeDestForRobots * 3 / 10)
					energy_to_shoot = energy * 15 / 100;
				else if (destination > safeDestForRobots * 3 / 10 && destination <= safeDestForRobots * 7 / 10) 
					energy_to_shoot = energy * 10 / 100;
				else 
					energy_to_shoot = energy * 5 / 100;
				
				// if energy_to_shoot is 0, we won't shoot
				if (!energy_to_shoot)
					break;

				//descending robot's energy
				energy -= energy_to_shoot;
				//shooting
				shoot(it->x, it->y, energy_to_shoot * 2);

				//move to another direction
				double future_destination = hypot(x - (it->x + it->vx * 1.0 / FPS), y - (it->y + it->vy * 1.0 / FPS));
				if (future_destination < destination) {
					//moving
					if (x - (it->x - x) > 0 && x - (it->x - x) < arenaXSize) {
						moveToPoint(x -= (it->x - x), it->y);
						move(1.0 / FPS);
					}
					else 
						break;

					//making to_move_random false (because we've moved already)
					to_move_random = false;
				}
			}
		}
		// if this object is a bolt
		else {
			double destination = hypot(x - it->x, y - it->y);
			if (destination < safeDestForBolts) {
				//move to another destination
				moveToPoint(x -= (it->x - x), it->y);
				move(1.0 / FPS);

				//making to_move_random false (because we've moved already)
				to_move_random = false;
			}
		}
	}

	//our robot decides if to move or not (depending on to_move_random)
	if (to_move_random) {
		//move random
		double random_x = rand() % (int)arenaXSize;
		double random_y = rand() % (int)arenaYSize;
		moveToPoint(random_x, random_y);
		move(1.0 / FPS);
	}
}