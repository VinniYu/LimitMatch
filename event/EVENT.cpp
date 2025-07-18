#include "event/EVENT.h"
#include "order/ORDER.h"

OrderSubmittedEvent::OrderSubmittedEvent(const Order& o) : order(o) {}

string OrderSubmittedEvent::getType()        const { return "OrderSubmitted"; }
const Order& OrderSubmittedEvent::getOrder() const { return order; }
