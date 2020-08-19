// copyright (c) 2017-2020 hors<horsicq@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#ifndef XPE_DEF_H
#define XPE_DEF_H

#include <QtGlobal>

namespace XPE_DEF
{
const quint32 S_IMAGE_NT_SIGNATURE                          =0x00004550;  // PE00
const quint32 S_IMAGE_NUMBEROF_DIRECTORY_ENTRIES            =16;

const quint32 S_IMAGE_DIRECTORY_ENTRY_EXPORT                =0;   // Export Directory
const quint32 S_IMAGE_DIRECTORY_ENTRY_IMPORT                =1;   // Import Directory
const quint32 S_IMAGE_DIRECTORY_ENTRY_RESOURCE              =2;   // Resource Directory
const quint32 S_IMAGE_DIRECTORY_ENTRY_EXCEPTION             =3;   // Exception Directory
const quint32 S_IMAGE_DIRECTORY_ENTRY_SECURITY              =4;   // Security Directory
const quint32 S_IMAGE_DIRECTORY_ENTRY_BASERELOC             =5;   // Base Relocation Table
const quint32 S_IMAGE_DIRECTORY_ENTRY_DEBUG                 =6;   // Debug Directory
//      XPE_DEF::IMAGE_DIRECTORY_ENTRY_COPYRIGHT       7   // (X86 usage)
const quint32 S_IMAGE_DIRECTORY_ENTRY_ARCHITECTURE          =7;   // Architecture Specific Data
const quint32 S_IMAGE_DIRECTORY_ENTRY_GLOBALPTR             =8;   // RVA of GP
const quint32 S_IMAGE_DIRECTORY_ENTRY_TLS                   =9;   // TLS Directory
const quint32 S_IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG           =10;   // Load Configuration Directory
const quint32 S_IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT          =11;   // Bound Import Directory in headers
const quint32 S_IMAGE_DIRECTORY_ENTRY_IAT                   =12;   // Import Address Table
const quint32 S_IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT          =13;   // Delay Load Import Descriptors
const quint32 S_IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR        =14;   // COM Runtime descriptor

const quint32 S_IMAGE_SIZEOF_FILE_HEADER                    =20;

const quint32 S_IMAGE_FILE_RELOCS_STRIPPED                  =0x0001;  // Relocation info stripped from file.
const quint32 S_IMAGE_FILE_EXECUTABLE_IMAGE                 =0x0002;  // File is executable  (i.e. no unresolved externel references).
const quint32 S_IMAGE_FILE_LINE_NUMS_STRIPPED               =0x0004;  // Line nunbers stripped from file.
const quint32 S_IMAGE_FILE_LOCAL_SYMS_STRIPPED              =0x0008;  // Local symbols stripped from file.
const quint32 S_IMAGE_FILE_AGGRESIVE_WS_TRIM                =0x0010;  // Agressively trim working set
const quint32 S_IMAGE_FILE_LARGE_ADDRESS_AWARE              =0x0020;  // App can handle >2gb addresses
const quint32 S_IMAGE_FILE_BYTES_REVERSED_LO                =0x0080;  // Bytes of machine quint16 are reversed.
const quint32 S_IMAGE_FILE_32BIT_MACHINE                    =0x0100;  // 32 bit quint16 machine.
const quint32 S_IMAGE_FILE_DEBUG_STRIPPED                   =0x0200;  // Debugging info stripped from file in .DBG file
const quint32 S_IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP          =0x0400;  // If Image is on removable media, copy and run from the swap file.
const quint32 S_IMAGE_FILE_NET_RUN_FROM_SWAP                =0x0800;  // If Image is on Net, copy and run from the swap file.
const quint32 S_IMAGE_FILE_SYSTEM                           =0x1000;  // System File.
const quint32 S_IMAGE_FILE_DLL                              =0x2000;  // File is a DLL.
const quint32 S_IMAGE_FILE_UP_SYSTEM_ONLY                   =0x4000;  // File should only be run on a UP machine
const quint32 S_IMAGE_FILE_BYTES_REVERSED_HI                =0x8000;  // Bytes of machine quint16 are reversed.

const quint32 S_IMAGE_FILE_MACHINE_UNKNOWN                  =0;
const quint32 S_IMAGE_FILE_MACHINE_I386                     =0x014c;  // Intel 386.
const quint32 S_IMAGE_FILE_MACHINE_R3000                    =0x0162;  // MIPS little-endian, 0x160 big-endian
const quint32 S_IMAGE_FILE_MACHINE_R4000                    =0x0166;  // MIPS little-endian
const quint32 S_IMAGE_FILE_MACHINE_R10000                   =0x0168;  // MIPS little-endian
const quint32 S_IMAGE_FILE_MACHINE_WCEMIPSV2                =0x0169;  // MIPS little-endian WCE v2
const quint32 S_IMAGE_FILE_MACHINE_ALPHA                    =0x0184;  // Alpha_AXP
const quint32 S_IMAGE_FILE_MACHINE_SH3                      =0x01a2;  // SH3 little-endian
const quint32 S_IMAGE_FILE_MACHINE_SH3DSP                   =0x01a3;
const quint32 S_IMAGE_FILE_MACHINE_SH3E                     =0x01a4;  // SH3E little-endian
const quint32 S_IMAGE_FILE_MACHINE_SH4                      =0x01a6;  // SH4 little-endian
const quint32 S_IMAGE_FILE_MACHINE_SH5                      =0x01a8;  // SH5
const quint32 S_IMAGE_FILE_MACHINE_ARM                      =0x01c0;  // ARM Little-Endian
const quint32 S_IMAGE_FILE_MACHINE_THUMB                    =0x01c2;
const quint32 S_IMAGE_FILE_MACHINE_AM33                     =0x01d3;
const quint32 S_IMAGE_FILE_MACHINE_POWERPC                  =0x01F0;  // IBM PowerPC Little-Endian
const quint32 S_IMAGE_FILE_MACHINE_POWERPCFP                =0x01f1;
const quint32 S_IMAGE_FILE_MACHINE_IA64                     =0x0200;  // Intel 64
const quint32 S_IMAGE_FILE_MACHINE_MIPS16                   =0x0266;  // MIPS
const quint32 S_IMAGE_FILE_MACHINE_ALPHA64                  =0x0284;  // ALPHA64
const quint32 S_IMAGE_FILE_MACHINE_MIPSFPU                  =0x0366;  // MIPS
const quint32 S_IMAGE_FILE_MACHINE_MIPSFPU16                =0x0466;  // MIPS
const quint32 S_IMAGE_FILE_MACHINE_AXP64                    =S_IMAGE_FILE_MACHINE_ALPHA64;
const quint32 S_IMAGE_FILE_MACHINE_TRICORE                  =0x0520;  // Infineon
const quint32 S_IMAGE_FILE_MACHINE_CEF                      =0x0CEF;
const quint32 S_IMAGE_FILE_MACHINE_EBC                      =0x0EBC;  // EFI Byte Code
const quint32 S_IMAGE_FILE_MACHINE_AMD64                    =0x8664;  // AMD64 (K8)
const quint32 S_IMAGE_FILE_MACHINE_M32R                     =0x9041;  // M32R little-endian
const quint32 S_IMAGE_FILE_MACHINE_CEE                      =0xC0EE;
const quint32 S_IMAGE_FILE_MACHINE_ARM64                    =0xAA64;

const quint32 S_IMAGE_SUBSYSTEM_UNKNOWN                     =0;
const quint32 S_IMAGE_SUBSYSTEM_NATIVE                      =1;
const quint32 S_IMAGE_SUBSYSTEM_WINDOWS_GUI                 =2;
const quint32 S_IMAGE_SUBSYSTEM_WINDOWS_CUI                 =3;
const quint32 S_IMAGE_SUBSYSTEM_OS2_CUI                     =5;
const quint32 S_IMAGE_SUBSYSTEM_POSIX_CUI                   =7;
const quint32 S_IMAGE_SUBSYSTEM_NATIVE_WINDOWS              =8;
const quint32 S_IMAGE_SUBSYSTEM_WINDOWS_CE_GUI              =9;
const quint32 S_IMAGE_SUBSYSTEM_EFI_APPLICATION             =10;
const quint32 S_IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER     =11;
const quint32 S_IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER          =12;
const quint32 S_IMAGE_SUBSYSTEM_EFI_ROM                     =13;
const quint32 S_IMAGE_SUBSYSTEM_XBOX                        =14;
const quint32 S_IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION    =16;

const qint32 S_IMAGE_SIZEOF_SHORT_NAME                      =8;

const quint32 S_IMAGE_SCN_MEM_EXECUTE                       =0x20000000;
const quint32 S_IMAGE_SCN_MEM_READ                          =0x40000000;
const quint32 S_IMAGE_SCN_MEM_WRITE                         =0x80000000;
const quint32 S_IMAGE_SCN_ALIGN_MASK                        =0x00F00000;

/* Predefined resource types */
const quint32 S_RT_NEWRESOURCE                              =0x2000;
const quint32 S_RT_ERROR                                    =0x7fff;
const quint32 S_RT_CURSOR                                   =1;
const quint32 S_RT_BITMAP                                   =2;
const quint32 S_RT_ICON                                     =3;
const quint32 S_RT_MENU                                     =4;
const quint32 S_RT_DIALOG                                   =5;
const quint32 S_RT_STRING                                   =6;
const quint32 S_RT_FONTDIR                                  =7;
const quint32 S_RT_FONT                                     =8;
const quint32 S_RT_ACCELERATORS                             =9;
const quint32 S_RT_RCDATA                                   =10;
const quint32 S_RT_MESSAGETABLE                             =11;
const quint32 S_RT_GROUP_CURSOR                             =12;
const quint32 S_RT_GROUP_ICON                               =14;
const quint32 S_RT_VERSION                                  =16;
const quint32 S_RT_NEWBITMAP                                =(S_RT_BITMAP|S_RT_NEWRESOURCE);
const quint32 S_RT_NEWMENU                                  =(S_RT_MENU|S_RT_NEWRESOURCE);
const quint32 S_RT_NEWDIALOG                                =(S_RT_DIALOG|S_RT_NEWRESOURCE);
const quint32 S_RT_MANIFEST                                 =24;

struct S_IMAGE_FILE_HEADER
{
    quint16 Machine;
    quint16 NumberOfSections;
    quint32 TimeDateStamp;
    quint32 PointerToSymbolTable;
    quint32 NumberOfSymbols;
    quint16 SizeOfOptionalHeader;
    quint16 Characteristics;
};

struct IMAGE_DATA_DIRECTORY
{
    quint32 VirtualAddress;
    quint32 Size;
};

struct IMAGE_OPTIONAL_HEADER32
{
    // Standard fields.
    quint16 Magic;
    quint8  MajorLinkerVersion;
    quint8  MinorLinkerVersion;
    quint32 SizeOfCode;
    quint32 SizeOfInitializedData;
    quint32 SizeOfUninitializedData;
    quint32 AddressOfEntryPoint;
    quint32 BaseOfCode;
    quint32 BaseOfData;
    // NT additional fields.
    quint32 ImageBase;
    quint32 SectionAlignment;
    quint32 FileAlignment;
    quint16 MajorOperatingSystemVersion;
    quint16 MinorOperatingSystemVersion;
    quint16 MajorImageVersion;
    quint16 MinorImageVersion;
    quint16 MajorSubsystemVersion;
    quint16 MinorSubsystemVersion;
    quint32 Win32VersionValue;
    quint32 SizeOfImage;
    quint32 SizeOfHeaders;
    quint32 CheckSum;
    quint16 Subsystem;
    quint16 DllCharacteristics;
    quint32 SizeOfStackReserve;
    quint32 SizeOfStackCommit;
    quint32 SizeOfHeapReserve;
    quint32 SizeOfHeapCommit;
    quint32 LoaderFlags;
    quint32 NumberOfRvaAndSizes;
    IMAGE_DATA_DIRECTORY DataDirectory[S_IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
};

struct IMAGE_OPTIONAL_HEADER32S
{
    // Standard fields.
    quint16 Magic;
    quint8  MajorLinkerVersion;
    quint8  MinorLinkerVersion;
    quint32 SizeOfCode;
    quint32 SizeOfInitializedData;
    quint32 SizeOfUninitializedData;
    quint32 AddressOfEntryPoint;
    quint32 BaseOfCode;
    quint32 BaseOfData;
    // NT additional fields.
    quint32 ImageBase;
    quint32 SectionAlignment;
    quint32 FileAlignment;
    quint16 MajorOperatingSystemVersion;
    quint16 MinorOperatingSystemVersion;
    quint16 MajorImageVersion;
    quint16 MinorImageVersion;
    quint16 MajorSubsystemVersion;
    quint16 MinorSubsystemVersion;
    quint32 Win32VersionValue;
    quint32 SizeOfImage;
    quint32 SizeOfHeaders;
    quint32 CheckSum;
    quint16 Subsystem;
    quint16 DllCharacteristics;
    quint32 SizeOfStackReserve;
    quint32 SizeOfStackCommit;
    quint32 SizeOfHeapReserve;
    quint32 SizeOfHeapCommit;
    quint32 LoaderFlags;
    quint32 NumberOfRvaAndSizes;
};

struct IMAGE_OPTIONAL_HEADER64
{
    // Standard fields.
    quint16 Magic;
    quint8  MajorLinkerVersion;
    quint8  MinorLinkerVersion;
    quint32 SizeOfCode;
    quint32 SizeOfInitializedData;
    quint32 SizeOfUninitializedData;
    quint32 AddressOfEntryPoint;
    quint32 BaseOfCode;
    // NT additional fields.
    qint64 ImageBase;
    quint32 SectionAlignment;
    quint32 FileAlignment;
    quint16 MajorOperatingSystemVersion;
    quint16 MinorOperatingSystemVersion;
    quint16 MajorImageVersion;
    quint16 MinorImageVersion;
    quint16 MajorSubsystemVersion;
    quint16 MinorSubsystemVersion;
    quint32 Win32VersionValue;
    quint32 SizeOfImage;
    quint32 SizeOfHeaders;
    quint32 CheckSum;
    quint16 Subsystem;
    quint16 DllCharacteristics;
    qint64 SizeOfStackReserve;
    qint64 SizeOfStackCommit;
    qint64 SizeOfHeapReserve;
    qint64 SizeOfHeapCommit;
    quint32 LoaderFlags;
    quint32 NumberOfRvaAndSizes;
    IMAGE_DATA_DIRECTORY DataDirectory[S_IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
};

struct IMAGE_OPTIONAL_HEADER64S
{
    // Standard fields.
    quint16 Magic;
    quint8  MajorLinkerVersion;
    quint8  MinorLinkerVersion;
    quint32 SizeOfCode;
    quint32 SizeOfInitializedData;
    quint32 SizeOfUninitializedData;
    quint32 AddressOfEntryPoint;
    quint32 BaseOfCode;
    // NT additional fields.
    qint64 ImageBase;
    quint32 SectionAlignment;
    quint32 FileAlignment;
    quint16 MajorOperatingSystemVersion;
    quint16 MinorOperatingSystemVersion;
    quint16 MajorImageVersion;
    quint16 MinorImageVersion;
    quint16 MajorSubsystemVersion;
    quint16 MinorSubsystemVersion;
    quint32 Win32VersionValue;
    quint32 SizeOfImage;
    quint32 SizeOfHeaders;
    quint32 CheckSum;
    quint16 Subsystem;
    quint16 DllCharacteristics;
    qint64 SizeOfStackReserve;
    qint64 SizeOfStackCommit;
    qint64 SizeOfHeapReserve;
    qint64 SizeOfHeapCommit;
    quint32 LoaderFlags;
    quint32 NumberOfRvaAndSizes;
};

struct IMAGE_NT_HEADERS64
{
    quint32 Signature;
    S_IMAGE_FILE_HEADER FileHeader;
    IMAGE_OPTIONAL_HEADER64 OptionalHeader;
};

struct IMAGE_NT_HEADERS32
{
    quint32 Signature;
    S_IMAGE_FILE_HEADER FileHeader;
    IMAGE_OPTIONAL_HEADER32 OptionalHeader;
};

struct IMAGE_SECTION_HEADER
{
    quint8  Name[S_IMAGE_SIZEOF_SHORT_NAME];
    union
    {
        quint32 PhysicalAddress;
        quint32 VirtualSize;
    } Misc;
    quint32 VirtualAddress;
    quint32 SizeOfRawData;
    quint32 PointerToRawData;
    quint32 PointerToRelocations;
    quint32 PointerToLinenumbers;
    quint16 NumberOfRelocations;
    quint16 NumberOfLinenumbers;
    quint32 Characteristics;
};

struct IMAGE_RESOURCE_DIRECTORY
{
    quint32 Characteristics;
    quint32 TimeDateStamp;
    quint16 MajorVersion;
    quint16 MinorVersion;
    quint16 NumberOfNamedEntries;
    quint16 NumberOfIdEntries;
};

struct IMAGE_RESOURCE_DIRECTORY_ENTRY
{
    union
    {
        struct
        {
            quint32 NameOffset:31;
            quint32 NameIsString:1;
        };
        quint32 Name;
        quint16 Id;
    };
    union
    {
        quint32 OffsetToData;
        struct
        {
            quint32 OffsetToDirectory:31;
            quint32 DataIsDirectory:1;
        };
    };
};

struct IMAGE_RESOURCE_DATA_ENTRY
{
    quint32 OffsetToData;
    quint32 Size;
    quint32 CodePage;
    quint32 Reserved;
};

struct IMAGE_IMPORT_DESCRIPTOR
{
    union
    {
        quint32 Characteristics;
        quint32 OriginalFirstThunk;
    };
    quint32 TimeDateStamp;
    quint32 ForwarderChain;
    quint32 Name;
    quint32 FirstThunk;
};

struct IMAGE_BASE_RELOCATION
{
    quint32 VirtualAddress;
    quint32 SizeOfBlock;
    // quint16    TypeOffset[1];
};

struct IMAGE_EXPORT_DIRECTORY
{
    quint32 Characteristics;
    quint32 TimeDateStamp;
    quint16 MajorVersion;
    quint16 MinorVersion;
    quint32 Name;
    quint32 Base;
    quint32 NumberOfFunctions;
    quint32 NumberOfNames;
    quint32 AddressOfFunctions;     // RVA from base of image
    quint32 AddressOfNames;         // RVA from base of image
    quint32 AddressOfNameOrdinals;  // RVA from base of image
};

struct SYSTEM_INFO32
{
    union
    {
        quint32 dwOemId;
        struct
        {
            quint16 wProcessorArchitecture;
            quint16 wReserved;
        };
    };
    quint32 dwPageSize;
    quint32 lpMinimumApplicationAddress;
    quint32 lpMaximumApplicationAddress;
    quint32 dwActiveProcessorMask;
    quint32 dwNumberOfProcessors;
    quint32 dwProcessorType;
    quint32 dwAllocationGranularity;
    quint16 wProcessorLevel;
    quint16 wProcessorRevision;
};

struct SYSTEM_INFO64
{
    union
    {
        quint32 dwOemId;
        struct
        {
            quint16 wProcessorArchitecture;
            quint16 wReserved;
        };
    };
    quint32 dwPageSize;
    quint64 lpMinimumApplicationAddress;
    quint64 lpMaximumApplicationAddress;
    quint32 dwActiveProcessorMask;
    quint32 dwNumberOfProcessors;
    quint32 dwProcessorType;
    quint32 dwAllocationGranularity;
    quint16 wProcessorLevel;
    quint16 wProcessorRevision;
};

struct IMAGE_COR20_HEADER
{
    // Header versioning
    quint32 cb;
    quint16 MajorRuntimeVersion;
    quint16 MinorRuntimeVersion;
    // Symbol table and startup information
    IMAGE_DATA_DIRECTORY MetaData;
    quint32 Flags;
    // DDBLD - Added next section to replace following lin
    // DDBLD - Still verifying, since not in NT SDK
    // unsigned int                   EntryPointToken;
    // If COMIMAGE_FLAGS_NATIVE_ENTRYPOINT is not set,
    // EntryPointToken represents a managed entrypoint.
    // If COMIMAGE_FLAGS_NATIVE_ENTRYPOINT is set,
    // EntryPointRVA represents an RVA to a native entrypoint.
    union
    {
        quint32 EntryPointToken;
        quint32 EntryPointRVA;
    };
    // DDBLD - End of Added Area
    // Binding information
    IMAGE_DATA_DIRECTORY Resources;
    IMAGE_DATA_DIRECTORY StrongNameSignature;
    // Regular fixup and binding information
    IMAGE_DATA_DIRECTORY CodeManagerTable;
    IMAGE_DATA_DIRECTORY VTableFixups;
    IMAGE_DATA_DIRECTORY ExportAddressTableJumps;
    // Precompiled image info (internal use only - set to zero)
    IMAGE_DATA_DIRECTORY ManagedNativeHeader;
};

enum ReplacesCorHdrNumericDefines
{
    // COM+ Header entry point flags.
    COMIMAGE_FLAGS_ILONLY               =0x00000001,
    COMIMAGE_FLAGS_32BITREQUIRED        =0x00000002,
    COMIMAGE_FLAGS_IL_LIBRARY           =0x00000004,
    COMIMAGE_FLAGS_STRONGNAMESIGNED     =0x00000008,
    COMIMAGE_FLAGS_NATIVE_ENTRYPOINT    =0x00000010,
    COMIMAGE_FLAGS_TRACKDEBUGDATA       =0x00010000,

    // Version flags for image.
    COR_VERSION_MAJOR_V2                =2,
    COR_VERSION_MAJOR                   =COR_VERSION_MAJOR_V2,
    COR_VERSION_MINOR                   =5,
    COR_DELETED_NAME_LENGTH             =8,
    COR_VTABLEGAP_NAME_LENGTH           =8,

    // Maximum size of a NativeType descriptor.
    NATIVE_TYPE_MAX_CB                  =1,
    COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE=0xFF,

    // #defines for the MIH FLAGS
    IMAGE_COR_MIH_METHODRVA             =0x01,
    IMAGE_COR_MIH_EHRVA                 =0x02,
    IMAGE_COR_MIH_BASICBLOCK            =0x08,

    // V-table constants
    COR_VTABLE_32BIT                    =0x01,          // V-table slots are 32-bits in size.
    COR_VTABLE_64BIT                    =0x02,          // V-table slots are 64-bits in size.
    COR_VTABLE_FROM_UNMANAGED           =0x04,          // If set, transition from unmanaged.
    COR_VTABLE_FROM_UNMANAGED_RETAIN_APPDOMAIN  =0x08,  // If set, transition from unmanaged with keeping the current appdomain.
    COR_VTABLE_CALL_MOST_DERIVED        =0x10,          // Call most derived method described by

    // EATJ constants
    IMAGE_COR_EATJ_THUNK_SIZE           =32,            // Size of a jump thunk reserved range.

    // Max name lengths
    //@todo: Change to unlimited name lengths.
    MAX_CLASS_NAME                      =1024,
    MAX_PACKAGE_NAME                    =1024
};

struct S_VS_VERSION_INFO
{
    quint16 wLength;             /* Length of the version resource */
    quint16 wValueLength;        /* Length of the value field for this block */
    quint16 wType;
};

struct S_tagVS_FIXEDFILEINFO
{
    quint32 dwSignature;        // e.g.  0xfeef04bd
    quint32 dwStrucVersion;     // e.g.  0x00000042 = "0.42"
    quint32 dwFileVersionMS;    // e.g.  0x00030075 = "3.75"
    quint32 dwFileVersionLS;    // e.g.  0x00000031 = "0.31"
    quint32 dwProductVersionMS; // e.g.  0x00030010 = "3.10"
    quint32 dwProductVersionLS; // e.g.  0x00000031 = "0.31"
    quint32 dwFileFlagsMask;    // = 0x3F for version "0.42"
    quint32 dwFileFlags;        // e.g.  VFF_DEBUG | VFF_PRERELEASE
    quint32 dwFileOS;           // e.g.  VOS_DOS_WINDOWS16
    quint32 dwFileType;         // e.g.  VFT_DRIVER
    quint32 dwFileSubtype;      // e.g.  VFT2_DRV_KEYBOARD
    quint32 dwFileDateMS;       // e.g.  0
    quint32 dwFileDateLS;       // e.g.  0
};
//typedef VOID (NTAPI *PIMAGE_TLS_CALLBACK)(PVOID DllHandle,quint32 Reason,PVOID Reserved);

struct S_IMAGE_TLS_DIRECTORY64
{
    quint64 StartAddressOfRawData;
    quint64 EndAddressOfRawData;
    quint64 AddressOfIndex;
    quint64 AddressOfCallBacks;
    quint32 SizeOfZeroFill;
    quint32 Characteristics;
};

struct S_IMAGE_TLS_DIRECTORY32
{
    quint32 StartAddressOfRawData;
    quint32 EndAddressOfRawData;
    quint32 AddressOfIndex;
    quint32 AddressOfCallBacks;
    quint32 SizeOfZeroFill;
    quint32 Characteristics;
};

//union {
//        quint32 Characteristics;
//        struct {
//            quint32 Reserved0 : 20;
//            quint32 Alignment : 4;
//            quint32 Reserved1 : 8;
//        } DUMMYSTRUCTNAME;
//    } DUMMYUNIONNAME;

struct S_IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY
{
    quint64 BeginAddress;
    quint64 EndAddress;
    quint64 ExceptionHandler;
    quint64 HandlerData;
    quint64 PrologEndAddress;
};

struct S_IMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY
{
    quint32 BeginAddress;
    quint32 EndAddress;
    quint32 ExceptionHandler;
    quint32 HandlerData;
    quint32 PrologEndAddress;
};

struct S_IMAGE_DEBUG_DIRECTORY
{
    quint32 Characteristics;
    quint32 TimeDateStamp;
    quint16 MajorVersion;
    quint16 MinorVersion;
    quint32 Type;
    quint32 SizeOfData;
    quint32 AddressOfRawData;
    quint32 PointerToRawData;
};

struct S_IMAGE_RUNTIME_FUNCTION_ENTRY
{
    quint32 BeginAddress;
    quint32 EndAddress;
    union
    {
        quint32 UnwindInfoAddress;
        quint32 UnwindData;
    };
};

struct S_IMAGE_LOAD_CONFIG_CODE_INTEGRITY
{
    quint16 Flags;          // Flags to indicate if CI information is available, etc.
    quint16 Catalog;        // 0xFFFF means not available
    quint32 CatalogOffset;
    quint32 Reserved;       // Additional bitmask to be defined later
};

struct S_IMAGE_LOAD_CONFIG_DIRECTORY32
{
    quint32 Size;
    quint32 TimeDateStamp;
    quint16 MajorVersion;
    quint16 MinorVersion;
    quint32 GlobalFlagsClear;
    quint32 GlobalFlagsSet;
    quint32 CriticalSectionDefaultTimeout;
    quint32 DeCommitFreeBlockThreshold;
    quint32 DeCommitTotalFreeThreshold;
    quint32 LockPrefixTable;                // VA
    quint32 MaximumAllocationSize;
    quint32 VirtualMemoryThreshold;
    quint32 ProcessHeapFlags;
    quint32 ProcessAffinityMask;
    quint16 CSDVersion;
    quint16 DependentLoadFlags;
    quint32 EditList;                       // VA
    quint32 SecurityCookie;                 // VA
    quint32 SEHandlerTable;                 // VA
    quint32 SEHandlerCount;
    // Standard
    quint32 GuardCFCheckFunctionPointer;    // VA
    quint32 GuardCFDispatchFunctionPointer; // VA
    quint32 GuardCFFunctionTable;           // VA
    quint32 GuardCFFunctionCount;
    quint32 GuardFlags;
    S_IMAGE_LOAD_CONFIG_CODE_INTEGRITY CodeIntegrity;
    quint32 GuardAddressTakenIatEntryTable; // VA
    quint32 GuardAddressTakenIatEntryCount;
    quint32 GuardLongJumpTargetTable;       // VA
    quint32 GuardLongJumpTargetCount;
    quint32 DynamicValueRelocTable;         // VA
    quint32 CHPEMetadataPointer;
    quint32 GuardRFFailureRoutine;          // VA
    quint32 GuardRFFailureRoutineFunctionPointer; // VA
    quint32 DynamicValueRelocTableOffset;
    quint16 DynamicValueRelocTableSection;
    quint16 Reserved2;
    quint32 GuardRFVerifyStackPointerFunctionPointer; // VA
    quint32 HotPatchTableOffset;
    quint32 Reserved3;
    quint32 EnclaveConfigurationPointer;    // VA
    quint32 VolatileMetadataPointer;        // VA
};

struct S_IMAGE_LOAD_CONFIG_DIRECTORY64
{
    quint32 Size;
    quint32 TimeDateStamp;
    quint16 MajorVersion;
    quint16 MinorVersion;
    quint32 GlobalFlagsClear;
    quint32 GlobalFlagsSet;
    quint32 CriticalSectionDefaultTimeout;
    quint64 DeCommitFreeBlockThreshold;
    quint64 DeCommitTotalFreeThreshold;
    quint64 LockPrefixTable;                // VA
    quint64 MaximumAllocationSize;
    quint64 VirtualMemoryThreshold;
    quint64 ProcessAffinityMask;
    quint32 ProcessHeapFlags;
    quint16 CSDVersion;
    quint16 DependentLoadFlags;
    quint64 EditList;                       // VA
    quint64 SecurityCookie;                 // VA
    quint64 SEHandlerTable;                 // VA
    quint64 SEHandlerCount;
    // Standard
    quint64 GuardCFCheckFunctionPointer;    // VA
    quint64 GuardCFDispatchFunctionPointer; // VA
    quint64 GuardCFFunctionTable;           // VA
    quint64 GuardCFFunctionCount;
    quint32 GuardFlags;
    S_IMAGE_LOAD_CONFIG_CODE_INTEGRITY CodeIntegrity;
    quint64 GuardAddressTakenIatEntryTable; // VA
    quint64 GuardAddressTakenIatEntryCount;
    quint64 GuardLongJumpTargetTable;       // VA
    quint64 GuardLongJumpTargetCount;
    quint64 DynamicValueRelocTable;         // VA
    quint64 CHPEMetadataPointer;            // VA
    quint64 GuardRFFailureRoutine;          // VA
    quint64 GuardRFFailureRoutineFunctionPointer; // VA
    quint32 DynamicValueRelocTableOffset;
    quint16 DynamicValueRelocTableSection;
    quint16 Reserved2;
    quint64 GuardRFVerifyStackPointerFunctionPointer; // VA
    quint32 HotPatchTableOffset;
    quint32 Reserved3;
    quint64 EnclaveConfigurationPointer;     // VA
    quint64 VolatileMetadataPointer;         // VA
};

struct S_IMAGE_DELAYLOAD_DESCRIPTOR {
    union
    {
        quint32 AllAttributes;
        struct
        {
            quint32 RvaBased : 1;             // Delay load version 2
            quint32 ReservedAttributes : 31;
        } DUMMYSTRUCTNAME;
    };
    quint32 DllNameRVA;                       // RVA to the name of the target library (NULL-terminate ASCII string)
    quint32 ModuleHandleRVA;                  // RVA to the HMODULE caching location (PHMODULE)
    quint32 ImportAddressTableRVA;            // RVA to the start of the IAT (PIMAGE_THUNK_DATA)
    quint32 ImportNameTableRVA;               // RVA to the start of the name table (PIMAGE_THUNK_DATA::AddressOfData)
    quint32 BoundImportAddressTableRVA;       // RVA to an optional bound IAT
    quint32 UnloadInformationTableRVA;        // RVA to an optional unload info table
    quint32 TimeDateStamp;                    // 0 if not bound,
                                              // Otherwise, date/time of the target DLL
};
}
#endif // XPE_DEF_H
