#include <bitset>
#include <vector>
#include <iostream>
#include <cstdint>

class FSM_Prediction{
    public:
        FSM_Prediction() : fsm_q(0) {} // Init to 0

        void make_pred(bool bit_i) {
            // std::cout << "Current Bit: " << bit_i << std::endl;
            // std::cout << "Current State: " << fsm_q << std::endl << std::endl;
            if (fsm_q == 0) {
                fsm_q = bit_i ? 1 : 0;
            } else if (fsm_q == 1) {
                fsm_q = bit_i ? 3 : 0;
            } else if (fsm_q == 3) {
                fsm_q = bit_i ? 3 : 2;
            } else if (fsm_q == 2) {
                fsm_q = bit_i ? 3 : 0;
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

        std::vector<bool> getAllBits(uint16_t number) {
            std::vector<bool> bits(16);
            for (int i = 0; i < 16; ++i) {
                bits[i] = (number >> i) & 1; // Extract each bit
            }
            return bits;
        }

    private:
        int fsm_q;
        bool bp_pred;
};

int main(){
    uint16_t testA = 0b0011001110001111;
    uint16_t testB = 0b1101001101001011;
    uint16_t testC = 0b0110110110001100;

    FSM_Prediction fsm;

    std::vector<bool> bits = fsm.getAllBits(testA);

    for (bool bit : bits){
        fsm.make_pred(bit);
    }

    bool pred_bit = fsm.bp_next_pred();
    if (pred_bit != 0){
        std::cout << "Test A Failed, Incorrect Prediction " << std::endl;
    } else {std::cout << "Test A Passed, Correct Prediction " << std::endl;}

    // TEST B

    bits = fsm.getAllBits(testB);

    for (bool bit : bits){
        fsm.make_pred(bit);
    }

    pred_bit = fsm.bp_next_pred();
    if (pred_bit != 1){std::cout << "Test B Failed, Incorrect Prediction " << std::endl;} 
    else {std::cout << "Test B Passed, Correct Prediction " << std::endl;}  

    // TEST C

    bits = fsm.getAllBits(testC);

    for (bool bit : bits){
        fsm.make_pred(bit);
    }

    pred_bit = fsm.bp_next_pred();
    if (pred_bit != 1){std::cout << "Test C Failed, Incorrect Prediction " << std::endl;} 
    else {std::cout << "Test C Passed, Correct Prediction " << std::endl;}  


    return 0;
}