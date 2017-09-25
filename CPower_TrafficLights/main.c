/*
 * main.c
 *
 *  Created on: 2017 Apr 26 10:02:22
 *  Author: ciara
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

 void changeLights(){
	 // green off, yellow on
	 DIGITAL_IO_SetOutputLow(&GREEN);
	 DIGITAL_IO_SetOutputHigh(&YELLOW);
	 TIMER_Start(&ThreeTimer);
	 while(!TIMER_GetInterruptStatus(&ThreeTimer));
	 TIMER_Stop(&ThreeTimer);
	 TIMER_Clear(&ThreeTimer);
	 TIMER_ClearEvent(&ThreeTimer);
	 
	 //yellow off, red on
	 DIGITAL_IO_SetOutputLow(&YELLOW);
	 DIGITAL_IO_SetOutputHigh(&RED);
	 TIMER_Start(&FiveTimer);
	 while(!TIMER_GetInterruptStatus(&FiveTimer));
	 TIMER_Stop(&FiveTimer);
	 TIMER_Clear(&FiveTimer);
	 TIMER_ClearEvent(&FiveTimer);
	 
	  // red off, green on
	 DIGITAL_IO_SetOutputLow(&RED);
	 DIGITAL_IO_SetOutputHigh(&GREEN);
	 TIMER_Start(&ThreeTimer);
	 while(!TIMER_GetInterruptStatus(&ThreeTimer));
	 TIMER_Stop(&ThreeTimer);
	 TIMER_Clear(&ThreeTimer);
	 TIMER_ClearEvent(&ThreeTimer);

 }
int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if(status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {
	 if(DIGITAL_IO_GetInput(&BUTTON)==1){
	 TIMER_Start(&DebounceTimer);
	 while(!TIMER_GetInterruptStatus(&DebounceTimer));
	 TIMER_Stop(&DebounceTimer);
	 TIMER_Clear(&DebounceTimer);
	 TIMER_ClearEvent(&DebounceTimer);
		 if(DIGITAL_IO_GetInput(&BUTTON)==1){
		changeLights();
		 }
	 }		 
  }
}
