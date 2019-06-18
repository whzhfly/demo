// GraphDirection.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "GraphDirectin.h"
int main()
{
	GraphLinkDirection g;
	g.InsertVertex('a');
	g.InsertVertex('b');
	g.InsertVertex('c');
	g.InsertVertex('d');
	g.InsertVertex('e');
	g.InsertVertex('f');
	g.InsertVertex('g');
	g.InsertVertex('h');
	g.InsertVertex('j');
	g.InsertEdge('a', 'h', 16);
	g.InsertEdge('b', 'h', 19);
	g.InsertEdge('c', 'd', 17);
	g.InsertEdge('g', 'b', 40);
	g.InsertEdge('d', 'g', 52);
	g.InsertEdge('e', 'f', 35);
	g.InsertEdge('g', 'e', 93);
	g.InsertEdge('a', 'c', 26);
	g.InsertEdge('f', 'h', 28);
	g.InsertEdge('b', 'd', 29);
	g.InsertEdge('b', 'f', 32);
	g.InsertEdge('c', 'h', 34);
	g.InsertEdge('b', 'c', 36);
	g.InsertEdge('e', 'h', 37);
	g.InsertEdge('a', 'e', 38);
	g.InsertEdge('g', 'a', 58);
	g.Show();
	Dijkstra(g, 'a');
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
