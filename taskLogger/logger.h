#pragma once
#include <cstdarg>
#include <stdio.h>
#include <string>
#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <fstream>
using namespace std;


enum LOG_LEVEL{
	FATAL=0,
	ERROR,
	WARNING,
	DEBUG,
	INFO,
	NOISE,
};

enum EXTENSION{
	TIMESTAMP=100,
	LOG_LEVEL_LABEL,
	THREAD_NAME,
};

enum PRINT{
	TOFILE = 200,
	STDOUT,
};

string GetLogLevel(int ll);

//normal class
class Timestamp{
	const char * timestamp;
	uint numberTimeStamp;
public:	
	Timestamp(){
		timestamp = "";
		numberTimeStamp = 0;
	}
	void setTimmeStamp(const char * str){
		timestamp = str;
	}
	void setNumberTimeStamp(int ts){
		numberTimeStamp = ts;
	}
	const char * getTimeStamp(){
		return timestamp;
	}
	int getNumberTimeStamp(){
		return numberTimeStamp;
	}
};

//the class can be changed on structure
class LogLevel{
public:	
	int loglevel;
	uint numberLogLevel;
	LogLevel(){
		loglevel = 0;
		numberLogLevel = 0;
	}
};

class ThreadName{
public:	
	const char *threadName;
	uint numberThreadName;
	ThreadName(){
		threadName = "";
		numberThreadName = 0;
	}
};


class Logger: public LogLevel, Timestamp, ThreadName
{
	//map to store Logger configuration
	map<int, int> mp;
	bool toFile;
	bool toStdOut;
	std::ofstream logFile;
public:
	Logger(int a[], int size):Timestamp(), LogLevel(), ThreadName()
	{
		toFile = false;
		toStdOut = false;
		for(int i=0;i<size;i++)
		{
			switch(a[i]){
				case TIMESTAMP:
					this->setNumberTimeStamp(i+1);
					mp.insert(pair<int, int>(this->getNumberTimeStamp(), TIMESTAMP));
					break;
				case FATAL:
				case ERROR:
				case WARNING:
				case INFO:
				case NOISE:
					this->numberLogLevel = i+1;
					mp.insert(pair<int, int>(this->numberLogLevel, a[i]));
					break;
				case THREAD_NAME:
					this->numberThreadName = i+1;
					mp.insert(pair<int, int>(this->numberThreadName, THREAD_NAME));
					break;
				case TOFILE:
					toFile = true;
					break;
				case STDOUT:
					toStdOut = true;
					break;
				default:
					std::cerr<<" not correct initialization of Logger"<<std::endl;
					break;
			}	
		}
	}

	bool Print(const LOG_LEVEL loglevel, const char * message){
		if(toFile){
			logFile.open("logFile.txt", ios::app);
		}
		map<int,int>::iterator it;
		for(it = mp.begin();it!=mp.end();++it)
		{
			if(it->second >= FATAL && it->second <= NOISE){
				if(loglevel > it->second){
					toFile ?  logFile<<" Log Level does not enable to print"<<endl : cout<<" Log Level does not enable to print"<<endl;
					return false;//do not print due to log level
				}
			}
			
		}
		//print everything except message
		for(auto entry: mp)
		{
			switch(entry.second){
				case THREAD_NAME:
					toFile ? logFile<<"[ My Thread ]": cout<<"[ My Thread ]";
					break;
				case FATAL:
				case ERROR:
				case WARNING:
				case INFO:
				case NOISE:
					toFile ? logFile<< "[ " << GetLogLevel(loglevel) << " ]" : cout<< "[ " << GetLogLevel(loglevel) << " ]";
					break;
				case TIMESTAMP:
					time_t t = time(nullptr);
					toFile ? logFile<< "[ " << asctime(localtime(&t)) << " ]": cout<< "[ " << asctime(localtime(&t)) << " ]";
					break;

			}
		}
		toFile ? logFile<<message<<endl : cout<<message<<endl;

		if(toFile){
			logFile.close();
		}
	}
};

class LoggerFactory{
public:
	static Logger NewLogger(int count, ...)
	{
		std::va_list args;
		va_start(args, count);
		int array[count];
		for(int i=0;i<count;i++)
		{
			array[i] = va_arg(args,int);
		}
		return Logger(array, count);
	}
};


