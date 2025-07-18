#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "SETTINGS.h"
#include "event/EVENT.h"
#include "listener/LISTENER.h"
#include "listener/orderbook/ORDERBOOK.h"

class Dispatcher {
private:
    unordered_map<string, vector<Listener*>> listeners;

public:
    void registerListener(const string& eventType, Listener* listener) {
        listeners[eventType].push_back(listener);
    }

    void dispatch(Event& event) {
        string type = event.getType();
        if (listeners.count(type)) {
            for (Listener *l : listeners[type]) {
                l->onEvent(event);
            }
        }
    }
};


#endif