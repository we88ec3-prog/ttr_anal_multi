
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005bafb0(void)

{
  int *in_EAX;
  int iVar1;
  undefined4 in_ECX;
  undefined2 local_8;
  undefined1 local_6;
  undefined1 uStack_5;
  
  uStack_5 = (undefined1)((uint)in_ECX >> 0x18);
  if (in_EAX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 == 0x105bd) goto LAB_005bafe5;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_005bafe5:
  if (in_EAX[5] == 0x6a7) {
    iVar1 = in_EAX[6];
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    _local_8 = CONCAT12(*(undefined1 *)(iVar1 + 0x14),0x5d);
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_8,3);
    }
  }
  return;
}

