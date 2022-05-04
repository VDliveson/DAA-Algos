#include<iostream>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int> *adj;

    public:
    Graph(){}
    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v,int w){
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void DFSUtil(int v,bool visited[]){
        visited[v] = true;
        list<int>::iterator i;
        for(i = adj[v].begin(); i!= adj[v].end();i++){
            if(!visited[*i]){
                DFSUtil(*i,visited);
            }
        }
    }
    bool isConnected(){
        bool visited[V];
        int i;
        for(i=0;i<V;i++){
            if(adj[i].size()!=0){
                break;
            }
        }
        if(i==V){
            return true;
        }

        DFSUtil(i,visited);

        for(i=0;i<V;i++){
            if(visited[i]==false && adj[i].size() > 0){
                return false;
            }
        }
        return true;
    }
    
    int isEulerian(){
        if (isConnected()==false){
            return 0;
        }
        int oddvertices=0;
         for (int i = 1; i < V; i++)
        {
            if (adj[i].size() & 1)
            {
                oddvertices++;
            }
        }

        if(oddvertices >2){
            return 0;
        }

        return (oddvertices)? 1 : 2;
    }

   
};

 void test(Graph &g){
        int res=g.isEulerian();
        if(res==0){
            cout<<"Graph is not eulerian"<<endl;
        }else if(res==1){
            cout<<"Graph is a euler path"<<endl;
        }else{
            cout<<"Graph has a euler cycle"<<endl;
        }
    }


int main(){
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    test(g1);

    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 0);
    test(g2);
 
    Graph g3(5);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1);
    g3.addEdge(0, 3);
    g3.addEdge(3, 4);
    g3.addEdge(1, 3);
    test(g3);
 
    // Let us create a graph with 3 vertices
    // connected in the form of cycle
    Graph g4(3);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);
    g4.addEdge(2, 0);
    test(g4);
 
    // Let us create a graph with all vertices
    // with zero degree
    Graph g5(3);
    test(g5);
 
}