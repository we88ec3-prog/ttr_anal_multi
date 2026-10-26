
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c6630(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int *in_ECX;
  undefined4 uStack_20;
  int iStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093605e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (in_ECX != (int *)0x0) {
    iVar2 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    if (iVar2 == 0x105bd) goto LAB_006c6689;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_006c6689:
  if (in_ECX[5] == 0x6a7) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 0;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
    }
    uStack_20 = *(undefined4 *)(param_1 + 0xb4);
    FUN_008438c0(&uStack_20);
    if ((iStack_1c != DAT_00fab14c) && (*(int *)(iStack_1c + 0x10) != 0)) {
      uVar1 = *(undefined2 *)(*(int *)(iStack_1c + 0x10) + 0x14);
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      uStack_20 = CONCAT22(uVar1,0xc5);
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&uStack_20,4);
      }
    }
  }
  ExceptionList = local_14;
  return;
}

