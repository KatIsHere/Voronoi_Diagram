#pragma once
#include <cmath>
#include "Binary_Tree.h"
#include <vector>
#include <queue>
#include <list>
#include <algorithm>

struct Point {
	double x = 0;
	double y = 0;

	// Euclidian distance
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

struct  Edge
{
	Point a;
	Point b;

	double length() {
		return a.dist(b);
	}
};

class Arc {

};


class T {

};

//class Event {
//	Event() {
//		_place_ = Point();
//	}
//	Event(Point place) {
//		_place_ = place;
//	}
//	const Point& getPlace() {
//		return _place_;
//	}
//	bool operator>(Event eventb) {
//		return (_place_ > eventb.getPlace());
//	}
//	bool operator<(Event eventb) {
//		return _place_ < eventb.getPlace();
//	}
//protected:
//	Point _place_;
//};
//
//class Event_Place : public Event {
//public:
//	Event_Place(Point place) : Event(place) {}
//	const Point& getPlace() : getPlace() {};
//	Event_Place& operator=(Event_Place pl) {
//		_place_ = pl.getPlace();
//		return *this;
//	}
//};
//
//class Event_Circle : public Event {
//public:
//	Event_Circle(Point place, Arc* dissArc) : Event(place) {
//		dissaperingArc = dissArc;
//	}
//
//	const Point& getPlace() : getPlace() {};
//	void deleteArc() {
//		if (dissaperingArc != nullptr)
//		{
//			delete dissaperingArc;
//		}
//	}
//private:
//	Arc * dissaperingArc;
//};


struct Place_Event {
	Point place;
	Place_Event(){}
	Place_Event(Point plac) {
		place = plac;
	}
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
	Event() {
		isPlace = false;
		isCircle = false;
	}

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


	bool isPlace_Event() {
		return isPlace;
	}



	Place_Event getPlaceEvent() {
		if (isPlace)
			return _place;
		return Place_Event();
	}

	Circle_Event getCircleEvent() {
		if (isCircle)
			return _circle;
		return Circle_Event();
	}

	Event& operator=(Event ev) {
		isPlace = ev.isPlace_Event();
		isCircle = !isPlace;
		_place = ev.getPlaceEvent();
		_circle = ev.getCircleEvent();
		return *this;
	}
private:
	Place_Event _place;
	bool isPlace;
	Circle_Event _circle;
	bool isCircle;
};


class Voronoi_diagram{
public:
	// NEED TO SORT EVENTS
	Voronoi_diagram();
	Voronoi_diagram(std::vector<Point> P);
	void setNewPoints(std::vector<Point> P);

private:
	// std::vector<Point> points;	// P
	std::priority_queue<Event> events;	// Q
	std::list<Edge> edges;		// D
	Binary_Tree<T> beachLine;	// T

	void HandlePlaceEvent(Place_Event p);
	void HandleCircleEvent(Circle_Event p);

	void ConstructDiagram();
};