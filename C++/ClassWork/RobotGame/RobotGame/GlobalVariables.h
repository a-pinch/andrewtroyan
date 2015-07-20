#pragma once

#include "Circle.h"
#include <list>

using std::list;

static list<Circle*> objectStorage;

const double FPS = 20;		  // frames per second
const double arenaXSize = 500; // pixels
const double arenaYSize = 500; // pixels