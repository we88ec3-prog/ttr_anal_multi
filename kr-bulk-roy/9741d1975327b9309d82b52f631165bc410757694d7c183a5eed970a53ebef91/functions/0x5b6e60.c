
void FUN_005b6e60(void)

{
  int iVar1;
  int *in_ECX;
  int in_EDX;
  int iStack_20;
  int iStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094932c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (in_ECX != (int *)0x0) {
    iVar1 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    if (iVar1 == 0x105b9) goto LAB_005b6ebc;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_005b6ebc:
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_c = 0;
    FUN_004ffe60();
    _atexit((_func_4879 *)&LAB_00bccf00);
    local_c = 0xffffffff;
  }
  iVar1 = DAT_00fb114c;
  iStack_20 = in_ECX[5];
  FUN_00503d20(&iStack_20);
  if ((iStack_1c != *(int *)(iVar1 + 4)) && (iStack_1c != -0x10)) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 1;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
    }
    FUN_00636520(DAT_00fab1bc,3,in_ECX[5]);
    FUN_0074a010(*(undefined4 *)(in_EDX + 0x224));
    FUN_00596e00(in_EDX,*(undefined4 *)(in_EDX + 0x224));
  }
  ExceptionList = local_14;
  return;
}

