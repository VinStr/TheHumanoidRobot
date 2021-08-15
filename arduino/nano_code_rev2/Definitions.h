//---------------------servo pins
//---------------- 0
#define B_LID_R 15
#define T_LID_R 14
#define BROW_2_R 13
#define BROW_1_R 12
#define CHEEK_LOW_R 11
#define CHEEK_UP_R 10
#define NOSE_R 9

#define NOSE_L 6
#define CHEEK_UP_L 5
#define CHEEK_LOW_L 4
#define BROW_1_L 3
#define BROW_2_L 2
#define T_LID_L 1
#define B_LID_L 0
//---------------- 1
#define LIP_LOW_R 15
#define LIP_UP_R 14
#define FULL_LIP_LOW_R 13
#define FULL_LIP_UP_R 12
#define JAW_PIVOT_R 11
#define JAW_SLIDE_R 10
#define V_EYE_R 9
#define H_EYE_R 8

#define H_EYE_L 7
#define V_EYE_L 6
#define JAW_SLIDE_L 5
#define JAW_PIVOT_L 4
#define FULL_LIP_UP_L 3
#define FULL_LIP_LOW_L 2
#define LIP_UP_L 1
#define LIP_LOW_L 0

//limits for movments
//------------------------------------right
#define H_EYE_R_MIN 180//210 //right
#define H_EYE_R_MAX 360//385 //left

#define V_EYE_R_MIN 180//140 //up
#define V_EYE_R_MAX 370//230 //down

#define T_LID_R_CENT 163//at center
#define T_LID_R_MIN 210//down
#define T_LID_R_MAX 71//up

#define B_LID_R_CENT 120//at center
#define B_LID_R_MIN 71//up
#define B_LID_R_MAX 193//down

#define BROW_1_R_MIN 320//top
#define BROW_1_R_MAX 440//bottom

#define BROW_2_R_MIN 470//top
#define BROW_2_R_MAX 375//bottom


//-----------------------------------left

#define H_EYE_L_MIN 95//160 //right
#define H_EYE_L_MAX 215//340 //left

#define V_EYE_L_MIN 190 //up
#define V_EYE_L_MAX 340 //down

#define T_LID_L_CENT 380//at center
#define T_LID_L_MIN 310//down
#define T_LID_L_MAX 440//up

#define B_LID_L_CENT 405//at center
#define B_LID_L_MIN 440//up
#define B_LID_L_MAX 340//down

#define BROW_1_L_MIN 440//top
#define BROW_1_L_MAX 310//bottom

#define BROW_2_L_MIN 100//top
#define BROW_2_L_MAX 215//bottom

#define LID_OFFSET_TOP 50+55
#define LID_OFFSET_BOTTOM 50+40

//-------------------------------------cheek
#define CHEEK_UP_R_DEF 263
#define CHEEK_LOW_R_DEF 240
#define CHEEK_UP_L_DEF 357
#define CHEEK_LOW_L_DEF 291

#define CHEEK_UP_R_FOR 190
#define CHEEK_LOW_R_FOR 346
#define CHEEK_UP_L_FOR 440
#define CHEEK_LOW_L_FOR 173

#define CHEEK_UP_R_BAK 280
#define CHEEK_LOW_R_BAK 170
#define CHEEK_UP_L_BAK 317
#define CHEEK_LOW_L_BAK 374

#define CHEEK_UP_R_UP 400
#define CHEEK_LOW_R_UP 180
#define CHEEK_UP_L_UP 180
#define CHEEK_LOW_L_UP 354

#define CHEEK_UP_R_DWN 200
#define CHEEK_LOW_R_DWN 190
#define CHEEK_UP_L_DWN 411
#define CHEEK_LOW_L_DWN 349
