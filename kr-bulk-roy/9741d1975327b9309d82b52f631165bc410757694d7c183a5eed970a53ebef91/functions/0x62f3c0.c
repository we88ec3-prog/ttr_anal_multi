
void FUN_0062f3c0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  uint unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009169be;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((unaff_EDI != 0xffffffff) &&
     (unaff_EDI < (uint)(*(int *)(in_ECX + 0x118) - *(int *)(in_ECX + 0x114) >> 2))) {
    piVar2 = (int *)FUN_00891268(0x1c,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      iVar1 = **(int **)(*(int *)(in_ECX + 0x114) + unaff_EDI * 4);
      piVar2[6] = *(int *)(in_ECX + 0xf4);
      piVar2[1] = -1;
      piVar2[2] = -1;
      piVar2[3] = 0;
      piVar2[4] = 0xf42ee;
      *piVar2 = (int)FoxUI::FXUIEventI2::vftable;
      piVar2[5] = iVar1;
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
    }
  }
  ExceptionList = local_10;
  return;
}

