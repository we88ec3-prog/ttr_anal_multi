
void FUN_004fee30(int param_1)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092f6de;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = DAT_00faadd4 & 1;
  *(undefined4 *)(in_ECX + 0x5eac) = 0;
  if (uVar1 == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  FUN_0058aad0();
  FUN_004ff080();
  switch(*(undefined1 *)(param_1 + 2)) {
  case 0:
    FUN_0040b3c0();
    local_8 = 1;
    FUN_0040b3f0();
    piVar3 = (int *)FUN_0080ab00();
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x14))();
    }
    local_8 = 0xffffffff;
    FUN_007cf450();
    FUN_004054c0();
    FUN_005854b0();
    FUN_00585330();
    FUN_00402250();
    local_8 = 2;
    FUN_005854b0();
    uVar4 = FUN_00585330();
    goto LAB_004ff028;
  case 1:
    FUN_004054c0();
    FUN_005854b0();
    FUN_00585330();
    FUN_00402250();
    local_8 = 3;
    break;
  case 2:
    FUN_004054c0();
    FUN_005854b0();
    FUN_00585330();
    FUN_00402250();
    local_8 = 5;
    break;
  case 3:
    FUN_004054c0();
    FUN_005854b0();
    FUN_00585330();
    FUN_00402250();
    local_8 = 4;
    break;
  default:
    goto switchD_004feeb7_caseD_4;
  case 5:
    FUN_004054c0();
    FUN_005854b0();
    FUN_00585330();
    FUN_00402250();
    local_8 = 6;
  }
  FUN_005854b0();
  uVar4 = FUN_00585330();
LAB_004ff028:
  FUN_00402250(uVar4);
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
switchD_004feeb7_caseD_4:
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

