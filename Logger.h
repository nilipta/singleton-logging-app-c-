/**
 * Logger (Singleton) Header
 * @description a Logger implementing the Singleton pattern
 * @author Denis Meyer
 * @website https://sites.google.com/site/calltopowersoftware/software
 * @version 1.0.0
 * @created 3/16/11
 * @file Logger.h
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
#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>
#include <ostream>
#include <stdlib.h>
#include <stdarg.h>

//Logger Singleton
class Logger
{
public:
    static Logger* instance();
    void newLine(const int nr = 1) const;
    void printTimes(const int times, const std::string str, const bool separator = false) const;
    bool log(const std::string str = "") const;
    bool log(const int i) const;
    bool log(const double d) const;
    bool log(double **d, const int rows, const int cols) const;
    int logX(const std::string szTypes = "", ...) const;
    void setPrefix(const std::string prefix = "");
    void setPostfix(const std::string postfix = "");
    void setSeparator(const std::string separator = " ");
    void setOutput(const bool output = true);
    void setEndline(const bool endline = true);
    void setStream(std::ostream &stream = std::cout);
    void resetNrOfLogs();
    void clearPrefix();
    void clearPostfix();
    void resetSeparator();
    unsigned int getNrOfLogs() const;
    std::string getPrefix() const;
    std::string getPostfix() const;
    std::string getSeparator() const;
    bool output() const;
    bool endl() const;
    
private:
    Logger();
    Logger(const Logger& l);
    ~Logger();
    
    Logger& operator=(const Logger& l);
    
    // static variables
    static Logger *m_instance;
    static std::string m_prefix;
    static std::string m_postfix;
    static std::string m_separator;
    static bool m_output;
    static bool m_endl;
    static std::ostream *m_stream;
    static unsigned int m_nrLogs;
    
    // union for multiple argument logging
    mutable union currType_t
    {
        int i;
        float f;
        char c;
        char *s;
    } m_currType;
};

#endif // LOGGER_H