#ifndef _BP_NEVER_TAKEN_H_
#define _BP_NEVER_TAKEN_H_

#include "cbp_to_scarab.h"

class NEVER_TAKEN {
 public:
  NEVER_TAKEN(void);
  void init();
  bool GetPrediction (UINT64 PC, int* bp_confidence);
  void UpdatePredictor(uint64_t PC, OpType OPTYPE, bool resolveDir,
                       bool predDir, uint64_t branchTarget);
  void TrackOtherInst(uint64_t PC, OpType opType, bool taken,
                      uint64_t branchTarget);
  bool IsFull(void);
};

#endif