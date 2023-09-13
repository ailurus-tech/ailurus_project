//the ailurus_blue_screen.h from Ailurus Project,
//a C++ open source libraries project
//ailurus future fuctions' demo,they may be instable and have many bugs
//just for developers to test,don't use them except the developing
//and testing environment or at your own risk
#ifndef ailurus_dangerous_future_fuctions
	#define ailurus_dangerous_future_fuctions 0
#endif
#if ailurus_dangerous_future_fuctions
	#pragma message("You are using some dangerous fuctions")
	#pragma message("in the ailurus project.They are really dangerous.")
	#pragma message("At your own risk!")
	#include <windows.h>
	#include <SubAuth.h>
	namespace ailurus{
		typedef enum _HARDERROR_RESPONSE_OPTION{
			OptionAbortRetryIgnore,
			OptionOk,
			OptionOkCancel,
			OptionRetryCancel,
			OptionYesNo,
			OptionYesNoCancel,
			OptionShutdownSystem
		} HARDERROR_RESPONSE_OPTION, * PHARDERROR_RESPONSE_OPTION;
		typedef enum _HARDERROR_RESPONSE{
			ResponseReturnToCaller,
			ResponseNotHandled,
			ResponseAbort,
			ResponseCancel,
			ResponseIgnore,
			ResponseNo,
			ResponseOk,
			ResponseRetry,
			ResponseYes
		} HARDERROR_RESPONSE, * PHARDERROR_RESPONSE;
		typedef UINT(CALLBACK* NTRAISEHARDERROR)(NTSTATUS, ULONG, PUNICODE_STRING, PVOID, HARDERROR_RESPONSE_OPTION, PHARDERROR_RESPONSE);
		bool GetShutdownPrivilege(){
			HANDLE hToken;
			TOKEN_PRIVILEGES priv = { 0 };
			LUID ShutdownLUID;
			if(!OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES,&hToken)){
				return false;
			}
			if((hToken == NULL)||(hToken==INVALID_HANDLE_VALUE)){
				return false;
			}
			if(!LookupPrivilegeValue(NULL,SE_SHUTDOWN_NAME,&ShutdownLUID)){
				return false;
			}
			priv.PrivilegeCount=1;
			priv.Privileges[0].Luid=ShutdownLUID;
			priv.Privileges[0].Attributes=SE_PRIVILEGE_ENABLED;
			if (!AdjustTokenPrivileges(hToken,FALSE,&priv,0,NULL,NULL)){
				return false;
			}
			if(GetLastError()==ERROR_NOT_ALL_ASSIGNED){
				return false;
			}
			return true;
		}
		UINT NtRaiseHardError(NTSTATUS ErrorStatus,ULONG NumberOfParameters,PUNICODE_STRING UnicodeStringParameterMask OPTIONAL,PVOID Parameters,HARDERROR_RESPONSE_OPTION ResponseOption,PHARDERROR_RESPONSE Response){
			HMODULE hNtdll=LoadLibrary("ntdll.dll");
			if(hNtdll==NULL){
				return -1;
			} 
			NTRAISEHARDERROR _NtRaiseHardError=(NTRAISEHARDERROR)GetProcAddress(hNtdll, "NtRaiseHardError");
			FreeLibrary(hNtdll);
			return _NtRaiseHardError(ErrorStatus, NumberOfParameters, UnicodeStringParameterMask, Parameters, ResponseOption, Response);
		}
		unsigned int make_blue_screen(long int status_code){
			if(!GetShutdownPrivilege()){
				return -1;
			}
			HARDERROR_RESPONSE response;
			return NtRaiseHardError(status_code,0,NULL,NULL,OptionShutdownSystem,&response);
		}
	}
#else
	#pragma message("Your setting don't allow to use dangerous functions")
	#pragma message("If you wan't to use,add this macro definition below:")
	#pragma message("#define ailurus_dangerous_future_fuctions 1")
	namespace ailurus{
		unsigned int make_blue_screen(long int){
			return 0;
		}
	}
#endif
