#ifndef ORDER_H
#define ORDER_H

#include "SETTINGS.h"

enum class OrderSide { BUY, SELL };
enum class OrderType { MARKET, LIMIT };

// Orders
class Order {
private:
    int id;
    OrderSide side;
    OrderType type;
    double price;
    int quantity;
    long timestamp;

public:
    Order(int id, OrderSide side, OrderType type, double price, int quantity, long timestamp);

    // utility functions
    void printOrder() const;

    // accessors
    int       getID()        const { return id; };
    OrderSide getSide()      const { return side; }; 
    OrderType getType()      const { return type; }; 
    double    getPrice()     const { return price; }; 
    int       getQuantity()  const { return quantity; }; 
    long      getTimestamp() const { return timestamp; }; 


};

// Order Factory
Order createRandomOrder(int timestep);

#endif