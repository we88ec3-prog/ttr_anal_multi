
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b71d0(int param_1)

{
  int *in_EAX;
  int iVar1;
  undefined2 local_8;
  undefined2 local_6;
  
  if (in_EAX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 == 0x105b9) goto LAB_005b7201;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_005b7201:
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  _local_8 = CONCAT22((short)in_EAX[5],0x86);
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_8,4);
  }
  if (((uint)(*(int **)(param_1 + 0x224))[10] >> 8 & 1) != 0) {
    (**(code **)(**(int **)(param_1 + 0x224) + 0xd4))();
  }
  return;
}

