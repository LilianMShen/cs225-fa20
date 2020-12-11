# CS 225 Fall 2020 Final Project
Contributors: Daniel Bargon, Spenser Fong, Justin Kim, Lilian Shen

## Overview
Our project looks at the musae-twitch dataset obtained from http://snap.stanford.edu/data/twitch-social-networks.html. The undirected, unweighted dataset is given through a CSV file, and the data format is **Vertex,Vertex**, representing edges formed from 2 digit nodes. Our goal was to simulate the logic behind the follow/subscription recommendation system in the Twitch network.

All testing and running of our code can be done within the individual test case files, located in the tests folder. The musae-twitch dataset, as well as other data used for testing, can be found in */tests/data*.
- - - -
## Fileio
### Files: fileio.h/cpp
- - - -
## Breadth First Search (BFS)
### Files: BFS.h/cpp
- - - -
## Dijkstra's Implementation
### Files: dijkstras.h/cpp
For each dataset/graph, create a new Dijkstras object with the constructor and input data (vector of vectors of strings) using the fileio namespace. The test cases are examples for running the code. Use the all-in-one function ***runDijkstras*** if you only want the path (vector of Edges). The ***Dijkstras_Helper*** function (and therefore ***runDijkstras***) will print the shortest path for you. If you want to see the current vertices (including adjacent vertices) being visited, uncomment the print statements in ***dijkstras.cpp***. More information can be found in the ***testDijkstras.cpp***.

IMPORTANT: The dataset we used is unweighted. If you want to test for weighted graphs, input the data like the dataset but with the weight after it: **Vertex,Vertex,Weight**, with each component being a string of digits if data is hardcoded in the test file. Examples are given in the test file.
- - - -
## Landmark Path Implementation
### Files: landmark.h/cpp
