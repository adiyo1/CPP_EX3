// 318725520
// adi.yohanann@gmail.com

#include <iostream>
#include <stdexcept>
#include <vector>
#include "player.hpp"
#include "board.hpp"
#include "vertex.hpp"
#include "board.hpp"
#include "catan.hpp"
#include "hexagon.hpp"
using namespace std;
// using namespace ariel;

int main()
{
    player p1("Amit");  
    player p2("Yossi");
    player p3("Dana");
    catan catanGame(p1, p2, p3);
    cout << "Player 1 Name: " << p1.getName() << endl;
    cout << "Player 2 Name: " << p2.getName() << endl;
    cout << "Player 3 Name: " << p3.getName() << endl;
    catanGame.ChooseStartingPlayer(p1);   
    board& gameBoard = catanGame.getBoard(); 


    p1.placeSettlement(gameBoard, 19); 
    p1.placeRoad(gameBoard, 26); 
    p1.placeRoad(gameBoard, 27); 
    p1.placeSettlement(gameBoard, 23);    
    p1.endTurn(catanGame);

    p2.placeSettlement(gameBoard, 29); 
    p2.placeSettlement(gameBoard, 40); 
    p2.placeRoad(gameBoard, 34); 
    p2.placeRoad(gameBoard, 56); 
    p2.endTurn(catanGame);

    p3.placeSettlement(gameBoard, 43); 
    p3.placeSettlement(gameBoard, 34); 
    p3.placeRoad(gameBoard, 58); 
    p3.placeRoad(gameBoard, 46); 
    p3.endTurn(catanGame);

    p1.printResources();
    catanGame.TestDiceRoll(6);
    p1.printResources();
    p1.placeRoad(gameBoard, 20); 
    p1.placeSettlement(gameBoard, 11); 
    p1.printResources();
    p1.endTurn(catanGame);

    p2.printResources();
    p1.printResources();
    p3.printResources();
    catanGame.TestDiceRoll(9);
    p2.printResources();
    p2.placeRoad(gameBoard, 63);
    p2.printResources();
    p2.endTurn(catanGame);

    catanGame.TestDiceRoll(3);
    p3.replaceResource(resourceTypes::stone, resourceTypes::wood, p2);
    p3.printResources();
    p2.printResources();
    p3.buyDevelopmentCardTest(DevelopmentCard::BuildingRoads);
    p3.useDevelopmentCardRoadBuilding(gameBoard, 51, 43, catanGame);
    // p3.placeRoad(gameBoard, 51);
    // p3.placeRoad(gameBoard, 43);
    p3.printResources();
    p3.endTurn(catanGame);

    catanGame.TestDiceRoll(4);
    p1.replaceResource(resourceTypes::wheat, resourceTypes::sheep, p3);
    p1.endTurn(catanGame);

    catanGame.TestDiceRoll(5);
    p2.replaceResource(resourceTypes::sheep, resourceTypes::wood, p3);
    p2.placeSettlement(gameBoard, 49);
    p2.endTurn(catanGame);

    catanGame.TestDiceRoll(11);
    // p3.replaceResource(resourceTypes::wheat, resourceTypes::stone, p2);
    p3.endTurn(catanGame);

    catanGame.TestDiceRoll(6);
    p1.placeRoad(gameBoard, 13);
    p1.endTurn(catanGame);

    catanGame.TestDiceRoll(3);
    p2.printResources();
    p2.endTurn(catanGame);

    p3.printResources();

    catanGame.TestDiceRoll(4);
    p3.endTurn(catanGame);

    catanGame.TestDiceRoll(12);
    p1.endTurn(catanGame);


    catanGame.TestDiceRoll(2);
    p2.endTurn(catanGame);

    catanGame.TestDiceRoll(10);
    p3.endTurn(catanGame);


    p1.printResources();
    p2.printResources();
    p3.printResources();

    catanGame.TestDiceRoll(3);
    p1.placeRoad(gameBoard,7);
    p1.placeSettlement(gameBoard,2);
    p1.endTurn(catanGame);

    catanGame.TestDiceRoll(6);  
    p2.printResources();
    p2.placeCity(gameBoard,40);
    p2.printResources();
    p2.endTurn(catanGame);

    catanGame.TestDiceRoll(3);
    p3.printResources();
    p1.printResources();
    p2.printResources();
    p3.replaceResource(resourceTypes::clay,resourceTypes::wood,p1);
    p3.printResources();
    p3.placeSettlement(gameBoard,31);
    p3.endTurn(catanGame);

    catanGame.TestDiceRoll(10);
    p1.printResources();
    p1.placeRoad(gameBoard,2);
    p1.placeRoad(gameBoard,3);
    p1.placeSettlement(gameBoard,4);
    p1.endTurn(catanGame);

    p2.printResources();
    catanGame.TestDiceRoll(5);   
    p2.placeRoad(gameBoard,24);
    p2.printResources();
    p3.printResources();
    p1.printResources();
    p2.replaceResource(resourceTypes::sheep,resourceTypes::clay,p3);
    p2.buyDevelopmentCardTest(DevelopmentCard  ::YearOfPlenty);
    p2.useDevelopmentCardYearOfPlenty(resourceTypes::sheep,resourceTypes::wood, catanGame);
    p2.printResources();
    p2.endTurn(catanGame);

    catanGame.TestDiceRoll(5);
    p3.placeRoad(gameBoard,47);
    p3.printResources();
    p2.printResources();
    p1.printResources();
    p3.replaceResource(resourceTypes::clay,resourceTypes::wheat,p2);
    p3.printResources();
    p3.placeSettlement(gameBoard,36);
    p3.endTurn(catanGame);

    p1.printPoints();
    p2.printPoints();
    p3.printPoints();


    catanGame.TestDiceRoll(12);
    p1.printResources();
    p1.buyDevelopmentCardTest(DevelopmentCard::VictoryPoint);
    p1.useDevelopmentCardVictoryPoint(catanGame);
    p1.endTurn(catanGame);

    
    catanGame.TestDiceRoll(9);
    p2.placeSettlement(gameBoard,17);
    p2.printResources();
    p2.endTurn(catanGame);

    catanGame.TestDiceRoll(3);
    p3.printResources();
    p3.replaceResource(resourceTypes::clay,resourceTypes::wood,p2);
    p3.printResources();
    // p3.placeRoad(gameBoard,37);
    p3.buyDevelopmentCardTest(DevelopmentCard::BuildingRoads);
    p3.useDevelopmentCardRoadBuilding(gameBoard,37,31,catanGame);
    p3.endTurn(catanGame);

    catanGame.TestDiceRoll(6);
    p1.printResources();
    p1.placeRoad(gameBoard,8);
    p1.placeRoad(gameBoard,15);
    p1.printResources();
    p1.endTurn(catanGame);

    catanGame.TestDiceRoll(5);
    p2.printResources();
    p2.placeCity(gameBoard,29);
    p2.placeRoad(gameBoard,18);
    p2.printResources();
    p2.endTurn(catanGame);

    catanGame.TestDiceRoll(8);
    p3.printResources();
    p3.placeSettlement(gameBoard,25);
    p3.printResources();
    p3.buyDevelopmentCardTest(DevelopmentCard::BuildingRoads);
    p3.useDevelopmentCardRoadBuilding(gameBoard,53,61,catanGame);
    // p3.endTurn(catanGame);
    
    p1.printResources();
    catanGame.TestDiceRoll(6);
    p1.endTurn(catanGame);

    p2.printResources();



    




    // catanGame.rollDiceAndDistributeResources(p2);





    // // gameBoard.make();
    // player p1("Amit");
    
    // player p2("Yossi");
    // player p3("Dana");
    // catan catanGame(p1, p2, p3);
    // cout << "Player 1 Name: " << p1.getName() << endl;
    // cout << "Player 2 Name: " << p2.getName() << endl;
    // cout << "Player 3 Name: " << p3.getName() << endl;
    // // Initialize development decks for each player
    
    // // // Starting of the game. Every player places two settlements and two roads.
    // catanGame.ChooseStartingPlayer(p1);   // should print the name of the starting player, assume it is Amit.
    // board& gameBoard = catanGame.getBoard(); // get the board of the game.
    // p1.placeSettlement(gameBoard, 19); // p1 places a settlement in the Forest.
    // // vertexes_[19].getVertexOwner();
    // p1.placeRoad(gameBoard, 26); // p1 places a road in the Forest.
    // p1.placeRoad(gameBoard, 27); // p1 places a road in the Forest.
    // p1.placeSettlement(gameBoard, 23); // p1 places a settlement in the Hills.
    // // p1.placeRoad(gameBoard, 28); // p1 places a road in the Forest.

    // // p1.printResources();
    // // p1.buyDevelopmentCard(catanGame); // p1 buys a development card.
    // // p1.buyDevelopmentCard(catanGame); // p1 buys a development card.
    // // p1.endTurn(); // p1 ends his turn.
    // p1.endTurn(catanGame);

    // p2.placeSettlement(gameBoard, 29); // p2 places a settlement in the Mountains.
    // p2.placeSettlement(gameBoard, 40); // p2 places a settlement in the Pasture Land.
    // p2.placeRoad(gameBoard, 34); // p2 places a road in the Pasture Land.
    // p2.placeRoad(gameBoard, 56); // p2 places a road in the Pasture Land.
    // p2.endTurn(catanGame);

    // p3.placeSettlement(gameBoard, 43); // p3 places a settlement in the Pasture Land.
    // p3.placeSettlement(gameBoard, 34); // p3 places a settlement in the Pasture Land.
    // p3.placeRoad(gameBoard, 58); // p3 places a road in the Pasture Land.
    // p3.placeRoad(gameBoard, 46); // p3 places a road in the Pasture Land.
    // p3.endTurn(catanGame);

    // p1.printResources();
    // catanGame.TestDiceRoll(6);
    // // catanGame.rollDiceAndDistributeResources(p1);
    // p1.printResources();
    // p1.placeRoad(gameBoard, 20); // p1 places a road in the Forest.
    // p1.placeSettlement(gameBoard, 11); // p1 places a settlement in the Hills.
    // p1.printResources();
    // p1.endTurn(catanGame);


    // catanGame.rollDiceAndDistributeResources(p2);
    // vector<string> places = {"Forest", "Hills"};
    // vector<int> placesNum = {5, 6};
    // p1.placeSettlement( gameBoard, 16);
    // p2.placeSettlement(gameBoard, 16); // p2 places a settlement in the Mountains.
    // p3.placeSettlement(gameBoard, 23); // p3 places a settlement in the Agricultural Land.
    // p3.placeRoad(gameBoard, 29); // p3 places a road in the Agricultural Land.
    // p2.placeSettlement(gameBoard, 40); // p2 places a settlement in the Pasture Land.
    // p3.placeSettlement(gameBoard, 44); // p3 places a settlement in the Pasture Land.
    // // p1.useDevelopmentCardMonopol(resourceTypes::sheep); // p1 uses a knight card.
    // // p1.useDevelopmentCardRoadBuilding(gameBoard, 28, 29); // p1 uses a road building card.
    // // p1.useDevelopmentCardYearOfPlenty(resourceTypes::wood, resourceTypes::stone); // p1 uses a year of plenty card.
    // p1.placeRoad(places, placesNum, board);
    // vector<string> places = {"Agricultural Land", "Desert"};
    // vector<int> placesNum = {3, 4};
    // p1.placeSettelemnt(places, placesNum, board);
    // p1.placeRoad(places, placesNum, board); // p1 chooses Forest, hills, Agricultural Land, Desert with numbers 5, 6, 3, 4.

    // vector<string> places = {"Mountains", "Pasture Land"};
    // vector<int> placesNum = {4, 9};
    // p2.placeSettelemnt(places, placesNum, board);
    // p2.placeRoad(places, placesNum, board);
    // try
    // {
    //     p3.placeSettelemnt(places, placesNum, board); // p3 tries to place a settlement in the same location as p2.
    // }
    // catch (const std::exception &e)
    // {
    //     cout << e.what() << endl;
    // }
    // vector<string> places = {"Forest", "Pasture Land"};
    // vector<int> placesNum = {5, 9};
    // //   p2.placeSettlement(board,1);
    // p2.placeSettelemnt(places, placesNum, board);
    // p2.placeRoad(places, placesNum, board); // p2 chooses Mountains, Pasture Land, and Forest with numbers 4, 9, 5.

    // vector<string> places = {"Mountains", "Pasture Land"};
    // vector<int> placesNum = {3, 8};
    // p3.placeSettelemnt(places, placesNum, board);
    // p3.placeRoad(places, placesNum, board);
    // vector<string> places = {"Agricultural Land", "Pasture Land"};
    // vector<int> placesNum = {3, 9};
    // p3.placeSettelemnt(places, placesNum, board);
    // p3.placeRoad(places, placesNum, board); // p3 chooses Mountains, Pasture Land, Agricultural Land, Pasture Land with numbers 3, 8, 3, 9.

    // // p1 has wood,bricks, and wheat, p2 has wood, ore, and wool, p3 has ore, wool, wheat.
    // int t=p1.rollDice();  
    // catanGame.rollDiceAndDistributeResources(p1);
    // // cout<<t<<endl;                                  // Lets say it's print 4. Then, p2 gets ore from the mountations.
    // p2.buyDevelopmentCard(catanGame);
    // p2.buyDevelopmentCard(catanGame);
    // p3.buyDevelopmentCard(catanGame);
    // p3.buyDevelopmentCard(catanGame);
    // p1.buyDevelopmentCard(catanGame);
    // p1.buyDevelopmentCard(catanGame);
    // p3.buyDevelopmentCard(catanGame);
    // p3.buyDevelopmentCard(catanGame);
    // p3.buyDevelopmentCard(catanGame);
    // p1.buyDevelopmentCard(catanGame);
    // p3.buyDevelopmentCard(catanGame);
    // p3.buyDevelopmentCard(catanGame);
    // p3.buyDevelopmentCard(catanGame);
    // p2.buyDevelopmentCard(catanGame);
    // p2.buyDevelopmentCard(catanGame);
    // p2.buyDevelopmentCard(catanGame);
    // p2.buyDevelopmentCard(catanGame);
    // p2.buyDevelopmentCard(catanGame);
    // p2.buyDevelopmentCard(catanGame);
    // p2.buyDevelopmentCard(catanGame);
    // p3.buyDevelopmentCard(catanGame);
    // p3.buyDevelopmentCard(catanGame);
    // p2.buyDevelopmentCard(catanGame);
    // p1.buyDevelopmentCard(catanGame);
    // p3.buyDevelopmentCard(catanGame);
    // p3.buyDevelopmentCard(catanGame);
    

    // cout << p1.getDevelopmentCardsSummary() << endl;
    // cout << p2.getDevelopmentCardsSummary() << endl;
    // cout << p3.getDevelopmentCardsSummary() << endl;

    // p1.printPoints();
    // p2.printPoints();
    // p3.printPoints();
    // catanGame.rollDiceAndDistributeResources(p2);
    // catanGame.rollDiceAndDistributeResources(p3);
    // catanGame.rollDiceAndDistributeResources(p1);
    // catanGame.rollDiceAndDistributeResources(p2);
    // catanGame.rollDiceAndDistributeResources(p3);
    // catanGame.rollDiceAndDistributeResources(p1);
    // catanGame.rollDiceAndDistributeResources(p2);
    // catanGame.rollDiceAndDistributeResources(p3);
    // catanGame.rollDiceAndDistributeResources(p1);
    
    // p1.printResources();
    // p2.printResources();
    // p3.printResources();
    
    // p1.replaceResource(resourceTypes::wood, resourceTypes::stone, p3);
    // p1.replaceResource(resourceTypes::wheat, resourceTypes::stone, p3);
//    p1.replaceResource(resourceTypes::wood, resourceTypes::stone, p2);
//     p2.replaceResource(resourceTypes::wood, resourceTypes::stone, p3);
//    p3.replaceResource(resourceTypes::wood, resourceTypes::stone, p2);

//    p1.printResources();
//     p2.printResources();
//     p3.printResources();
    
    // p1.getDevelopmentCards();
    // p1.placeRoad({"Forest", "Hills"}, {5, 6}, board); // p1 continues to build a road.
    // p1.endTurn();                                     // p1 ends his turn.

    // p2.rollDice(); // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
    // p2.endTurn();  // p2 ends his turn.

    // p3.rollDice(); // Lets say it's print 3. Then, p3 gets wheat from the Agricultural Land and Ore from the Mountains, p1 gets wheat from the Agricultural Land.
    // p3.endTurn();  // p3 ends his turn.

    // try
    // {
    //     p2.rollDice(); // p2 tries to roll the dice again, but it's not his turn.
    // }
    // catch (const std::exception &e)
    // {
    //     cout << e.what() << endl;
    // }

    // p1.rollDice();                       // Lets say it's print 6. Then, p1 gets bricks from the hills.
    // p1.trade(p2, "wood", "brick", 1, 1); // p1 trades 1 wood for 1 brick with p2.
    // p1.endTurn();                        // p1 ends his turn.

    // p2.rollDice();           // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
    // p2.buyDevelopmentCard(); // p2 buys a development card. Lets say it is a bonus points card.
    // p2.endTurn();            // p2 ends his turn.

    // p1.printPoints(); // p1 has 2 points because it has two settelments.
    // p2.printPoints(); // p2 has 3 points because it has two settelments and a bonus points card.
    // p3.printPoints(); // p3 has 2 points because it has two settelments.

    // catan.printWinner(); // Should print None because no player reached 10 points.
    return 0;
}