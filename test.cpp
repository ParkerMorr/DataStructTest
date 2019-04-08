#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vertex *findVertex(std::string name)
{

}

void Graph::addEdge(std::string v1, std::string v2, int distance)
{
	Edge e;
	vertex *V1 = findVertex(v1);
	vertex *V2 = findVertex(v2);
	e.v = V2;
	e.distance = distance;
	V1->Edges.push_back(e);
}

void Graph::addVertex(std::string name)
{
	vertex v;
	v.name = name;
    vertices.push_back(v);
}
void Graph::BFT_traversal(vertex* v)
{
    queue<vertex> queue;
	queue.push(*v);
	cout << (*v).name << endl;
	(*v).visited = true;
	while(!(queue.empty()))
	{
		vertex v0 = queue.front();
		queue.pop();
		for(int i = 0; i < v0.Edges.size();i++)
		{
			vertex *v1 = v0.Edges[i].v;
			if(!((*v1).visited))
			{
				(*v1).visited = true;
				cout << (*v1).name << endl;
				queue.push((*v1));
			}
		}
	}
}
void Graph::printBFT()
{
	//while loop while going through all vertices then call BFT traversal if not visited
	for(int i = 0; i < vertices.size();i++)
	{
		if(!(vertices[i].visited))
		{
			BFT_traversal(&vertices[i]);
		}
	}
}

//use same while from printBST //use ampersand to call helper
//call helper recursively

void Graph::DFT_traversal(vertex* v)
{
    v->visited = true;
    cout << v->name << endl;
    for(int i = 0; i < v->Edges.size();i++)
	{
		if(!(v->Edges[i].v->visited))
		{
			DFT_traversal(v->Edges[i].v);
		}
	}
}
void Graph::printDFT()
{
    for(int i = 0; i < vertices.size();i++)
	{
		if(!(vertices[i].visited))
		{
			DFT_traversal(&vertices[i]);
		}
	}
}

