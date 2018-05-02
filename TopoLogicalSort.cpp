 ///Topological Sort
/*  God Help Me
    Indrojit Mondal
    Department of Computer Science and Engineering,
    University of Barisal
    Using Corman
    */
#include<bits/stdc++.h>
using namespace std;
int Vertex,Edge;

vector<int>G[100];
int Time=0;
int Color[100];
int Par[100];
 /* 0==>White
   1==>Gray
   2==>Black
   */

int D[100]; // D->Discovery Time
int F[100]; // F->Finishing Time
void DFS_VISIT(int U);

void DFS(int x)
{
    DFS_VISIT(x);
    for(int I=1; I<=Vertex; I++)
    {
        if(Color[I]==0)
        {
            DFS_VISIT(I);
        }
    }
}

string StringHome[101];
int StrCount=0;

int Search_Index(string str)
{
    int ck=0;
    for(int I=1; I<=StrCount; I++)
    {
        if(str==StringHome[I])
        {
            ck=1;
            return I;
        }
    }
      if(ck==0){
    StrCount = StrCount +1;
    StringHome[StrCount] = str;
    return StrCount;
      }
}

void DFS_VISIT(int U)
{
    Color[U]=1;
    Time=Time+1;
    D[U]=Time;


     for(int V=0; V<G[U].size(); V++)
     {
         if(Color[G[U][V]]==0)
         {
             Par[G[U][V]]=U;
             DFS_VISIT(G[U][V]);
         }
     }
    Color[U]=2;
    Time = Time +1;
    F[U]=Time;

}
void PathPrint(int s,int v)
{
      if(s==v)
      {
          cout<<StringHome[s]<<" ";
          //return;
      }
      else if(Par[v]==0) cout<<"No Path From Source To Destination"<<endl;
      else {PathPrint(s,Par[v]);
      cout<<StringHome[v]<<" ";
      }
}

bool sortbyOutDegere(const pair< int , pair< int ,int> > &a, const pair< int, pair< int, int> > &b)
{
    return a.second.second > b.second.second;
}

int main()
{
    int i,j;
    //cout<<"Enter VerTex and Edge: ";
    cin>>Vertex>>Edge;
    int Node1,Node2;
    string S1, S2;
    for(i=1; i<=Edge; i++)
    {
        cin>>S1>>S2;
        Node1 = Search_Index(S1);
        Node2 = Search_Index(S2);
        //cin>>Node1>>Node2;
        G[Node1].push_back(Node2);


    }

    for(int I=1; I<=Vertex; I++)
    {
        Color[I]=0;
        Par[I]=0;
    }
    for(int U=1; U<=Vertex; U++)
    {


        cout<<U<<" : ";
       // X=Vect[U-1].first;
        for(int V=0; V<G[U].size(); V++)
        {
            cout<<G[U][V]<<" ";
          //  Y=G[X][V];
           // G[X].push_back(Y);
        }
        cout<<endl;
    }
    string src;
    cout<<"Enter Source :  ";
    cin>>src;

    DFS(Search_Index(src));


    for( int V=1; V<=Vertex; V++)
    {
        cout<<StringHome[V]<<" 's Discovery Time = "<<D[V]<<" & Finishing Time = "<<F[V]<<endl;

    }

    string Dsn;
     cout<<"Enter Destination : ";
     cin>>Dsn;

     //cout<<Search_Index(Dsn)<<endl;

    PathPrint(Search_Index(src),Search_Index(Dsn));

    cout<<endl;
    ///Star TopoLogical Sorting

    vector< pair< int, pair<int, int> > >Vect;

    for( int V=1; V<=Vertex; V++)
    {
        Vect.push_back(make_pair(V,make_pair(D[V],F[V])));
        //cout<<StringHome[V]<<" 's Discovery Time = "<<D[V]<<" & Finishing Time = "<<F[V]<<endl;

    }
    sort(Vect.begin(), Vect.end(), sortbyOutDegere);
    cout<<endl;
    for(int V=1 ; V<=Vertex; V++)
    {
        cout<<StringHome[Vect[V-1].first] <<" 's "<<Vect[V-1].second.first<<" / "<<Vect[V-1].second.second<<endl;

    }
    cout<<endl;

    ///Now Connect Node...
    int X,Y;

    for(int U=1; U<=Vertex; U++)
    {



        X=Vect[U-1].first;
        cout<<StringHome[X]<<" : ";
        for(int V=0; V<G[X].size(); V++)
        {

            Y=G[X][V];
            cout<<StringHome[Y]<<" ";

        }
        cout<<endl;
    }






    return 0;
}






