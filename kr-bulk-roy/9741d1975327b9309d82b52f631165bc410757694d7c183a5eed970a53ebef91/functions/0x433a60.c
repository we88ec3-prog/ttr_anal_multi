
undefined4 FUN_00433a60(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 in_ECX;
  int in_EDX;
  undefined4 *puVar3;
  _Lockit local_1c [4];
  uint local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908b59;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18[1] = 0;
  FUN_004338a0(param_1,in_ECX);
  local_8 = 0;
  local_18[1] = 1;
  if (*(int *)(in_EDX + 0x38) != 0) {
    FUN_004339d0(local_18,in_ECX);
    if (local_18[0] != 0) {
      std::_Lockit::_Lockit(local_1c,0);
      iVar1 = *(int *)(local_18[0] + 4);
      if ((iVar1 != 0) && (iVar1 != -1)) {
        *(int *)(local_18[0] + 4) = iVar1 + -1;
      }
      iVar1 = *(int *)(local_18[0] + 4);
      FUN_0087dd6f(uVar2);
      puVar3 = (undefined4 *)(~-(uint)(iVar1 != 0) & local_18[0]);
      if (puVar3 != (undefined4 *)0x0) {
        (**(code **)*puVar3)(1);
      }
    }
  }
  ExceptionList = local_10;
  return param_1;
}

