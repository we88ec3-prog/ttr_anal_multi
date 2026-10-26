
void FUN_0068a350(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009169ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (unaff_EDI[0x35] != 0) {
    piVar2 = (int *)FUN_00891268(0x18,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    piVar3 = (int *)0x0;
    if (piVar2 != (int *)0x0) {
      iVar1 = unaff_EDI[0x2a];
      piVar2[3] = 0;
      piVar2[1] = -1;
      piVar2[2] = -1;
      piVar2[4] = 0xf43aa;
      *piVar2 = (int)FoxUI::FXUIEventI1::vftable;
      piVar2[5] = iVar1;
      piVar3 = piVar2;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 0;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8 = 0xffffffff;
    }
    if ((int *)unaff_EDI[0x35] != (int *)0x0) {
      (**(code **)(*(int *)unaff_EDI[0x35] + 0x15c))(piVar3);
    }
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x10))(1);
    }
    unaff_EDI[0x35] = 0;
  }
  (**(code **)(*unaff_EDI + 0xd4))();
  ExceptionList = local_10;
  return;
}

