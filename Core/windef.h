#ifndef _WINDEF_H
#define _WINDEF_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WINVER
#define WINVER 0x0400
/*
 * If you need Win32 API features newer the Win95 and WinNT then you must
 * define WINVER before including windows.h or any other method of including
 * the windef.h header.
 */
#endif
#ifndef _WIN32_WINNT
#define _WIN32_WINNT WINVER
/*
 * There may be the need to define _WIN32_WINNT to a value different from
 * the value of WINVER.  I don't have any example of why you would do that.
 * However, if you must then define _WIN32_WINNT to the value required before
 * including windows.h or any other method of including the windef.h header.
 */
#endif
#ifndef WIN32
#define WIN32
#endif
#ifndef _WIN32
#define _WIN32
#endif
#define FAR
#define far
#define NEAR
#define near
#ifndef CONST
#define CONST const
#endif
#undef MAX_PATH
#define MAX_PATH 260

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void*)0)
#endif
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif
#define IN
#define OUT
#ifndef OPTIONAL
#define OPTIONAL
#endif

#ifdef __GNUC__
#define PACKED __attribute__((packed))
#ifndef _fastcall
#define _fastcall __attribute__((fastcall))
#endif
#ifndef __fastcall
#define __fastcall __attribute__((fastcall))
#endif
#ifndef _stdcall
#define _stdcall __attribute__((stdcall))
#endif
#ifndef __stdcall
#define __stdcall __attribute__((stdcall))
#endif
#ifndef _cdecl
#define _cdecl __attribute__((cdecl))
#endif
#ifndef __cdecl
#define __cdecl __attribute__((cdecl))
#endif
#ifndef __declspec
#define __declspec(e) __attribute__((e))
#endif
#ifndef _declspec
#define _declspec(e) __attribute__((e))
#endif
#elif defined(__WATCOMC__)
#define PACKED
#else
#define PACKED
#define _cdecl
#define __cdecl
#endif

#undef pascal
#undef _pascal
#undef __pascal
#define pascal __stdcall
#define _pascal __stdcall
#define __pascal __stdcall
#define PASCAL _pascal
#define CDECL _cdecl
#define STDCALL __stdcall
#define FASTCALL __fastcall
#define WINAPI __stdcall
#define WINAPIV __cdecl
#define APIENTRY __stdcall
#define CALLBACK __stdcall
#define APIPRIVATE __stdcall

#define DECLSPEC_IMPORT __declspec(dllimport)
#define DECLSPEC_EXPORT __declspec(dllexport)
#ifdef __GNUC__
#define DECLSPEC_NORETURN __declspec(noreturn)
#define DECLARE_STDCALL_P( type ) __stdcall type
#elif defined(__WATCOMC__)
#define DECLSPEC_NORETURN
#define DECLARE_STDCALL_P( type ) type __stdcall
#endif /* __GNUC__/__WATCOMC__ */
#define MAKEWORD(a,b)	((WORD)(((BYTE)(a))|(((WORD)((BYTE)(b)))<<8)))
#define MAKELONG(a,b)	((LONG)(((WORD)(a))|(((DWORD)((WORD)(b)))<<16)))
#define LOWORD(l)	((WORD)((DWORD)(l)))
#define HIWORD(l)	((WORD)(((DWORD)(l)>>16)&0xFFFF))
#define LOBYTE(w)	((BYTE)(w))
#define HIBYTE(w)	((BYTE)(((WORD)(w)>>8)&0xFF))

#ifndef __WATCOMC__
#ifndef _export
#define _export
#endif
#ifndef __export
#define __export
#endif
#endif

#ifndef NOMINMAX
#ifndef max
#define max(a,b) ((a)>(b)?(a):(b))
#endif
#ifndef min
#define min(a,b) ((a)<(b)?(a):(b))
#endif
#endif

#define UNREFERENCED_PARAMETER(P) {(P)=(P);}
#define UNREFERENCED_LOCAL_VARIABLE(L) {(L)=(L);}
#define DBG_UNREFERENCED_PARAMETER(P)
#define DBG_UNREFERENCED_LOCAL_VARIABLE(L)

#ifdef __GNUC__
#ifndef NONAMELESSUNION
#if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)
#define _ANONYMOUS_UNION __extension__
#define _ANONYMOUS_STRUCT __extension__
#else
#if defined(__cplusplus)
#define _ANONYMOUS_UNION __extension__
#endif /* __cplusplus */
#endif /* __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 95) */
#endif /* NONAMELESSUNION */
#elif defined(__WATCOMC__)
#define _ANONYMOUS_UNION
#define _ANONYMOUS_STRUCT
#endif /* __GNUC__/__WATCOMC__ */

#ifndef _ANONYMOUS_UNION
#define _ANONYMOUS_UNION
#define _UNION_NAME(x) x
#define DUMMYUNIONNAME	u
#define DUMMYUNIONNAME2	u2
#define DUMMYUNIONNAME3	u3
#define DUMMYUNIONNAME4	u4
#define DUMMYUNIONNAME5	u5
#define DUMMYUNIONNAME6	u6
#define DUMMYUNIONNAME7	u7
#define DUMMYUNIONNAME8	u8
#else
#define _UNION_NAME(x)
#define DUMMYUNIONNAME
#define DUMMYUNIONNAME2
#define DUMMYUNIONNAME3
#define DUMMYUNIONNAME4
#define DUMMYUNIONNAME5
#define DUMMYUNIONNAME6
#define DUMMYUNIONNAME7
#define DUMMYUNIONNAME8
#endif
#ifndef _ANONYMOUS_STRUCT
#define _ANONYMOUS_STRUCT
#define _STRUCT_NAME(x) x
#define DUMMYSTRUCTNAME	s
#define DUMMYSTRUCTNAME2 s2
#define DUMMYSTRUCTNAME3 s3
#else
#define _STRUCT_NAME(x)
#define DUMMYSTRUCTNAME
#define DUMMYSTRUCTNAME2
#define DUMMYSTRUCTNAME3
#endif

#ifndef NO_STRICT
#ifndef STRICT
#define STRICT 1
#endif
#endif

/* FIXME: This will make some code compile. The programs will most
   likely crash when an exception is raised, but at least they will
   compile. */
#if defined (__GNUC__) && defined (__SEH_NOOP)
#define __try
#define __except(x) if (0) /* don't execute handler */
#define __finally

#define _try __try
#define _except __except
#define _finally __finally
#endif

typedef unsigned long DWORD;
typedef int WINBOOL,*PWINBOOL,*LPWINBOOL;
/* FIXME: Is there a good solution to this? */
#ifndef XFree86Server
#ifndef __OBJC__
typedef WINBOOL BOOL;
#else
#define BOOL WINBOOL
#endif
typedef unsigned char BYTE;
#endif /* ndef XFree86Server */
typedef BOOL *PBOOL,*LPBOOL;
typedef unsigned short WORD;
typedef float FLOAT;
typedef FLOAT *PFLOAT;
typedef BYTE *PBYTE,*LPBYTE;
typedef int *PINT,*LPINT;
typedef WORD *PWORD,*LPWORD;
typedef long *LPLONG;
typedef DWORD *PDWORD,*LPDWORD;
typedef CONST void *PCVOID,*LPCVOID;
typedef int INT;
typedef unsigned int UINT,*PUINT,*LPUINT;

#ifdef __cplusplus
}
#endif
#endif
