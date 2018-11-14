#include <sys/time.h>
#include <iostream>
#include <unistd.h>

enum Unit
{
	SECOND = 1,
	MILISECOND = 2,
	MICROSECOND = 3
};

class StopWatch
{
public:
	StopWatch(Unit unit = SECOND);
	~StopWatch();
	void start();
	double stop();
private:
	double getTime(struct timeval& source);
private:
	Unit unit;
	bool isRunning;
	struct timeval startTime;
	struct timeval endTime;
};

StopWatch::StopWatch(Unit unit):unit(unit), startTime(), endTime(), isRunning(false)
{
}

StopWatch::~StopWatch()
{
}

double StopWatch::getTime(struct timeval& source)
{
	double time;
	switch(unit)
	{
		case SECOND:
			time = (double)source.tv_sec + ((double)source.tv_usec * 1e-6);
			break;
		case MILISECOND:
			time = ((double)source.tv_sec*1e3) + ((double)source.tv_usec * 1e-3);
			break;
		case MICROSECOND:
			time = ((double)source.tv_sec*1e6) + (double)source.tv_usec;
			break;
		default:
			std::cout << "Wrong unit" << std::endl; 
	}
	return time;
}

void StopWatch::start()
{
	if(this->isRunning)
	{
		std::cout << "Stopwatch already running" << std::endl;
		return;
	}
	this->isRunning =  true;
	gettimeofday(&startTime, NULL);
}

double StopWatch::stop()
{	
	gettimeofday(&endTime, NULL);
	double result = 0;
	if(!this->isRunning)
	{
		std::cout << "Stopwatch is  not running" << std::endl;
		return result;
	}
	this->isRunning = false;
	double start = this->getTime(this->startTime);
	double end = this->getTime(this->endTime);
	result = end - start;
	return result;
}


