
undefined4 * FUN_00539230(int param_1,undefined4 *param_2,int param_3)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  bool bVar9;
  
  iVar6 = param_3;
  puVar5 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  puVar7 = (undefined4 *)(param_3 + 0xc);
  bVar9 = true;
  cVar1 = *(char *)((int)puVar5 + 0x45);
  puVar2 = *(undefined4 **)(param_1 + 4);
  while (cVar1 == '\0') {
    piVar3 = puVar5 + 3;
    if (7 < (uint)puVar5[8]) {
      piVar3 = (int *)*piVar3;
    }
    iVar4 = FUN_0044df20(0,piVar3,puVar5[7]);
    bVar9 = iVar4 < 0;
    if (bVar9) {
      puVar8 = (undefined4 *)*puVar5;
    }
    else {
      puVar8 = (undefined4 *)puVar5[2];
    }
    puVar2 = puVar5;
    puVar5 = puVar8;
    cVar1 = *(char *)((int)puVar8 + 0x45);
  }
  if (bVar9) {
    if (puVar2 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar5 = (undefined4 *)FUN_00539350(&param_3,1,param_3);
      *param_2 = *puVar5;
      *(undefined1 *)(param_2 + 1) = 1;
      return param_2;
    }
    FUN_004f9850();
  }
  if (7 < *(uint *)(iVar6 + 0x20)) {
    puVar7 = (undefined4 *)*puVar7;
  }
  iVar6 = FUN_0044df20(0,puVar7,*(undefined4 *)(iVar6 + 0x1c));
  if (iVar6 < 0) {
    puVar5 = (undefined4 *)FUN_00539350(&param_3,bVar9,param_3);
    *param_2 = *puVar5;
    *(undefined1 *)(param_2 + 1) = 1;
    return param_2;
  }
  FUN_005375f0();
  FUN_0089120c(param_3);
  *param_2 = puVar2;
  *(undefined1 *)(param_2 + 1) = 0;
  return param_2;
}

