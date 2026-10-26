
void FUN_005ac0e0(int param_1)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093605e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (in_ECX == (int *)0x0) {
LAB_005ac137:
    in_ECX = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    if (iVar1 != 0x105bf) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_005ac137;
    }
  }
  if (in_ECX[5] == 1) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 0;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
    }
    FUN_00654070(*(undefined4 *)(param_1 + 0x16c),1,in_ECX[7]);
    iVar1 = in_ECX[6];
    uVar2 = *(undefined4 *)(param_1 + 0x164);
  }
  else {
    if (in_ECX[5] != 0) goto LAB_005ac1cc;
    FUN_00654070(*(undefined4 *)(param_1 + 0x16c),0,in_ECX[7]);
    uVar2 = *(undefined4 *)(param_1 + 0x164);
    iVar1 = 0;
  }
  FUN_006565e0(uVar2,iVar1);
LAB_005ac1cc:
  (**(code **)(**(int **)(param_1 + 0x16c) + 0xd0))();
  ExceptionList = local_14;
  return;
}

