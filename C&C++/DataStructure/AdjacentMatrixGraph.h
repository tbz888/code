#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <deque>

class Graph
{
public:
	Graph();
	Graph(bool[5][5]);
	void bfs(int root);
	void bfsTraverse();

	void dfs(int root);
	void dfsTraverse();
//	void printShortestPathDijistra(int src, int dest);
private:
	int vertex[5];
	bool adjacence[5][5];
	bool visited[5];
};

void Graph::dfs(int root)
{
	if (visited[root-1])	return;
	std::cout << root << "\n";
	visited[root-1] = true;
	for (int i = 1; i <= 5; ++i)
		if (adjacence[root-1][i-1] && !visited[i-1])
			Graph::dfs(i);
}

void Graph::dfsTraverse()
{
	for (int i = 0; i < 5; ++i)
	{
		visited[i] = false;
	}
	for (int i = 0; i < 5; ++i)
	{
		dfs(i+1);
	}
}

void Graph::bfs(int root)
{
	std::deque<int> toBeVisit;
	toBeVisit.push_back(root);
	visited[root-1] = true;
	while (!toBeVisit.empty())
	{
		int number = *(toBeVisit.begin());
		std::cout << number << "\n";
		for (int i = 0; i < 5; ++i)
		{
			if (adjacence[number-1][i] && !visited[i])
			{
				toBeVisit.push_back(i+1);
				visited[i] = true;
			}
		}
		toBeVisit.pop_front();
	}
}

void Graph::bfsTraverse()
{
	for (int i = 0; i < 5; ++i)
	{
		visited[i] = false;
	}
	for (int i = 0; i < 5; ++i)
	{
		bfs(i+1);
	}
}

Graph::Graph()
{
	for (int i = 0; i < 5; ++i)
	{
		visited[i] = false;
		for (int j = 0; j < 5; ++j)
			adjacence[i][j] = 0;
	}
}

Graph::Graph(bool src[5][5])
{
	for (int i = 0; i < 5; ++i)
	{
		visited[i] = false;
		for (int j = 0; j < 5; ++j)
			adjacence[i][j] = src[i][j];
	}
}

#endif
