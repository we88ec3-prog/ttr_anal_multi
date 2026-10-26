
void FUN_0047f2d0(void)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  short *psVar4;
  int in_ECX;
  short *psVar5;
  undefined4 local_34;
  undefined4 local_24;
  uint local_20;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b2f6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  iVar3 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_0047f335;
    iVar3 = FUN_00745c20();
  }
  if ((((iVar3 != 0) && (*(int *)(iVar3 + 0x60) != 0)) &&
      ((*(uint *)(iVar3 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar3 + 0x60) != 0)) {
    FUN_0074a010(iVar3);
  }
LAB_0047f335:
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_14 = 0x345;
  FUN_005740f0(&local_14);
  if (local_18 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  psVar5 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar5 = *(short **)psVar5;
  }
  local_34 = (uint)local_34._2_2_ << 0x10;
  local_20 = 7;
  local_24 = 0;
  psVar4 = psVar5;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar4 - (int)(psVar5 + 1) >> 1);
  iVar3 = *(int *)(in_ECX + 0x100);
  local_8 = 1;
  FUN_007578f0();
  FUN_00759ed0(iVar3 + 0xe8,&local_34,0x7b,0x7d);
  local_8 = 0xffffffff;
  if (7 < local_20) {
    FUN_0089120c(local_34);
  }
  local_34 = local_34 & 0xffff0000;
  local_20 = 7;
  local_24 = 0;
  (**(code **)(**(int **)(in_ECX + 0x100) + 200))();
  ExceptionList = local_10;
  return;
}

