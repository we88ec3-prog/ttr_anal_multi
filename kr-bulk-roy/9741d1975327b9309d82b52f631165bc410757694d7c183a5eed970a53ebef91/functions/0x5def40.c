
undefined4 FUN_005def40(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009169ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((param_1[1] != 0) && (*param_1 == 100)) {
    iVar2 = (**(code **)(*(int *)param_1[1] + 8))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar2 == 0xf4245) {
      iVar2 = *(int *)(param_1[1] + 0x20);
      iVar1 = *(int *)(param_1[1] + 0x2d0);
      piVar3 = (int *)FUN_00891268(0x1c);
      if (piVar3 == (int *)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3[6] = iVar2 + 1;
        piVar3[1] = -1;
        piVar3[2] = -1;
        piVar3[3] = 0;
        piVar3[4] = 0xf43b6;
        *piVar3 = (int)FoxUI::FXUIEventI2::vftable;
        piVar3[5] = iVar1;
      }
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        local_8 = 0;
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
        local_8 = 0xffffffff;
      }
      if (DAT_00f95bd4 != (int *)0x0) {
        (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar3);
      }
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x10))(1);
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  ExceptionList = local_10;
  return 0;
}

