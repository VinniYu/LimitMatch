#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "SETTINGS.h"
#include "order/ORDER.h"
#include "listener/LISTENER.h"

/*
The buy and sell orders for a symbol.
*/
class SymbolOrderbook {
private:
    map<double, deque<Order>, greater<double>> buyOrders;
    map<double, deque<Order>> sellOrders;

public:
    void addOrder(const Order& order);

};

/*
Central orderbook engine
*/
class Orderbook : public Listener {
private:
    unordered_map<string, SymbolOrderbook> symbolBook;

public:
    // main listener method
    void onEvent(const Event& event) override;

    // orderbook methods
    void addOrder(const Order& order);


    // print methods
    void printSymbolOrders(string symbol);
    void printSymbolBook();

};


#endif