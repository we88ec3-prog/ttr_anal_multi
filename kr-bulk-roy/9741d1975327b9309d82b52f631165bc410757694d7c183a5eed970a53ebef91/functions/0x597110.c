
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00597110(int *param_1)

{
  int *piVar1;
  int *in_EAX;
  int iVar2;
  int *piVar3;
  uint local_14;
  uint local_10;
  int local_8;
  
  piVar1 = param_1;
  if (in_EAX != (int *)0x0) {
    iVar2 = (**(code **)(*in_EAX + 4))();
    if (iVar2 == 0x105bc) goto LAB_0059714b;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_0059714b:
  param_1 = (int *)in_EAX[5];
  if ((*(uint *)((int)param_1 + 0x28) >> 8 & 1) == 0) {
    iVar2 = 0;
    piVar3 = piVar1 + 0x31;
    while (FUN_00848020(&param_1), local_8 == *piVar3) {
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 4;
      if (2 < iVar2) {
        return;
      }
    }
    if ((piVar1[iVar2 + 0x3c] != 0) && ((int *)piVar1[iVar2 + 0x3c] == param_1)) {
      if (*(char *)((int)piVar1 + iVar2 * 0x10 + 0x101) != '\0') {
        if ((_DAT_00fb1314 & 1) == 0) {
          _DAT_00fb1314 = _DAT_00fb1314 | 1;
          _atexit((_func_4879 *)&DAT_00bccf10);
        }
        FUN_004a3d20(0);
      }
      if ((char)piVar1[(iVar2 + 0x10) * 4] != '\0') {
        *(undefined2 *)(piVar1 + 0x2c) = 0;
      }
      if ((char)piVar1[iVar2 * 4 + 0x41] != '\0') {
        (**(code **)(*piVar1 + 0x1a0))(0);
      }
      piVar1[iVar2 + 0x3c] = 0;
      piVar1[iVar2 * 4 + 0x3f] = 0;
      local_14 = local_14 & 0xff000000;
      local_10 = local_10 & 0xffffff00;
      piVar1[iVar2 * 4 + 0x40] = local_14;
      piVar1[iVar2 * 4 + 0x41] = local_10;
      piVar1[iVar2 * 4 + 0x42] = 0;
    }
  }
  return;
}

