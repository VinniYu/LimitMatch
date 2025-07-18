#ifndef EVENT_H
#define EVENT_H

#include "SETTINGS.h"
#include "order/ORDER.h"

class Event {
public:
    virtual string getType() const = 0;
    virtual ~Event() = default;
};

class OrderSubmittedEvent : public Event {
private: 
    Order order;
public:
    OrderSubmittedEvent(const Order& o);

    string getType() const override;
    const Order& getOrder() const;
};

#endif