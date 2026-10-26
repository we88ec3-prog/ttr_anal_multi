
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c5400(int param_1)

{
  int *in_EAX;
  int iVar1;
  
  if (in_EAX[4] == 0x70b) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      in_EAX = (int *)0x0;
    }
    if ((_DAT_00fc0d5c & 1) == 0) {
      _DAT_00fc0d5c = _DAT_00fc0d5c | 1;
      DAT_00fc0d60 = 0;
      DAT_00fc0d64 = 0;
      _DAT_00fc0d68 = 0;
      _atexit((_func_4879 *)&LAB_00bcd8c0);
    }
    FUN_006c8d90(in_EAX[5],*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x30),
                 *(undefined4 *)(param_1 + 0xb0));
  }
  return;
}

