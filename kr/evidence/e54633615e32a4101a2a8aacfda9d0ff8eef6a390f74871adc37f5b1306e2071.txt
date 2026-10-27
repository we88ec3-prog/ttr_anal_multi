
void FUN_004b3c10(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *piStack_44;
  uint local_40;
  undefined4 uStack_30;
  uint uStack_2c;
  uint uStack_24;
  void *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00930c7f;
  local_14 = ExceptionList;
  local_1c = (void *)(DAT_00d61f20 ^ (uint)&piStack_44);
  ExceptionList = &local_14;
  local_40 = FUN_00891268(0x58,DAT_00d61f20 ^ (uint)&stack0xffffffb0);
  local_c = 0;
  if (local_40 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)FUN_00540250(*(undefined2 *)(param_1 + 2));
  }
  if ((DAT_00fb7354 & 1) == 0) {
    DAT_00fb7354 = DAT_00fb7354 | 1;
    local_c = 1;
    FUN_005533d0();
    _atexit((_func_4879 *)&LAB_00bcd100);
  }
  local_c = 0xffffffff;
  (**(code **)(*piVar1 + 4))();
  (**(code **)(*piVar1 + 0x20))(DAT_00fb73ac,DAT_00fb73b0);
  piVar1[0x10] = 0;
  piStack_44 = piVar1;
  uVar2 = FUN_0057ef20();
  FUN_0082f200(&DAT_00fb7378,uVar2);
  DAT_00fb7398 = DAT_00fb7398 + 1;
  uStack_2c = 0xf;
  uStack_30 = 0;
  local_40 = local_40 & 0xffffff00;
  FUN_0040b310("TRIGGER_MESSAGE");
  local_14 = (void *)0x2;
  if ((DAT_00fab0d4 & 1) == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_14._0_1_ = 3;
    local_14._1_3_ = 0;
    FUN_0080a3a0();
    _atexit((_func_4879 *)&LAB_00bccdd0);
    local_14 = (void *)CONCAT31(local_14._1_3_,2);
  }
  piVar1 = (int *)FUN_0080ab00(&DAT_00fab028);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x14))();
  }
  if (0xf < uStack_2c) {
    FUN_0089120c(local_40);
  }
  ExceptionList = local_1c;
  __security_check_cookie(uStack_24 ^ (uint)&stack0xffffffb4);
  return;
}

