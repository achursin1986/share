
/* 
 * Function accounts hysteresis, however here are accounted specific ranges per the task, no margin set and no general approach were implemnted
 */ 
unsigned int hysteresis(unsigned int input_percent)
{
	static unsigned int percent_previous;
	static unsigned int current_level;

	if ( input_percent > 100 ) {
                return -1;
        }

	/* hysteresis handling, might be to do in one if statement */  
	if (input_percent < percent_previous) { 
		if ( input_percent > 10  && input_percent < 15 ) {
			percent_previous = input_percent;
                        return current_level;
		}	
		if ( input_percent > 35  && input_percent < 40 ) {
                        percent_previous = input_percent;
                        return current_level;
                }
		if ( input_percent > 60  && input_percent < 65 ) {
                        percent_previous = input_percent;
                        return current_level;
                }
		if ( input_percent > 85  && input_percent < 90 ) {
                        percent_previous = input_percent;
                        return current_level;
                }
		
		
	}
	
	/* stable ranges */ 
	if ( input_percent >= 0 && input_percent < 15 ){
		percent_previous = input_percent;
		current_level = 0;
		return 0;
	}
	if ( input_percent >= 15 && input_percent < 40 ){
                percent_previous = input_percent;
		current_level = 1;
                return 1;
        }
	if ( input_percent >= 40 && input_percent < 65 ){
                percent_previous = input_percent;
		current_level = 2;
                return 2;
        }
	if ( input_percent >= 65 && input_percent < 90 ){
                percent_previous = input_percent;
		current_level = 3;
                return 3;
        }
	if ( input_percent >= 90 && input_percent <= 100 ){
                percent_previous = input_percent;
		current_level = 4;
                return 4;
        }
	
}
