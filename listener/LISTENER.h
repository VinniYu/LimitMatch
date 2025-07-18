#ifndef LISTENER_H
#define LISTENER_H

#include "SETTINGS.h"
#include "event/EVENT.h"

class Listener {
public:
    virtual void onEvent(const Event& event) = 0;
    virtual ~Listener() = default;
};

#endif