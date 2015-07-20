#include "Bolt.h"
#include "Circle.h"
#include "Robot.h"
#include "GlobalVariables.h"
#include <typeinfo>
#include <cmath>

int main() {
	objectStorage.push_back(new Robot(10, 10));
	objectStorage.push_back(new Robot(100, 20));

	while (objectStorage.size() > 1) {
		for (auto it = objectStorage.begin(); it != objectStorage.end(); ++it) {
			//check boarders
			if ((*it)->x < 0 || (*it)->x > arenaXSize || (*it)->y < 0 || (*it)->y > arenaYSize) {
				objectStorage.erase(it);
			}

			//if object's in correct boarders, act
			Robot* it_conv = dynamic_cast<Robot*>(*it);
			//if object is robot
			if (it_conv) {
				it_conv->makeDecision();
			}
			//if object is bolt
			else {
				(*it)->move(2.0 / FPS);
			}
		}

		//check bolts and collisions
		for (auto it : objectStorage) {
			//if it's robot
			if (typeid(it) == typeid(Robot*)) {
				//check other objects
				for (auto enemy : objectStorage) {
					//if that object is our robot
					if (&it == &enemy)
						continue;

					//if that object is other robot
					if (typeid(enemy) == typeid(Robot*)) {
						double distance = hypot(it->x - enemy->x, it->y - enemy->y);
						if (distance < Robot::robot_radius) {
							double deltaEnergy = abs(it->energy - enemy->energy);
							it->energy -= deltaEnergy;
							enemy->energy -= deltaEnergy;
						}
					}
					//if that object is bolt
					else {
						double distance = hypot(it->x - enemy->x, it->y - enemy->y);
						if (distance < Robot::robot_radius / 2) {
							double deltaEnergy = abs(it->energy - enemy->energy);
							it->energy -= deltaEnergy;
							enemy->energy -= deltaEnergy;
						}
					}

				}
			}
		}

		//if object is dead
		for (auto it = objectStorage.begin(); it != objectStorage.end(); ++it) {
			if ((*it)->energy <= 0) {
				objectStorage.erase(it);
			}
		}
	}

	return 0;
}