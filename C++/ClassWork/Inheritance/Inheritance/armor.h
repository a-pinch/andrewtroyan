#pragma once

#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

class detail {
public:
	int id;

	detail() { id = rand(); };
};

class platform : public detail {
public:
	void ride() { cout << "Choo choo..." << endl; };
};

class turret : public detail {
public:
	void shoot() { cout << "Bang Bang!!!" << endl; };
};

class armor : public platform, public turret {
public:
	void show_details_id() {
		cout << platform::id << endl;
		cout << turret::id << endl;
	}
};

class virtual_platform : virtual public detail {
public:
	void ride() { cout << "Choo choo..." << endl; };
};

class virtual_turret : virtual public detail {
public:
	void shoot() { cout << "Bang Bang!!!" << endl; };
};

class virtual_armor : virtual public virtual_platform, virtual public virtual_turret {
public:
	void show_details_id() {
		cout << virtual_platform::id << endl;
		cout << virtual_turret::id << endl;
	}
};