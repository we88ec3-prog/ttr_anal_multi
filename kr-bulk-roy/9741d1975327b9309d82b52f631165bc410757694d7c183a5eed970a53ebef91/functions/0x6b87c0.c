
/* WARNING: Removing unreachable block (ram,0x006b8946) */

void FUN_006b87c0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009357de;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_c = 1;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c._0_1_ = 2;
    local_c._1_3_ = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffc0);
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = CONCAT31(local_c._1_3_,1);
  }
  piVar1 = (int *)(in_ECX + 0x9c);
  if (*(int *)(DAT_00fab130 + 0x5ef8) == 0) {
    FUN_005adc60();
  }
  else {
    FUN_005c2e20();
  }
  FUN_005a9f40(piVar1);
  FUN_006b9040();
  FUN_005a9f40(in_ECX + 0xa0);
  FUN_006b9120();
  FUN_005a9f40(in_ECX + 0xa4);
  FUN_006b9200();
  FUN_005a9f40(in_ECX + 0xa8);
  FUN_006b92e0();
  FUN_005a9f40((int *)(in_ECX + 0xac));
  FUN_006b93c0();
  FUN_005a9f40((int *)(in_ECX + 0xb0));
  FUN_0040b670(in_ECX);
  iVar2 = *(int *)(in_ECX + 0xac);
  if (*(int *)(iVar2 + 0x60) != 0) {
    FUN_00749f40(iVar2);
  }
  iVar2 = *(int *)(in_ECX + 0xb0);
  if (*(int *)(iVar2 + 0x60) != 0) {
    FUN_00749f40(iVar2);
  }
  iVar2 = *piVar1;
  *(uint *)(iVar2 + 0x28) = *(uint *)(iVar2 + 0x28) | 0x10;
  if ((*(uint *)(iVar2 + 0x28) & 0x20) != 0) {
    *(uint *)(iVar2 + 0x28) = *(uint *)(iVar2 + 0x28) ^ 0x20;
  }
  if ((*(uint *)(iVar2 + 0x28) & 0x40) != 0) {
    *(uint *)(iVar2 + 0x28) = *(uint *)(iVar2 + 0x28) ^ 0x40;
  }
  (**(code **)(*(int *)*piVar1 + 0xd0))();
  ExceptionList = local_14;
  return;
}

