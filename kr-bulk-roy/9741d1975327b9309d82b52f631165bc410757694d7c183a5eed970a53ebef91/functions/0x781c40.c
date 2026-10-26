
void FUN_00781c40(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091c0db;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_00891268(0xb0,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_007816a0(iVar1,param_1,param_2,0);
  }
  local_8 = 0xffffffff;
  unaff_ESI[0x21] = iVar1;
  (**(code **)(*unaff_ESI + 4))();
  ExceptionList = local_10;
  return;
}

