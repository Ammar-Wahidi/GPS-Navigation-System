#ifndef Bit_Utilies
#define Bit_Utilies

// Set specific bits in a register using a bitmask (val)
#define SET(reg,val)          (reg |= (val))

// Set a single bit (bit) in a register (reg)
#define SET_BIT(reg,bit)      (reg |= (1 << (bit)))

// Get the value (0 or 1) of a specific bit from a register
#define GET_BIT(reg,bit)      (((reg) >> (bit)) & 1)

// Get only the least significant 8 bits of a register
#define GET_REG(reg)          ((reg) & 0xff)

// Clear specific bits in a register using a bitmask (val)
#define CLR(reg,val)          (reg &= (val))

// Clear (reset to 0) a single bit in a register
#define CLR_BIT(reg,bit)      (reg &= ~(1 << (bit)))

// Check if specific bits (from reg2) are set in reg1
#define CHECK_REG(reg1,reg2)  ((reg1) & (reg2))

#endif
