#include "logger.h"
#include <iostream>


string GetLogLevel(int ll){
	string str;
	switch(ll){
		case FATAL:
			str = "FATAL";
			break;
		case ERROR:
			str = "ERROR";
			break;
		case WARNING:
			str = "WARNING";
			break;
		case DEBUG:
			str = "DEBUG";
			break;
		case INFO:
			str = "INFO";
			break;
		case NOISE:
			str = "NOISE";
			break;
		default:
			str = "Error!!!";
			break;
	}
	return str;
};
