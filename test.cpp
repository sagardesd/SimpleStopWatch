
#include "stopwatch.h"
int main(int argc, char* argv[])
{
	int j = 0;
	//StopWatch stopWatch(SECOND);
	StopWatch stopWatch(MILISECOND);
	//StopWatch stopWatch(MICROSECOND);
	stopWatch.start();
	while(j != 1000)
	{
		j++;
	}
	double timeElapsed = stopWatch.stop();
	std::cout << "Time elapsed : " << timeElapsed << std::endl;
	return 0;
}
