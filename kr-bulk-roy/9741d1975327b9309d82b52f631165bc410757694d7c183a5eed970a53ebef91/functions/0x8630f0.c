
undefined4 FUN_008630f0(undefined4 *param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 **ppuVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *local_8;
  
  puVar3 = param_1;
  FUN_004d8460();
  piVar4 = (int *)FUN_008634e0();
  iVar8 = 0;
  if ((int *)*piVar4 != (int *)0x0) {
    iVar8 = *(int *)*piVar4;
  }
  uVar5 = piVar4[2];
  if (*(uint *)(iVar8 + 8) <= uVar5) {
    uVar5 = uVar5 - *(uint *)(iVar8 + 8);
  }
  iVar8 = *(int *)(*(int *)(iVar8 + 4) + uVar5 * 4);
  if (*(int *)(iVar8 + 4) != (*(int **)(iVar8 + 8))[1] - **(int **)(iVar8 + 8) >> 2) {
    do {
      uVar5 = *(uint *)(iVar8 + 4);
      *(uint *)(iVar8 + 4) = uVar5 + 1;
      iVar2 = **(int **)(iVar8 + 8);
      if ((uint)((*(int **)(iVar8 + 8))[1] - iVar2 >> 2) <= uVar5) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db7d("invalid vector<T> subscript");
      }
      piVar4 = *(int **)(iVar2 + uVar5 * 4);
      (**(code **)(*piVar4 + 0x10))(*(undefined4 *)(param_2 + 4));
      if (((*(int *)(iVar8 + 0x18) == -1) || (*(int *)(iVar8 + 0x10) != 0)) || (piVar4[2] == 6)) {
        puVar9 = (undefined4 *)((undefined4 *)puVar3[0x11])[1];
        cVar1 = *(char *)((int)puVar9 + 0x15);
        param_1 = (undefined4 *)puVar3[0x11];
        while (cVar1 == '\0') {
          if ((int)puVar9[3] < piVar4[2]) {
            puVar6 = (undefined4 *)puVar9[2];
            puVar9 = param_1;
          }
          else {
            puVar6 = (undefined4 *)*puVar9;
          }
          param_1 = puVar9;
          puVar9 = puVar6;
          cVar1 = *(char *)((int)puVar6 + 0x15);
        }
        if ((param_1 == (undefined4 *)puVar3[0x11]) || (piVar4[2] < (int)param_1[3])) {
          local_8 = (undefined4 *)puVar3[0x11];
          ppuVar7 = &local_8;
        }
        else {
          ppuVar7 = &param_1;
        }
        if (*ppuVar7 != (undefined4 *)puVar3[0x11]) {
          (*(code *)(*ppuVar7)[4])(param_2,param_3,puVar3,iVar8,piVar4);
        }
      }
    } while (*(int *)(iVar8 + 4) != (*(int **)(iVar8 + 8))[1] - **(int **)(iVar8 + 8) >> 2);
  }
  if (puVar3[0xe] != 0) {
    uVar5 = puVar3[0xe] + -1 + puVar3[0xd];
    if ((uint)puVar3[0xc] <= uVar5) {
      uVar5 = uVar5 - puVar3[0xc];
    }
    puVar9 = *(undefined4 **)(puVar3[0xb] + uVar5 * 4);
    *puVar9 = 0;
    puVar9[1] = 0;
    puVar9[2] = 0;
    puVar9[3] = 0;
    puVar9[4] = 0;
    puVar9[5] = 0;
    puVar9[6] = 0xffffffff;
    puVar9[7] = 0;
    puVar9[8] = 0;
    piVar4 = puVar3 + 0xe;
    *piVar4 = *piVar4 + -1;
    if (*piVar4 == 0) {
      puVar3[0xd] = 0;
    }
  }
  return 1;
}

