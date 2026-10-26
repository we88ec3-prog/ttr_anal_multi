
void FUN_0066a5d0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0091d0de;
  local_14 = ExceptionList;
  puVar3 = (undefined4 *)(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
  ExceptionList = &local_14;
  local_20 = (undefined4 *)(param_1 + 0x10c);
  local_1c = 0;
  piVar5 = (int *)(param_1 + 0x11c);
  do {
    (**(code **)(*(int *)*local_20 + 0x1ac))(0xffffffff,0xffffffff,0,0,0);
    FUN_0066aca0(param_1,0xffffffff,0xffffffff);
    (**(code **)(*(int *)*puVar3 + 200))();
    if ((piVar5[-1] != 0) && (*piVar5 != 0)) {
      piVar4 = (int *)FUN_00891268(0x1c);
      if (piVar4 == (int *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        iVar1 = *piVar5;
        iVar2 = piVar5[-1];
        piVar4[1] = -1;
        piVar4[2] = -1;
        piVar4[3] = 0;
        piVar4[4] = 0xf4369;
        *piVar4 = (int)FoxUI::FXUIEventI2::vftable;
        piVar4[5] = iVar2;
        piVar4[6] = iVar1;
      }
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        uStack_c = 0;
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
        uStack_c = 0xffffffff;
      }
      if (DAT_00f95bd4 != (int *)0x0) {
        (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar4);
      }
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x10))(1);
      }
    }
    local_20 = local_20 + 1;
    local_1c = local_1c + 1;
    piVar5[-1] = 0;
    *piVar5 = 0;
    piVar5[2] = 0;
    piVar5[1] = 0;
    piVar5[3] = 0;
    piVar5[4] = 0;
    piVar5 = piVar5 + 6;
  } while (local_1c < 3);
  ExceptionList = local_14;
  return;
}

