/**
 * Logger (Singleton) test
 * @description Logger test suite
 * @author Denis Meyer
 * @website https://sites.google.com/site/calltopowersoftware/software
 * @version 1.0.0
 * @created 3/16/11
 * @file main.cpp
 *
 *  Copyright (C) 2014 Denis Meyer, calltopower88@googlemail.com
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#include <iostream>
#include <string>
#include "Logger.h"

#define VERSION "v1.0.0"

using std::string;

/**
 * main
 * test some of the Logger functionality
 */
int main (int argc, const char * argv[])
{
    Logger::instance()->newLine(2);
    Logger::instance()->log("Logger " + string(VERSION) + " by Denis Meyer");
    Logger::instance()->newLine(2);
    
    Logger::instance()->log("test suite");
    Logger::instance()->printTimes(50, "#");
    
    /* test case 0 */ 
    Logger::instance()->setOutput(true);
    Logger::instance()->newLine();
    Logger::instance()->log("0. logging normal strings");
    Logger::instance()->setPrefix("Log ----- ");
    Logger::instance()->setPostfix(" ----- /Log");
    Logger::instance()->log("string 1");
    Logger::instance()->clearPostfix();
    Logger::instance()->log("string 2");
    Logger::instance()->clearPrefix();
    Logger::instance()->setOutput(true);
    Logger::instance()->log("string 3");
    Logger::instance()->setOutput(false);
    Logger::instance()->log("string 4");
    Logger::instance()->setOutput(true);
    Logger::instance()->newLine();
    Logger::instance()->logX("si", "Successful number of logs: ", Logger::instance()->getNrOfLogs());
    Logger::instance()->newLine();
    
    /* test case 1 */
    Logger::instance()->newLine();
    Logger::instance()->log("1. logging variable number of arguments (w/o separator)");
    // without separator
    Logger::instance()->resetSeparator();
    Logger::instance()->setPrefix("Log ----- ");
    Logger::instance()->setPostfix(" ----- /Log");
    Logger::instance()->logX("fcsib", 3.41f, 'c', "string 1", 42, true);
    Logger::instance()->clearPostfix();
    Logger::instance()->logX("fcsib", 3.41f, 'c', "string 2", 42, false);
    Logger::instance()->clearPrefix();
    Logger::instance()->setOutput(true);
    Logger::instance()->logX("fcsib", 3.41f, 'c', "string 3", 42, true);
    Logger::instance()->setOutput(false);
    Logger::instance()->logX("fcsib", 3.41f, 'c', "string 4", 42, true);
    Logger::instance()->setOutput(true);
    Logger::instance()->newLine();
    Logger::instance()->logX("si", "Successful number of logs: ", Logger::instance()->getNrOfLogs());
    Logger::instance()->newLine();
    
    /* test case 2 */
    Logger::instance()->newLine();
    Logger::instance()->log("2. logging variable number of arguments (w separator)");
    // with separator
    Logger::instance()->setSeparator(" - ");
    Logger::instance()->setPrefix("Log ----- ");
    Logger::instance()->setPostfix(" ----- /Log");
    Logger::instance()->logX("fcsib", 3.41f, 'c', "string 1", 42, true);
    Logger::instance()->clearPostfix();
    Logger::instance()->logX("fcsib", 3.41f, 'c', "string 2", 42, false);
    Logger::instance()->clearPrefix();
    Logger::instance()->setOutput(true);
    Logger::instance()->logX("fcsib", 3.41f, 'c', "string 3", 42, true);
    Logger::instance()->setOutput(false);
    Logger::instance()->logX("fcsib", 3.41f, 'c', "string 4", 42, true);
    Logger::instance()->resetSeparator();
    Logger::instance()->setOutput(true);
    Logger::instance()->newLine();
    Logger::instance()->logX("si", "Successful number of logs: ", Logger::instance()->getNrOfLogs());
    Logger::instance()->newLine();
    
    /* test case 3 */
    Logger::instance()->newLine();
    Logger::instance()->log("3. logging an bool, an int and a double separately");
    Logger::instance()->setEndline(false);
    Logger::instance()->log("bool, int, double: ");
    Logger::instance()->logX("b", true);
    Logger::instance()->log(", ");
    Logger::instance()->log(42);
    Logger::instance()->log(", ");
    Logger::instance()->log(3.41);
    Logger::instance()->setEndline(true);
    Logger::instance()->newLine(2);
    Logger::instance()->logX("si", "Successful number of logs: ", Logger::instance()->getNrOfLogs());
    Logger::instance()->newLine();
    
    /* test case 4 */
    Logger::instance()->newLine();
    Logger::instance()->log("4. log return values");
    Logger::instance()->logX("si", "Number of arguments logged previously: ", Logger::instance()->log(42));
    Logger::instance()->logX("si", "Number of arguments logged previously: ", Logger::instance()->logX("ii", 42, 21));
    Logger::instance()->newLine();
    Logger::instance()->logX("si", "Successful number of logs: ", Logger::instance()->getNrOfLogs());
    Logger::instance()->newLine();
    
    /* test case 5 */
    Logger::instance()->newLine();
    Logger::instance()->log("5. helper");
    Logger::instance()->printTimes(10, "c");
    Logger::instance()->setSeparator(" - ");
    Logger::instance()->printTimes(10, "c", true);
    Logger::instance()->resetSeparator();
    Logger::instance()->newLine();
    Logger::instance()->logX("si", "Successful number of logs: ", Logger::instance()->getNrOfLogs());
    Logger::instance()->resetNrOfLogs();
    Logger::instance()->logX("si", "Successful number of logs after reset: ", Logger::instance()->getNrOfLogs());
    Logger::instance()->newLine();
    
    /* test case 6 */
    Logger::instance()->newLine();
    Logger::instance()->log("6. log double**");
    double **d;
    d = new double*[5];
    for (int i = 0; i < 5; ++i)
    {
        d[i] = new double[4];
    }
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            d[i][j] = i + j;
        }
    }
    Logger::instance()->setSeparator("\t");
    if(!Logger::instance()->log(d, 5, 4))
    {
        Logger::instance()->log("Error logging double**");
    }
    Logger::instance()->resetSeparator();
    for (int i = 0; i < 4; ++i)
    {
        delete d[i];
    }
    delete[] d;
    Logger::instance()->newLine();
    Logger::instance()->logX("si", "Successful number of logs: ", Logger::instance()->getNrOfLogs());
    Logger::instance()->newLine();
    
    Logger::instance()->printTimes(50, "#");
    Logger::instance()->log("/test suite");
    Logger::instance()->newLine(2);
    
    return 0;
}