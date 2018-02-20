// BellManFordAlgorithm.cpp : Defines the entry point for the console application.
// also it can detect -ve weight in the graph

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <SDL.h>
#include <map>
#include <limits>
void addedge(std::vector< std::pair<int,int> > v1[], int u, int v,int wt)
{
	v1[u].push_back(std::make_pair(v, wt));
	//v1[v].push_back(std::make_pair(u, wt));
}
/*
void printgraph(std::vector<std::pair<int, int> > v1[], int V)
{
	SDL_Window  * w = NULL;
	w = SDL_CreateWindow("Graph Plotting", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,480, SDL_WINDOW_RESIZABLE);
	if (w == NULL)
	{
		std::cout << SDL_GetError();
	}


		SDL_Renderer * R1 = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED);
		if (R1 == nullptr)
		{
			std::cout << SDL_GetError();
		}

		bool check = true;
		SDL_Event e;

		SDL_SetRenderDrawColor(R1, 23, 67, 53, 89);

		while (check == true)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					check = false;
				}


			}
			
				for (int i = 0; i < V; i++)
				{

					for (std::vector<std::pair<int, int> > ::iterator it = v1[i].begin(); it != v1[i].end(); it++)
					{
							SDL_RenderDrawLine(R1, 95*i + 50, 50, it->first + 700,(it->second)*5);
					}

				}
			


			SDL_RenderPresent(R1);
		}

		SDL_DestroyRenderer(R1);
		SDL_DestroyWindow(w);

}
*/
void showparent(std::map<int, int> p, int parent, int child)
{
	if (p[child] == 0)
		std::cout << child<<"-->" << p[child];
	else
	{
		std::cout << child << "-->" << p[child];
		showparent(p, p[parent], parent);
	}
}


void bellmanford(std::vector<std::pair<int, int> > v[], int source, int vertex)
{
	std::map<int, int> m;
	m.insert(std::pair<int, int>(0, 0));
	m.insert(std::pair<int, int>(1, INT_MAX));
	m.insert(std::pair<int, int>(2, INT_MAX));
	m.insert(std::pair<int, int>(3, INT_MAX));
//	m.insert(std::pair<int, int>(4, INT_MAX));

	std::map<int, int> parent;
	parent.insert(std::pair<int, int>(0, 0));
	parent.insert(std::pair<int, int>(1, 0));
	parent.insert(std::pair<int, int>(2, 0));
	parent.insert(std::pair<int, int>(3, 0));
//	parent.insert(std::pair<int, int>(4, 0));


	
	for (int k = 0; k < vertex ; k++)
	{
		 
		for (int i = 0; i < vertex; i++)
		{
			for (std::vector<std::pair<int, int> > ::iterator it = v[i].begin(); it != v[i].end(); it++)
			{
				if (m[it->first] > m[i] + it->second)
				{
					m[it->first] = m[i] + it->second;
					parent[it->first] = i;
				}
					
			}
		}
	}
	std::cout << "Repetion done v times : " << std::endl;
	for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		std::cout << it->first << "\t" << it->second << "\n";
	}
	
	for (std::map<int, int>::iterator it = parent.begin(); it != parent.end(); it++)
	{
		std::cout << it->first << "-->" << it->second << "\n";
	}


/*
	for (int i = 0; i < vertex; i++)
	{
		showparent(parent, parent[i], i);
		std::cout << std::endl;
	}
*/
	system("pause");
}


int main(int argc,char ** argv)
{
	int V = 4;
	std::vector <std::pair<int, int>> adj[5];
/*
	addedge(adj, 0, 1, 4);
	addedge(adj, 0, 2, 5);
	addedge(adj, 0, 3, 8);
	addedge(adj, 2, 4, 4);
	addedge(adj, 3, 4, 2);
	addedge(adj, 4, 3, 1);
	addedge(adj, 1, 2, -3);
*/
	addedge(adj, 0, 1, 1);
	addedge(adj, 1, 2, 3);
	addedge(adj, 2, 3, 2);
	addedge(adj, 3, 1, -6);
	//printgraph(adj, V);
	int source = 0;
	bellmanford(adj, source,V);
    return 0;
}

