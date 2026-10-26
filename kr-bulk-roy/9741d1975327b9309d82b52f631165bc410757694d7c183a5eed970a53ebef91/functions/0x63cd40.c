
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063cd40(int param_1)

{
  int *in_EAX;
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (in_EAX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 == 0x105ba) goto LAB_0063cd74;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_0063cd74:
  if ((_DAT_00fd94dc & 1) == 0) {
    _DAT_00fd94dc = _DAT_00fd94dc | 1;
    FUN_004f10f0();
    _atexit((_func_4879 *)&LAB_00bce260);
  }
  uVar4 = DAT_00fdf390 - DAT_00fdf38c >> 2;
  uVar2 = 0;
  if (uVar4 != 0) {
    do {
      iVar1 = *(int *)(DAT_00fdf38c + uVar2 * 4);
      if (*(int *)(iVar1 + 8) == in_EAX[6]) {
        if (*(int *)(*(int *)(param_1 + 0xec) + 0xcc) == 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = FUN_00412c70(*(undefined4 *)(iVar1 + 8));
        }
        FUN_0063be80(uVar3);
        break;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar4);
  }
  FUN_00749920(*(undefined4 *)(param_1 + 0xec));
  (**(code **)(**(int **)(param_1 + 0xec) + 200))();
  return;
}

