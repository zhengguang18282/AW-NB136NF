
/****************************************************************************
 *  (c) Copyright 2007 Wi-Fi Alliance.  All Rights Reserved
 *
 *
 *  LICENSE
 *
 *  License is granted only to Wi-Fi Alliance members and designated
 *  contractors ($B!H(BAuthorized Licensees$B!I(B)..AN  Authorized Licensees are granted
 *  the non-exclusive, worldwide, limited right to use, copy, import, export
 *  and distribute this software:
 *  (i) solely for noncommercial applications and solely for testing Wi-Fi
 *  equipment; and
 *  (ii) solely for the purpose of embedding the software into Authorized
 *  Licensee$B!G(Bs proprietary equipment and software products for distribution to
 *  its customers under a license with at least the same restrictions as
 *  contained in this License, including, without limitation, the disclaimer of
 *  warranty and limitation of liability, below..AN  The distribution rights
 *  granted in clause
 *  (ii), above, include distribution to third party companies who will
 *  redistribute the Authorized Licensee$B!G(Bs product to their customers with or
 *  without such third party$B!G(Bs private label. Other than expressly granted
 *  herein, this License is not transferable or sublicensable, and it does not
 *  extend to and may not be used with non-Wi-Fi applications..AN  Wi-Fi Alliance
 *  reserves all rights not expressly granted herein..AN 
 *.AN 
 *  Except as specifically set forth above, commercial derivative works of
 *  this software or applications that use the Wi-Fi scripts generated by this
 *  software are NOT AUTHORIZED without specific prior written permission from
 *  Wi-Fi Alliance.
 *.AN 
 *  Non-Commercial derivative works of this software for internal use are
 *  authorized and are limited by the same restrictions; provided, however,
 *  that the Authorized Licensee shall provide Wi-Fi Alliance with a copy of
 *  such derivative works under a perpetual, payment-free license to use,
 *  modify, and distribute such derivative works for purposes of testing Wi-Fi
 *  equipment.
 *.AN 
 *  Neither the name of the author nor "Wi-Fi Alliance" may be used to endorse
 *  or promote products that are derived from or that use this software without
 *  specific prior written permission from Wi-Fi Alliance.
 *
 *  THIS SOFTWARE IS PROVIDED BY WI-FI ALLIANCE "AS IS" AND ANY EXPRESS OR
 *  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 *  OF MERCHANTABILITY, NON-INFRINGEMENT AND FITNESS FOR A.AN PARTICULAR PURPOSE,
 *  ARE DISCLAIMED. IN NO EVENT SHALL WI-FI ALLIANCE BE LIABLE FOR ANY DIRECT,
 *  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, THE COST OF PROCUREMENT OF SUBSTITUTE
 *  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 *  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE) ARISING IN ANY WAY OUT OF
 *  THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ******************************************************************************
 */
 

#ifndef _WFA_MISCS_H_
#define _WFA_MISCS_H_

#ifdef WIN32
#define inline __inline
#define uint unsigned int 
#define PING_STATUS_FILE_PATH	"temp\\RWL\\pingstatus.txt"
ULONG exitcode ;
extern int wfa_Winitime_diff(SYSTEMTIME *t1,SYSTEMTIME *t2);
extern int ChangeGateWay(GateWay);
extern int GetPingStat(FILE* pFile, const wchar_t* lpszSearchString , unsigned int *pos,unsigned int *sent, const char* delim) ;
extern int GetStats(FILE* pFile, const wchar_t* lpszSearchString , unsigned int *pos, const char* delim) ;
extern int FileSearch(FILE* pFile, const wchar_t* lpszSearchString, unsigned int *pos) ;
extern unsigned int uGetLocalIP(void);
extern char* GetHostName(char* buf, int len) ;
extern char* GetDutIP(char* );
extern DWORD PingStart( );
extern char * strtok_r(char *s1, const char *s2, char **lasts);
extern int strncasecmp(const char *s1, const char *s2, unsigned int length);
extern int strcasecmp(const char *s1, const char *s2);
extern FILE* asd_Config(char* , char*);
extern HANDLE processHandle;
extern HANDLE processThread;
extern int wfa_Win_estimate_timer_latency();
typedef unsigned long GateWay;   //new gateway
#endif/*WIN32*/
extern int wfaTGSetPrio(int sockfd, int tgClass);

/* 802.1x Defines */
#define KEY_FILE                "key.pem"
#define TTLS_innerEAP           "mschapv2"
#define AES_ENCPTYPE            "aes"
#define AES_LEN                 0x4
/* defines for EAP types */
#define BCM_DEFAULT_SEC_MODE	0x0
#define BCM_EAP_TYPE_TLS	0x1
#define BCM_EAP_TYPE_TTLS	0x2
#define BCM_EAP_TYPE_SIM	0x3
#define BCM_EAP_TYPE_PEAP	0x4
#define BCM_EAP_TYPE_FAST	0x5
#define BCM_EAP_TYPE_AKA	0x6

#define STD_ERR 2
#define TEMP_FILE_PATH "tempr.txt"
#define TEMP_STD_ERR_FILE "temp_err.dat"
#define TEMP_STD_OUT_FILE "temp_out.dat"

#if defined(WIN32)
#define DUP _dup
#define DUP2 _dup2
#else
#define DUP dup
#define DUP2 dup2
#endif 

#ifndef WIN32
#define S_N_PRINTF snprintf
#else
#define S_N_PRINTF _snprintf
#endif
extern int Start_Socket_Service();
extern int Stop_Socket_Service();
extern int isString(char *);
extern int isNumber(char *);
extern int isIpV4Addr(char *);
extern inline double wfa_timeval2double(struct timeval *tval);
extern inline void wfa_double2timeval(struct timeval *tval, double dval);
extern inline double wfa_ftime_diff(struct timeval *t1, struct timeval *t2);
extern int wfa_itime_diff(struct timeval *t1, struct timeval *t2);
void p_error(char *errorString);
/* OS abstraction APIs*/
extern void asd_sleep(int sleepTime);
extern void uapsd_sleep(int sleepTime);
extern void asd_closeSocket(int Sockfd);
extern void asd_shutDown(int Sockfd);
extern void exec_process(char* command);
extern int exec_wmmCmd(char* command);
extern int asd_Config_wmm(char *strFunct, char *strstrParams);
extern inline void int2BuffBigEndian(int val, char *buf);
extern inline int bigEndianBuff2Int(char *buff);
extern char* rwl_client_path;
extern int rwl_wifi_flag;
extern int gagtSockfd;
extern void Cleanup_File(FILE *fp);
extern unsigned short wfa_defined_debug;
extern void GetWirelessAdapter(char *adapter_name);
extern void get_rwl_exe_path(char *rwl_exe_path, int exe_path_len);
extern FILE *asd_cmd_exec(char * trafficPath);
extern int interface_validation(char *interfac);
extern void file_cleanup(FILE *fp);
extern FILE *asd_Config(char *strFunct, char *strstrParams);
extern int exec_process_cnclient(char *buf, char *rwl_client_path, int rwl_wifi_flag);

/*
 * Following declarations are separated for LINUX and ANDROID
 * The default path given for Linux are not taken in Android
 */
#ifndef WIN32
#ifdef TARGETENV_android
#define SH_PATH "/data/busybox/sh"
#define PING_PATH "/data/busybox/ping"
#define IFCONFIG_PATH "/data/busybox/ifconfig"
#define ROUTE_PATH "/data/busybox/route"
#define DHCLIENT_PATH "/data/busybox/dhclient"
#define TMP_FILE_PATH "/data/local/temp.txt"
#define RESOLV_FILE_PATH "/data/local/resolv.conf.bak"
#define PINGOUT_FILE_PATH "/data/local/pingout.txt" 
#define SPOUT_FILE_PATH "/data/local/spout.txt" 
#else
#define PING_PATH "/bin/ping"
#define SH_PATH "/bin/sh"
#define IFCONFIG_PATH "/sbin/ifconfig"
#define ROUTE_PATH "/sbin/route"
#define DHCLIENT_PATH "/sbin/dhclient"
#define TMP_FILE_PATH "/tmp/temp.txt"
#define RESOLV_FILE_PATH "/tmp/resolv.conf.bak"
#define PINGOUT_FILE_PATH "/tmp/pingout.txt" 
#define SPOUT_FILE_PATH "/tmp/spout.txt" 
#endif
#endif
#endif/*_WFA_MISCS_H_*/
