
void FUN_0062c590(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_10c;
  undefined1 local_108 [124];
  undefined1 local_8c [48];
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined2 local_4c [8];
  undefined4 local_3c;
  undefined4 local_38;
  undefined2 local_30 [8];
  undefined4 local_20;
  undefined4 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092d2c2;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  _eh_vector_constructor_iterator_
            (local_8c,0x10,3,(_func_void_void_ptr *)&LAB_00689330,FUN_00418290);
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = 0;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = 0;
  local_8._1_3_ = 0;
  if ((DAT_00fdfb10 & 1) == 0) {
    DAT_00fdfb10 = DAT_00fdfb10 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_00590760(uVar1);
    _atexit((_func_4879 *)&LAB_00bce760);
  }
  local_8._0_1_ = 0;
  uVar2 = FUN_004f7ba0();
  FUN_004026e0(uVar2,0,0xffffffff);
  if ((DAT_00fdfb10 & 1) == 0) {
    DAT_00fdfb10 = DAT_00fdfb10 | 1;
    local_8._0_1_ = 2;
    FUN_00590760(uVar1);
    _atexit((_func_4879 *)&LAB_00bce760);
    local_8._0_1_ = 0;
  }
  uVar2 = FUN_004f7ba0();
  FUN_004026e0(uVar2,0,0xffffffff);
  local_10c = param_2;
  FUN_0062e1d0(local_108);
  local_8._0_1_ = 3;
  uVar2 = FUN_0062e0f0(&local_10c);
  FUN_0062de20(param_1 + 0x11c,uVar2);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00628890();
  iVar4 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
  if (((iVar4 != 0) &&
      (piVar3 = (int *)FUN_00412c70(*(undefined4 *)(iVar4 + 0xe4)), piVar3 != (int *)0x0)) &&
     (iVar4 = (**(code **)(*piVar3 + 4))(), iVar4 != 0x12d)) {
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  uVar2 = FUN_0057ef20();
  FUN_0082f200(param_1 + 300,uVar2);
  piVar3 = (int *)FUN_00831f50();
  iVar4 = *piVar3;
  *(undefined4 *)(*(int *)(iVar4 + 0x24c) + 0x24c) = param_2;
  *(undefined4 *)(*(int *)(iVar4 + 0x250) + 0x24c) = param_2;
  *(undefined4 *)(iVar4 + 0x248) = param_2;
  FUN_00831f50();
  FUN_00757800(local_4c);
  puVar5 = (undefined4 *)FUN_00831f50();
  iVar4 = (**(code **)(*(int *)*puVar5 + 0x58))();
  if (iVar4 != 0) {
    puVar5 = (undefined4 *)FUN_00831f50();
    piVar3 = (int *)(**(code **)(*(int *)*puVar5 + 0x58))();
    if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 4))(), iVar4 != 1000)) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
    }
    FUN_00757800(local_30);
    FUN_00754510();
  }
  puVar5 = (undefined4 *)FUN_00831f50();
  (**(code **)(*(int *)*puVar5 + 200))();
  local_8 = 0xffffffff;
  FUN_00628890();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

