//---------------------servo pins
//---------------- 0
#define B_LID_R 15
#define T_LID_R 14
#define BROW_2_R 13
#define BROW_1_R 12
#define CHEEK_LOW_R 11
#define CHEEK_UP_R 10
#define LIP_UP_R 9
#define LIP_LOW_R 8

#define LIP_LOW_L 7 
#define LIP_UP_L 6
#define CHEEK_UP_L 5
#define CHEEK_LOW_L 4
#define BROW_1_L 3
#define BROW_2_L 2
#define T_LID_L 1
#define B_LID_L 0
//---------------- 1
#define NOSE_R 12 
#define JAW_PIVOT_R 11
#define JAW_SLIDE_R 10
#define V_EYE_R 9
#define H_EYE_R 8

#define H_EYE_L 7
#define V_EYE_L 6
#define JAW_SLIDE_L 5
#define JAW_PIVOT_L 4
#define NOSE_L 3 

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
#define B_LID_R_MAX 230//down

#define BROW_1_R_MIN 85//top
#define BROW_1_R_MAX 200//bottom

#define BROW_2_R_MIN 80//top
#define BROW_2_R_MAX 180//bottom

#define LID_OFFSET_TOP_R 50
#define LID_OFFSET_BOTTOM_R 50

//-----------------------------------left

#define H_EYE_L_MIN 95 //right
#define H_EYE_L_MAX 215 //left

#define V_EYE_L_MIN 190 //up
#define V_EYE_L_MAX 380 //down

#define T_LID_L_CENT 420//at center
#define T_LID_L_MIN 310//down
#define T_LID_L_MAX 525//up

#define B_LID_L_CENT 430//at center
#define B_LID_L_MIN 470//up
#define B_LID_L_MAX 340//down

#define BROW_1_L_MIN 340//top
#define BROW_1_L_MAX 220//bottom

#define BROW_2_L_MIN 140//top
#define BROW_2_L_MAX 220//bottom

#define LID_OFFSET_TOP_L 50
#define LID_OFFSET_BOTTOM_L 50

//-------------------------------------cheek
#define CHEEK_UP_R_DEF 263
#define CHEEK_LOW_R_DEF 240
#define CHEEK_UP_L_DEF 410
#define CHEEK_LOW_L_DEF 337

#define CHEEK_UP_R_FOR 190
#define CHEEK_LOW_R_FOR 346
#define CHEEK_UP_L_FOR 489
#define CHEEK_LOW_L_FOR 239

#define CHEEK_UP_R_BAK 280
#define CHEEK_LOW_R_BAK 170
#define CHEEK_UP_L_BAK 383
#define CHEEK_LOW_L_BAK 440

#define CHEEK_UP_R_UP 400
#define CHEEK_LOW_R_UP 180
#define CHEEK_UP_L_UP 335
#define CHEEK_LOW_L_UP 362

#define CHEEK_UP_R_DWN 200
#define CHEEK_LOW_R_DWN 190
#define CHEEK_UP_L_DWN 500
#define CHEEK_LOW_L_DWN 345

//---------------------------------------jaw
#define JAW_SLIDE_R_FOR 220
#define JAW_SLIDE_R_BAK 380
#define JAW_SLIDE_L_FOR 290
#define JAW_SLIDE_L_BAK 110

#define JAW_PIVOT_R_CLOS_SLD_FOR 400
#define JAW_PIVOT_R_CLOS_SLD_BAK 280
#define JAW_PIVOT_R_OPN_SLD_FOR 125
#define JAW_PIVOT_R_OPN_SLD_BAK 71

//---------------------------------------nose
#define NOSE_R_UP 425
#define NOSE_R_DWN 360
#define NOSE_L_UP 285
#define NOSE_L_DWN 350

//----------------------------------------lip
#define LIP_LOW_R_OUT 275
#define LIP_LOW_R_IN 445

#define LIP_UP_R_OUT 250
#define LIP_UP_R_IN 390

#define LIP_LOW_L_OUT 325
#define LIP_LOW_L_IN 115

#define LIP_UP_L_OUT 440
#define LIP_UP_L_IN 250
