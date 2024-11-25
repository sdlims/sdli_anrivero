#ifndef _BP_TWO_LEVEL_H_
#define _BP_TWO_LEVEL_H_

#include "cbp_to_scarab.h"

class TWOLEVEL {
 public:
  TWOLEVEL(void);
  void init();
  bool GetPrediction (uint16_t PC, int* bp_confidence);
  void UpdatePredictor(uint64_t PC, OpType OPTYPE, bool resolveDir,
                       bool predDir, uint64_t branchTarget);
  void TrackOtherInst(uint64_t PC, OpType opType, bool taken,
                      uint64_t branchTarget);
  bool IsFull(void);
};

#endif