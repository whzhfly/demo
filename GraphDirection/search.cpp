#include "GraphDirectin.h"
#include <algorithm>
#define SIZE 10
#include <queue>
using namespace std;
bool visited1[SIZE];
int distTo[SIZE];  //weightֵ
Edge  edgeTo[SIZE];
struct paircmp
{
	bool operator()(const pair<int, int> a, const pair<int, int> b) {
		return a.second > b.second;
	}
};
priority_queue<pair<int, int>, vector <pair<int, int> >, paircmp> PQ;
void relax(GraphLinkDirection G, int s) {
	Edge* p = G.vertextable[s].list;
	while (p)
	{
		char v = p->des;
		int w = G.GetVertex(v);
		if (distTo[w] > distTo[s] + p->weight)
		{
			distTo[w] = distTo[s] + p->weight;
			edgeTo[w] = *p;
			bool flag = false;
			priority_queue<pair<int, int> > tmp;
			while (!PQ.empty())
			{
				int k1 = PQ.top().first;
				int k2 = PQ.top().second;
				PQ.pop();
				if (k1 == w) {
					flag = true;
					k2 = distTo[w];
				}
				tmp.push(make_pair(k1, k2));
			}
			if (!flag)
				tmp.push(make_pair(w,distTo[w]));
			while (!tmp.empty())
			{
				int k1 = tmp.top().first;
				int k2 = tmp.top().second;
				tmp.pop();
				PQ.push(make_pair(k1, k2));

			}
		}
		p = p->link;
	}
}
void Dijkstra(GraphLinkDirection G,char a) {
	int s = G.GetVertex(a);
	for (int i = 0; i < G.V; i++)
		distTo[i] = 1000;
	distTo[s] = 0;
	PQ.push(make_pair(s, 0));
	while (!PQ.empty())
	{
		int k = PQ.top().first;
		PQ.pop();
		relax(G, k);
	}

	cout << "0" << "  edgeTo " << "       distTo " << endl;
	for (int i = 1; i < G.V; i++)
		cout << i << "  " << edgeTo[i].begin << " -> " << edgeTo[i].des << "  " << edgeTo[i].weight<<"  "<<distTo[i] << endl;
}