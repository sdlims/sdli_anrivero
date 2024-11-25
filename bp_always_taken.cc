#include "bp_always_taken.h"
#include "bp/bp.param.h"
#include "cbp_to_scarab.h"

ALWAYS_TAKEN::ALWAYS_TAKEN(void){};

void ALWAYS_TAKEN::init(){};

bool ALWAYS_TAKEN::GetPrediction(UINT64 PC, int* bp_confidence) {return 1;};

//Does nothing for now
void ALWAYS_TAKEN::UpdatePredictor(uint64_t PC, OpType OPTYPE, bool resolveDir, bool predDir, uint64_t branchTarget) {};

//Does nothing for now
void ALWAYS_TAKEN::TrackOtherInst(uint64_t PC, OpType opType, bool taken, uint64_t branchTarget) {};

bool ALWAYS_TAKEN::IsFull(void){return 0;};