#include "listener/orderbook/ORDERBOOK.h"
#include "event/EVENT.h"

// method from Listener class
void Orderbook::onEvent(const Event& event) {
    if (event.getType() == "OrderSubmitted") {
        // cast the event to type
        const OrderSubmittedEvent& e = static_cast<const OrderSubmittedEvent&>(event);
        // add the order to the orderbook
        addOrder(e.getOrder());
    }
}

// high level add order
// routes the order to the proper symbol book
void Orderbook::addOrder(const Order& order) {
    OrderSide side = order.getSide();
    string symbol = order.getSymbol();

    // create the symbol orderbook
    SymbolOrderbook& book = symbolBook[symbol];

    // delegate order to the symbol level orderbook
    book.addOrder(order);
}

// low level add order
void SymbolOrderbook::addOrder(const Order& order) {

    // TODO: MATCH LOGIC
    // if (order.getType() == OrderType::MARKET) {
    //     // match immediately against best opposite side
    //     // matchMarketOrder();
    // }
    // else {
    //     if (order.getSide() == OrderSide::BUY) 
    //         buyOrders[order.getPrice()].push_back(order);
    //     else if (order.getSide() == OrderSide::SELL) 
    //         sellOrders[order.getPrice()].push_back(order);
    // }
}
