
void FUN_00476b20(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edde;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((param_2 == 1) && (iVar2 = DAT_00f94300 + 0x16f8, iVar2 != 0)) {
    if (99 < param_3 - 1U) {
      FUN_006edb60(&DAT_00c0ddc0);
      ExceptionList = local_14;
      return;
    }
    piVar1 = (int *)(param_3 * 0x20 + iVar2);
    if (((((*(int *)(param_3 * 0x20 + 0xc + iVar2) != 0) && (piVar1[2] != 0)) &&
         (piVar1 != (int *)0x0)) && ((*piVar1 == 0xb || (*piVar1 == 0x19)))) &&
       (*(float *)(*(int *)(param_1 + 0x128) + 0xd0) < 1.0)) {
      local_20 = piVar1[1];
      iVar2 = FUN_00444e60();
      FUN_008438c0(&local_20);
      if ((local_1c != *(int *)(iVar2 + 8)) && (*(int *)(local_1c + 0x10) != 0)) {
        iVar2 = 0;
        piVar4 = (int *)(param_1 + 0xf4);
        while (-1 < *(int *)(*piVar4 + 0x250)) {
          iVar2 = iVar2 + 1;
          piVar4 = piVar4 + 1;
          if (9 < iVar2) {
            ExceptionList = local_14;
            return;
          }
        }
        FUN_004451b0(piVar1[3],piVar1[4],piVar1[5],1);
        FUN_00477b20();
        puVar3 = (undefined4 *)FUN_00891268(0x1c);
        if (puVar3 != (undefined4 *)0x0) {
          puVar3[1] = 0xffffffff;
          puVar3[2] = 0xffffffff;
          puVar3[3] = 0;
          puVar3[4] = 0xf4368;
          *puVar3 = FoxUI::FXUIEventI2::vftable;
          puVar3[5] = 1;
          puVar3[6] = param_3;
        }
        FUN_004072a0();
      }
    }
  }
  ExceptionList = local_14;
  return;
}

