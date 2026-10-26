
void FUN_004a9c80(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091b689;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = (int *)FUN_00891268(0x74,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    FUN_00553c90(piVar1,param_1);
    *piVar1 = (int)CScalingObject::vftable;
    piVar1[0x19] = param_2;
    piVar1[0x1a] = param_3;
    piVar1[0x1b] = 0;
    piVar1[0x1c] = 0;
  }
  local_8 = 0xffffffff;
  param_1 = piVar1;
  uVar2 = FUN_006bde40(&param_1);
  FUN_0044bbd0(in_ECX + 0x14,uVar2);
  if ((DAT_00fb7354 & 1) == 0) {
    DAT_00fb7354 = DAT_00fb7354 | 1;
    local_8 = 1;
    FUN_005533d0();
    _atexit((_func_4879 *)&LAB_00bcd100);
    local_8 = 0xffffffff;
  }
  (**(code **)(*piVar1 + 4))();
  (**(code **)(*piVar1 + 0x20))(DAT_00fb73ac,DAT_00fb73b0);
  piVar1[0x10] = 0;
  uVar2 = FUN_0057ef20();
  FUN_0082f200(&DAT_00fb7358,uVar2);
  DAT_00fb7398 = DAT_00fb7398 + 1;
  ExceptionList = local_10;
  return;
}

