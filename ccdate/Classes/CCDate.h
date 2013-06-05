//
//  CCDate.h
//  ccdate
//
//  Created by Ghost on 12-10-1.
//
//

#ifndef __ccdate__CCDate__
#define __ccdate__CCDate__

#include "cocos2d.h"

using namespace cocos2d;

typedef int DATE_Year;
typedef int DATE_Month;
typedef int DATE_Week;
typedef int DATE_Day;
typedef int DATE_Hour;
typedef int DATE_Minute;
typedef int DATE_Second;
typedef long DATE_Microsecond;
typedef double DATE_Time;
typedef int DATE_Timezone;

class CCDate : public CCObject
{
private:
    timeval _localTime;
    timeval _UTCTime;
    tm _localDate;
    tm _UTCDate;
    
    void syncFromLocalTime();
    void syncFromLocalDate();
    void syncFromUTCTime();
    void syncFromUTCDate();
    
    static int sharedTimezoneOffset();
public:
    
    /**
     *	@brief	创建一个经过初始化的CCDate
     *
     *	@return	CCDate*
     */
    static CCDate* create();

    /**
     *	@brief	以当前时间创建一个CCDate
     *
     *	@return	CCDate*
     */
    static CCDate* createWithCurrentTime();

    /**
     *	@brief	以timeval为时间点创建CCDate
     *
     *	@param 	timeval 	cc_timeval类型
     *
     *	@return	CCDate
     */
    static CCDate* createWithCC_TimevalWithLocaltime(cc_timeval timeval);

    /**
     *	@brief	以timeval为时间点创建CCDate
     *
     *	@param 	timeval 	timeval类型
     *
     *	@return	CCDate
     */
    static CCDate* createWithTimevalWithLocaltime(timeval timeval);

    /**
     *	@brief	初始化(作为保留)
     */
    virtual void init();

    /**
     *	@brief	以当前时间初始化CCDate
     */
    virtual void initWithCurrentTime();

    /**
     *	@brief	以timeval初始化CCDate
     *
     *	@param 	timeval 	cc_timeval类型
     */
    void setCC_TimevalWithLocaltime(cc_timeval timeval);

    /**
     *	@brief	以timeval初始化CCDate
     *
     *	@param 	timeval 	timeval类型
     */
    void setTimevalWithLocaltime(timeval timeval);
    
    /**
     *	@brief	
     *
     *	@return	按照通用时间返回 Date 对象中自 1970 年 1 月 1 日午夜以来的毫秒数。
     */
    DATE_Time getTime();

    /**
     *	@brief	返回时区时间偏移量,单位为Second
     *
     *	@return	DATE_Timezones
     */
    DATE_Timezone getTimezoneOffset();

    /**
     *	@brief	设置通用时间自 1970 年 1 月 1 日午夜以来的毫秒数。
     *
     *	@param 	time 	单位Second
     *
     *	@return	DATE_Time
     */
    DATE_Time setTime(DATE_Time time);

    /**
     *	@brief	设置时区时间偏移量,单位Second
     *
     *	@param 	timezone 	单位Second
     *
     *	@return	DATE_Time
     */
    DATE_Time setTimezoneOffset(DATE_Timezone timezone);
    
    
    
    

    /**
     *	@brief	返回时间中的微秒值
     *
     *	@return	DATE_Microsecond
     */
    DATE_Microsecond getMicroseconds();
    
    /**
     *	@brief	返回时间中的秒值
     *
     *	@return	DATE_Second
     */
    DATE_Second getSeconds();
    
    /**
     *	@brief	返回时间中的分钟值
     *
     *	@return	DATE_Minute
     */
    DATE_Minute getMinutes();
    
    /**
     *	@brief	返回时间中的小时值
     *
     *	@return	DATE_Hour
     */
    DATE_Hour getHours();
    
    /**
     *	@brief	返回时间中的日期值
     *
     *	@return	DATE_Day
     */
    DATE_Day getDay();
    
    /**
     *	@brief	返回时间中的星期值
     *
     *	@return	DATE_Week
     */
    DATE_Week getWeek();
    
    /**
     *	@brief	返回时间中的月份值
     *
     *	@return	DATE_Month
     */
    DATE_Month getMonth();
    
    /**
     *	@brief	返回时间中的年份值
     *
     *	@return	DATE_Year
     */
    DATE_Year getYear();
    
    
    
    
    
    /**
     *	@brief	返回UTC时间中的微秒值
     *
     *	@return	DATE_Microsecond
     */
    DATE_Microsecond getUTCMicroseconds();
    
    /**
     *	@brief	返回UTC时间中的秒值
     *
     *	@return	DATE_Second
     */
    DATE_Second getUTCSeconds();
    
    /**
     *	@brief	返回UTC时间中的分钟值
     *
     *	@return	DATE_Minute
     */
    DATE_Minute getUTCMinutes();
    
    /**
     *	@brief	返回UTC时间中的小时值
     *
     *	@return	DATE_Hour
     */
    DATE_Hour getUTCHours();
    
    /**
     *	@brief	返回UTC时间中的日期值
     *
     *	@return	DATE_Day
     */
    DATE_Day getUTCDay();
    
    /**
     *	@brief	返回UTC时间中的星期值
     *
     *	@return	DATE_Week
     */
    DATE_Week getUTCWeek();
    
    /**
     *	@brief	返回UTC时间中的月份值
     *
     *	@return	DATE_Month
     */
    DATE_Month getUTCMonth();
    
    /**
     *	@brief	返回UTC时间中的年份值
     *
     *	@return	DATE_Year
     */
    DATE_Year getUTCYear();

    
    
    /**
     *	@brief	设置时间中的微秒值
     *
     *	@param 	microsecond 	DATE_Microsecond
     *
     *	@return	DATE_Time 按照通用时间返回 Date 对象中自 1970 年 1 月 1 日午夜以来的毫秒数。
     */
    DATE_Time setMicroseconds(DATE_Microsecond microsecond);

    /**
     *	@brief	设置时间中的秒值
     *
     *	@param 	second 	DATE_Second
     *
     *	@return	DATE_Time 按照通用时间返回 Date 对象中自 1970 年 1 月 1 日午夜以来的毫秒数。
     */
    DATE_Time setSeconds(DATE_Second second);

    /**
     *	@brief	设置时间中的分钟值
     *
     *	@param 	minute 	DATE_Minute
     *
     *	@return	DATE_Time 按照通用时间返回 Date 对象中自 1970 年 1 月 1 日午夜以来的毫秒数。
     */
    DATE_Time setMinutes(DATE_Minute minute);

    /**
     *	@brief	设置时间中的小时值
     *
     *	@param 	hour 	DATE_Hour
     *
     *	@return	DATE_Time 按照通用时间返回 Date 对象中自 1970 年 1 月 1 日午夜以来的毫秒数。
     */
    DATE_Time setHours(DATE_Hour hour);

    /**
     *	@brief	设置时间中的日期值
     *
     *	@param 	day 	DATE_Day
     *
     *	@return	DATE_Time 按照通用时间返回 Date 对象中自 1970 年 1 月 1 日午夜以来的毫秒数。
     */
    DATE_Time setDay(DATE_Day day);

    /**
     *	@brief	设置时间中的月份值
     *
     *	@param 	month 	DATE_Month
     *
     *	@return	DATE_Time 按照通用时间返回 Date 对象中自 1970 年 1 月 1 日午夜以来的毫秒数。
     */
    DATE_Time setMonth(DATE_Month month);

    /**
     *	@brief	设置时间中的年份值
     *
     *	@param 	year 	DATE_Year
     *
     *	@return	DATE_Time 按照通用时间返回 Date 对象中自 1970 年 1 月 1 日午夜以来的毫秒数。
     */
    DATE_Time setYear(DATE_Year year);

    
    
    
    
    /**
     *	@brief	设置UTC时间中的微秒值
     *
     *	@param 	microsecond 	DATE_Microsecond
     *
     *	@return	DATE_Time 按照通用时间返回 Date 对象中自 1970 年 1 月 1 日午夜以来的毫秒数。
     */
    DATE_Time setUTCMicroseconds(DATE_Microsecond microsecond);
    
    /**
     *	@brief	设置UTC时间中的秒值
     *
     *	@param 	second 	DATE_Second
     *
     *	@return	DATE_Time 按照通用时间返回 Date 对象中自 1970 年 1 月 1 日午夜以来的毫秒数。
     */
    DATE_Time setUTCSeconds(DATE_Second second);
    
    /**
     *	@brief	设置UTC时间中的分钟值
     *
     *	@param 	minute 	DATE_Minute
     *
     *	@return	DATE_Time 按照通用时间返回 Date 对象中自 1970 年 1 月 1 日午夜以来的毫秒数。
     */
    DATE_Time setUTCMinutes(DATE_Minute minute);
    
    /**
     *	@brief	设置UTC时间中的小时值
     *
     *	@param 	hour 	DATE_Hour
     *
     *	@return	DATE_Time 按照通用时间返回 Date 对象中自 1970 年 1 月 1 日午夜以来的毫秒数。
     */
    DATE_Time setUTCHours(DATE_Hour hour);
    
    /**
     *	@brief	设置UTC时间中的日期值
     *
     *	@param 	day 	DATE_Day
     *
     *	@return	DATE_Time 按照通用时间返回 Date 对象中自 1970 年 1 月 1 日午夜以来的毫秒数。
     */
    DATE_Time setUTCDay(DATE_Day day);
    
    /**
     *	@brief	设置UTC时间中的月份值
     *
     *	@param 	month 	DATE_Month
     *
     *	@return	DATE_Time 按照通用时间返回 Date 对象中自 1970 年 1 月 1 日午夜以来的毫秒数。
     */
    DATE_Time setUTCMonth(DATE_Month month);
    
    /**
     *	@brief	设置UTC时间中的年份值
     *
     *	@param 	year 	DATE_Year
     *
     *	@return	DATE_Time 按照通用时间返回 Date 对象中自 1970 年 1 月 1 日午夜以来的毫秒数。
     */
    DATE_Time setUTCYear(DATE_Year year);
    
    std::string description();
};

#endif
