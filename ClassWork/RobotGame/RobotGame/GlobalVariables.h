#pragma once

#include "Circle.h"
#include <vector>

using std::vector;

static vector<Circle*> objectStorage;

static const double FPS = 20;		  // frames per second
static const double arenaXSize = 500; // pixels
static const double arenaYSize = 500; // pixels