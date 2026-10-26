
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063de70(int param_1)

{
  int *in_EAX;
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (in_EAX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 == 0x105ba) goto LAB_0063dea4;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_0063dea4:
  if ((_DAT_00fd94dc & 1) == 0) {
    _DAT_00fd94dc = _DAT_00fd94dc | 1;
    FUN_004f10f0();
    _atexit((_func_4879 *)&LAB_00bce260);
  }
  uVar3 = DAT_00fdf3a0 - DAT_00fdf39c >> 2;
  uVar2 = 0;
  if (uVar3 != 0) {
    do {
      iVar1 = *(int *)(DAT_00fdf39c + uVar2 * 4);
      if (*(int *)(iVar1 + 4) == in_EAX[6]) {
        if (*(int *)(*(int *)(param_1 + 0xec) + 0xcc) != 0) {
          FUN_00412c70(*(undefined4 *)(iVar1 + 4));
        }
        FUN_00757710();
        break;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar3);
  }
  FUN_00749920(*(undefined4 *)(param_1 + 0xec));
  (**(code **)(**(int **)(param_1 + 0xec) + 200))();
  return;
}

