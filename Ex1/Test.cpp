// ID - 208762765
// GMAIL - kolanielioz@gmail.com

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 6},
        {1, 1, 0, 1, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 8, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph4 = {
        {0, 0, -1, 0, 0},
        {0, 0, 4, 0, 0},
        {1, 0, 0, 0, 8},
        {0, 3, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph5 = {
        {0, 1},
        {-1, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");

    vector<vector<int>> graph2 = {
        {0, 1, 4},
        {1, 0, 2},
        {0, 1, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph3 = {
        {0, 1, 1, 0, 6},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, -1},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0->2->3->4");

    vector<vector<int>> graph4 = {// Here there is -6 instead of 6
                                  {0, 1, 1, 0, -6},
                                  {1, 0, 1, 0, 0},
                                  {1, 1, 0, 1, 0},
                                  {0, 0, 1, 0, -1},
                                  {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0->4");

    vector<vector<int>> graph5 = {// Here there is a negative cycle
                                  {0, 1, 1, 0, -6},
                                  {1, 0, 1, 0, 0},
                                  {1, -4, 0, 1, 0},
                                  {0, 0, 1, 0, -1},
                                  {0, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}

TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph3 = {
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph4 = {
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 4, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph5 = {
        {0, 0, 0, 0, 3},
        {5, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, -1, 0, 0, 0},
        {0, 0, -3, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}

TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0,2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph4 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 1, 0},
        {0, 0, 0, 4, 0},
        {0, 0, 4, 0, 0},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}
TEST_CASE("Test negativeCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 0, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle");

    vector<vector<int>> graph2 = {
        {0, 0, 0},
        {1, 0, -1},
        {0, 1, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle");

    vector<vector<int>> graph3 = {
        {0, 0, 0},
        {1, 0, -1},
        {0, -1, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle");

    vector<vector<int>> graph4 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {-6, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Negative cycle found: 0->2->0");

    vector<vector<int>> graph5 = {
        {0, -1, 0, 0, 0},
        {0, 0, -1, 0, 0},
        {0, 0, 0, -1, 0},
        {0, 0, 1, 0, -1},
        {-1, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Negative cycle found: 1->0->4->3->2->1");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));

    vector<vector<int>> graph2 = {
        {0, 1, 2, 0, 3},
        {1, 0, 3, 0, 2},
        {2, 3, 0, 4, 1},
        {0, 0, 4, 0, 0}};
    CHECK_THROWS(g.loadGraph(graph2));
}

// And more tests to check diffarent types of matricies :

TEST_CASE("Test empty graph")
{
    ariel::Graph g;
    vector<vector<int>> emptyGraph = {};
    g.loadGraph(emptyGraph);

    // An empty graph should not contain any cycles
    CHECK(ariel::Algorithms::isContainsCycle(g) == 0);

    // An empty graph is trivially bipartite
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={}, B={}");

    // There are no negative cycles in an empty graph
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle");

    // There is connectivity in an empty graph
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("Test graph with self-loops")
{
    ariel::Graph g;
    vector<vector<int>> graphWithSelfLoops = {
        {1, 1, 0},
        {0, -1, 2},
        {0, 2, 1}};
    g.loadGraph(graphWithSelfLoops);

    // Self loops are cycles
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    // Self loops make the same vertex inside the same group color
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    // Self loops can introduce negative cycles if weights are negative
    CHECK(ariel::Algorithms::negativeCycle(g) == "Negative cycle found: 1->1");

    // There is no way from vertex 2 to vertex 0
    CHECK(ariel::Algorithms::isConnected(g) == false);
}
// Tests i added:
TEST_CASE("Test graph with multiple components")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0,2}, B={1,3}");
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle");

    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 1, 0, 1},
        {0, 0, 1, 1, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle");
}

TEST_CASE("Test graph with disconnected nodes")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0,2,3}, B={1,4}");
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle");
}

TEST_CASE("Test fully connected graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1, 1, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle");
}
//*************************************************************************************************************************************8
TEST_CASE("Graph Operations")
{
    SUBCASE("Graph Addition and Subtraction")
    {
        vector<vector<int>> graph1 = {
            {0, 1, -1},
            {1, 0, 1},
            {-1, 1, 0}};
        vector<vector<int>> graph2 =
            {{0, 1, -2},
             {1, 0, 1},
             {-2, 1, 0}};
        vector<vector<int>> graph3 =
            {{0, 2, -3},
             {2, 0, 2},
             {-3, 2, 0}};
        vector<vector<int>> graph4 =
            {{0, 0, -1},
             {0, 0, 0},
             {-1, 0, 0}};
        Graph g1, g2, g3, g4;
        g1.loadGraph(graph1);
        g2.loadGraph(graph2);
        g3.loadGraph(graph3);
        g4.loadGraph(graph4);
        Graph sum = g1 + g2;
        Graph diff = g2 - g1;

        CHECK(sum == g3);
        CHECK(diff == g4);
        CHECK_FALSE(diff == g3);
    }

    SUBCASE("Graph Multiplication and >=")
    {
        vector<vector<int>> graph1 = {
            {0, 1, -1},
            {1, 0, 1},
            {-1, 1, 0}};
        vector<vector<int>> graph2 = {
            {0, 1, -2},
            {1, 0, 1},
            {-2, 1, 0}};
             vector<vector<int>> graph3 =
             {{3, -1, 1}, 
             {-2, 2, -2}, 
             {1, -1, 3}};
             vector<vector<int>> graph4 =
             {{-3, 1, -1}, 
             {2, -2, 2}, 
             {-1, 1, -3}};
        Graph g1, g2,res,g4;
        g1.loadGraph(graph1);
        g2.loadGraph(graph2);
        res.loadGraph(graph3);
        g4.loadGraph(graph4);
         -g4;//unary minus
          Graph product = g1 * g2;
        CHECK(g4 == res);
        CHECK(product >= res);
    }

    SUBCASE("Unary Operators")
    {
        vector<vector<int>> graph1 = {
            {0, 1, -1},
            {1, 0, 1},
            {-1, 1, 0}};
        Graph g;
        g.loadGraph(graph1);

        +g;
        -g;

        CHECK(g.getAdjacencyMatrix() == vector<vector<int>>{{0, -1, 1}, {-1, 0, -1}, {1, -1, 0}});
    }

    SUBCASE("Increment and Decrement Operators")
    {
        vector<vector<int>> graph = {
            {0, 2, -1},
            {1, 0, 1},
            {-1, 1, 0}};
        vector<vector<int>> graph1 = {
            {0, 2, -1},
            {1, 0, 1},
            {-1, 1, 0}};
             vector<vector<int>> graph2= {
            {0, 2, -2},
            {2, 0, 2},
            {-2, 2, 0}};
        Graph g,g1,g2;
        g.loadGraph(graph);
        g1.loadGraph(graph1);
        g2.loadGraph(graph2);
        ++g1;
        --g1;
        ++g2;
        --g2;

        CHECK(!(g == g1));//check == operator and --, and ++
        CHECK(g2.getAdjacencyMatrix() == graph2);
    }

    SUBCASE("Graph Comparison")
    {
        vector<vector<int>> graph1 = {
            {0, 1, -1},
            {1, 0, 1},
            {-1, 1, 0}};
        vector<vector<int>> graph2 = {
            {0, 1, -2},
            {1, 0, 1},
            {-2, 1, 0}};
            vector<vector<int>> subGraph1 = {
            {0, 1, -1},
            {0, 0, 1},
            {-1, 1, 0}};
        Graph g1, g2,subg1;
        g1.loadGraph(graph1);
        g2.loadGraph(graph2);
        subg1.loadGraph(subGraph1);

        CHECK(g1 == g1);
        CHECK(g1 != g2);
        CHECK_FALSE(subg1 > g1);
        CHECK(g1 > subg1);
        CHECK(g1 <= g2);
        CHECK_FALSE(subg1 >= g1);
        
    }
}
