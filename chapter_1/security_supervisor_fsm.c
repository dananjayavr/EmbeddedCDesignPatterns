//
// Created by dananjaya on 6/30/25.
//

/*
*   The most common FSM (Finite-State Machine) implementation is to generate simple if-then or switch-case statements.
*   For example, a common and easy implementation scheme is to:

    - Add a state variable (e.g., activeState).
    - For each event to the “class,” add an event receptor function and pass in any data that it needs as parameters
    - Create an event dispatcher function, called by each event receptor; this processes the incoming event

    The structure of the event dispatcher can be as simple as below:
*/

#include <stdbool.h>

typedef enum {
    state1,
    state2,
} State;

State activeState;

typedef enum {
    event1,
    event2,
} Event;

Event eventID;

bool guard1(void);

bool guard2(void);

bool guard3(void);

bool guard4(void);

void action1(void);

void action2(void);

void action3(void);

void action4(void);

void action5(void);

int main(int argc, char *argv[]) {
    switch (activeState) {
        /* for each state */

        case state1:
            /* for each event */
            switch (eventID) {
                event1:
                    /* check each guard */
                    if (guard1()) {
                        action1();
                    } else if (guard2()) {
                        action2();
                    }
                    break;

                event2:
                    if (guard3()) {
                        action3();
                    } else if (guard4()) {
                        action5();
                    };
                    break;
                default: ;
            }

            break;

        case state2:

            // etc
            break;
    }
}
