
void FUN_006c5a80(void)

{
  int iVar1;
  int *in_ECX;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b55e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX == (int *)0x0) {
LAB_006c5ad2:
    in_ECX = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_006c5ad2;
    }
  }
  if (in_ECX[5] != 0x6a7) {
    ExceptionList = local_10;
    return;
  }
  piVar2 = (int *)in_ECX[6];
  if (piVar2 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar2 + 4))();
    if (iVar1 == 0x105b9) goto LAB_006c5b06;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  piVar2 = (int *)0x0;
LAB_006c5b06:
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_8 = 0;
    FUN_004e8010();
    _atexit((_func_4879 *)&LAB_00bcd6b0);
    local_8 = 0xffffffff;
  }
  FUN_004ecd10(&DAT_00fbad18,piVar2[5]);
  ExceptionList = local_10;
  return;
}

