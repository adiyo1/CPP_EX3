// 318725520
// adi.yohanann@gmail.com

#include "vertex.hpp"
#include "player.hpp"

// Default constructor
vertex::vertex() : id_(0), resources_(), owner_(nullptr) {}

// Parameterized constructor
vertex::vertex(int id, std::vector<resourceTypes> resources, player *owner, std::vector<vertex*> neighboringVertices,std::vector<int>circlesNumbers)
    : id_(id), resources_(resources), owner_(owner),neighboringVertices_(neighboringVertices),circlesNumbers_(circlesNumbers) {}

int vertex::getVertexId() const
{
    return id_;
}

player* vertex::getVertexOwner() const
{
    return owner_;
}



const std::vector<resourceTypes>& vertex::getVertexResources() const {
    return resources_;
}


void vertex::setVertexOwner(player *owner)
{
    if (owner_ != nullptr) {
        std::cout << "Vertex is already owned by another player." << std::endl;
        return;
    }
    this->avaliable_=1;
    owner_ = owner;
}
void vertex:: setAvaliable(int avaliable){//0 is avalible, 1 is there is a satlement, 2 is there is a city
    avaliable_ = avaliable;
}
int vertex::getAvaliable(){
    return avaliable_;
}
std::vector<vertex*> vertex::getNeighboringVertices() const
{
    return neighboringVertices_;
}
std::vector<int> vertex::getCirclesNumbers() const{
    return circlesNumbers_;
}


