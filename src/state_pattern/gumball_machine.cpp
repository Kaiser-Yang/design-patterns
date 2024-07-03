#include "gumball_machine.h"

#include "state/has_quarter_state.h"
#include "state/no_quarter_state.h"
#include "state/sold_out_state.h"
#include "state/sold_state.h"
#include "state/winner_state.h"

// we use enable_shared_from_this,
// this function must be called after construction
void GumballMachine::init() {
    soldOutState    = std::make_shared<SoldOutState>(shared_from_this());
    noQuarterState  = std::make_shared<NoQuarterState>(shared_from_this());
    hasQuarterState = std::make_shared<HasQuarterState>(shared_from_this());
    soldState       = std::make_shared<SoldState>(shared_from_this());
    winnerState     = std::make_shared<WinnerState>(shared_from_this());
    if (numberGumballs > 0) {
        state = noQuarterState;
    } else {
        state = soldOutState;
    }
}
