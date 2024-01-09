#include <iostream>
#include<vector> 
using namespace std;
void DijkstrasTest();

class Node;
class Edge;

vector<Node*>* AdjacentRemainingNodes(Node* node);
Node* ExtractSmallest(vector<Node*>& nodes);
int Distance(Node* node1, Node* node2);
bool Contains(vector<Node*>& nodes, Node* node);
void PrintShortestRouteTo(Node* destination);
vector<Node*> nodes;
vector<Edge*> edges; 

class Node{
public:
    string id;
	Node* previous;
	int distanceFromStart;
	Node(string id)
		: id(id), previous(NULL), distanceFromStart(INT_MAX)
	{
		nodes.push_back(this);
	}
};
class Edge{
    public:
    Node* node1;
	Node* node2;
	int distance;
	Edge(Node* node1, Node* node2, int distance): node1(node1), node2(node2), distance(distance){
		edges.push_back(this);
	}
	bool Connects(Node* node1, Node* node2)
	{
		return (
			(node1 == this->node1 &&
			node2 == this->node2) ||
			(node1 == this->node2 &&
			node2 == this->node1));
	}
};

void Dijkstras()
{
	while (nodes.size() > 0)
	{
		Node* smallest = ExtractSmallest(nodes);
		vector<Node*>* adjacentNodes = AdjacentRemainingNodes(smallest);
		const int size = adjacentNodes->size();
		for (int i=0; i<size; ++i){
			Node* adjacent = adjacentNodes->at(i);
			int distance = Distance(smallest, adjacent)+smallest->distanceFromStart;
			if (distance < adjacent->distanceFromStart){
				adjacent->distanceFromStart = distance;
				adjacent->previous = smallest;
			}
		}
		delete adjacentNodes;
	}
}
Node* ExtractSmallest(vector<Node*>& nodes)
{
	int size = nodes.size();
	if (size == 0) return NULL;
	int smallestPosition = 0;
	Node* smallest = nodes.at(0);
	for (int i=1; i<size; ++i){
		Node* current = nodes.at(i);
		if (current->distanceFromStart <smallest->distanceFromStart){
			smallest = current;
			smallestPosition = i;
		}
	}
	nodes.erase(nodes.begin() + smallestPosition);
	return smallest;
}
vector<Node*>* AdjacentRemainingNodes(Node* node){
	vector<Node*>* adjacentNodes = new vector<Node*>();
	const int size = edges.size();
	for(int i=0; i<size; ++i){
		Edge* edge = edges.at(i);
		Node* adjacent = NULL;
		if (edge->node1 == node){
			adjacent = edge->node2;
		}else if (edge->node2 == node){
			adjacent = edge->node1;
		}if (adjacent && Contains(nodes, adjacent)){
			adjacentNodes->push_back(adjacent);
		}
	}
	return adjacentNodes;
}
int Distance(Node* node1, Node* node2){
	const int size = edges.size();
	for(int i=0; i<size; ++i){
		Edge* edge = edges.at(i);
		if (edge->Connects(node1, node2)){
			return edge->distance;
		}
	}
	return -1;
}
bool Contains(vector<Node*>& nodes, Node* node){
	const int size = nodes.size();
	for(int i=0; i<size; ++i){
		if (node == nodes.at(i)){
			return true;
		}
	}
	return false;
}
void PrintShortestRouteTo(Node* destination){
	Node* previous = destination;
	cout << "Distance from start: "<< destination->distanceFromStart << endl;
	while (previous){
		cout << previous->id << "<-";
		previous = previous->previous;
	}
	cout << endl;
}
main(){
	Node* islambad = new Node("islambad");
	Node* rawalpindi = new Node("rawalpindi");
	Node* lahore = new Node("lahore");
	Node* murree = new Node("murree");
	Node* multan = new Node("multan");
	Node* peshawar = new Node("peshawar");
	Node* gujrat = new Node("gujrat");

	Edge* e1 = new Edge(islambad, lahore, 25);
	Edge* e2 = new Edge(islambad, murree, 65);
	Edge* e3 = new Edge(rawalpindi, lahore, 31);
	Edge* e4 = new Edge(lahore, murree, 63);
	Edge* e5 = new Edge(rawalpindi, peshawar, 15);
	Edge* e6 = new Edge(lahore, multan, 6);
	Edge* e7 = new Edge(multan, peshawar, 54);
	Edge* e8 = new Edge(murree, gujrat, 15);
	Edge* e9 = new Edge(gujrat, peshawar, 69);

	islambad->distanceFromStart = 0;
	Dijkstras();
	PrintShortestRouteTo(islambad);
    PrintShortestRouteTo(rawalpindi);
    PrintShortestRouteTo(lahore);
}