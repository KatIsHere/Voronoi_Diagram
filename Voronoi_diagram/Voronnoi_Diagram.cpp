#include "Voronnoi_Diagram.h"
using namespace std;
Voronoi_diagram::Voronoi_diagram(){}


Voronoi_diagram::Voronoi_diagram(std::vector<Point> P)
{
	setNewPoints(P);
}


void Voronoi_diagram::setNewPoints(std::vector<Point> P)
{
	edges.clear();
	// initialize T
	for (int i = 0; i < P.size(); ++i) {
		events.push_back(Event(Place_Event(P[i])));
	}
}


void Voronoi_diagram::HandlePlaceEvent(Place_Event p)
{
	if (beachLine.isEmpty()) {

	}
}

void Voronoi_diagram::ConstructDiagram()
{
	Event currentEvent;
	while (!events.empty())
	{
		currentEvent = events.top();
		events.pop();
		if (currentEvent.isPlace_Event()) {
			HandlePlaceEvent(currentEvent.getPlaceEvent());
		}
		else {
			HandleCircleEvent(currentEvent.getCircleEvent());
		}
	}
}
