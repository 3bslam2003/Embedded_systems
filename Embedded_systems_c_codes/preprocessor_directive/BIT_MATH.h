/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<       BIT_MATH.h         >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * NAME  : Ahmed Mohamed Abdelsalam
 *cousre : Embedded Systems
 *TOPIC  : Preprocessor Directive/Macros/Function like Macros
 * 
 *
 *
 *
 */
 
 
 #ifndef BIT_MATH_H_
 #define BIT_MATH_H_
 
 
 
 
 #define SET_BIT(Reg,Bit)              Reg|=(1<<Bit)
 #define TOG_BIT(Reg,Bit)              Reg^=(1<<Bit)
 #define CLR_BIT(Reg,Bit)              Reg&=(~(1<<Bit))
 #define GET_BIT(Reg,Bit)              (Reg&(1<<Bit))>>Bit
 #define IS_BIT_SET(Reg,Bit)           (Reg&(1<<Bit))>>Bit
 #define IS_BIT_CLR(Reg,Bit)           !(Reg&(1<<Bit))>>Bit
 #define ROR(Reg,Num,NUM_OF_BITs)      ((Reg>>Num)|(Reg<<(NUM_OF_BITs - Num)))           
 #define ROL(Reg,Num,NUM_OF_BITs)      ((Reg<<Num)|(Reg>>(NUM_OF_BITs - Num)))  
 
 
 
 
 #endif
