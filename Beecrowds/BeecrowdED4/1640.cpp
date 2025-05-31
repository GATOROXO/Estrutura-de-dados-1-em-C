#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <limits> // for numeric_limits
#include <set>
#include <utility> // for pair
#include <algorithm>
#include <iterator>
using namespace std;

typedef long long int vertex_t;
typedef double weight_t;
const weight_t max_weight = numeric_limits<double>::infinity();

struct neighbor {
  vertex_t target;
  weight_t weight;
  weight_t current;
  bool hotel;
  neighbor(vertex_t arg_target, weight_t arg_weight,weight_t arg_current,bool arg_hotel):target(arg_target), weight(arg_weight),current(arg_current),hotel(arg_hotel){ }
};

typedef vector<vector<neighbor> > adjacency_list_t;

void DijkstraComputePaths(vertex_t source,adjacency_list_t &adjacency_list, vector<weight_t> &min_distance, vector<vertex_t> &previous,vector<vertex_t> &hoteis,vector<vertex_t> &weights,vector<bool> &tHotel){
  int n = adjacency_list.size();
  min_distance.clear();
  min_distance.resize(n, max_weight);
  min_distance[source] = 0;
  previous.clear();
  previous.resize(n, -1);
  weights.clear();
  weights.resize(n,0);
  tHotel.clear();
  tHotel.resize(n,false);
  set<pair<weight_t, vertex_t> > vertex_queue;
  vertex_queue.insert(make_pair(min_distance[source], source));
  while (!vertex_queue.empty()){
    weight_t dist = vertex_queue.begin()->first;
    vertex_t u = vertex_queue.begin()->second;
    vertex_queue.erase(vertex_queue.begin());
    vector<neighbor> &neighbors = adjacency_list[u];
    for (vector<neighbor>::iterator neighbor_iter = neighbors.begin(); neighbor_iter != neighbors.end(); neighbor_iter++){
      vertex_t v = neighbor_iter->target;
      weight_t weight = neighbor_iter->weight;
      weight_t current= neighbor_iter->current;
      weight_t distance_through_u = dist + weight;
      if (distance_through_u < min_distance[v]) {
        bool l=true;
        bool ho=false;//Variavel criada para falar se dormiu no hotel ou nao
        //if(distance_through_u>600){
        if(weight+weights[u]>600){
          //Procurando por um hotel
          if(hoteis.size()==0)
            l=false;
          for(vector<vertex_t>::iterator it=hoteis.begin();it!=hoteis.end();it++){
            if(*it==u){
              l=true;
              ho=true;
              break;
            }
            else{
              l=false;
            }
          }
        }
        if(l){
          if(ho){
            tHotel[v]=true;
            weights[v]=weight;
            //cout<<"O nó u= "<<u<<" e nó v= "<<v<<" precisaram de hotel! Entao o peso é: "<<weights[v]<<endl;
          }
          else{
            tHotel[v]=false;
            weights[v]=distance_through_u;
            //cout<<"O nó u= "<<u<<" e nó v= "<<v<<" NÃO precisaram de hotel! Entao o peso é: "<<weights[v]<<endl;
          }
          vertex_queue.erase(make_pair(min_distance[v], v));
          min_distance[v] = distance_through_u;
          previous[v] = u;
          vertex_queue.insert(make_pair(min_distance[v], v));
        }
      }
    }
  }
}

list<vertex_t> DijkstraGetShortestPathTo( vertex_t vertex, const vector<vertex_t> &previous){
   list<vertex_t> path;
   for (;vertex != -1; vertex = previous[vertex])
     path.push_front(vertex);
   return path;
}

int main(){
  int n=1,m,x,y,w,v;
  while(n!=0){
    vector<vertex_t> hoteis;
    cin>>n;
    adjacency_list_t adjacency_list(n);
    if(n==0)
      break;
    cin>>v;
    for(int i=0;i<v;i++){
      cin>>x;
      hoteis.push_back(x-1);
    }
    cin>>m;
    for(int i=0;i<m;i++){
      cin>>x>>y>>w;
      adjacency_list[x-1].push_back(neighbor(y-1,w,0,false));
    }
    vector<weight_t> min_distance;
    vector<vertex_t> previous;
    vector<vertex_t> weights;
    vector<bool> tHotel;
    DijkstraComputePaths(0, adjacency_list, min_distance, previous,hoteis,weights,tHotel);
    //cout << "Distance from 0 to "<<n-1<<" : " << min_distance[n-1] << endl;
    list<vertex_t> path = DijkstraGetShortestPathTo(n-1, previous);
    //cout<<"Weights: ";
    //copy(min_distance.begin(),min_distance.end(),ostream_iterator<vertex_t>(cout," "));
    //cout<<endl;
    //cout << "Path : ";
    //copy(path.begin(), path.end(), ostream_iterator<vertex_t>(cout, " "));
    //cout<<endl;
    int total=0;
    //for(vector<bool>::iterator it=tHotel.begin();it!=tHotel.end();it++){
    //  cout<<*it<<" ";
    //}
    for(list<vertex_t>::iterator it=path.begin();it!=path.end();it++){
      if(tHotel[*it]==1)
        total++;
    }
    //cout<<endl;
    if(min_distance[n-1]==max_weight){
      cout<<"-1\n";
    }
    else{
      cout<<total<<endl;
    }
  }
  return 0;
}