
void FUN_00538870(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  undefined4 **ppuVar4;
  short *psVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  short *psVar9;
  int extraout_EDX;
  int *piVar10;
  int *piVar11;
  undefined4 in_stack_0000001c;
  uint in_stack_00000020;
  undefined4 *local_3c;
  int *local_38;
  undefined4 *local_34;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00912cd6;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_38 = (int *)*param_2;
  piVar10 = (int *)*local_38;
  local_14 = uVar3;
  if ((int *)*local_38 != local_38) {
    do {
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_8._0_1_ = 1;
        FUN_0051c120(uVar3);
        _atexit((_func_4879 *)&LAB_00bccc90);
        local_8 = (uint)local_8._1_3_ << 8;
      }
      cVar1 = *(char *)((int)DAT_00f8d91c[1] + 0x15);
      puVar6 = (undefined4 *)DAT_00f8d91c[1];
      local_3c = DAT_00f8d91c;
      while (puVar8 = puVar6, cVar1 == '\0') {
        if ((int)puVar8[3] < piVar10[2]) {
          puVar6 = (undefined4 *)puVar8[2];
          puVar8 = local_3c;
        }
        else {
          puVar6 = (undefined4 *)*puVar8;
        }
        cVar1 = *(char *)((int)puVar6 + 0x15);
        local_3c = puVar8;
      }
      if ((local_3c == DAT_00f8d91c) || (piVar10[2] < (int)local_3c[3])) {
        local_34 = DAT_00f8d91c;
        ppuVar4 = &local_34;
      }
      else {
        ppuVar4 = &local_3c;
      }
      if ((*ppuVar4 == DAT_00f8d91c) || (psVar9 = (short *)(*ppuVar4)[4], psVar9 == (short *)0x0)) {
        piVar11 = (int *)*piVar10;
        if (piVar10 != (int *)*param_2) {
          *(int **)piVar10[1] = piVar11;
          *(int *)(*piVar10 + 4) = piVar10[1];
          FUN_0089120c(piVar10);
          param_2[1] = param_2[1] + -1;
        }
      }
      else {
        if (7 < *(uint *)(psVar9 + 10)) {
          psVar9 = *(short **)psVar9;
        }
        local_30[0] = local_30[0] & 0xffff0000;
        local_1c = 7;
        local_20 = 0;
        psVar5 = psVar9;
        do {
          sVar2 = *psVar5;
          psVar5 = psVar5 + 1;
        } while (sVar2 != 0);
        FUN_00402160(psVar9,(int)psVar5 - (int)(psVar9 + 1) >> 1);
        puVar6 = param_3;
        if (in_stack_00000020 < 8) {
          puVar6 = &param_3;
        }
        iVar7 = FUN_00466df0(local_30,puVar6,in_stack_0000001c);
        if (iVar7 == -1) {
          piVar11 = (int *)*piVar10;
          if (piVar10 != (int *)*param_2) {
            *(int **)piVar10[1] = piVar11;
            *(int *)(*piVar10 + 4) = piVar10[1];
            FUN_0089120c(piVar10);
            param_2[1] = param_2[1] + -1;
          }
        }
        else {
          piVar11 = (int *)*piVar10;
        }
        if (7 < local_1c) {
          FUN_0089120c(local_30[0]);
        }
      }
      piVar10 = piVar11;
    } while (piVar11 != local_38);
  }
  iVar7 = param_2[1];
  if (7 < in_stack_00000020) {
    FUN_0089120c(param_3);
    iVar7 = extraout_EDX;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc,iVar7);
  return;
}

