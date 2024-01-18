//
// Created by Giada on 25/11/2023.
//

#ifndef LISTASPESA_OBSERVER_H
#define LISTASPESA_OBSERVER_H


class Observer {
public:
    virtual ~Observer()= default;
    virtual void update() = 0;
};


#endif //LISTASPESA_OBSERVER_H
