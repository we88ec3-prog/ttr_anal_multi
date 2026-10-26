
undefined4 FUN_006de450(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0090806b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  bVar3 = false;
  if ((param_1 != (int *)0x0) && (*param_1 == 0)) {
    iVar1 = FUN_00891268(0x18,DAT_00d61f20 ^ (uint)&stack0xffffffc0);
    local_4 = 0;
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(*param_2 + 0x18);
      if (iVar1 == 0) {
        iVar1 = *param_2 + 0x1c;
      }
      uVar2 = FUN_00431550(iVar1);
      bVar3 = true;
      iVar1 = FUN_006de410(uVar2,0);
    }
    local_4 = 0xffffffff;
    *param_1 = iVar1;
    if (bVar3) {
      FUN_00431620();
    }
  }
  ExceptionList = local_c;
  return 2;
}

