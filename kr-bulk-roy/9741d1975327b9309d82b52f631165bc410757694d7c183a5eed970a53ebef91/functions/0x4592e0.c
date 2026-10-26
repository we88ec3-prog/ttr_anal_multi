
undefined4 FUN_004592e0(int *param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  int iVar6;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00947f9e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (((param_1[1] != 0) && (*param_1 == 100)) &&
     (iVar3 = (**(code **)(*(int *)param_1[1] + 8))(DAT_00d61f20 ^ (uint)&stack0xffffffd8),
     iVar3 == 0xf4245)) {
    iVar3 = *(int *)(param_1[1] + 0x2d0);
    uVar1 = *(undefined4 *)(in_ECX + 0x298);
    iVar6 = *(int *)(param_1[1] + 0x20) + 1;
    iVar4 = FUN_0045c050(uVar1,iVar6);
    if (iVar4 == 1) {
      cVar2 = FUN_0045b110(iVar3);
    }
    else {
      if (iVar4 != 2) {
        ExceptionList = local_14;
        return 0;
      }
      cVar2 = FUN_0045bc30(uVar1);
    }
    if (cVar2 != '\0') {
      piVar5 = (int *)FUN_00891268(0x1c);
      if (piVar5 == (int *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5[6] = iVar6;
        piVar5[1] = -1;
        piVar5[2] = -1;
        piVar5[3] = 0;
        piVar5[4] = 0xf441f;
        *piVar5 = (int)FoxUI::FXUIEventI2::vftable;
        piVar5[5] = iVar3;
      }
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        uStack_c = 0;
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
        uStack_c = 0xffffffff;
      }
      if (DAT_00f95bd4 != (int *)0x0) {
        (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar5);
      }
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0x10))(1);
      }
      ExceptionList = local_14;
      return 1;
    }
  }
  ExceptionList = local_14;
  return 0;
}

