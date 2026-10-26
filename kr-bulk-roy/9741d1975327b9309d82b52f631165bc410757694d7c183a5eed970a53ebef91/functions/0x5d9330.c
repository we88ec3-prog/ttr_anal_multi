
undefined4 FUN_005d9330(int *param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093f1ae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((param_1[1] != 0) && (*param_1 == 100)) {
    iVar4 = (**(code **)(*(int *)param_1[1] + 8))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar4 == 0xf4245) {
      iVar4 = *(int *)(param_1[1] + 0x2d0);
      iVar1 = *(int *)(param_1[1] + 0x20);
      cVar3 = FUN_0067fea0(*(undefined4 *)(in_ECX + 0x2a0),iVar4);
      if (cVar3 != '\0') {
        piVar5 = (int *)FUN_00891268(0x20);
        if (piVar5 == (int *)0x0) {
          piVar5 = (int *)0x0;
        }
        else {
          iVar2 = *(int *)(in_ECX + 0x2a0);
          piVar5[7] = iVar1 + 1;
          piVar5[1] = -1;
          piVar5[2] = -1;
          piVar5[3] = 0;
          piVar5[4] = 0xf437d;
          *piVar5 = (int)FoxUI::FXUIEventI3::vftable;
          piVar5[5] = iVar2;
          piVar5[6] = iVar4;
        }
        if ((DAT_00faadd0 & 1) == 0) {
          DAT_00faadd0 = DAT_00faadd0 | 1;
          local_8 = 0;
          FUN_0074d990();
          _atexit((_func_4879 *)&LAB_00bccc70);
          local_8 = 0xffffffff;
        }
        if (DAT_00f95bd4 != (int *)0x0) {
          (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar5);
        }
        if (piVar5 != (int *)0x0) {
          (**(code **)(*piVar5 + 0x10))(1);
        }
        ExceptionList = local_10;
        return 1;
      }
    }
  }
  ExceptionList = local_10;
  return 0;
}

