/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "s3eMATSDK.h"

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef       void(*MATStartMobileAppTracker_t)(const char* adId, const char* convKey);
typedef       void(*MATSDKParameters_t)();
typedef       void(*MATTrackInstall_t)();
typedef       void(*MATTrackUpdate_t)();
typedef       void(*MATTrackInstallWithReferenceId_t)(const char* refId);
typedef       void(*MATTrackActionForEventIdOrName_t)(const char* eventIdOrName, bool isId, const char* refId);
typedef       void(*MATTrackActionForEventIdOrNameItems_t)(const char* eventIdOrName, bool isId, const MATArray* items, const char* refId, double revenueAmount, const char* currencyCode, uint8 transactionState, const char* receipt);
typedef       void(*MATTrackAction_t)(const char* eventIdOrName, bool isId, double revenue, const char* currency);
typedef       void(*MATSetPackageName_t)(const char* packageName);
typedef       void(*MATSetCurrencyCode_t)(const char* currencyCode);
typedef       void(*MATSetOpenUDID_t)(const char* openUDID);
typedef       void(*MATSetUIID_t)(const char* uiid);
typedef       void(*MATSetUserId_t)(const char* userId);
typedef       void(*MATSetRevenue_t)(double revenue);
typedef       void(*MATSetSiteId_t)(const char* siteId);
typedef       void(*MATSetTRUSTeId_t)(const char* tpid);
typedef       void(*MATSetAppAdTracking_t)(bool enable);
typedef       void(*MATSetDelegate_t)(bool enable);
typedef       void(*MATSetUseHTTPS_t)(bool enable);
typedef       void(*MATSetJailbroken_t)(bool isJailbroken);
typedef       void(*MATSetShouldAutoDetectJailbroken_t)(bool shouldAutoDetect);
typedef       void(*MATSetMACAddress_t)(const char* mac);
typedef       void(*MATSetODIN1_t)(const char* odin1);
typedef       void(*MATSetUseCookieTracking_t)(bool useCookieTracking);
typedef       void(*MATSetAge_t)(int age);
typedef       void(*MATSetGender_t)(int gender);
typedef       void(*MATSetLocation_t)(double latitude, double longitude, double altitude);
typedef       void(*MATStartAppToAppTracking_t)(const char* targetAppId, const char* advertiserId, const char* offerId, const char* publisherId, bool shouldRedirect);
typedef       void(*MATSetRedirectUrl_t)(const char* redirectUrl);
typedef       void(*MATSetAppleAdvertisingIdentifier_t)(const char* advertiserId);
typedef       void(*MATSetAppleVendorIdentifier_t)(const char* vendorId);
typedef       void(*MATSetShouldAutoGenerateAppleVendorIdentifier_t)(bool shouldAutoGenerate);
typedef       void(*MATSetShouldAutoGenerateAppleAdvertisingIdentifier_t)(bool shouldAutoGenerate);
typedef       void(*MATSetDebugMode_t)(bool shouldDebug);
typedef       void(*MATSetAllowDuplicates_t)(bool allowDuplicates);

/**
 * struct that gets filled in by s3eMATSDKRegister
 */
typedef struct s3eMATSDKFuncs
{
    MATStartMobileAppTracker_t m_MATStartMobileAppTracker;
    MATSDKParameters_t m_MATSDKParameters;
    MATTrackInstall_t m_MATTrackInstall;
    MATTrackUpdate_t m_MATTrackUpdate;
    MATTrackInstallWithReferenceId_t m_MATTrackInstallWithReferenceId;
    MATTrackActionForEventIdOrName_t m_MATTrackActionForEventIdOrName;
    MATTrackActionForEventIdOrNameItems_t m_MATTrackActionForEventIdOrNameItems;
    MATTrackAction_t m_MATTrackAction;
    MATSetPackageName_t m_MATSetPackageName;
    MATSetCurrencyCode_t m_MATSetCurrencyCode;
    MATSetOpenUDID_t m_MATSetOpenUDID;
    MATSetUIID_t m_MATSetUIID;
    MATSetUserId_t m_MATSetUserId;
    MATSetRevenue_t m_MATSetRevenue;
    MATSetSiteId_t m_MATSetSiteId;
    MATSetTRUSTeId_t m_MATSetTRUSTeId;
    MATSetAppAdTracking_t m_MATSetAppAdTracking;
    MATSetDelegate_t m_MATSetDelegate;
    MATSetUseHTTPS_t m_MATSetUseHTTPS;
    MATSetJailbroken_t m_MATSetJailbroken;
    MATSetShouldAutoDetectJailbroken_t m_MATSetShouldAutoDetectJailbroken;
    MATSetMACAddress_t m_MATSetMACAddress;
    MATSetODIN1_t m_MATSetODIN1;
    MATSetUseCookieTracking_t m_MATSetUseCookieTracking;
    MATSetAge_t m_MATSetAge;
    MATSetGender_t m_MATSetGender;
    MATSetLocation_t m_MATSetLocation;
    MATStartAppToAppTracking_t m_MATStartAppToAppTracking;
    MATSetRedirectUrl_t m_MATSetRedirectUrl;
    MATSetAppleAdvertisingIdentifier_t m_MATSetAppleAdvertisingIdentifier;
    MATSetAppleVendorIdentifier_t m_MATSetAppleVendorIdentifier;
    MATSetShouldAutoGenerateAppleVendorIdentifier_t m_MATSetShouldAutoGenerateAppleVendorIdentifier;
    MATSetShouldAutoGenerateAppleAdvertisingIdentifier_t m_MATSetShouldAutoGenerateAppleAdvertisingIdentifier;
    MATSetDebugMode_t m_MATSetDebugMode;
    MATSetAllowDuplicates_t m_MATSetAllowDuplicates;
} s3eMATSDKFuncs;

static s3eMATSDKFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0xbb39d6f4, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: s3eMATSDK");
            
        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0xbb39d6f4, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool s3eMATSDKAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

void MATStartMobileAppTracker(const char* adId, const char* convKey)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[0] func: MATStartMobileAppTracker"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATStartMobileAppTracker(adId, convKey);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSDKParameters()
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[1] func: MATSDKParameters"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSDKParameters();

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATTrackInstall()
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[2] func: MATTrackInstall"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATTrackInstall();

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATTrackUpdate()
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[3] func: MATTrackUpdate"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATTrackUpdate();

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATTrackInstallWithReferenceId(const char* refId)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[4] func: MATTrackInstallWithReferenceId"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATTrackInstallWithReferenceId(refId);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATTrackActionForEventIdOrName(const char* eventIdOrName, bool isId, const char* refId)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[5] func: MATTrackActionForEventIdOrName"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATTrackActionForEventIdOrName(eventIdOrName, isId, refId);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATTrackActionForEventIdOrNameItems(const char* eventIdOrName, bool isId, const MATArray* items, const char* refId, double revenueAmount, const char* currencyCode, uint8 transactionState, const char* receipt)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[6] func: MATTrackActionForEventIdOrNameItems"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATTrackActionForEventIdOrNameItems(eventIdOrName, isId, items, refId, revenueAmount, currencyCode, transactionState, receipt);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATTrackAction(const char* eventIdOrName, bool isId, double revenue, const char* currency)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[7] func: MATTrackAction"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATTrackAction(eventIdOrName, isId, revenue, currency);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetPackageName(const char* packageName)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[8] func: MATSetPackageName"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetPackageName(packageName);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetCurrencyCode(const char* currencyCode)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[9] func: MATSetCurrencyCode"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetCurrencyCode(currencyCode);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetOpenUDID(const char* openUDID)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[10] func: MATSetOpenUDID"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetOpenUDID(openUDID);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetUIID(const char* uiid)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[11] func: MATSetUIID"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetUIID(uiid);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetUserId(const char* userId)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[12] func: MATSetUserId"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetUserId(userId);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetRevenue(double revenue)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[13] func: MATSetRevenue"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetRevenue(revenue);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetSiteId(const char* siteId)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[14] func: MATSetSiteId"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetSiteId(siteId);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetTRUSTeId(const char* tpid)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[15] func: MATSetTRUSTeId"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetTRUSTeId(tpid);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetAppAdTracking(bool enable)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[16] func: MATSetAppAdTracking"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetAppAdTracking(enable);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetDelegate(bool enable)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[17] func: MATSetDelegate"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetDelegate(enable);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetUseHTTPS(bool enable)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[18] func: MATSetUseHTTPS"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetUseHTTPS(enable);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetJailbroken(bool isJailbroken)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[19] func: MATSetJailbroken"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetJailbroken(isJailbroken);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetShouldAutoDetectJailbroken(bool shouldAutoDetect)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[20] func: MATSetShouldAutoDetectJailbroken"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetShouldAutoDetectJailbroken(shouldAutoDetect);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetMACAddress(const char* mac)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[21] func: MATSetMACAddress"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetMACAddress(mac);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetODIN1(const char* odin1)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[22] func: MATSetODIN1"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetODIN1(odin1);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetUseCookieTracking(bool useCookieTracking)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[23] func: MATSetUseCookieTracking"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetUseCookieTracking(useCookieTracking);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetAge(int age)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[24] func: MATSetAge"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetAge(age);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetGender(int gender)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[25] func: MATSetGender"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetGender(gender);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetLocation(double latitude, double longitude, double altitude)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[26] func: MATSetLocation"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetLocation(latitude, longitude, altitude);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATStartAppToAppTracking(const char* targetAppId, const char* advertiserId, const char* offerId, const char* publisherId, bool shouldRedirect)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[27] func: MATStartAppToAppTracking"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATStartAppToAppTracking(targetAppId, advertiserId, offerId, publisherId, shouldRedirect);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetRedirectUrl(const char* redirectUrl)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[28] func: MATSetRedirectUrl"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetRedirectUrl(redirectUrl);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetAppleAdvertisingIdentifier(const char* advertiserId)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[29] func: MATSetAppleAdvertisingIdentifier"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetAppleAdvertisingIdentifier(advertiserId);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetAppleVendorIdentifier(const char* vendorId)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[30] func: MATSetAppleVendorIdentifier"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetAppleVendorIdentifier(vendorId);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetShouldAutoGenerateAppleVendorIdentifier(bool shouldAutoGenerate)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[31] func: MATSetShouldAutoGenerateAppleVendorIdentifier"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetShouldAutoGenerateAppleVendorIdentifier(shouldAutoGenerate);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetShouldAutoGenerateAppleAdvertisingIdentifier(bool shouldAutoGenerate)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[32] func: MATSetShouldAutoGenerateAppleAdvertisingIdentifier"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetShouldAutoGenerateAppleAdvertisingIdentifier(shouldAutoGenerate);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetDebugMode(bool shouldDebug)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[33] func: MATSetDebugMode"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetDebugMode(shouldDebug);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetAllowDuplicates(bool allowDuplicates)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[34] func: MATSetAllowDuplicates"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetAllowDuplicates(allowDuplicates);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}
