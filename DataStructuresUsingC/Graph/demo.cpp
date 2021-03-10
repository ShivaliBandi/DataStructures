#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createAdjacencyMatrix(int V, int E, vector<vector<int>> input)
{
    vector<int> vobj(V , 0);
    vector<vector<int>> output(V , vobj);
    
    //cout << "hii\n";
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
            output[i].push_back(0);
        //cout << endl;
    }

     for (int i = 0; i < V; i++) 
    {   
        // Find X and Y of Edges 
        int x = input[i][0]; 
        int y = input[i][1]; 
  
        // Update value to 1 
        output[x][y] = 1; 
        output[y][x] = 1; 
    } 

    return output;
}

int main()
{
    int V = 0, E = 0, no = 0;
    vector<vector<int>> input, output;
    cout << "Enter no of vertices and no of edges : " << endl;
    cin >> V >> E;

    cout << "Vertices which forms edges are as follows : \n";
    for(int i = 0; i < E; i++)
    {
        vector<int> vobj;
        cout << "Enter starting vertex : " << endl;
        cin >> no;
        label1 : if(no < V && no >= 1)
        {
          vobj.push_back(no);
        }
        else
        {
          cout << "Enter valid Edge between 0 and "<< V <<endl;
          cin >> no;
          goto label;  
        }
        
        cout << "Enter ending vertex : " << endl;
        cin >> no;
        label : if(no < V && no >= 1)
        {
          vobj.push_back(no);
        }
        else
        {
          cout << "Enter valid Edge between 0 and "<< V << ": "<<endl;
          cin >> no;
          goto label;
        }
        input.push_back(vobj);
    }

  
    cout << "Edges are :\n";
    for(int i = 0; i < input.size(); i++)
    {
        for(int j = 0; j < 2; j++)
            cout << input[i][j] << " ";
        cout << endl;
    }

    output = createAdjacencyMatrix(V , E, input);

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
            cout << output[i][j] << " ";
            //output[i][j] = 0;
        cout << endl;
    }
    return 0;
}