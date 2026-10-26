
void FUN_0062c0b0(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  undefined4 in_ECX;
  int iVar3;
  int iVar4;
  undefined4 *local_24;
  int local_20;
  int local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00935e4e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_0062c590(in_ECX,0xd);
  FUN_0062c590(in_ECX,0xe);
  FUN_0062c590(in_ECX,0xf);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = 0xffffffff;
  }
  local_20 = 0xa3;
  FUN_005740f0(&local_20);
  if (local_1c[0] == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (*(uint *)(local_1c[0] + 0x24) < 8) {
    iVar3 = local_1c[0] + 0x10;
  }
  else {
    iVar3 = *(int *)(local_1c[0] + 0x10);
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c = 1;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = 0xffffffff;
  }
  local_1c[0] = 0x8c;
  FUN_005740f0(local_1c);
  if (local_20 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (*(uint *)(local_20 + 0x24) < 8) {
    iVar4 = local_20 + 0x10;
  }
  else {
    iVar4 = *(int *)(local_20 + 0x10);
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c = 2;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = 0xffffffff;
  }
  local_1c[0] = 0x8c;
  FUN_005740f0(local_1c);
  if (local_20 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  puVar2 = (undefined4 *)(local_20 + 0x10);
  if (7 < *(uint *)(local_20 + 0x24)) {
    puVar2 = (undefined4 *)*puVar2;
  }
  FUN_0062a730(puVar2,iVar4,iVar3);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c = 3;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = 0xffffffff;
  }
  local_1c[0] = 0xa4;
  FUN_005740f0(local_1c);
  if (local_20 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (*(uint *)(local_20 + 0x24) < 8) {
    iVar3 = local_20 + 0x10;
  }
  else {
    iVar3 = *(int *)(local_20 + 0x10);
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c = 4;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = 0xffffffff;
  }
  local_1c[0] = 0x8d;
  FUN_005740f0(local_1c);
  if (local_20 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (*(uint *)(local_20 + 0x24) < 8) {
    iVar4 = local_20 + 0x10;
  }
  else {
    iVar4 = *(int *)(local_20 + 0x10);
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c = 5;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = 0xffffffff;
  }
  local_1c[0] = 0x8d;
  FUN_005740f0(local_1c);
  if (local_20 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  puVar2 = (undefined4 *)(local_20 + 0x10);
  if (7 < *(uint *)(local_20 + 0x24)) {
    puVar2 = (undefined4 *)*puVar2;
  }
  FUN_0062a730(puVar2,iVar4,iVar3);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c = 6;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = 0xffffffff;
  }
  local_1c[0] = 0xa5;
  FUN_005740f0(local_1c);
  if (local_20 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  local_24 = (undefined4 *)(local_20 + 0x10);
  if (7 < *(uint *)(local_20 + 0x24)) {
    local_24 = (undefined4 *)*local_24;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c = 7;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = 0xffffffff;
  }
  local_1c[0] = 0x8e;
  FUN_005740f0(local_1c);
  if (local_20 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (*(uint *)(local_20 + 0x24) < 8) {
    iVar3 = local_20 + 0x10;
  }
  else {
    iVar3 = *(int *)(local_20 + 0x10);
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c = 8;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = 0xffffffff;
  }
  local_1c[0] = 0x8e;
  FUN_005740f0(local_1c);
  if (local_20 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  puVar2 = (undefined4 *)(local_20 + 0x10);
  if (7 < *(uint *)(local_20 + 0x24)) {
    puVar2 = (undefined4 *)*puVar2;
  }
  FUN_0062a730(puVar2,iVar3,local_24);
  FUN_0062c590(in_ECX,0x10);
  FUN_0062c590(in_ECX,0x16);
  FUN_0062c590(in_ECX,0x11);
  FUN_0062c590(in_ECX,0x12);
  FUN_0062c590(in_ECX,0x13);
  FUN_0062c590(in_ECX,0x14);
  FUN_0062c590(in_ECX,0x1b);
  FUN_0062c590(in_ECX,0x17);
  FUN_0062c590(in_ECX,0x26);
  ExceptionList = local_14;
  return;
}

