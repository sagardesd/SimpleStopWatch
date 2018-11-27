
/*
 Sample test program to test the stopwatch
*/
#include "stopwatch.h"
int main(int argc, char* argv[])
{
	int j = 0;
	//StopWatch stopWatch(SECOND);
	//StopWatch stopWatch(MILISECOND);
	StopWatch stopWatch(MICROSECOND);
	stopWatch.start();
	while(j != 1000)
	{
		j++;
	}
	double timeElapsed = stopWatch.stop();
	std::string startTime = stopWatch.getStartDateAndTime();
	std::string endTime = stopWatch.getStopDateAndTime();
	std::cout << "Stop watch started at :" << startTime << std::endl;
	std::cout << "Stop watch stopped at :" << endTime << std::endl;
	std::cout << "Time elapsed : " << timeElapsed << std::endl;
	return 0;
}
