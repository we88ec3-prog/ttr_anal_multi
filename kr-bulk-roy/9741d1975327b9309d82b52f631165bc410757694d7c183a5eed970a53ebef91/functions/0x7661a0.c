
void FUN_007661a0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091cc2b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = *(int *)(param_1 + 0x114);
  iVar2 = *(int *)(param_1 + 0x110);
  iVar3 = FUN_00891268(0x38,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  uVar4 = 0;
  local_8 = 0;
  if (iVar3 != 0) {
    uVar4 = FUN_00757200(iVar3);
  }
  local_8 = 0xffffffff;
  FUN_00405300(uVar4);
  FUN_00757da0(uVar4);
  FUN_007bb350();
  FUN_00766390(iVar1 - iVar2 >> 2,0,0);
  FUN_00767fa0();
  ExceptionList = local_10;
  return;
}

