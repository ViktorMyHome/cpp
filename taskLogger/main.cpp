#include "logger.h"
#include <iostream>
#include <memory>



int main() {


	// In file: [ FATAL ][ Sun Jun  9 13:07:25 2024][ My Thread ]Test message1
	auto logger1 = LoggerFactory::NewLogger(4,WARNING,TIMESTAMP,THREAD_NAME, TOFILE);
	logger1.Print(FATAL,"Test message1");

	//In console: [ Sun Jun  9 13:07:25 2024][ ERROR ]Test message2
	auto logger2 = LoggerFactory::NewLogger(3,TIMESTAMP, WARNING, STDOUT);
	logger2.Print(ERROR,"Test message2");

	//In console: Log Level does not enable to print
	auto logger3 = LoggerFactory::NewLogger(2,ERROR, TIMESTAMP);
	logger3.Print(WARNING,"Test message3");

    return 0;
}



