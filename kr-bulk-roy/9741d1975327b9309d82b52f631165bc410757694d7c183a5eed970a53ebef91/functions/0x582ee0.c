
void FUN_00582ee0(void)

{
  code *pcVar1;
  int iVar2;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090fd94;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
  }
  local_8 = 0xffffffff;
  local_14 = 0x38;
  FUN_005740f0(&local_14);
  if (local_18 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d65c14 = (undefined *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    PTR_DAT_00d65c14 = *(undefined **)PTR_DAT_00d65c14;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 1;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x39;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d65c18 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d65c18 = *(undefined **)PTR_DAT_00d65c18;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 2;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x3a;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d65c1c = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d65c1c = *(undefined **)PTR_DAT_00d65c1c;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 3;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x3b;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a0d4 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a0d4 = *(undefined **)PTR_DAT_00d6a0d4;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 4;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x3c;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a0d8 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a0d8 = *(undefined **)PTR_DAT_00d6a0d8;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 5;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x3e;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a0dc = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a0dc = *(undefined **)PTR_DAT_00d6a0dc;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 6;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x3f;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a0e0 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a0e0 = *(undefined **)PTR_DAT_00d6a0e0;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 7;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x40;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a0e4 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a0e4 = *(undefined **)PTR_DAT_00d6a0e4;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 8;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x41;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a0e8 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a0e8 = *(undefined **)PTR_DAT_00d6a0e8;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 9;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x42;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a0ec = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a0ec = *(undefined **)PTR_DAT_00d6a0ec;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 10;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x43;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a0f0 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a0f0 = *(undefined **)PTR_DAT_00d6a0f0;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0xb;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x44;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a0f4 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a0f4 = *(undefined **)PTR_DAT_00d6a0f4;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0xc;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x45;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a0f8 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a0f8 = *(undefined **)PTR_DAT_00d6a0f8;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0xd;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x47;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a0fc = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a0fc = *(undefined **)PTR_DAT_00d6a0fc;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0xe;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x48;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a100 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a100 = *(undefined **)PTR_DAT_00d6a100;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0xf;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x3b;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d672dc = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d672dc = *(undefined **)PTR_DAT_00d672dc;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x10;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x49;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d672e0 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d672e0 = *(undefined **)PTR_DAT_00d672e0;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x11;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x4a;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d672e4 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d672e4 = *(undefined **)PTR_DAT_00d672e4;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x12;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x4b;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d672e8 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d672e8 = *(undefined **)PTR_DAT_00d672e8;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x13;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x4c;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d672ec = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d672ec = *(undefined **)PTR_DAT_00d672ec;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x14;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x4d;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a104 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a104 = *(undefined **)PTR_DAT_00d6a104;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x15;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x4e;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a108 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a108 = *(undefined **)PTR_DAT_00d6a108;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x16;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x4f;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a10c = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a10c = *(undefined **)PTR_DAT_00d6a10c;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x17;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x50;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a110 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a110 = *(undefined **)PTR_DAT_00d6a110;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x18;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x51;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a114 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a114 = *(undefined **)PTR_DAT_00d6a114;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x19;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x52;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a118 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a118 = *(undefined **)PTR_DAT_00d6a118;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x1a;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x53;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a11c = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a11c = *(undefined **)PTR_DAT_00d6a11c;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x1b;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x54;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a120 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a120 = *(undefined **)PTR_DAT_00d6a120;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x1c;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x55;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a124 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a124 = *(undefined **)PTR_DAT_00d6a124;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x1d;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x56;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a128 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a128 = *(undefined **)PTR_DAT_00d6a128;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x1e;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x57;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_u______00d6a12c = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_u______00d6a12c = *(undefined **)PTR_u______00d6a12c;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x1f;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x58;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a130 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a130 = *(undefined **)PTR_DAT_00d6a130;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x20;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x59;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a134 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a134 = *(undefined **)PTR_DAT_00d6a134;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x21;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x5a;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a138 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a138 = *(undefined **)PTR_DAT_00d6a138;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x22;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x5b;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a13c = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a13c = *(undefined **)PTR_DAT_00d6a13c;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x23;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x5c;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a140 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a140 = *(undefined **)PTR_DAT_00d6a140;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x24;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x5d;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a144 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a144 = *(undefined **)PTR_DAT_00d6a144;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x25;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x5e;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a148 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a148 = *(undefined **)PTR_DAT_00d6a148;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x26;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x5f;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a14c = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a14c = *(undefined **)PTR_DAT_00d6a14c;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x27;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x60;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a150 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a150 = *(undefined **)PTR_DAT_00d6a150;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x28;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x61;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a154 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a154 = *(undefined **)PTR_DAT_00d6a154;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x29;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x62;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a158 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a158 = *(undefined **)PTR_DAT_00d6a158;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x2a;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 99;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a15c = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a15c = *(undefined **)PTR_DAT_00d6a15c;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x2b;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x1dc;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a1c8 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a1c8 = *(undefined **)PTR_DAT_00d6a1c8;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x2c;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x1dd;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a1cc = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a1cc = *(undefined **)PTR_DAT_00d6a1cc;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x2d;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x1df;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a1d0 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a1d0 = *(undefined **)PTR_DAT_00d6a1d0;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x2e;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x1e0;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a1d4 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a1d4 = *(undefined **)PTR_DAT_00d6a1d4;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x2f;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x1e1;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a1d8 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a1d8 = *(undefined **)PTR_DAT_00d6a1d8;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x30;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x1e2;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a1dc = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a1dc = *(undefined **)PTR_DAT_00d6a1dc;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x31;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x1e3;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a1e0 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a1e0 = *(undefined **)PTR_DAT_00d6a1e0;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x32;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x1e4;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a1e4 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a1e4 = *(undefined **)PTR_DAT_00d6a1e4;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x33;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x1e5;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a1e8 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a1e8 = *(undefined **)PTR_DAT_00d6a1e8;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x34;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x1f1;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a18c = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a18c = *(undefined **)PTR_DAT_00d6a18c;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x35;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x1f2;
  FUN_005740f0(&local_18);
  if (local_14 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  PTR_DAT_00d6a190 = (undefined *)(local_14 + 0x10);
  if (7 < *(uint *)(local_14 + 0x24)) {
    PTR_DAT_00d6a190 = *(undefined **)PTR_DAT_00d6a190;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x36;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 499;
  FUN_005740f0(&local_18);
  if (local_14 != DAT_00fe5ac8) {
    PTR_DAT_00d6a194 = (undefined *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      PTR_DAT_00d6a194 = *(undefined **)PTR_DAT_00d6a194;
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 0x37;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_18 = 500;
    FUN_005740f0(&local_18);
    if (local_14 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    PTR_DAT_00d6a198 = (undefined *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      PTR_DAT_00d6a198 = *(undefined **)PTR_DAT_00d6a198;
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 0x38;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_18 = 0x1f5;
    FUN_005740f0(&local_18);
    if (local_14 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    PTR_DAT_00d6a19c = (undefined *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      PTR_DAT_00d6a19c = *(undefined **)PTR_DAT_00d6a19c;
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 0x39;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_18 = 0x1f6;
    FUN_005740f0(&local_18);
    if (local_14 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    PTR_DAT_00d6a1a0 = (undefined *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      PTR_DAT_00d6a1a0 = *(undefined **)PTR_DAT_00d6a1a0;
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 0x3a;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_18 = 0x1f7;
    FUN_005740f0(&local_18);
    if (local_14 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    PTR_DAT_00d6a1a4 = (undefined *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      PTR_DAT_00d6a1a4 = *(undefined **)PTR_DAT_00d6a1a4;
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 0x3b;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_18 = 0x1f8;
    FUN_005740f0(&local_18);
    if (local_14 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    PTR_DAT_00d6a1a8 = (undefined *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      PTR_DAT_00d6a1a8 = *(undefined **)PTR_DAT_00d6a1a8;
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 0x3c;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_18 = 0x1fd;
    FUN_005740f0(&local_18);
    if (local_14 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    PTR_DAT_00d6a1ac = (undefined *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      PTR_DAT_00d6a1ac = *(undefined **)PTR_DAT_00d6a1ac;
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 0x3d;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_18 = 0x1fe;
    FUN_005740f0(&local_18);
    if (local_14 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    PTR_DAT_00d6a1b0 = (undefined *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      PTR_DAT_00d6a1b0 = *(undefined **)PTR_DAT_00d6a1b0;
    }
    local_18 = 0x1ff;
    iVar2 = FUN_00585620();
    FUN_005740f0(&local_18);
    if (local_14 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    PTR_DAT_00d6a1b4 = (undefined *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      PTR_DAT_00d6a1b4 = *(undefined **)PTR_DAT_00d6a1b4;
    }
    local_18 = 0x200;
    iVar2 = FUN_00585620();
    FUN_005740f0(&local_18);
    if (local_14 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    PTR_DAT_00d6a1b8 = (undefined *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      PTR_DAT_00d6a1b8 = *(undefined **)PTR_DAT_00d6a1b8;
    }
    local_18 = 0x201;
    iVar2 = FUN_00585620();
    FUN_005740f0(&local_18);
    if (local_14 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    PTR_DAT_00d6a1bc = (undefined *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      PTR_DAT_00d6a1bc = *(undefined **)PTR_DAT_00d6a1bc;
    }
    local_18 = 0x202;
    iVar2 = FUN_00585620();
    FUN_005740f0(&local_18);
    if (local_14 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    PTR_DAT_00d6a1c0 = (undefined *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      PTR_DAT_00d6a1c0 = *(undefined **)PTR_DAT_00d6a1c0;
    }
    local_18 = 0x76;
    iVar2 = FUN_00585620();
    FUN_005740f0(&local_18);
    if (local_14 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    PTR_u_Normal_00d6a208 = (undefined *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      PTR_u_Normal_00d6a208 = *(undefined **)PTR_u_Normal_00d6a208;
    }
    local_18 = 0x77;
    iVar2 = FUN_00585620();
    FUN_005740f0(&local_18);
    if (local_14 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    PTR_u_Hard_00d6a20c = (undefined *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      PTR_u_Hard_00d6a20c = *(undefined **)PTR_u_Hard_00d6a20c;
    }
    local_18 = 0x78;
    iVar2 = FUN_00585620();
    FUN_005740f0(&local_18);
    if (local_14 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    PTR_u_Expert_00d6a210 = (undefined *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      PTR_u_Expert_00d6a210 = *(undefined **)PTR_u_Expert_00d6a210;
    }
    local_18 = 0x79;
    iVar2 = FUN_00585620();
    FUN_005740f0(&local_18);
    if (local_14 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    PTR_u_Master_00d6a214 = (undefined *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      PTR_u_Master_00d6a214 = *(undefined **)PTR_u_Master_00d6a214;
    }
    local_18 = 299;
    iVar2 = FUN_00585620();
    FUN_005740f0(&local_18);
    if (local_14 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    PTR_DAT_00d6a218 = (undefined *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      PTR_DAT_00d6a218 = *(undefined **)PTR_DAT_00d6a218;
    }
    local_18 = 300;
    iVar2 = FUN_00585620();
    FUN_005740f0(&local_18);
    if (local_14 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    PTR_DAT_00d6a21c = (undefined *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      PTR_DAT_00d6a21c = *(undefined **)PTR_DAT_00d6a21c;
    }
    local_18 = 0x12d;
    iVar2 = FUN_00585620();
    FUN_005740f0(&local_18);
    if (local_14 == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    PTR_DAT_00d6a220 = (undefined *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      PTR_DAT_00d6a220 = *(undefined **)PTR_DAT_00d6a220;
    }
    local_18 = 0x12e;
    iVar2 = FUN_00585620();
    FUN_005740f0(&local_18);
    if (local_14 != *(int *)(iVar2 + 4)) {
      PTR_DAT_00d6a224 = (undefined *)(local_14 + 0x10);
      if (7 < *(uint *)(local_14 + 0x24)) {
        PTR_DAT_00d6a224 = *(undefined **)PTR_DAT_00d6a224;
      }
      local_18 = 0x12f;
      iVar2 = FUN_00585620();
      FUN_005740f0(&local_18);
      if (local_14 != *(int *)(iVar2 + 4)) {
        PTR_DAT_00d6a228 = (undefined *)(local_14 + 0x10);
        if (7 < *(uint *)(local_14 + 0x24)) {
          PTR_DAT_00d6a228 = *(undefined **)PTR_DAT_00d6a228;
        }
        local_18 = 0x130;
        iVar2 = FUN_00585620();
        FUN_005740f0(&local_18);
        if (local_14 != *(int *)(iVar2 + 4)) {
          PTR_DAT_00d6a22c = (undefined *)(local_14 + 0x10);
          if (7 < *(uint *)(local_14 + 0x24)) {
            PTR_DAT_00d6a22c = *(undefined **)PTR_DAT_00d6a22c;
          }
          ExceptionList = local_10;
          return;
        }
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

