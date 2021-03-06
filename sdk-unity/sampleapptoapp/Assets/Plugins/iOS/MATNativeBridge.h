#import <Foundation/Foundation.h>
#import <MobileAppTracker/MobileAppTracker.h>
#import <string>
#import <map>

typedef struct MATItem
{
    const char* name;
	double 		unitPrice;
	int         quantity;
	double		revenue;
    const char* attribute1;
    const char* attribute2;
    const char* attribute3;
    const char* attribute4;
    const char* attribute5;
} MATItem;