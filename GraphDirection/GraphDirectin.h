
#include <iostream>
#define SIZE 10
using namespace std;
using namespace std;
struct Edge
{
	int weight;
	char begin;
	char des;
	Edge* link;
	Edge() {};
	Edge(char a, char d, int v) :begin(a), des(d), weight(v), link(NULL) {}
};
struct Vertex
{
	char data;
	Edge* list;
	Vertex() :list(NULL) {}
};
class GraphLinkDirection
{
private:
	int V;
	int E;
	int MaxVertex;
public:

	friend void Dijkstra(GraphLinkDirection G,char a);
	Vertex* vertextable;
	GraphLinkDirection() {
		MaxVertex = SIZE;
		V = E = 0;
		vertextable = new Vertex[MaxVertex];
	}
	void InsertVertex(char v) {
		if (V >= MaxVertex)
			return;
		vertextable[V++].data = v;
	}
	int GetVertex(char v) {
		for (int i = 0; i < V; i++)
		{
			if (vertextable[i].data == v)
				return i;
		}
		return -1;
	}
	void InsertEdge(char v1, char v2, int weight) {
		int p1 = GetVertex(v1);
		int p2 = GetVertex(v2);
		if (p1 == -1 || p2 == -1)
			return;
		//p1->p2
		Edge * ed = new Edge(v1, v2, weight);
		ed->link = vertextable[p1].list;//05  015  0215 list指向第一个链接点位置
		vertextable[p1].list = ed;
		E++;
	}
	void Show()
	{
		int i;
		for (i = 0; i < V; i++)
		{
			cout << vertextable[i].data << "->";
			Edge* p = vertextable[i].list;
			while (p)
			{
				cout << p->des << " " << p->weight << " " << "->";
				p = p->link;
			}
			cout << "nul" << endl;
		}
	}
	void DeleteEdge(char v1, char v2) {
		int p1 = GetVertex(v1);
		int p2 = GetVertex(v2);
		if (p1 == -1 || p2 == -1)
			return;
		//p1->p2
		Edge * p = vertextable[p1].list;
		Edge * s = NULL;
		while (p && p->des != v2)
		{
			s = p;
			p = p->link;
		}
		if (p == NULL)
			return;
		if (s == NULL)
			vertextable[p1].list = p->link;
		else
			s->link = p->link;
		delete p;
		//p2->p1;
		E--;
	}
	/*void DeleteVertex(char v)
	{
		int p = GetVertex(v);
		if (p == -1)
			return;
		Edge * s = NULL;
		Edge *dep = vertextable[p].list;//找到v的边
		while (dep)
		{
			int destvalue = edp->destvalue;
			Edge *q = VertexTable[destvalue].list;
			s = NULL;
			while(q && q->destvalue != p)
			{
				s = q;
				q = q->link;
			}
			if(s == NULL)
				VertexTable[destvalue].list = q->link;
			else
				s->link = q->link;
			delete q;
			q = NULL;
			VertexTable[p].list = edp->link;
			delete edp;
			edp = VertexTable[p].list;
			NumEdge--;
		}
		//删除顶点
		NumVertex--;
		//用最后一个覆盖删除的顶点
		VertexTable[p].data = VertexTable[NumVertex].data;
		VertexTable[p].list = VertexTable[NumVertex].list;

		edp = VertexTable[p].list;
		while(edp)
		{
			int destvalue = edp->destvalue;
			s = VertexTable[destvalue].list;
			while(s&&s->destvalue != NumVertex)
			{
				s = s ->link;
			}
			s->destvalue = p;
			edp = edp->link;
		}
	}*/
	~GraphLinkDirection()
	{
		/*Edge *p = NULL;
		for (int i = 0; i < V; ++i)
		{
			p = vertextable[i].list;
			while (p)
			{
				vertextable[i].list = p->link;
				delete p;
				p = vertextable[i].list;
			}
		}
		delete[]vertextable;
		vertextable = NULL;*/
	}
};

