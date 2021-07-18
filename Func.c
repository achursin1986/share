unsigned int hysteresis(unsigned int input_percent)
{
	static unsigned int percent_previous;


	if ( input_percent > 100 ) {
                return -1;
        }

	// hysterisis ranges
	if (input_percent < percent_previous) {
		if ( input_percent >= 0  && input_percent <= 10 ) {
			percent_previous = input_percent;
                        return 0;
		}
		if ( input_percent > 10  && input_percent <= 35 ) {
                        percent_previous = input_percent;
                        return 1;
                }
		if ( input_percent > 35  && input_percent <= 60 ) {
                        percent_previous = input_percent;
                        return 2;
                }
		if ( input_percent > 60  && input_percent <= 85 ) {
                        percent_previous = input_percent;
                        return 3;
                }
		if ( input_percent > 85  && input_percent <= 100 ) {
                        percent_previous = input_percent;
                        return 4;
                }


	}

	// stable ranges
	if ( input_percent >= 0 && input_percent < 15 ){
		percent_previous = input_percent;
		return 0;
	}
	if ( input_percent >= 15 && input_percent < 40 ){
                percent_previous = input_percent;
                return 1;
        }
	if ( input_percent >= 40 && input_percent < 65 ){
                percent_previous = input_percent;
                return 2;
        }
	if ( input_percent >= 65 && input_percent < 90 ){
                percent_previous = input_percent;
                return 3;
        }
	if ( input_percent >= 90 && input_percent <= 100 ){
                percent_previous = input_percent;
                return 4;
        }

}
