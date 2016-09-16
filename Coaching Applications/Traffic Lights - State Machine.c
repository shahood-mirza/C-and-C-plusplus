/* 
	Traffic Lights - State Machine
	State 1: Red, Red
	State 2: Red, Green
	State 3: Red Yellow
	State 4: Green, Red
	State 5: Yellow, Red
*/

#include "Main.h"

int goToState1(int stateStart) {
	time_t timeStart, timeStop;
	int nextState;

	if(stateStart) {
		timeStart = time(NULL);
		stateStart=0;
	}
	timeStop = time(NULL);

	if((timeStop-timeStart)>60) nextState=s2;
	else nextState=s1;
}
int goToState2() {
}
int goToState3() {
}
int goToState4() {
}
int goToState5() {
}

void main(void) {
	// below comments have already been added as #define; they just show a different way of declaration
	//enum States{s1, s2, s3, s4, s5};
	//const int s1=0, s2=1, s3=2, s4=3, s5=4;
	
	int currentState=1, stateStart=1;

	while(1) {
		switch(currentState) {
			case s1: {
				currentState = goToState1(stateStart);
				stateStart=0;
				if(currentState!=s1) stateStart=1;

				break;
			}
			case s2: {
				currentState = goToState2();
				break;
			}
			case s3: {
				currentState = goToState3();
				break;
			}
			case s4: {
				currentState = goToState4();
				break;
			}
			case s5: {
				currentState = goToState5();
				break;
			}
			default: {
				//notify user:
				currentState = s1;
			}
		}
	}
}