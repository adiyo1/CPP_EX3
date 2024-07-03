// 318725520
// adi.yohanann@gmail.com

#include "doctest.h"
#include "catan.hpp"
#include "player.hpp"

using namespace std;
TEST_CASE("Test building a settlement")
{
    player p1("Amit");
    player p2("Yossi");
    player p3("Dana");
    catan catanGame(p1, p2, p3);
    board &gameBoard = catanGame.getBoard();
    p1.setIsMyTurn(true);
    p1.placeSettlement(gameBoard, 19);
    CHECK(gameBoard.getVertexes()[19].getVertexOwner() == &p1);
}
TEST_CASE("Tess building a settlement on a taken vertex")
{
    player p1("Amit");
    player p2("Yossi");
    player p3("Dana");
    catan catanGame(p1, p2, p3);
    board &gameBoard = catanGame.getBoard();
    p1.setIsMyTurn(true);
    p1.placeSettlement(gameBoard, 19);
    p1.endTurn(catanGame);
    CHECK_THROWS(p2.placeSettlement(gameBoard, 19));
}
TEST_CASE("Test building a settlement on a vertex that is too close to another settlement")
{
    player p1("Amit");
    player p2("Yossi");
    player p3("Dana");
    catan catanGame(p1, p2, p3);
    board &gameBoard = catanGame.getBoard();
    p1.setIsMyTurn(true);
    p1.placeSettlement(gameBoard, 19);
    p1.endTurn(catanGame);
    p2.setIsMyTurn(true);
    CHECK_THROWS(p2.placeSettlement(gameBoard, 20));
}

TEST_CASE("Test building a road")
{
    player p1("Amit");
    player p2("Yossi");
    player p3("Dana");
    catan catanGame(p1, p2, p3);
    board &gameBoard = catanGame.getBoard();
    p1.setIsMyTurn(true);
    p1.placeSettlement(gameBoard, 19);
    p1.placeRoad(gameBoard, 19);
    CHECK(gameBoard.getEdges()[19].getEdgeOwner() == &p1);
}

TEST_CASE("Test building a road on a taken edge")
{
    player p1("Amit");
    player p2("Yossi");
    player p3("Dana");
    catan catanGame(p1, p2, p3);
    board &gameBoard = catanGame.getBoard();
    p1.setIsMyTurn(true);
    p1.placeSettlement(gameBoard, 19);
    p1.placeRoad(gameBoard, 19);
    p1.endTurn(catanGame);

    p2.placeSettlement(gameBoard, 10);
    p2.placeRoad(gameBoard, 12);
    CHECK_THROWS(p2.placeRoad(gameBoard, 19));
}

TEST_CASE("Test building a road that not connected to one of the player's settlements")
{
    player p1("Amit");
    player p2("Yossi");
    player p3("Dana");
    catan catanGame(p1, p2, p3);
    board &gameBoard = catanGame.getBoard();
    p1.setIsMyTurn(true);
    p1.placeSettlement(gameBoard, 19);
    CHECK_THROWS(p1.placeRoad(gameBoard, 20));
}

TEST_CASE("Test building a road when player doesn't have enough resources")
{
    player p1("Amit");
    player p2("Yossi");
    player p3("Dana");
    catan catanGame(p1, p2, p3);

    board &gameBoard = catanGame.getBoard();
    p1.setIsMyTurn(true);
    p1.placeSettlement(gameBoard, 19);
    p1.placeRoad(gameBoard, 25);
    p1.placeRoad(gameBoard, 24);
    p1.setResources(0, 0, 1, 1, 1);
    CHECK_THROWS(p1.placeRoad(gameBoard, 19));
}

TEST_CASE("Test building a settlement when player doesn't have enough resources")
{
    player p1("Amit");
    player p2("Yossi");
    player p3("Dana");
    catan catanGame(p1, p2, p3);
    board &gameBoard = catanGame.getBoard();
    p1.setIsMyTurn(true);
    p1.placeSettlement(gameBoard, 1);
    p1.placeSettlement(gameBoard, 43);
    p1.setResources(0, 0, 1, 1, 1);
    CHECK_THROWS(p1.placeSettlement(gameBoard, 19));
}

TEST_CASE("Test building a settlement when player doesn't have enough resources")
{
    player p1("Amit");
    player p2("Yossi");
    player p3("Dana");
    catan catanGame(p1, p2, p3);
    board &gameBoard = catanGame.getBoard();
    p1.setIsMyTurn(true);
    p1.placeSettlement(gameBoard, 1);
    p1.placeSettlement(gameBoard, 43);
    p1.setResources(0, 0, 1, 1, 1);
    CHECK_THROWS(p1.placeSettlement(gameBoard, 19));
}

TEST_CASE("Test buying a development card when player doesn't have enough resources")
{
    player p1("Amit");
    player p2("Yossi");
    player p3("Dana");
    catan catanGame(p1, p2, p3);
    board &gameBoard = catanGame.getBoard();
    p1.setIsMyTurn(true);
    p1.setResources(1, 1, 1, 0, 0);
    CHECK_THROWS(p1.buyDevelopmentCard(catanGame));
}

TEST_CASE("Test buying a development card when there are no more development cards in the deck")
{
    player p1("Amit");
    player p2("Yossi");
    player p3("Dana");
    catan catanGame(p1, p2, p3);
    p1.setResources(0, 0, 26, 26, 26);
    p1.setIsMyTurn(true);

    for (int i = 0; i < 25; i++)
    {
        p1.buyDevelopmentCard(catanGame);
    }
    CHECK_THROWS(p1.buyDevelopmentCard(catanGame));
}

TEST_CASE("Test rolling the dice not on the player's turn")
{
    player p1("Amit");
    player p2("Yossi");
    player p3("Dana");
    catan catanGame(p1, p2, p3);

    p1.setIsMyTurn(false);
    CHECK_THROWS(catanGame.rollDiceAndDistributeResources(p1));
}

TEST_CASE("Test update resources after rolling the dice")
{
    player p1("Amit");
    player p2("Yossi");
    player p3("Dana");
    catan catanGame(p1, p2, p3);

    board &gameBoard = catanGame.getBoard();
    
    p1.setIsMyTurn(true);

    p1.placeSettlement(gameBoard, 19);
    p1.placeSettlement(gameBoard, 43);
    p1.placeRoad(gameBoard, 19);
    p1.setResources(0, 0, 0, 0, 0);
    int roll=catanGame.rollDiceAndDistributeResources(p1);
    bool ans=true;
    std:: cout<<"roll: "<<roll<<std::endl;
    if (roll==4||roll==6||roll==12)
    {
      if( p1.getResourceAmount(resourceTypes::wheat) ==0)
        {

            std::cout<<"wheat: "<<p1.getResourceAmount(resourceTypes::wheat)<<std::endl;
            ans=false;
        }
    }
    if(roll==11)
    {
      if( p1.getResourceAmount(resourceTypes::sheep) == 0||p1.getResourceAmount(resourceTypes::stone) == 0)
        {
            std::cout<<"sheep: "<<p1.getResourceAmount(resourceTypes::sheep)<<std::endl;
            std::cout<<"stone: "<<p1.getResourceAmount(resourceTypes::stone)<<std::endl;
            ans=false;
        }
    }
    
    CHECK(ans);    
}


TEST_CASE("Test update resources after rolling the dice")
{
    player p1("Amit");
    player p2("Yossi");
    player p3("Dana");
    catan catanGame(p1, p2, p3);
    board &gameBoard = catanGame.getBoard();

    p1.setResources(14, 0, 0, 0, 0);
    catanGame.TestDiceRoll(7);
    CHECK(p1.getResourceAmount(resourceTypes::wood) == 7);


}

TEST_CASE("HAVING THE LARGEST ARMY IN THE GANE")
{
    player p1("Amit");
    player p2("Yossi");
    player p3("Dana");
    catan catanGame(p1, p2, p3);
    board &gameBoard = catanGame.getBoard();

    p1.setNumOfKnights(3);
    p2.setNumOfKnights(4);
    p3.setNumOfKnights(5);
    bool ans=false;
    p1.updateLargestArmy();
    p2.updateLargestArmy();
    p3.updateLargestArmy();
    p1.printPoints();
    p2.printPoints();   
    p3.printPoints();
    if(p1.getVictoryPoints()==0&&p2.getVictoryPoints()==0&&p3.getVictoryPoints()==2)
    {
        ans=true;
    }
    CHECK(ans);
}

TEST_CASE("HAVING THE LARGEST ARMY IN THE GANE2")
{
    player p1("Amit");
    player p2("Yossi");
    player p3("Dana");
    catan catanGame(p1, p2, p3);
    board &gameBoard = catanGame.getBoard();

    p1.setNumOfKnights(3);
    p2.setNumOfKnights(5);
    p3.setNumOfKnights(4);
    bool ans=false;
    p1.updateLargestArmy();
    p2.updateLargestArmy();
    p3.updateLargestArmy();
    p1.printPoints();
    p2.printPoints();   
    p3.printPoints();
    if(p1.getVictoryPoints()==0&&p2.getVictoryPoints()==2&&p3.getVictoryPoints()==0)
    {
        ans=true;
    }
    CHECK(ans);
}

TEST_CASE("GAME IS OVER")
{
    player p1("Amit");
    player p2("Yossi");
    player p3("Dana");
    catan catanGame(p1, p2, p3);
    board &gameBoard = catanGame.getBoard();

    p1.setVictoryPoints(10);
    p2.setVictoryPoints(8);
    p3.setVictoryPoints(9);
    bool ans=false;
    p1.GAME_IS_OVER();
    p2.GAME_IS_OVER();
    p3.GAME_IS_OVER();
    p1.printPoints();
    p2.printPoints();   
    p3.printPoints();
    if(p1.getVictoryPoints()==10&&p2.getVictoryPoints()==8&&p3.getVictoryPoints()==9)
    {
        ans=true;
    }
    CHECK(ans);
}

TEST_CASE("after roll dice 7")
{
    player p1("Amit");
    player p2("Yossi");
    player p3("Dana");
    catan catanGame(p1, p2, p3);

    board &gameBoard = catanGame.getBoard();
    p1.setResources(14, 0, 0, 0, 0);
    catanGame.TestDiceRoll(7);
    CHECK(p1.getResourceAmount(resourceTypes::wood) == 7);
}

