// 318725520
// adi.yohanann@gmail.com

#pragma once
#include "hexagon.hpp"


class board
{
private:
    std::vector<hexagon> hexagons_;
    std::vector<edge> edges_;
    std::vector<vertex> vertexes_;
    std::vector<vertex*> vertexes2_;
public:
void make ();
    board();
    // Method to get a vertex by its ID
    vertex& getVertex(int vertexId);
    vertex* getVertex2(int vertexId);
    std::vector<hexagon> getHexagons() const;
    std::vector<edge> getEdges() const;
    std::vector<vertex> getVertexes() const;
    std::vector<vertex*> getVertexes2() ;
    const std::vector<int>& getNeighboringVertices(int id) const;
    const vertex& getVertex(int id) const;
    edge& getEdge(int edgeId);
    
};