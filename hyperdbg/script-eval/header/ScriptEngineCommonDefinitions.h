#pragma once
#ifndef SCRIPT_ENGINE_COMMON_DEFINITIONS_H
#define SCRIPT_ENGINE_COMMON_DEFINITIONS_H

typedef struct SYMBOL
{
    //
    // DO NOT CHANGE THE FIELDS OF THIS STRUCTURE (EITHER ADD OR REMOVE)
    // WITHOUT COORDINATION WITH SINA (THE SIZE ALSO SHOULD NOT BE CHANGED)
    // THIS STRUCTURE IS USED IN HWDBG AND SIZE SHOULD REMAIN CONSTANT FOR
    // HWDBG BIT COMPRESSION
    //
    long long unsigned Type;
    long long unsigned Len;
    long long unsigned VariableType;
    long long unsigned Value;
    //
    // DO NOT CHANGE THE FIELDS OF THIS STRUCTURE (EITHER ADD OR REMOVE)
    // WITHOUT COORDINATION WITH SINA (THE SIZE ALSO SHOULD NOT BE CHANGED)
    // THIS STRUCTURE IS USED IN HWDBG AND SIZE SHOULD REMAIN CONSTANT FOR
    // HWDBG BIT COMPRESSION
    //
} SYMBOL, *PSYMBOL;

typedef struct SYMBOL_BUFFER {
    PSYMBOL Head;
    unsigned int Pointer;
    unsigned int Size;
    char* Message;
} SYMBOL_BUFFER, * PSYMBOL_BUFFER;

typedef struct SYMBOL_MAP
{
    char* Name;
    long long unsigned Type;
} SYMBOL_MAP, * PSYMBOL_MAP;
typedef struct ACTION_BUFFER {
  long long unsigned Tag;
  long long unsigned CurrentAction;
  char ImmediatelySendTheResults;
  long long unsigned Context;
  char CallingStage;
} ACTION_BUFFER, *PACTION_BUFFER;

#define SYMBOL_GLOBAL_ID_TYPE 0
#define SYMBOL_LOCAL_ID_TYPE 1
#define SYMBOL_NUM_TYPE 2
#define SYMBOL_REGISTER_TYPE 3
#define SYMBOL_PSEUDO_REG_TYPE 4
#define SYMBOL_SEMANTIC_RULE_TYPE 5
#define SYMBOL_TEMP_TYPE 6
#define SYMBOL_STRING_TYPE 7
#define SYMBOL_VARIABLE_COUNT_TYPE 8
#define SYMBOL_INVALID 9
#define SYMBOL_WSTRING_TYPE 10
#define SYMBOL_USER_DEFINED_FUNCTION_TYPE 11
#define SYMBOL_FUNCTION_PARAMETER_ID_TYPE 12
#define SYMBOL_RETURN_ADDRESS_TYPE 13
#define SYMBOL_STACK_TEMP_TYPE 14
#define SYMBOL_FUNCTION_PARAMETER_TYPE 15

#define SYMBOL_MEM_VALID_CHECK_MASK (1 << 31)
#define INVALID 0x80000000
#define LALR_ACCEPT 0x7fffffff



#define FUNC_INC 0
#define FUNC_DEC 1
#    define FUNC_REFERENCE                                                    2
#    define FUNC_DEREFERENCE                                                  3
#    define FUNC_OR                                                           4
#    define FUNC_XOR                                                          5
#    define FUNC_AND                                                          6
#    define FUNC_ASR                                                          7
#    define FUNC_ASL                                                          8
#    define FUNC_ADD                                                          9
#    define FUNC_SUB                                                          10
#    define FUNC_MUL                                                          11
#    define FUNC_DIV                                                          12
#    define FUNC_MOD                                                          13
#    define FUNC_GT                                                           14
#    define FUNC_LT                                                           15
#    define FUNC_EGT                                                          16
#    define FUNC_ELT                                                          17
#    define FUNC_EQUAL                                                        18
#    define FUNC_NEQ                                                          19
#    define FUNC_START_OF_IF                                                  20
#    define FUNC_JMP                                                          21
#    define FUNC_JZ                                                           22
#    define FUNC_JNZ                                                          23
#    define FUNC_JMP_TO_END_AND_JZCOMPLETED                                   24
#    define FUNC_END_OF_IF                                                    25
#    define FUNC_START_OF_WHILE                                               26
#    define FUNC_END_OF_WHILE                                                 27
#    define FUNC_VARGSTART                                                    28
#    define FUNC_MOV                                                          29
#    define FUNC_START_OF_DO_WHILE                                            30
#    define FUNC_                                                             31
#    define FUNC_START_OF_DO_WHILE_COMMANDS                                   32
#    define FUNC_END_OF_DO_WHILE                                              33
#    define FUNC_START_OF_FOR                                                 34
#    define FUNC_FOR_INC_DEC                                                  35
#    define FUNC_START_OF_FOR_OMMANDS                                         36
#    define FUNC_IGNORE_LVALUE                                                37
#    define FUNC_END_OF_USER_DEFINED_FUNCTION                                 38
#    define FUNC_RETURN_OF_USER_DEFINED_FUNCTION_WITH_VALUE                   39
#    define FUNC_RETURN_OF_USER_DEFINED_FUNCTION_WITHOUT_VALUE                40
#    define FUNC_CALL_USER_DEFINED_FUNCTION_PARAMETER                         41
#    define FUNC_END_OF_CALLING_USER_DEFINED_FUNCTION_WITHOUT_RETURNING_VALUE 42
#    define FUNC_END_OF_CALLING_USER_DEFINED_FUNCTION_WITH_RETURNING_VALUE    43
#    define FUNC_CALL_USER_DEFINED_FUNCTION                                   44
#    define FUNC_START_OF_USER_DEFINED_FUNCTION                               45
#    define FUNC_MOV_RETURN_VALUE                                             46
#    define FUNC_VOID                                                         47
#    define FUNC_BOOL                                                         48
#    define FUNC_CHAR                                                         49
#    define FUNC_SHORT                                                        50
#    define FUNC_INT                                                          51
#    define FUNC_LONG                                                         52
#    define FUNC_UNSIGNED                                                     53
#    define FUNC_SIGNED                                                       54
#    define FUNC_FLOAT                                                        55
#    define FUNC_DOUBLE                                                       56
#    define FUNC_PRINT                                                        57
#    define FUNC_FORMATS                                                      58
#    define FUNC_EVENT_ENABLE                                                 59
#    define FUNC_EVENT_DISABLE                                                60
#    define FUNC_EVENT_CLEAR                                                  61
#    define FUNC_TEST_STATEMENT                                               62
#    define FUNC_SPINLOCK_LOCK                                                63
#    define FUNC_SPINLOCK_UNLOCK                                              64
#    define FUNC_EVENT_SC                                                     65
#    define FUNC_PRINTF                                                       66
#    define FUNC_PAUSE                                                        67
#    define FUNC_FLUSH                                                        68
#    define FUNC_EVENT_TRACE_STEP                                             69
#    define FUNC_EVENT_TRACE_STEP_IN                                          70
#    define FUNC_EVENT_TRACE_STEP_OUT                                         71
#    define FUNC_EVENT_TRACE_INSTRUMENTATION_STEP                             72
#    define FUNC_EVENT_TRACE_INSTRUMENTATION_STEP_IN                          73
#    define FUNC_SPINLOCK_LOCK_CUSTOM_WAIT                                    74
#    define FUNC_EVENT_INJECT                                                 75
#    define FUNC_POI                                                          76
#    define FUNC_DB                                                           77
#    define FUNC_DD                                                           78
#    define FUNC_DW                                                           79
#    define FUNC_DQ                                                           80
#    define FUNC_NEG                                                          81
#    define FUNC_HI                                                           82
#    define FUNC_LOW                                                          83
#    define FUNC_NOT                                                          84
#    define FUNC_CHECK_ADDRESS                                                85
#    define FUNC_DISASSEMBLE_LEN                                              86
#    define FUNC_DISASSEMBLE_LEN32                                            87
#    define FUNC_DISASSEMBLE_LEN64                                            88
#    define FUNC_INTERLOCKED_INCREMENT                                        89
#    define FUNC_INTERLOCKED_DECREMENT                                        90
#    define FUNC_PHYSICAL_TO_VIRTUAL                                          91
#    define FUNC_VIRTUAL_TO_PHYSICAL                                          92
#    define FUNC_ED                                                           93
#    define FUNC_EB                                                           94
#    define FUNC_EQ                                                           95
#    define FUNC_INTERLOCKED_EXCHANGE                                         96
#    define FUNC_INTERLOCKED_EXCHANGE_ADD                                     97
#    define FUNC_INTERLOCKED_COMPARE_EXCHANGE                                 98
#    define FUNC_STRLEN                                                       99
#    define FUNC_STRCMP                                                       100
#    define FUNC_MEMCMP                                                       101
#    define FUNC_STRNCMP                                                      102
#    define FUNC_WCSNCMP                                                      103
#    define FUNC_WCSLEN                                                       104
#    define FUNC_WCSCMP                                                       105
#    define FUNC_EVENT_INJECT_ERROR_CODE                                      106
#    define FUNC_MEMCPY                                                       107

typedef enum REGS_ENUM {
	REGISTER_RAX = 0,
	REGISTER_EAX = 1,
	REGISTER_AX = 2,
	REGISTER_AH = 3,
	REGISTER_AL = 4,
	REGISTER_RCX = 5,
	REGISTER_ECX = 6,
	REGISTER_CX = 7,
	REGISTER_CH = 8,
	REGISTER_CL = 9,
	REGISTER_RDX = 10,
	REGISTER_EDX = 11,
	REGISTER_DX = 12,
	REGISTER_DH = 13,
	REGISTER_DL = 14,
	REGISTER_RBX = 15,
	REGISTER_EBX = 16,
	REGISTER_BX = 17,
	REGISTER_BH = 18,
	REGISTER_BL = 19,
	REGISTER_RSP = 20,
	REGISTER_ESP = 21,
	REGISTER_SP = 22,
	REGISTER_SPL = 23,
	REGISTER_RBP = 24,
	REGISTER_EBP = 25,
	REGISTER_BP = 26,
	REGISTER_BPL = 27,
	REGISTER_RSI = 28,
	REGISTER_ESI = 29,
	REGISTER_SI = 30,
	REGISTER_SIL = 31,
	REGISTER_RDI = 32,
	REGISTER_EDI = 33,
	REGISTER_DI = 34,
	REGISTER_DIL = 35,
	REGISTER_R8 = 36,
	REGISTER_R8D = 37,
	REGISTER_R8W = 38,
	REGISTER_R8H = 39,
	REGISTER_R8L = 40,
	REGISTER_R9 = 41,
	REGISTER_R9D = 42,
	REGISTER_R9W = 43,
	REGISTER_R9H = 44,
	REGISTER_R9L = 45,
	REGISTER_R10 = 46,
	REGISTER_R10D = 47,
	REGISTER_R10W = 48,
	REGISTER_R10H = 49,
	REGISTER_R10L = 50,
	REGISTER_R11 = 51,
	REGISTER_R11D = 52,
	REGISTER_R11W = 53,
	REGISTER_R11H = 54,
	REGISTER_R11L = 55,
	REGISTER_R12 = 56,
	REGISTER_R12D = 57,
	REGISTER_R12W = 58,
	REGISTER_R12H = 59,
	REGISTER_R12L = 60,
	REGISTER_R13 = 61,
	REGISTER_R13D = 62,
	REGISTER_R13W = 63,
	REGISTER_R13H = 64,
	REGISTER_R13L = 65,
	REGISTER_R14 = 66,
	REGISTER_R14D = 67,
	REGISTER_R14W = 68,
	REGISTER_R14H = 69,
	REGISTER_R14L = 70,
	REGISTER_R15 = 71,
	REGISTER_R15D = 72,
	REGISTER_R15W = 73,
	REGISTER_R15H = 74,
	REGISTER_R15L = 75,
	REGISTER_DS = 76,
	REGISTER_ES = 77,
	REGISTER_FS = 78,
	REGISTER_GS = 79,
	REGISTER_CS = 80,
	REGISTER_SS = 81,
	REGISTER_RFLAGS = 82,
	REGISTER_EFLAGS = 83,
	REGISTER_FLAGS = 84,
	REGISTER_CF = 85,
	REGISTER_PF = 86,
	REGISTER_AF = 87,
	REGISTER_ZF = 88,
	REGISTER_SF = 89,
	REGISTER_TF = 90,
	REGISTER_IF = 91,
	REGISTER_DF = 92,
	REGISTER_OF = 93,
	REGISTER_IOPL = 94,
	REGISTER_NT = 95,
	REGISTER_RF = 96,
	REGISTER_VM = 97,
	REGISTER_AC = 98,
	REGISTER_VIF = 99,
	REGISTER_VIP = 100,
	REGISTER_ID = 101,
	REGISTER_RIP = 102,
	REGISTER_EIP = 103,
	REGISTER_IP = 104,
	REGISTER_IDTR = 105,
	REGISTER_LDTR = 106,
	REGISTER_GDTR = 107,
	REGISTER_TR = 108,
	REGISTER_CR0 = 109,
	REGISTER_CR2 = 110,
	REGISTER_CR3 = 111,
	REGISTER_CR4 = 112,
	REGISTER_CR8 = 113,
	REGISTER_DR0 = 114,
	REGISTER_DR1 = 115,
	REGISTER_DR2 = 116,
	REGISTER_DR3 = 117,
	REGISTER_DR6 = 118,
	REGISTER_DR7 = 119

} REGS_ENUM;

static const char *const RegistersNames[] = {
"rax", "eax", "ax", "ah", "al", "rcx", "ecx", "cx",
"ch", "cl", "rdx", "edx", "dx", "dh", "dl", "rbx",
"ebx", "bx", "bh", "bl", "rsp", "esp", "sp", "spl",
"rbp", "ebp", "bp", "bpl", "rsi", "esi", "si", "sil",
"rdi", "edi", "di", "dil", "r8", "r8d", "r8w", "r8h",
"r8l", "r9", "r9d", "r9w", "r9h", "r9l", "r10", "r10d",
"r10w", "r10h", "r10l", "r11", "r11d", "r11w", "r11h", "r11l",
"r12", "r12d", "r12w", "r12h", "r12l", "r13", "r13d", "r13w",
"r13h", "r13l", "r14", "r14d", "r14w", "r14h", "r14l", "r15",
"r15d", "r15w", "r15h", "r15l", "ds", "es", "fs", "gs",
"cs", "ss", "rflags", "eflags", "flags", "cf", "pf", "af",
"zf", "sf", "tf", "if", "df", "of", "iopl", "nt",
"rf", "vm", "ac", "vif", "vip", "id", "rip", "eip",
"ip", "idtr", "ldtr", "gdtr", "tr", "cr0", "cr2", "cr3",
"cr4", "cr8", "dr0", "dr1", "dr2", "dr3", "dr6", 	"dr7"
};

#define PSEUDO_REGISTER_PID 0
#define PSEUDO_REGISTER_TID 1
#define PSEUDO_REGISTER_PNAME 2
#define PSEUDO_REGISTER_CORE 3
#define PSEUDO_REGISTER_PROC 4
#define PSEUDO_REGISTER_THREAD 5
#define PSEUDO_REGISTER_PEB 6
#define PSEUDO_REGISTER_TEB 7
#define PSEUDO_REGISTER_IP 8
#define PSEUDO_REGISTER_BUFFER 9
#define PSEUDO_REGISTER_CONTEXT 10
#define PSEUDO_REGISTER_EVENT_TAG 11
#define PSEUDO_REGISTER_EVENT_ID 12
#define PSEUDO_REGISTER_EVENT_STAGE 13

#endif
