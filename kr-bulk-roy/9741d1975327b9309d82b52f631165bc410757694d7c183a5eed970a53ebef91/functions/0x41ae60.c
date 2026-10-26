
void FUN_0041ae60(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917cde;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX == (int *)0x0) {
LAB_0041aeb4:
    in_ECX = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_0041aeb4;
    }
  }
  if (in_ECX[5] != 0x6a7) {
    ExceptionList = local_10;
    return;
  }
  piVar2 = (int *)in_ECX[6];
  if (piVar2 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar2 + 4))();
    if (iVar1 == 0x105b9) goto LAB_0041aeee;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  piVar2 = (int *)0x0;
LAB_0041aeee:
  if (piVar2[5] == 0) {
    piVar2 = (int *)FUN_00891268(0x1c);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2[1] = -1;
      piVar2[2] = -1;
      piVar2[3] = 0;
      piVar2[4] = 0xf4392;
      *piVar2 = (int)FoxUI::FXUIEventI2::vftable;
      piVar2[5] = 0;
      piVar2[6] = 0;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 0;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8 = 0xffffffff;
    }
    if (DAT_00f95bd4 != (int *)0x0) {
      (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar2);
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x10))(1);
      ExceptionList = local_10;
      return;
    }
  }
  else if (piVar2[5] == 1) {
    puVar3 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar3 != (undefined4 *)0x0) {
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      puVar3[4] = 0xf4394;
      *puVar3 = FoxUI::FXUIEventI2::vftable;
      puVar3[5] = 0;
      puVar3[6] = 2;
    }
    FUN_00404aa0();
    FUN_00750020();
  }
  ExceptionList = local_10;
  return;
}

