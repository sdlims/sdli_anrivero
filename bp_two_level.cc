#include "bp_two_level.h"
#include "bp/bp.param.h"
#include "cbp_to_scarab.h"

#include <bitset>
#include <vector>

class FSM_Prediction{
    public:
        FSM_Prediction() : fsm_q(0) {} // Init to 0

    // Transition logic based on the current state and input bit
    void make_pred(bool bit_i) {
        
        if (fsm_q == 0) {
            fsm_q = bit_i ? 1 : 0;
        } else if (fsm_q == 1) {
            fsm_q = bit_i ? 3 : 0;
        } else if (fsm_q == 3) {
            fsm_q = bit_i ? 3 : 2;
        } else if (fsm_q == 2) {
            fsm_q = bit_i ? 3 : 2;
        }

        if (fsm_q == 0 | fsm_q == 1){
            bp_pred = 0;
        } else if (fsm_q == 2 | fsm_q == 3){
            bp_pred = 1;
        }
    }

    bool bp_next_pred() const {
        return bp_pred;
    }

    private:
        int fsm_q;
        bool bp_pred;
};


TWOLEVEL::TWOLEVEL(void){};

void TWOLEVEL::init(){};

bool TWOLEVEL::GetPrediction(uint16_t PC, int* bp_confidence) {
    std::vector<bool> bin_pred(16);

    for (int i = 0; i < 16; ++i) {
        bin_pred[i] = (PC >> (15 - i)) & 1;
    }

    FSM_Prediction fsm;

    for (bool bit : bin_pred){
        fsm.make_pred(bit);
    }

    bool ideal_pred = fsm.bp_next_pred();
    return(ideal_pred);
};

//Does nothing for now
void TWOLEVEL::UpdatePredictor(uint64_t PC, OpType OPTYPE, bool resolveDir, bool predDir, uint64_t branchTarget) {};

//Does nothing for now
void TWOLEVEL::TrackOtherInst(uint64_t PC, OpType opType, bool taken, uint64_t branchTarget) {};

bool TWOLEVEL::IsFull(void){return 0;};