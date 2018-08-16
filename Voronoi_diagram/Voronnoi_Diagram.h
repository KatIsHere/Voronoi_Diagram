#pragma once
#include <cmath>
#include "Binary_Tree.h"

struct Point {
	double x = 0;
	double y = 0;

	double dist(const Point& b) {
		return sqrt((x - b.x)*(x - b.x) + (y - b.y)*(y - b.y));
	}

	Point& operator=(Point b) {
		x = b.x;
		y = b.y;
		return *this;
	}

	bool operator==(const Point& b) {
		return x == b.x && y == b.y;
	}

	bool operator>(const Point& b) {
		return (y > b.y) || (y <= b.y && x > b.x);
	}

	bool operator<(const Point& b) {
		return (y < b.y) || (y >= b.y && x < b.x);
	}
};


class Arc {

};


struct Place_Event {
	Point place;
	Place_Event& operator=(Place_Event pl) {
		place = pl.place;
		return*this;
	}
};

struct Circle_Event {
	Point Low_circle_point;
	Arc* dissaperingArc;
	Circle_Event() {
		dissaperingArc = nullptr;
	}

	Circle_Event& operator=(Circle_Event cir) {
		Low_circle_point = cir.Low_circle_point;
		dissaperingArc = cir.dissaperingArc;
		return *this;
	}
};

class Event {
	Event(Place_Event place) {
		isPlace = true;
		isCircle = false;
		_place = place;
		_circle = Circle_Event();
	}


	Event(Circle_Event circle) {
		isPlace = false;
		isCircle = true;
		_circle = circle;
	}

private:
	Place_Event _place;
	bool isPlace;
	Circle_Event _circle;
	bool isCircle;
};