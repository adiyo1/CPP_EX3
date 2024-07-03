// 318725520
// adi.yohanann@gmail.com

#include "catan.hpp"
#include "player.hpp"
#include <iostream>
#include "enums.hpp"
#include <algorithm>
catan::catan(player &p1, player &p2, player &p3)
{
    players_.push_back(&p1);
    players_.push_back(&p2);
    players_.push_back(&p3);

    currentPlayer_ = &p1;
    gameBoard_ = new board();
    initializeDevelopmentDeck();
}
void catan::initializeDevelopmentDeck()
{
    developmentDeck_.clear();
    developmentDeck_.insert(developmentDeck_.end(), 2, DevelopmentCard::Monopol);
    developmentDeck_.insert(developmentDeck_.end(), 2, DevelopmentCard::YearOfPlenty);
    developmentDeck_.insert(developmentDeck_.end(), 2, DevelopmentCard::BuildingRoads);
    developmentDeck_.insert(developmentDeck_.end(), 14, DevelopmentCard::Knight);
    developmentDeck_.insert(developmentDeck_.end(), 5, DevelopmentCard::VictoryPoint);

    std::shuffle(developmentDeck_.begin(), developmentDeck_.end(), randomEngine_);
}
std::vector<DevelopmentCard> &catan::getDevelopmentDeck()
{
    return developmentDeck_;
}

catan::~catan()
{
    delete gameBoard_;
}

board &catan::getBoard()
{
    return *gameBoard_;
}
player *catan::getCurrentPlayer()
{
    return currentPlayer_;
}
void catan::setCurrentPlayer(player *currentPlayer)
{
    currentPlayer_ = currentPlayer;
}

void catan::ChooseStartingPlayer(player &p)
{
    player *startingPlayer = &p;
    startingPlayer->setIsMyTurn(true);
    std::cout << "Starting player: " << startingPlayer->getName() << std::endl;
}
int catan::rollDiceAndDistributeResources(player &currentPlayer)
{
    if (currentPlayer.getIsMyTurn(*this) == false)
    {
        throw std::invalid_argument("It is not your turn");
    }

    int roll = currentPlayer.rollDice();

    std::cout << currentPlayer.getName() << " rolled a " << roll << std::endl;

    for (int i = 0; i < 54; i++)
    {
        const vertex vert = getBoard().getVertex(i);
        if (vert.getVertexOwner() != nullptr && vert.getVertexOwner() != 0)
        {
            for (size_t j = 0; j < vert.getCirclesNumbers().size(); j++)
            {
                if (vert.getCirclesNumbers()[j] == roll)
                {
                    for (size_t k = 0; k < getBoard().getHexagons().size(); k++)
                    {
                        if (getBoard().getHexagons()[k].getHexagonCircleNumber() == roll)
                        {
                            if (gameBoard_->getVertex(i).getAvaliable() == 1)
                            {
                                vert.getVertexOwner()->addResource(getBoard().getHexagons()[k].getResourceType(), 1);
                            }
                            if (gameBoard_->getVertex(i).getAvaliable() == 2)
                            {
                                vert.getVertexOwner()->addResource(getBoard().getHexagons()[k].getResourceType(), 2);
                            }
                        }
                    }
                }
            }
        }
    }
    

    if (roll == 7)
    {
        for (player *player : players_)
        {
            int sum = 0;
            sum = +player->getPlayerResources()[resourceTypes::clay];
            sum += player->getPlayerResources()[resourceTypes::wood];
            sum += player->getPlayerResources()[resourceTypes::sheep];
            sum += player->getPlayerResources()[resourceTypes::wheat];
            sum += player->getPlayerResources()[resourceTypes::stone];
            if (sum > 7)
            {
                player->getPlayerResources()[resourceTypes::clay] = player->getPlayerResources()[resourceTypes::clay] / 2;
                player->getPlayerResources()[resourceTypes::wood] = player->getPlayerResources()[resourceTypes::wood] / 2;
                player->getPlayerResources()[resourceTypes::sheep] = player->getPlayerResources()[resourceTypes::sheep] / 2;
                player->getPlayerResources()[resourceTypes::wheat] = player->getPlayerResources()[resourceTypes::wheat] / 2;
                player->getPlayerResources()[resourceTypes::stone] = player->getPlayerResources()[resourceTypes::stone] / 2;
            }
        }
    }
    return roll;
}
void catan::TestDiceRoll(int num)
{
    std::cout << "Rolling a " << num << std::endl;
    for (size_t i = 0; i < 54; i++)
    {
        vertex *currentVertex = &getBoard().getVertex(i);
        if (currentVertex->getVertexOwner() != nullptr && currentVertex->getVertexOwner() != 0)
        {
            for (size_t j = 0; j < currentVertex->getCirclesNumbers().size(); j++)
            {
                if (num == currentVertex->getCirclesNumbers()[j])
                {
                    for (size_t k = 0; k < getBoard().getHexagons().size(); k++)
                    {
                        if (getBoard().getHexagons()[k].getHexagonCircleNumber() == num)
                        {
                            if (getBoard().getHexagons()[k].containsVertex(currentVertex))
                            {
                                if (currentVertex->getAvaliable() == 1)
                                {
                                    currentVertex->getVertexOwner()->addResource(getBoard().getHexagons()[k].getResourceType(), 1);
                                }
                                else if (currentVertex->getAvaliable() == 2)
                                {
                                    currentVertex->getVertexOwner()->addResource(getBoard().getHexagons()[k].getResourceType(), 2);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    

    if (num == 7)
    {
        for (player *player : players_)
        {
            int sum = 0;
            sum += player->getPlayerResources()[resourceTypes::clay];
            sum += player->getPlayerResources()[resourceTypes::wood];
            sum += player->getPlayerResources()[resourceTypes::sheep];
            sum += player->getPlayerResources()[resourceTypes::wheat];
            sum += player->getPlayerResources()[resourceTypes::stone];
            if (sum > 7)
            {
                player->setResources(player->getPlayerResources()[resourceTypes::wood] / 2, player->getPlayerResources()[resourceTypes::clay] / 2, player->getPlayerResources()[resourceTypes::sheep] / 2, player->getPlayerResources()[resourceTypes::wheat] / 2, player->getPlayerResources()[resourceTypes::stone] / 2);
            }
        }
    }
}
