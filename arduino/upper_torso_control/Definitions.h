//----------------------------------pins
//-----------------------motors
#define MTR1ENB 6
#define MTR1_1 7
#define MTR1_2 8

#define MTR2ENB 5
#define MTR2_1 4
#define MTR2_2 12
//----------------------sensors
#define TRN_POT A0

//-----------------------servos
//-----------------------0
#define neck_top_left 8
#define neck_top_right 9

#define left_up 5
#define left_down 4
#define right_up 7
#define right_down 6

//--------------------------------tuning variables
#define KP 10
#define KO 110
#define NECKDEAD 50

//--------------------------------limits for movments
#define trn_pot_max 775
#define trn_pot_min 0

#define neck_top_left_max 432 //out
#define neck_top_left_def 285
#define neck_top_left_min 204 //in
#define neck_top_right_max 460 //in
#define neck_top_left_def 305
#define neck_top_right_min 208 //out

#define ORIG_PITCH 10
#define MAX_PITCH 0
#define MIN_PITCH 0
#define ORIG_ROLL 20
#define MAX_ROLL 0
#define MIN_ROLL 0
