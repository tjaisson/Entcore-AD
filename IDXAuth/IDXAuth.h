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

#ifdef IDXAUTH_EXPORTS
#define IDXAUTH_API __declspec(dllexport)
#else
#define IDXAUTH_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" 
{
#endif

IDXAUTH_API NTSTATUS LsaApCallPackage(
  __in   PLSA_CLIENT_REQUEST ClientRequest,
  __in   PVOID ProtocolSubmitBuffer,
  __in   PVOID ClientBufferBase,
  __in   ULONG SubmitBufferLength,
  __out  PVOID* ProtocolReturnBuffer,
  __out  PULONG ReturnBufferLength,
  __out  PNTSTATUS ProtocolStatus
);

IDXAUTH_API NTSTATUS LsaApCallPackagePassthrough(
  __in   PLSA_CLIENT_REQUEST ClientRequest,
  __in   PVOID ProtocolSubmitBuffer,
  __in   PVOID ClientBufferBase,
  __in   ULONG SubmitBufferLength,
  __out  PVOID* ProtocolReturnBuffer,
  __out  PULONG ReturnBufferLength,
  __out  PNTSTATUS ProtocolStatus
);

IDXAUTH_API NTSTATUS LsaApCallPackageUntrusted(
  __in   PLSA_CLIENT_REQUEST ClientRequest,
  __in   PVOID ProtocolSubmitBuffer,
  __in   PVOID ClientBufferBase,
  __in   ULONG SubmitBufferLength,
  __out  PVOID* ProtocolReturnBuffer,
  __out  PULONG ReturnBufferLength,
  __out  PNTSTATUS ProtocolStatus
);

IDXAUTH_API NTSTATUS LsaApInitializePackage(
  __in      ULONG AuthenticationPackageId,
  __in      PLSA_DISPATCH_TABLE LsaDispatchTable,
  __in_opt  PLSA_STRING Database,
  __in_opt  PLSA_STRING Confidentiality,
  __out     PLSA_STRING* AuthenticationPackageName
);

IDXAUTH_API VOID LsaApLogonTerminated(
  __in  PLUID LogonId
);

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
);

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
);

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
);



#ifdef __cplusplus
}
#endif
