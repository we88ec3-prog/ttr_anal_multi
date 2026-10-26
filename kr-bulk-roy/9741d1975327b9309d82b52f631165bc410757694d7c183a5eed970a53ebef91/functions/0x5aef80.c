
void FUN_005aef80(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00936efe;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (in_ECX != (int *)0x0) {
    iVar3 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    if (iVar3 == 0x105bf) goto LAB_005aefd4;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_005aefd4:
  *(int *)(param_1 + 0x228) = in_ECX[5];
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  iVar2 = DAT_00fab130;
  iVar3 = in_ECX[7];
  iVar1 = in_ECX[6];
  *(int *)(DAT_00fab130 + 0x5f14) = iVar1;
  *(int *)(iVar2 + 0x5f18) = iVar3;
  *(int *)(iVar2 + 0x5f1c) = iVar1;
  *(int *)(iVar2 + 0x5f20) = iVar3;
  ExceptionList = local_14;
  return;
}

