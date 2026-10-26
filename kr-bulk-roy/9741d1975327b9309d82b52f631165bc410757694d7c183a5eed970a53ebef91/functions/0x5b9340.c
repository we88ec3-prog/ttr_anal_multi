
void FUN_005b9340(void)

{
  undefined2 uVar1;
  int iVar2;
  int *in_ECX;
  int *piVar3;
  undefined4 local_1c;
  undefined2 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009473b7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX == (int *)0x0) {
LAB_005b9395:
    in_ECX = (int *)0x0;
  }
  else {
    iVar2 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar2 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_005b9395;
    }
  }
  if (in_ECX[5] != 0x6a7) {
    if (in_ECX[5] != 0x6a8) {
      ExceptionList = local_10;
      return;
    }
    piVar3 = (int *)in_ECX[6];
    if (piVar3 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar3 + 4))();
      if (iVar2 == 0x105bf) goto LAB_005b94cd;
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
    }
    piVar3 = (int *)0x0;
LAB_005b94cd:
    iVar2 = DAT_00fe1bd0;
    local_14 = piVar3[5];
    FUN_008438c0(&local_14);
    if (local_1c == *(int *)(iVar2 + 0xc)) {
      ExceptionList = local_10;
      return;
    }
    iVar2 = *(int *)(local_1c + 0x10);
    if (iVar2 == 0) {
      ExceptionList = local_10;
      return;
    }
    if (*(int *)(iVar2 + 0x40) == *(int *)(iVar2 + 0x44)) {
      ExceptionList = local_10;
      return;
    }
    local_1c = FUN_00891268(0x1c);
    local_8 = 2;
    if (local_1c == 0) {
      local_1c = 0;
    }
    else {
      iVar2 = FUN_0040f060();
      local_1c = FUN_00753f80(*(undefined4 *)(iVar2 + 0x8c));
    }
    local_8 = 0xffffffff;
    FUN_00404aa0();
    FUN_00804260(&local_1c);
    ExceptionList = local_10;
    return;
  }
  piVar3 = (int *)in_ECX[6];
  if (piVar3 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar3 + 4))();
    if (iVar2 == 0x105bf) goto LAB_005b93cf;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  piVar3 = (int *)0x0;
LAB_005b93cf:
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_8 = 0;
    FUN_004ffe60();
    _atexit((_func_4879 *)&LAB_00bccf00);
    local_8 = 0xffffffff;
  }
  uVar1 = FUN_005008b0();
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_8 = 1;
    FUN_00560170();
    _atexit((_func_4879 *)&LAB_00bcd110);
    local_8 = 0xffffffff;
  }
  FUN_00561760(uVar1,1);
  local_1c = CONCAT22((short)piVar3[6],0x1c);
  local_18 = (undefined2)piVar3[7];
  if (DAT_00fba798 != 0) {
    ExceptionList = local_10;
    return;
  }
  (**(code **)(*DAT_00fba854 + 0x10))(0,&local_1c,6);
  ExceptionList = local_10;
  return;
}

