
undefined4 FUN_005deab0(int *param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  int iVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093f1ae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((param_1[1] != 0) && (*param_1 == 100)) {
    iVar3 = (**(code **)(*(int *)param_1[1] + 8))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar3 == 0xf4245) {
      iVar3 = *(int *)(param_1[1] + 0x2d0);
      iVar5 = *(int *)(param_1[1] + 0x20) + 1;
      cVar2 = FUN_00679ad0(*(undefined4 *)(in_ECX + 0x298),iVar5);
      if (cVar2 != '\0') {
        piVar4 = (int *)FUN_00891268(0x20);
        if (piVar4 == (int *)0x0) {
          piVar4 = (int *)0x0;
        }
        else {
          iVar1 = *(int *)(in_ECX + 0x20);
          piVar4[7] = iVar5;
          piVar4[1] = -1;
          piVar4[2] = -1;
          piVar4[3] = 0;
          piVar4[4] = 0xf43a8;
          *piVar4 = (int)FoxUI::FXUIEventI3::vftable;
          piVar4[5] = iVar1;
          piVar4[6] = iVar3;
        }
        if ((DAT_00faadd0 & 1) == 0) {
          DAT_00faadd0 = DAT_00faadd0 | 1;
          local_8 = 0;
          FUN_0074d990();
          _atexit((_func_4879 *)&LAB_00bccc70);
          local_8 = 0xffffffff;
        }
        if (DAT_00f95bd4 != (int *)0x0) {
          (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar4);
        }
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 0x10))(1);
        }
        ExceptionList = local_10;
        return 1;
      }
    }
  }
  ExceptionList = local_10;
  return 0;
}

