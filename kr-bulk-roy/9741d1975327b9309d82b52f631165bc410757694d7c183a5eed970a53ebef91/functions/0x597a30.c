
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00597a30(void)

{
  int *piVar1;
  int *in_EAX;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined2 local_14;
  undefined4 local_12;
  int *local_c;
  undefined2 local_8;
  undefined1 local_6;
  
  uVar3 = 0;
  if (in_EAX == (int *)0x0) {
LAB_00597a69:
    in_EAX = (int *)0x0;
  }
  else {
    iVar2 = (**(code **)(*in_EAX + 4))();
    if (iVar2 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_00597a69;
    }
  }
  if (in_EAX[5] != 0x6a7) {
    return;
  }
  piVar1 = (int *)in_EAX[6];
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 4))();
    local_c = piVar1;
    if (iVar2 == 0xf4285) goto LAB_00597aa5;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  local_c = (int *)0x0;
LAB_00597aa5:
  uVar4 = local_c[7] - local_c[6] >> 2;
  if (uVar4 != 0) {
    do {
      iVar2 = local_c[6];
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      local_12 = *(undefined4 *)(iVar2 + uVar3 * 4);
      local_14 = 0x62;
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&local_14,6);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar4);
  }
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_6 = (undefined1)local_c[5];
  local_8 = 0x3d;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_8,3);
  }
  return;
}

