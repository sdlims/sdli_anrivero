#include "bp_never_taken.h"
#include "bp/bp.param.h"
#include "cbp_to_scarab.h"

NEVER_TAKEN::NEVER_TAKEN(void){};

void NEVER_TAKEN::init(){};

bool NEVER_TAKEN::GetPrediction(UINT64 PC, int* bp_confidence) {return 0;};

//Does nothing for now
void NEVER_TAKEN::UpdatePredictor(uint64_t PC, OpType OPTYPE, bool resolveDir, bool predDir, uint64_t branchTarget) {};

//Does nothing for now
void NEVER_TAKEN::TrackOtherInst(uint64_t PC, OpType opType, bool taken, uint64_t branchTarget) {};

bool NEVER_TAKEN::IsFull(void){return 0;};