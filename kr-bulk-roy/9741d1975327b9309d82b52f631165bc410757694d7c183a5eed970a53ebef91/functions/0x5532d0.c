
void FUN_005532d0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916d49;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_00891268(0x68,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (iVar1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00553e90(iVar1,0x3c,0x14,0);
  }
  if ((DAT_00fb7354 & 1) == 0) {
    DAT_00fb7354 = DAT_00fb7354 | 1;
    local_8 = 1;
    FUN_005533d0();
    _atexit((_func_4879 *)&LAB_00bcd100);
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar2 + 4))();
  (**(code **)(*piVar2 + 0x20))(DAT_00fb73ac,DAT_00fb73b0);
  piVar2[0x10] = 0;
  uVar3 = FUN_0057ef20();
  FUN_0082f200(&DAT_00fb7378,uVar3);
  DAT_00fb7398 = DAT_00fb7398 + 1;
  ExceptionList = local_10;
  return;
}

