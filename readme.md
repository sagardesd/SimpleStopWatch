This is a simple stopwatch program implimented using gettimeofday().
To use this just include the stopwatch.h header in your program.
Usage example:
  StopWatch obj(SECOND/MILISECOND/MICROSECOND);
  obj.start()
  // Code whose performance needs to be measured
  double timeElapsed = obj.stop()
- timeElapsed is the time calulcated in Second/MiliSecond/Micrsecond based on the enum(SECOND/MILISECOND/MICRSECOND) passed
  while creating the StopWatch object.
