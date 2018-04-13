/*
 * A sample stubbed implementation of a Windows Custom Authentication Package
 *
 * Copyright (c) 2008 Mounir IDRASSI <mounir.idrassi@idrix.fr>. All rights reserved.
 *
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE.
 * 
 */

#include "stdafx.h"
#include "IDXAuth.h"


#ifdef _MANAGED
#pragma managed(push, off)
#endif

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
    return TRUE;
}

#ifdef _MANAGED
#pragma managed(pop)
#endif

#define STATUS_NOT_IMPLEMENTED           ((NTSTATUS)0xC0000002L)
#define IDXAUTH_PKG_NAME				"idxauth"



IDXAUTH_API NTSTATUS LsaApCallPackage(
  __in   PLSA_CLIENT_REQUEST ClientRequest,
  __in   PVOID ProtocolSubmitBuffer,
  __in   PVOID ClientBufferBase,
  __in   ULONG SubmitBufferLength,
  __out  PVOID* ProtocolReturnBuffer,
  __out  PULONG ReturnBufferLength,
  __out  PNTSTATUS ProtocolStatus
)
{
	return STATUS_NOT_IMPLEMENTED;
}

IDXAUTH_API NTSTATUS LsaApCallPackagePassthrough(
  __in   PLSA_CLIENT_REQUEST ClientRequest,
  __in   PVOID ProtocolSubmitBuffer,
  __in   PVOID ClientBufferBase,
  __in   ULONG SubmitBufferLength,
  __out  PVOID* ProtocolReturnBuffer,
  __out  PULONG ReturnBufferLength,
  __out  PNTSTATUS ProtocolStatus
)
{
	return STATUS_NOT_IMPLEMENTED;
}


IDXAUTH_API NTSTATUS LsaApCallPackageUntrusted(
  __in   PLSA_CLIENT_REQUEST ClientRequest,
  __in   PVOID ProtocolSubmitBuffer,
  __in   PVOID ClientBufferBase,
  __in   ULONG SubmitBufferLength,
  __out  PVOID* ProtocolReturnBuffer,
  __out  PULONG ReturnBufferLength,
  __out  PNTSTATUS ProtocolStatus
)
{
	return STATUS_NOT_IMPLEMENTED;
}

IDXAUTH_API NTSTATUS LsaApInitializePackage(
  __in      ULONG AuthenticationPackageId,
  __in      PLSA_DISPATCH_TABLE LsaDispatchTable,
  __in_opt  PLSA_STRING Database,
  __in_opt  PLSA_STRING Confidentiality,
  __out     PLSA_STRING* AuthenticationPackageName
)
{
	time_t t1;
	time(&t1);
	FILE *f =fopen("c:\\auth.log","wt");
	fprintf(f, "started at %s\n", ctime(&t1));
	fflush(f);
	PLSA_STRING name = NULL;

	/* Allocate and set the name of the authentication package. */
	if (!(name = (LSA_STRING *) LsaDispatchTable->AllocateLsaHeap (sizeof *name)))
	{
		fprintf(f, "error\n");
		fflush(f);
		fclose(f);
		return STATUS_NO_MEMORY;
	}
	if (!(name->Buffer = (char *) LsaDispatchTable->AllocateLsaHeap(sizeof (IDXAUTH_PKG_NAME) + 1)))
	{
		fprintf(f, "error\n");
		fflush(f);
		fclose(f);
		LsaDispatchTable->FreeLsaHeap(name);
		return STATUS_NO_MEMORY;
	}

	name->Length = sizeof(IDXAUTH_PKG_NAME) - 1;
	name->MaximumLength = sizeof(IDXAUTH_PKG_NAME);
	strcpy_s(name->Buffer, sizeof (IDXAUTH_PKG_NAME) + 1, IDXAUTH_PKG_NAME);

	(*AuthenticationPackageName) = name;

	fprintf(f, "finished\n");
	fflush(f);
	fclose(f);

	return NO_ERROR; 
}

IDXAUTH_API VOID LsaApLogonTerminated(
  __in  PLUID LogonId
)
{

}

IDXAUTH_API NTSTATUS LsaApLogonUser(
  __in   PLSA_CLIENT_REQUEST ClientRequest,
  __in   SECURITY_LOGON_TYPE LogonType,
  __in   PVOID AuthenticationInformation,
  __in   PVOID ClientAuthenticationBase,
  __in   ULONG AuthenticationInformationLength,
  __out  PVOID* ProfileBuffer,
  __out  PULONG ProfileBufferLength,
  __out  PLUID LogonId,
  __out  PNTSTATUS SubStatus,
  __out  PLSA_TOKEN_INFORMATION_TYPE TokenInformationType,
  __out  PVOID* TokenInformation,
  __out  PLSA_UNICODE_STRING* AccountName,
  __out  PLSA_UNICODE_STRING* AuthenticatingAuthority
)
{
	return STATUS_NOT_IMPLEMENTED;
}

IDXAUTH_API NTSTATUS LsaApLogonUserEx(
  __in   PLSA_CLIENT_REQUEST ClientRequest,
  __in   SECURITY_LOGON_TYPE LogonType,
  __in   PVOID AuthenticationInformation,
  __in   PVOID ClientAuthenticationBase,
  __in   ULONG AuthenticationInformationLength,
  __out  PVOID* ProfileBuffer,
  __out  PULONG ProfileBufferLength,
  __out  PLUID LogonId,
  __out  PNTSTATUS SubStatus,
  __out  PLSA_TOKEN_INFORMATION_TYPE TokenInformationType,
  __out  PVOID* TokenInformation,
  __out  PUNICODE_STRING* AccountName,
  __out  PUNICODE_STRING* AuthenticatingAuthority,
  __out  PUNICODE_STRING* MachineName
)
{
	return STATUS_NOT_IMPLEMENTED;
}

IDXAUTH_API NTSTATUS LsaApLogonUserEx2(
  __in   PLSA_CLIENT_REQUEST ClientRequest,
  __in   SECURITY_LOGON_TYPE LogonType,
  __in   PVOID ProtocolSubmitBuffer,
  __in   PVOID ClientBufferBase,
  __in   ULONG SubmitBufferSize,
  __out  PVOID* ProfileBuffer,
  __out  PULONG ProfileBufferSize,
  __out  PLUID LogonId,
  __out  PNTSTATUS SubStatus,
  __out  PLSA_TOKEN_INFORMATION_TYPE TokenInformationType,
  __out  PVOID* TokenInformation,
  __out  PUNICODE_STRING* AccountName,
  __out  PUNICODE_STRING* AuthenticatingAuthority,
  __out  PUNICODE_STRING* MachineName,
  __out  PSECPKG_PRIMARY_CRED PrimaryCredentials,
  __out  PSECPKG_SUPPLEMENTAL_CRED_ARRAY* SupplementalCredentials
)
{
	return STATUS_NOT_IMPLEMENTED;
}
