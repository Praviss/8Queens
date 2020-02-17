#include <bits/stdc++.h>
using namespace std;

int heuristic(int graph[][4], int g[], vector<int> not_v,int node){
	std::vector<int> not_visited;
	for(int i = 0; i < not_v.size(); ++i){
		not_visited.push_back(not_v[i]);
	}
	int x = not_visited.size(), n = node;
	std::vector<int> vis;
	int cost = 0, idx = 0, m;
	vis.push_back(node);
	not_visited.erase(std::remove(not_visited.begin(), not_visited.end(), node), not_visited.end());
	while(vis.size() != x){
	

		m = INT_MAX;
		for(int i = 0; i < not_visited.size(); ++i){
			if(node != not_visited[i]){
				if(graph[node][not_visited[i]] < m){
					idx = not_visited[i];
					m = graph[node][not_visited[i]];
				}
			}
		}
		// cout << "pushing " << idx << " to vis\n";
		vis.push_back(idx);
		not_visited.erase(std::remove(not_visited.begin(), not_visited.end(), idx), not_visited.end());
		node = idx;
		// cout << "adding " << m << " to cost .. \n";
		cost += m;
	}
	m = INT_MAX;
	for(int i = 0; i < not_v.size(); ++i){
		if(not_v[i] != n){
			if(graph[n][i] < m){
				m = graph[n][i];
			}
		}
	}
	int w;
	switch(n){
		case 0 : 
				w = 0;
				break;
		case 1 :
				w = 10;
				break;
		case 2 :
				w = 15;
				break;
		case 3 :
				w = 20;
				break;
	}
	cout << "node : " << n << "  m : " << m  << " w : " << w << endl;
	return cost + m + w;
}

void a_star_algo(int graph[][4], int g[], int h[], int node){
	vector<int> visited;
	vector<int> not_visited;
	vector<int> open;
	vector<int> closed;
	// node graph_data[4];
	int f[4] = {0, 0, 0, 0};

	for(int i = 0; i < 4; ++i){
		not_visited.push_back(i);
	}

	open.push_back(node);

	// int c = 0;
	int min = 10000, idx = 0;
	h[0] = heuristic(graph, g, not_visited, 0);
	f[0] = g[0] + h[0];

	while(1){
		min = 1000;
		// cout << "while started..................." << endl;
		for(int i = 0; i < open.size(); ++i){
			// cout << "f[open[i]] : " << f[open[i]] << "  min : " << min << "\n"; 
			if(f[open[i]] < min){
				// cout << "hfffffffffffffff\n";
				min = f[open[i]];
				idx = open[i];
				// cout << " idx : " << idx;
			}
		}

		node = idx;

		open.erase(std::remove(open.begin(), open.end(), idx), open.end());

		if(visited.size() == 4) break;
		int ct = 0;
		for(int i = 0; i < 4; ++i){
			for(int k = 0; k < closed.size(); ++k){
				if(closed[k] == i){
					ct = 1;
					break;
				}
			}
			if(i != node && ct == 0){
				// cout << "fmdkj";

				// cout << "node  : " << node <<  "   ";

				if(find(open.begin(), open.end(), i) != open.end())
				{
				    //elem exists in the vector
				    // cout << "deleting " << i << " from open list" << endl;
					open.erase(std::remove(open.begin(), open.end(), i), open.end()); //delete that value from node
					// cout << "\npushing " << i << " in open list\n";
					open.push_back(i);
					// cout << " hello  world ";
				} 
				

				//if it is also not in closed
				else if(find(closed.begin(), closed.end(), i) != closed.end());

				else {
					// cout << "\npushing " << i << " in open list\n";
					open.push_back(i);
				}
				
				g[i] = g[node] + graph[node][i];
				f[i] = g[i] + heuristic(graph, g, not_visited, i);
			}
			ct = 0;
		}
		// cout << "open .... " << endl;
		// for(int j = 0; j < open.size(); ++j) cout << "open[" << j << "] : " << open[j] << endl;
		// cout << "end .. " << endl;

		// cout << "INSERTING " << node << "INTO CLOSED\n";
	
		closed.push_back(node);
	
		visited.push_back(node);
	
		not_visited.erase(std::remove(not_visited.begin(), not_visited.end(), node), not_visited.end());
		// not_visited.delete(node);
	}
	for(int i = 0; i < visited.size(); ++i){
		cout << visited[i] + 1 << endl;
	}
}

int main(){
	
	int graph[][4] = {
		{ 0, 10, 15, 20 }, 
        { 10, 0, 35, 25 }, 
        { 15, 35, 0, 30 }, 
        { 20, 25, 30, 0 }
	};

	int g[4] = {0, 0, 0, 0};
	int h[4] = {0, 0, 0, 0};

	a_star_algo(graph, g, h, 0);

	return 0;
}