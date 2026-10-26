
void FUN_007016c0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  double *pdVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  uint local_10 [2];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar5 = *(int **)(param_1 + 0xc);
  iVar10 = param_1;
  if (((piVar5 < *(int **)(param_1 + 8)) && (piVar5 != &DAT_00c0bfc8)) && (piVar5[2] == 8)) {
    if (*(int **)(param_1 + 8) <= piVar5) {
      piVar5 = &DAT_00c0bfc8;
    }
    if (piVar5[2] == 8) {
      iVar10 = *piVar5;
    }
    else {
      iVar10 = 0;
    }
  }
  local_10[0] = (uint)*(byte *)(iVar10 + 0x38);
  if ((*(code **)(iVar10 + 0x44) == (code *)0x0) || (*(code **)(iVar10 + 0x44) == FUN_00701320)) {
    FUN_00701450();
    piVar5 = *(int **)(param_1 + 8);
    *piVar5 = iVar10;
    piVar5[2] = 2;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    puVar7 = (undefined4 *)FUN_006f9c50();
    iVar1 = *(int *)(param_1 + 8);
    *(undefined4 *)(iVar1 + -0x10) = *puVar7;
    *(undefined4 *)(iVar1 + -0xc) = puVar7[1];
    *(undefined4 *)(iVar1 + -8) = puVar7[2];
    puVar2 = *(undefined4 **)(param_1 + 8);
    puVar7 = puVar2 + -8;
    puVar8 = puVar2 + -4;
    if (puVar8 < puVar2) {
      do {
        *puVar7 = *puVar8;
        puVar7[1] = puVar8[1];
        puVar7[2] = puVar7[6];
        puVar8 = puVar8 + 4;
        puVar7 = puVar7 + 4;
      } while (puVar8 < *(undefined4 **)(param_1 + 8));
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  }
  else {
    if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    puVar7 = *(undefined4 **)(param_1 + 8);
    uVar6 = FUN_006fec70(param_1,"external hook",0xd);
    *puVar7 = uVar6;
    puVar7[2] = 4;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  }
  uVar4 = local_10[0];
  bVar11 = (local_10[0] & 1) != 0;
  if (bVar11) {
    local_10[0] = CONCAT31(local_10[0]._1_3_,99);
  }
  uVar9 = (uint)bVar11;
  if ((uVar4 & 2) != 0) {
    *(undefined1 *)((int)local_10 + uVar9) = 0x72;
    uVar9 = uVar9 + 1;
  }
  if ((uVar4 & 4) != 0) {
    *(undefined1 *)((int)local_10 + uVar9) = 0x6c;
    uVar9 = uVar9 + 1;
  }
  *(undefined1 *)((int)local_10 + uVar9) = 0;
  FUN_006f5510(local_10);
  pdVar3 = *(double **)(param_1 + 8);
  *pdVar3 = (double)*(int *)(iVar10 + 0x3c);
  *(undefined4 *)(pdVar3 + 1) = 3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

