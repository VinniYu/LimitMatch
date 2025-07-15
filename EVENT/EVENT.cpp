#include "EVENT.h"
#include "ORDER/ORDER.h"

OrderSubmittedEvent::OrderSubmittedEvent(const Order& o) : order(o) {}

string OrderSubmittedEvent::getType() const { return "OrderSubmitted"; }
const Order& OrderSubmittedEvent::getOrder() const { return order; }
