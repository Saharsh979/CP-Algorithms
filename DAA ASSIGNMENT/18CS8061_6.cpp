/*
We can construct a graph by treating each person as a node and letting an edge between two nodes indicate that the two users are friends. If we want to find the path between two people, we start with one person and do a simple breadth-first search.
so friend relationships are an undirected graph, and you represent individuals -> friends as an adjacency list. to find mutual friends of a source, you would search for all nodes that are a distance <= 2 away and not in the source's adjacency list with BFS/DFS and rank them based on the size of the intersection between the adjacency lists. this would be e + v for a single node and v(e + v) for all of them. there is probably a faster way to do this though.

1-> 3,2;
2->1,4,5;
3->1,5;
4->2;
5->2,3;
Suggestions for 1 -> (4,5);
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> ar[1000001]; // adjacency list
bool vis[1000001];       // to maintain visited nodes;
int dist[1000001];       // to count distance of each node from x

void BFS(int node)
{
    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    dist[node] = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int child : ar[curr]) // iterating over the adjacency list of curr node;
        {
            if (vis[child] == 0) // if node is not visited;
            {
                q.push(child);
                dist[child] = dist[curr] + 1; // updating distance
                vis[child] = 1;               // marking it visited;
            }
        }
    }
}
int main()
{
    int no_of_friends;
    int no_of_connections;
    cin >> no_of_friends >> no_of_connections;
    int distance[no_of_friends];
    memset(distance, 0, sizeof(distance));

    for (int i = 0; i < no_of_connections; i++)
    {
        int a, b;
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    // finding mututal friends for 1;
    int friend_no = 1;
    while (friend_no <= no_of_friends)
    {
        vector<int> mutualfriends;
        BFS(friend_no); // calling BFS for 1
        cout << "Mutual Friend Reccomendation for"
             << " " << friend_no << "="
             << " ";
        for (int i = 1; i <= no_of_friends; i++)
        {
            if (dist[i] >= 2)
            {
                mutualfriends.push_back(i);
            }
        }
        for (auto it : mutualfriends)
        {
            cout << it << " ";
        }
        cout << endl;
        friend_no++;
    }
}