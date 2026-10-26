
void FUN_00408350(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00926ebe;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  local_1c = 0;
  if (*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2 != 0) {
    do {
      piVar7 = *(int **)(*(int *)(param_1 + 0xf0) + local_1c * 4);
      piVar4 = (int *)FUN_00891268(0x1c,uVar3);
      piVar8 = (int *)0x0;
      if (piVar4 != (int *)0x0) {
        iVar1 = piVar7[0xa7];
        iVar2 = piVar7[0xa6];
        piVar4[3] = 0;
        piVar4[1] = -1;
        piVar4[2] = -1;
        piVar4[4] = 0xf4369;
        *piVar4 = (int)FoxUI::FXUIEventI2::vftable;
        piVar4[5] = iVar2;
        piVar4[6] = iVar1;
        piVar8 = piVar4;
      }
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        local_c = 0;
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
        local_c = 0xffffffff;
      }
      if (DAT_00f95bd4 != (int *)0x0) {
        (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar8);
      }
      if (piVar8 != (int *)0x0) {
        (**(code **)(*piVar8 + 0x10))(1);
      }
      piVar7[0xa6] = -1;
      piVar7[0xa7] = -1;
      FUN_005d7240(0xffffffff,0xffffffff,0,0);
      (**(code **)(*piVar7 + 200))();
      iVar1 = piVar7[0xa8];
      if (iVar1 != 0) {
        uVar6 = 0;
        uVar5 = *(int *)(iVar1 + 0xf4) - *(int *)(iVar1 + 0xf0) >> 2;
        if (uVar5 != 0) {
          piVar7 = *(int **)(iVar1 + 0xf0);
          do {
            if (*(int *)(*piVar7 + 0x25c) == 0) {
              *(uint *)(iVar1 + 0x100) = uVar6;
              goto LAB_004084a9;
            }
            uVar6 = uVar6 + 1;
            piVar7 = piVar7 + 1;
          } while (uVar6 < uVar5);
        }
        *(undefined4 *)(iVar1 + 0x100) = 0xffffffff;
      }
LAB_004084a9:
      local_1c = local_1c + 1;
    } while (local_1c < (uint)(*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2));
  }
  ExceptionList = local_14;
  return;
}

