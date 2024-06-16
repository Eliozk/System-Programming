// Player.hpp

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Settlement.hpp"
#include "Board.hpp"
#include "Settlement.hpp"
#include "Tile.hpp"
#include "Card.hpp"
#include <string>
#include <vector>
#include <map>

// #include "Resource.hpp"
// #include "DevelopmentCard.hpp"



namespace ariel
{

  using namespace std; 
  
  class Settlement; // Forward declaration
  class City;       // Forward declaration
  class Road;       // Forward declaration

  class Player
  {
  private:
    string name;                      ///< The name of the player.
    int points;                       ///< The player's points.
    vector<Settlement> settlements;   ///< The player's settlements.
    int numberOfRoads;                ///< The number of roads the player has built.
    vector<City> cities;              ///< The player's cities.
    vector<Road> roads;               ///< The player's roads.
    vector<Tile> tiles;               ///< The player's tiles.
    vector<DevelopmentCard> devCards; ///< The player's cards.
    map<string, int> resources;       ///< The player's resources.

  public:
    Player(const string &playerName);
    int getPoints() const;
    // Methods to place settlements and roads
    void placeSettlement(const vector<string> &places, const vector<int> &placesNum, Board &board);
    /**
     * @brief Places a road on the board.
     * @param places The list of places for the road.
     * @param placesNum The list of place numbers.
     * @param board The game board.
     */
    void placeRoad(const vector<string> &places, const vector<int> &placesNum, Board &board);
    /**
     * @brief Upgrades a settlement to a city.
     * @param settlement The settlement to upgrade.
     */
    void upgradeSettlementToCity(const Settlement &settlement);
    // Method to roll dice
    int rollDice() const;

    /**
     * @brief Distributes resources based on the dice roll result.
     * @param rollResult The result of the dice roll.
     * @param tiles The list of game tiles.
     */
    void resourcesFromRolledDice(int rollResult, const vector<Tile> &tiles);
    // Method to trade resources
    // void trade(Player& otherPlayer, const std::string& giveResource, const std::string& getResource, int giveAmount, int getAmount);

    // Method to buy development cards
    // void buyDevelopmentCard();

    // Method to print points
    void printPoints() const;

    /**
     * @brief Adds resources to the player's inventory.
     * @param resource The type of resource to add.
     * @param quantity The quantity of the resource to add.
     */
    void addResource(string &resource, int quantity);
    /**
     * @brief Removes resources from the player's inventory.
     * @param resource The type of resource to remove.
     * @param quantity The quantity of the resource to remove.
     */
    void removeResource(string resource, int quantity);

    // Method to end turn
    // void endTurn();

    // Get player's name
    string getName() const;
  };
}
#endif