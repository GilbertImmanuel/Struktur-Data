#include<bits/stdc++.h>
using namespace std;

class Graph {
    private:
        int v;
        string nama[100];
        vector<vector<int>> adj;
        vector<int> dfsResult;
        vector<int> dijkstraRes;
        int dfsWeight;

    public:
        Graph(int v) {
            this->v = v;
            vector<int> l (v+1, -1);
            adj.assign(v+1, l);
            dfsResult.assign(v+1, 0);
            vector<int> vec (v+1, 0);
        }
        void nameVertex(int i, string nama){
	    this->nama[i]=nama;
	    vector<int>arr;
	    arr.push_back(i);
	    sort(arr.begin(), arr.end());
	}

        void addEdge(int u, int v, int w){
            adj[u][v] = w;
        }

        void tampilList(){
        	cout << "=== Adjacency Matrix ===" << endl<<endl;
            for (int i = 1; i <= v; i++)
            {
                for ( int j = 1; j <= v; j++)
                {
                	
                    if(adj[i][j] == -1)cout << ".  ";
                    else if (adj[i][j] < 10) cout << adj[i][j] << "  ";
                    else cout << adj[i][j] << " ";
                    
                }
                cout << endl;
            }
            cout << endl;
        }
        
        void BFS(int start, int end){
            cout << endl;
            cout << "=== BFS ===" << endl;
            vector<int> visit (v+1, 0);
            vector<int> dist (v+1, INT_MAX);
            vector<int> domain (v+1, 0);
            queue<int> q;

            dist[start] = 0;
            q.push(start);
            visit[start] = true;

            while (!q.empty())
            {
                int curr = q.front();
                for (int it = 1; it <= v; it++)
                {
                        if(adj[curr][it] != -1 && adj[curr][it] + dist[curr] < dist[it]){
                            dist[it] = adj[curr][it] + dist[curr];
                            domain[it] = curr;
                            q.push(it);
                        }
                }
                q.pop();
            }
            vector<int> result;
            int i = end;
            while(true){
                result.push_back(i);
                if(i == start) break;
                i = domain[i];
            }

            for (int i = result.size()-1; i >= 0; i--)
            {
                cout << nama[result[i]] <<"(V" <<  result[i] << ")"<< ", ";
            }
            
            cout << endl << "Weight = " << dist[end] << endl;
            
        }
        
        void DFS(int start, int end){
            cout << endl;
            cout << "=== DFS === "<< endl;
            dfsWeight = INT_MAX;
            vector<int> path;
            vector<bool> visited (v+1, false);
            solveDFS(start, end, path, visited, 0 );
            
            for (int i = 0; i < dfsResult.size(); i++)
            {
                cout << nama[dfsResult[i]] <<"(V" <<  dfsResult[i] << ")"<< ", ";
            }

            cout << endl << "Weight = " << dfsWeight << endl;
        }

        void solveDFS(int start, int end, vector<int> path, vector<bool> visited, int currWeight){
            if(start == end) {
                path.push_back(end);
                if(currWeight < dfsWeight ) {
                    dfsWeight = currWeight;
                    dfsResult = path;
                }
            }
            visited[start] = true;
            path.push_back(start);
            bool flag = false;
            for ( int it = 1; it <= v; it++)
            {
                if(!visited[it] && adj[start][it] != -1){
                    int wtemp = currWeight;
                    wtemp += adj[start][it];
                    flag = true;
                    solveDFS(it, end, path, visited, wtemp);
                }
            }
        }

        int minDist(vector<int> dist, vector<bool> vis){
            int min = INT_MAX;
            int min_index = INT_MAX;
            for (int i = 1; i <= v; i++)
            {
                if(!vis[i] && dist[i] < min) {
                    min = dist[i];
                    min_index = i;
                }
            }
            return min_index;
        }

        void dijkstra(int start, int end){
            cout << endl << "===  Dijkstra ===" << endl;
            vector<int> dist (v+1, INT_MAX);
            vector<bool> vis (v+1, false);
            vector<int> res (v+1, 0);
            dist[start] = 0;
            for (int itv = 1; itv <= v ; itv++)
            {
                int min = minDist(dist, vis);
                vis[min] = true;
                for(int it = 1; it <= v; it++){
                    if (
                        adj[min][it] != -1 &&
                        !vis[it] && 
                        dist[min] + adj[min][it] < dist[it]
                    )
                    {
                        dist[it] = dist[min] + adj[min][it] ; 
                        res[it] = min;
                    }
                }
            }
            int i = res[end];
            vector<int> r;
            r.push_back(end);
            while (true)
            {
                r.push_back(i);
                if(i == start) break;
                i = res[i];
            }
            reverse(r.begin(), r.end());
            for (int i = 0; i <  r.size(); i++)
            {
                cout << nama[r[i]] <<"(V" <<  r[i] << ")"<< ", ";
            }
            cout << endl << "Weight = " << dist[end] << endl;
        }
};

int main(){
    Graph g(22);
    g.nameVertex(1, "Rumah"); 						g.nameVertex(12, "Apotek_Kimia_Farma");
    g.nameVertex(2, "Sodaqo_Minimarket");			g.nameVertex(13, "SD_Strada_Dipamarga");
    g.nameVertex(3, "Ruamah_Sepupu");  				g.nameVertex(14, "Pom_Bensin_Pertamina");
    g.nameVertex(4, "Kantor_Kelurahan"); 			g.nameVertex(15, "Mall_Giant_Pondok Kopi");
    g.nameVertex(5, "SMPN_213"); 					g.nameVertex(16, "SMPN_199");
    g.nameVertex(6, "Pasar_Perumnas_Klender"); 		g.nameVertex(17, "Pondok_Kelapa_Town_Square");
    g.nameVertex(7, "GO_Delima"); 					g.nameVertex(18, "McDonalds_Raden_Inten");
    g.nameVertex(8, "Carl's_Junior'"); 				g.nameVertex(19, "Burger_King_Raden_Inten");
    g.nameVertex(9, "Carrefour_Buaran"); 			g.nameVertex(20, "Inten_Kalimalang");
    g.nameVertex(10, "Dunkin_Donuts"); 				g.nameVertex(21, "GO_Kalimalang");
    g.nameVertex(11, "HKBP_Duren_Sawit");			g.nameVertex(22, "SMAN_81"); 	

    g.addEdge(1, 2, 1);			g.addEdge(10, 12, 15);
    g.addEdge(1, 5, 3);			g.addEdge(11, 12, 8);
    g.addEdge(1, 7, 4);			g.addEdge(12, 13, 9);
    g.addEdge(2, 3, 3);			g.addEdge(14, 15, 11);
    g.addEdge(2, 4, 3);			g.addEdge(14, 17, 15);
    g.addEdge(3, 4, 2);			g.addEdge(14, 18, 22);
    g.addEdge(4, 6, 10);		g.addEdge(15, 16, 11);
    g.addEdge(4, 14, 10);		g.addEdge(16, 17, 24);
    g.addEdge(5, 6, 6);			g.addEdge(17, 16, 24);
    g.addEdge(6, 4, 10);		g.addEdge(18, 14, 22);
    g.addEdge(7, 8, 5);			g.addEdge(18, 19, 1);
    g.addEdge(8, 9, 13);		g.addEdge(18, 20, 31);
    g.addEdge(8, 10, 2);		g.addEdge(20, 21, 8);
    g.addEdge(8, 18, 16);		g.addEdge(20, 22, 5);
    g.addEdge(10, 9, 12);		g.addEdge(21, 22, 14);
    g.addEdge(10, 11, 12);
  
    g.tampilList();
    int start, end;
    cout << "Start: ";
    cin >> start;
    cout << "End: ";
    cin >> end;
    g.BFS(start, end);
    g.DFS(start, end);
    g.dijkstra(start, end);
    return 0;
}
