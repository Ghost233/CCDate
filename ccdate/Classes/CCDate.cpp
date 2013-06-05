//
//  CCDate.cpp
//  ccdate
//
//  Created by Ghost on 12-10-1.
//
//

#include "CCDate.h"
#include <cmath>

int timezoneOffset = 2147483647;

int CCDate::sharedTimezoneOffset()
{
    if (timezoneOffset == 2147483647)
    {
        timeval tempTimeval;
        gettimeofday(&tempTimeval, 0);
        tm tempTM;
        tempTM = *localtime(&tempTimeval.tv_sec );
        timezoneOffset = tempTM.tm_gmtoff;
    }
    return timezoneOffset;
}

CCDate* CCDate::create()
{
    CCDate *temp = new CCDate();
    temp->init();
    temp->autorelease();
    return temp;
}

CCDate* CCDate::createWithCurrentTime()
{
    CCDate *temp = new CCDate();
    temp->initWithCurrentTime();
    temp->autorelease();
    return temp;
}

CCDate* CCDate::createWithCC_TimevalWithLocaltime(cc_timeval timeval)
{
    
    CCDate *temp = new CCDate();
    temp->init();
    temp->setCC_TimevalWithLocaltime(timeval);
    temp->autorelease();
    return temp;
}

CCDate* CCDate::createWithTimevalWithLocaltime(timeval timeval)
{
    
    CCDate *temp = new CCDate();
    temp->init();
    temp->setTimevalWithLocaltime(timeval);
    temp->autorelease();
    return temp;
}

void CCDate::init()
{
    
}

void CCDate::initWithCurrentTime()
{
    this->init();
    gettimeofday(&_localTime, 0);
    this->syncFromLocalTime();
}

void CCDate::setCC_TimevalWithLocaltime(cc_timeval timeval)
{
    _localTime.tv_sec = timeval.tv_sec;
    _localTime.tv_usec = timeval.tv_usec;
    this->syncFromLocalTime();
}

void CCDate::setTimevalWithLocaltime(timeval timeval)
{
    _localTime.tv_sec = timeval.tv_sec;
    _localTime.tv_usec = timeval.tv_usec;
    this->syncFromLocalTime();
}

void CCDate::syncFromLocalTime()
{
    _localDate = *localtime(&_localTime.tv_sec );
    _UTCTime.tv_sec = _localTime.tv_sec - sharedTimezoneOffset();
//    _UTCTime.tv_sec = _localTime.tv_sec - _localDate.tm_gmtoff;
    _UTCDate = *localtime(&_UTCTime.tv_sec );
}

void CCDate::syncFromLocalDate()
{
    _localTime.tv_sec = mktime(&_localDate);
    _UTCTime.tv_sec = _localTime.tv_sec - sharedTimezoneOffset();
//    _UTCTime.tv_sec = _localTime.tv_sec - _localDate.tm_gmtoff;
    _UTCDate = *localtime(&_UTCTime.tv_sec );
}

void CCDate::syncFromUTCTime()
{
    _UTCDate = *localtime(&_UTCTime.tv_sec );
    _localTime.tv_sec = _UTCTime.tv_sec + sharedTimezoneOffset();
//    _localTime.tv_sec = _UTCTime.tv_sec + _localDate.tm_gmtoff;
    _localDate = *localtime(&_localTime.tv_sec );
}

void CCDate::syncFromUTCDate()
{
    _UTCTime.tv_sec = mktime(&_UTCDate);
    _localTime.tv_sec = _UTCTime.tv_sec + sharedTimezoneOffset();
//    _localTime.tv_sec = _UTCTime.tv_sec + _localDate.tm_gmtoff;
    _localDate = *localtime(&_localTime.tv_sec );
}

DATE_Time CCDate::getTime()
{
    return _localTime.tv_sec * 1.0 + _localTime.tv_usec * 1.0 / 1000000;
}

DATE_Timezone CCDate::getTimezoneOffset()
{
    return sharedTimezoneOffset();
//    return _localDate.tm_gmtoff;
}

DATE_Time CCDate::setTime(DATE_Time time)
{
    _localTime.tv_sec = time;
    this->syncFromLocalTime();
    return _localTime.tv_sec;
}

DATE_Time CCDate::setTimezoneOffset(DATE_Timezone timezone)
{
//    _localDate.tm_gmtoff = timezone;
    timezoneOffset = timezone;
    this->syncFromUTCTime();
    return _localTime.tv_sec;
}

DATE_Microsecond CCDate::getMicroseconds()
{
    return _localTime.tv_usec;
}

DATE_Second CCDate::getSeconds()
{
    return _localDate.tm_sec;
}

DATE_Minute CCDate::getMinutes()
{
    return _localDate.tm_min;
}

DATE_Hour CCDate::getHours()
{
    return _localDate.tm_hour;
}

DATE_Day CCDate::getDay()
{
    return _localDate.tm_mday;
}

DATE_Week CCDate::getWeek()
{
    return _localDate.tm_wday;
}

DATE_Month CCDate::getMonth()
{
    return _localDate.tm_mon;
}

DATE_Year CCDate::getYear()
{
    return _localDate.tm_year + 1900;
}

DATE_Microsecond CCDate::getUTCMicroseconds()
{
    return _UTCTime.tv_usec;
}

DATE_Second CCDate::getUTCSeconds()
{
    return _UTCDate.tm_sec;
}

DATE_Minute CCDate::getUTCMinutes()
{
    return _UTCDate.tm_min;
}

DATE_Hour CCDate::getUTCHours()
{
    return _UTCDate.tm_hour;
}

DATE_Day CCDate::getUTCDay()
{
    return _UTCDate.tm_mday;
}

DATE_Week CCDate::getUTCWeek()
{
    return _UTCDate.tm_wday;
}

DATE_Month CCDate::getUTCMonth()
{
    return _UTCDate.tm_mon;
}

DATE_Year CCDate::getUTCYear()
{
    return _UTCDate.tm_year + 1900;
}

DATE_Time CCDate::setMicroseconds(DATE_Microsecond microsecond)
{
    _localTime.tv_usec = microsecond;
    return this->getTime();
}

DATE_Time CCDate::setSeconds(DATE_Second second)
{
    _localDate.tm_sec = second;
    this->syncFromLocalDate();
    return this->getTime();
}

DATE_Time CCDate::setMinutes(DATE_Minute minute)
{
    _localDate.tm_min = minute;
    this->syncFromLocalDate();
    return this->getTime();
}

DATE_Time CCDate::setHours(DATE_Hour hour)
{
    _localDate.tm_hour = hour;
    this->syncFromLocalDate();
    return this->getTime();
}

DATE_Time CCDate::setDay(DATE_Day day)
{
    _localDate.tm_mday = day;
    this->syncFromLocalDate();
    return this->getTime();
}

DATE_Time CCDate::setMonth(DATE_Month month)
{
    _localDate.tm_mon = month;
    this->syncFromLocalDate();
    return this->getTime();
}

DATE_Time CCDate::setYear(DATE_Year year)
{
    _localDate.tm_year = year - 1900;
    this->syncFromLocalDate();
    return this->getTime();
}

DATE_Time CCDate::setUTCMicroseconds(DATE_Microsecond microsecond)
{
    _UTCTime.tv_usec = microsecond;
    return this->getTime();
}

DATE_Time CCDate::setUTCSeconds(DATE_Second second)
{
    _UTCDate.tm_sec = second;
    this->syncFromUTCDate();
    return this->getTime();
}

DATE_Time CCDate::setUTCMinutes(DATE_Minute minute)
{
    _UTCDate.tm_min = minute;
    this->syncFromUTCDate();
    return this->getTime();
}

DATE_Time CCDate::setUTCHours(DATE_Hour hour)
{
    _UTCDate.tm_hour = hour;
    this->syncFromUTCDate();
    return this->getTime();
}

DATE_Time CCDate::setUTCDay(DATE_Day day)
{
    _UTCDate.tm_mday = day;
    this->syncFromUTCDate();
    return this->getTime();
}

DATE_Time CCDate::setUTCMonth(DATE_Month month)
{
    _UTCDate.tm_mon = month;
    this->syncFromUTCDate();
    return this->getTime();
}

DATE_Time CCDate::setUTCYear(DATE_Year year)
{
    _UTCDate.tm_year = year - 1900;
    this->syncFromUTCDate();
    return this->getTime();
}

std::string CCDate::description()
{
    CCString *tempDescription = CCString::createWithFormat("%d %d %d %d %d %d %ld",
                                                           this->getYear(),
                                                           this->getMonth(),
                                                           this->getDay(),
                                                           this->getHours(),
                                                           this->getMinutes(),
                                                           this->getSeconds(),
                                                           this->getMicroseconds());
    return tempDescription->m_sString;
}
