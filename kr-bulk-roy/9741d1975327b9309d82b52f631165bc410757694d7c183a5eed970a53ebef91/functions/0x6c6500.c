
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c6500(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  undefined4 uStack_24;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00936a1e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (in_ECX != (int *)0x0) {
    iVar3 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    if (iVar3 == 0x105bd) goto LAB_006c6559;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_006c6559:
  if (in_ECX[5] == 0x6a7) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 0;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
    }
    uStack_24 = *(undefined4 *)(param_1 + 0xb4);
    FUN_008438c0(&uStack_24);
    if ((CONCAT22(uStack_1e,uStack_20) != DAT_00fab14c) &&
       (puVar1 = *(undefined4 **)(CONCAT22(uStack_1e,uStack_20) + 0x10), puVar1 != (undefined4 *)0x0
       )) {
      uVar2 = *puVar1;
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      uStack_20 = 0xc3;
      uStack_1e = (undefined2)uVar2;
      uStack_1c = (undefined2)((uint)uVar2 >> 0x10);
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&uStack_20,6);
      }
    }
  }
  ExceptionList = local_14;
  return;
}

