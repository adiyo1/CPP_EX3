// 318725520
// adi.yohanann@gmail.com

#pragma once
#include "edge.hpp"
#include <vector>
#include <map>
#include <string>
#include "vertex.hpp"
#include <random>
#include "catan.hpp"

class edge;
class board;




class player {
private:
    std::string name_;
    std::map<resourceTypes, int> playerResources_;
    int victoryPoints_;
    static std::vector<player*> players_;
    std::map<DevelopmentCard, int> developmentCards_;
    std::default_random_engine randomEngine_;
    std::vector<vertex*> settlements_;
    std::vector<edge*> roads_;
    int NumOfRoads_;
    int NumOfSettlements_;
    int NumOfCities_;
    int NumOfKnights_;
    static player* playerWithLargestArmy_;
    bool isMyTurn_;
    

public:
    player();
    player(const std::string& name, std::map<resourceTypes, int> playerResources = {}, int victoryPoints = 0, std::vector<vertex*> settlements = {}, std::vector<edge*> roads = {}, int NumOfRoads = 0, int NumOfSettlements = 0,  int NumOfCities = 0, int NumOfKnights = 0,bool isMyTurn = false);
    std::vector<vertex*> getSettlements();
    std::string getName() const;
    std::map<resourceTypes, int> getPlayerResources() const;
    
    int getVictoryPoints() const;
    int rollDice();
    void placeSettlement(board& gameBoard, int vertexId);
    static player* getPlayerByName(const std::string& name);
    bool checkFirstSettlements(board& gameBoard, int vertexId);
    bool checkNeighboringVertices( board& gameBoard, int vertexId);
    std::map<DevelopmentCard, int> getDevelopmentCards() const;
    std::string getDevelopmentCardsSummary() const;
    bool checkNeighboringVertices(const board& gameBoard, int vertexId);
    void placeRoad(board& gameBoard, int edgeId);
    int getNumOfRoads();
    bool canPlaceRoad(board& gameBoard, int edgeId) const;
    void placeCity(board& gameBoard, int vertexId);
    void useDevelopmentCardMonopol(resourceTypes resource, catan& game);
    bool hasDevelopmentCard(DevelopmentCard cardType) const;
    void useDevelopmentCardRoadBuilding(board& gameBoard, int edgeId1, int edgeId2,catan& game);
    void useDevelopmentCardYearOfPlenty( resourceTypes resource1, resourceTypes resource2,catan& game);
    void useDevelopmentCardVictoryPoint(catan& game);
    void buyDevelopmentCardTest(DevelopmentCard card);
    void updateLargestArmy();
    void printPoints();
    std::string resourceToString(resourceTypes resource);
    void replaceResource(resourceTypes resourceThePlayerWants, resourceTypes resourceThePlayerGives, player& playerThePlayerReplaceWith);
    void printResources();
    DevelopmentCard buyDevelopmentCard(catan& game);
    DevelopmentCard drawDevelopmentCard(catan& game);
    bool getIsMyTurn(catan& game);
    void setIsMyTurn(bool isMyTurn);
    void endTurn(catan& game);
    void setResources(int wood, int clay, int sheep, int wheat, int stone);
    void GAME_IS_OVER();
    int getPlayerIndex();
    int getResourceAmount(resourceTypes resource) const;
    void addResource(resourceTypes resource, int amount);
    void ForTestAddDevelopmentCard(DevelopmentCard card);
    int getNumOfKnights();
    void setNumOfKnights(int num);
    void setVictoryPoints(int num);
};
