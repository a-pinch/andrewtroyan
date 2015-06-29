#pragma once

//I've located these classes in one file just for example

class Animal {
};

class Flyers {
};

class Donkey : public Animal {
};

class Bat : public Animal, public Flyers {
};

