typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned int    pointer;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned long long    qword;
typedef char    sbyte;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined3;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined6;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    wchar16;
typedef unsigned short    word;
typedef struct Remocon Remocon, *PRemocon;

typedef struct RemoconVftable RemoconVftable, *PRemoconVftable;

typedef ulong u32;

struct Remocon { /* PlaceHolder Class Structure */
    struct RemoconVftable * vftable;
    undefined4 field_0x4;
    undefined4 field_0x8;
    u32 hold; /* Created by retype action */
    u32 prevHold; /* Created by retype action */
    u32 heldButtons; /* Created by retype action */
    u32 prevHeldButtons; /* Created by retype action */
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    undefined field_0x20;
    undefined field_0x21;
    undefined field_0x22;
    undefined field_0x23;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    undefined field_0x28;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    undefined field_0x30;
    undefined field_0x31;
    undefined field_0x32;
    undefined field_0x33;
    float accX; /* Created by retype action */
    float accY; /* Created by retype action */
    float accZ; /* Created by retype action */
    float prevAccX; /* Created by retype action */
    float prevAccY; /* Created by retype action */
    float prevAccZ; /* Created by retype action */
    float field_0x4c;
    float field_0x50;
    float field_0x54;
    float field_0x58;
    float field_0x5c;
    float field_0x60;
    float field_0x64;
    float field_0x68;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    undefined field_0x70;
    undefined field_0x71;
    undefined field_0x72;
    undefined field_0x73;
    float field_0x74;
    float field_0x78;
    float field_0x7c;
    float field_0x80;
    float field_0x84;
    float field_0x88;
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    undefined field_0x90;
    undefined field_0x91;
    undefined field_0x92;
    undefined field_0x93;
};

struct RemoconVftable {
    pointer field_0x0;
    pointer field_0x4;
    pointer field_0x8;
};

typedef struct RemoconMgr RemoconMgr, *PRemoconMgr;

typedef struct RemoconMgrVftable RemoconMgrVftable, *PRemoconMgrVftable;

struct RemoconMgr { /* PlaceHolder Class Structure */
    struct RemoconMgrVftable * vftable;
    struct Remocon * p1;
    struct Remocon * p2;
    struct Remocon * p3;
    struct Remocon * p4;
};

struct RemoconMgrVftable {
    pointer field_0x0;
    pointer field_0x4;
    pointer field_0x8;
};

