#include "ORDER/ORDER.h"


Order::Order(int id, OrderSide side, OrderType type, double price, int quantity, long timestamp)
    : id(id), side(side), type(type), price(price), quantity(quantity), timestamp(timestamp) {}


void Order::printOrder() const {
    cout << "Printing out order" << endl;
    cout << "ID: " << getID() << endl;

    cout << "Side: " << (side == OrderSide::BUY ? "BUY" : "SELL") << endl;
    cout << "Type: " << (type == OrderType::LIMIT ? "LIMIT" : "MARKET") << endl;

    cout << "Price: $" << getPrice() << endl;
    cout << "Quantity: " << getQuantity() << endl;
    cout << "Timestamp: " << getTimestamp() << endl;
}


Order createRandomOrder(int timestep) {

    // generate the random order values
    int id = 0;
    OrderSide side = (rand() % 2 == 0) ? OrderSide::BUY : OrderSide::SELL;
    OrderType type = (rand() % 2 == 0) ? OrderType::MARKET : OrderType::LIMIT;

    double price = 100.0 + (rand() % 1000) / 10.0; // between $100 and $200
    int quantity = (rand() % 100) + 1; // 1 to 100 shares
    long timestamp = static_cast<long>(timestep);

    // return using constructor
    return Order(id, side, type, price, quantity, timestamp);
}