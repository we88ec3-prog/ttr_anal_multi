
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0073f770(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00907ecb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar2 = FUN_0073fa20(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar2 == 0) {
    param_1 = FUN_00891268(0x2c);
    local_8 = 0;
    if (param_1 != 0) {
      FUN_0073fd00(param_1,*in_ECX,in_ECX[3],in_ECX[4]);
    }
    local_8 = 0xffffffff;
    *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
    uVar3 = FUN_0057ef20();
    FUN_0057e850(iVar1,uVar3);
    ExceptionList = local_10;
    return *(int *)(iVar1 + 0x10) + -1;
  }
  param_1 = iVar2;
  FUN_008438c0(&param_1);
  if (local_18 == *(int *)(iVar1 + 4)) {
    (*(code *)*_DAT_00000000)();
    ExceptionList = local_10;
    return iVar2;
  }
  (**(code **)**(undefined4 **)(local_18 + 0x10))();
  ExceptionList = local_10;
  return iVar2;
}

