
uint FUN_007c9470(undefined4 param_1,int *param_2,undefined4 *param_3,float *param_4,
                 undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 auStack_6c [5];
  undefined4 uStack_58;
  undefined4 uStack_54;
  uint uStack_50;
  undefined1 *puStack_4c;
  float *pfStack_48;
  undefined4 uStack_44;
  undefined1 *puStack_40;
  undefined1 local_30 [44];
  
  piVar1 = param_2;
  puStack_40 = (undefined1 *)0x7c9485;
  iVar2 = (**(code **)(*param_2 + 4))();
  if (*(int *)(iVar2 + 4) == -0x5eed0000) {
    puStack_40 = local_30;
    uStack_44 = 0x7c9503;
    (**(code **)(*param_2 + 0x24))();
    iVar2 = param_2[0x37] - param_2[0x36] >> 2;
    uVar3 = 0;
    param_2 = (int *)0x0;
    if (0 < iVar2) {
      do {
        if (param_2 < (uint)(piVar1[0x37] - piVar1[0x36] >> 2)) {
          uStack_50 = *(undefined4 *)(piVar1[0x36] + (int)param_2 * 4);
        }
        else {
          uStack_50 = 0;
        }
        uStack_44 = param_5;
        pfStack_48 = param_4;
        puStack_4c = local_30;
        uStack_54 = param_1;
        uStack_58 = 0x7c955c;
        uVar4 = FUN_007c9470();
        if (uVar3 < uVar4) {
          uVar3 = uVar4;
        }
        param_2 = (int *)((int)param_2 + 1);
      } while ((int)param_2 < iVar2);
    }
    uStack_44 = 0x7c9579;
    uVar4 = (**(code **)(*piVar1 + 0x34))();
    uVar8 = 0;
    if (uVar4 != 0) {
      do {
        uStack_44 = param_5;
        pfStack_48 = param_4;
        puStack_4c = local_30;
        uStack_54 = 0x7c959b;
        uStack_50 = uVar8;
        uStack_50 = (**(code **)(*piVar1 + 0x30))();
        uStack_54 = param_1;
        uStack_58 = 0x7c95a5;
        uVar5 = FUN_007c9470();
        if (uVar3 < uVar5) {
          uVar3 = uVar5;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < uVar4);
    }
    return uVar3;
  }
  if (*(int *)(iVar2 + 4) == -0x5edc0000) {
    iVar2 = param_2[0x1e];
    puStack_40 = (undefined1 *)param_5;
    puVar7 = auStack_6c;
    for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar7 = *param_3;
      param_3 = param_3 + 1;
      puVar7 = puVar7 + 1;
    }
    uVar3 = FUN_007c95c0(param_1,iVar2);
    if (0.0 <= *param_4) {
      return uVar3;
    }
    *param_4 = 0.0;
    return uVar3;
  }
  return 0;
}

