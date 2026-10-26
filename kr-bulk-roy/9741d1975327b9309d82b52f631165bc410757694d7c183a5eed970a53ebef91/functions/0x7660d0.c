
void FUN_007660d0(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091cc2b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_3 < (uint)(*(int *)(param_1 + 0x114) - *(int *)(param_1 + 0x110) >> 2)) {
    FUN_00757da0(*(undefined4 *)(*(int *)(param_1 + 0x110) + param_3 * 4));
  }
  else {
    iVar1 = FUN_00891268(0x38,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    local_8 = 0;
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_00757200(iVar1);
    }
    local_8 = 0xffffffff;
    FUN_00757da0(uVar2);
    FUN_007bb350();
  }
  FUN_00766390(param_3,0,0);
  ExceptionList = local_10;
  return;
}

