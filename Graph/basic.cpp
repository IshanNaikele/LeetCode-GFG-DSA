#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,m;
    cout<<"Enter the number of Nodes(1-Indexed) :";
    cin>>n;
    cout<<"Enter the number of Edges :";
    cin>>m;
    // Adjcancey Matrix
    cout<<"Provides the info edges"<<endl;
    vector<vector<int>>adj(n+1,vector<int>(m+1,0));
    for( int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,m;
    cout<<"Enter the number of Nodes(1-Indexed) :";
    cin>>n;
    cout<<"Enter the number of Edges :";
    cin>>m;
    // Adjcancey List
    cout<<"Provides the info edges"<<endl;
    vector<vector<int>>adj(n+1);
    for( int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int num:adj[i])
        cout<<num<<" ";
        
        cout<<endl;
    }
    return 0;
}


#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,m;
    cout<<"Enter the number of Nodes(1-Indexed) :";
    cin>>n;
    cout<<"Enter the number of Edges :";
    cin>>m;
    // Adjcancey List of Weighted Graph 
    cout<<"Provides the info edges with weights"<<endl;
    vector<vector<pair<int,int>>>adj(n+1);
    for( int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        pair<int,int>p1={u,w};
        pair<int,int>p2={v,w};
        adj[u].push_back(p2);
        adj[v].push_back(p1);
    }
    
    for(int i=1;i<=n;i++)
    {
        for(auto &it:adj[i])
        cout<<it.first<<" "<<it.second<<endl;
        
        cout<<endl;
    }
    return 0;
}
