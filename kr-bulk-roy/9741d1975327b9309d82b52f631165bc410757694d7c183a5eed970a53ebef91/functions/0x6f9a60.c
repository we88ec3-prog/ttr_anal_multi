
undefined4 * FUN_006f9a60(int param_1,int param_2,int *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar2 = (undefined4 *)FUN_006f9100();
  if ((puVar2[2] == 0) && (puVar5 = puVar2, puVar2 != (undefined4 *)&DAT_00c0bfa8)) {
LAB_006f9b23:
    puVar5[4] = *param_3;
    puVar5[5] = param_3[1];
    puVar5[6] = param_3[2];
    if (((3 < param_3[2]) && ((*(byte *)(*param_3 + 5) & 3) != 0)) &&
       ((*(byte *)(param_2 + 5) & 4) != 0)) {
      iVar4 = *(int *)(param_1 + 0x10);
      *(byte *)(param_2 + 5) = *(byte *)(param_2 + 5) & 0xfb;
      *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(iVar4 + 0x28);
      *(int *)(iVar4 + 0x28) = param_2;
    }
    return puVar5;
  }
  if (*(uint *)(param_2 + 0x10) < *(uint *)(param_2 + 0x14)) {
    do {
      *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + -0x20;
      puVar5 = *(undefined4 **)(param_2 + 0x14);
      if (puVar5[6] == 0) {
        if (puVar5 == (undefined4 *)0x0) goto LAB_006f9ac0;
        puVar3 = (undefined4 *)FUN_006f9100();
        if (puVar3 == puVar2) {
          puVar5[7] = puVar2[7];
          puVar2[7] = puVar5;
        }
        else {
          puVar1 = (undefined4 *)puVar3[7];
          while (puVar1 != puVar2) {
            puVar3 = (undefined4 *)puVar3[7];
            puVar1 = (undefined4 *)puVar3[7];
          }
          puVar3[7] = puVar5;
          puVar3 = puVar2;
          for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar5 = *puVar3;
            puVar3 = puVar3 + 1;
            puVar5 = puVar5 + 1;
          }
          puVar2[7] = 0;
          puVar2[2] = 0;
          puVar5 = puVar2;
        }
        goto LAB_006f9b23;
      }
    } while (*(undefined4 **)(param_2 + 0x10) < puVar5);
  }
  *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + -0x20;
LAB_006f9ac0:
  FUN_006f9850(param_1,param_3);
  puVar2 = (undefined4 *)FUN_006f9d20(param_1);
  return puVar2;
}

