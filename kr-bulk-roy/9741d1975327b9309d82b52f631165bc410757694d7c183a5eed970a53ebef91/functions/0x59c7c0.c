
void FUN_0059c7c0(void)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00922cea;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0;
    FUN_00587480(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 1;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  local_c = 0xffffffff;
  FUN_00753440(0xf4318);
  if (in_ECX != (int *)0x0) {
    iVar1 = (**(code **)(*in_ECX + 4))();
    if (iVar1 == 0x105ca) goto LAB_0059c883;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_0059c883:
  piVar2 = (int *)FUN_00891268(0x20);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    iVar1 = in_ECX[6];
    piVar2[7] = in_ECX[7];
    piVar2[1] = -1;
    piVar2[2] = -1;
    piVar2[3] = 0;
    piVar2[4] = 0xf4317;
    *piVar2 = (int)FoxUI::FXUIEventBI1::vftable;
    piVar2[6] = iVar1;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 2;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_c = 0xffffffff;
  }
  if (DAT_00f95bd4 != (int *)0x0) {
    (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar2);
  }
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x10))(1);
  }
  ExceptionList = local_14;
  return;
}

