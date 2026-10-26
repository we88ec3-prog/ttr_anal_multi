
int * FUN_00423850(void)

{
  int iVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091e649;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00fb7464 == (int *)0x0) {
    iVar1 = FUN_00891268(0x10,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    local_8 = 0;
    if (iVar1 == 0) {
      DAT_00fb7464 = (int *)0x0;
    }
    else {
      DAT_00fb7464 = (int *)FUN_00423c20(iVar1);
    }
    if ((DAT_00faafd4 & 1) == 0) {
      DAT_00faafd4 = DAT_00faafd4 | 1;
      local_8 = 1;
      FUN_0044dfb0();
      _atexit(FUN_00bccd10);
    }
    local_8 = 0xffffffff;
    (**(code **)(*DAT_00fb7464 + 0x10))();
    uVar2 = FUN_0057ef20();
    FUN_0082f200(&DAT_00faafec,uVar2);
  }
  ExceptionList = local_10;
  return DAT_00fb7464;
}

