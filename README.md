# traveling-salesman
-------------
Traveling Salesman Problem using A* Algorithm

Submitted by :-
  Name : Ravindra Singh Sisodiya
  Roll no. : 1801138
-------------
Here I have represented all the cities as nodes of a Graph.
--------

Initial State: Agent in the start city and has not visited any other city

Goal State: Agent has visited all the cities and reached the start city again

Successor Function: Generates all cities that have not yet visited

Edge-cost: distance between the cities represented by the nodes, used this cost to calculate g(n).

h(n): distance to the nearest unvisited city from the current city + estimated distance to travel 
      all the unvisited cities (MST heuristic used here) + nearest distance from an unvisited city to the start city. 
      This is an admissible heuristic function.
------------

Compile using the command : g++ tsp.cpp -o tsp
Run using command : ./tsp

------------

Test Case:
Size of the graph : 4

Populating the graph with the data as:
        { 0, 10, 15, 20 }, 
        { 10, 0, 35, 25 }, 
        { 15, 35, 0, 30 }, 
        { 20, 25, 30, 0 }

----------

Output of the above program will be : 1 -> 2 -> 4 -> 3 -> 1

-----------

