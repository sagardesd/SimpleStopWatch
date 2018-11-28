/*
 Date : 14/11/2018
 Description: A simple stopwatch in c++ using gettimeofday() api
*/
#include <sys/time.h>
#include <iostream>
#include <unistd.h>
#include <cstdio>

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
	
	/* API to start the stopwatch */  	
	void start();
	
	/* 
 	 * API to stop the stopwatch
 	 * This will return the total elapsed time(In second, Mili second or Micro second)
 	 */
	double stop();
	
	/*
 	 * This api will return the stopwatch start date and time of the stop watch in the below format:
 	 * YYYY-MM-DD HH:MM:SS  
 	 */	 	
	std::string getStartDateAndTime();
	
	/*
 	 * This api will return the stopwatch stop date and time of the stop watch in the below format:
 	 * YYYY-MM-DD HH:MM:SS  
 	 */	 	
	std::string getStopDateAndTime();

private:
	double getTime(struct timeval& source);
	std::string format(struct timeval& arg);

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

std::string StopWatch::format(struct timeval& arg)
{
	char formatedResult[100];
	struct tm timeval;
	localtime_r(&arg.tv_sec, &timeval);
	int ret = strftime(formatedResult, sizeof(formatedResult), "%Y-%m-%d %H:%M:%S", &timeval);
	snprintf(formatedResult + ret, 100 + ret, "%06ld", arg.tv_usec);
	std::string result(formatedResult);
	return result;
}

std::string StopWatch::getStartDateAndTime()
{
	return this->format(this->startTime);
}

std::string StopWatch::getStopDateAndTime()
{
	return this->format(this->endTime);
}

double StopWatch::getTime(struct timeval& source)
{
	double time = 0;
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


