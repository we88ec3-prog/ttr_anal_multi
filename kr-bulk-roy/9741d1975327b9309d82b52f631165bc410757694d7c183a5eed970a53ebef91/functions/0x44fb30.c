
undefined4 * FUN_0044fb30(int param_1,undefined4 *param_2,int param_3)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  bool bVar8;
  
  iVar3 = param_3;
  puVar6 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  bVar8 = true;
  cVar1 = *(char *)((int)puVar6 + 0x2d);
  puVar2 = *(undefined4 **)(param_1 + 4);
  while (cVar1 == '\0') {
    piVar4 = puVar6 + 3;
    if (7 < (uint)puVar6[8]) {
      piVar4 = (int *)*piVar4;
    }
    iVar5 = FUN_0044df20(0,piVar4,puVar6[7]);
    bVar8 = iVar5 < 0;
    if (bVar8) {
      puVar7 = (undefined4 *)*puVar6;
    }
    else {
      puVar7 = (undefined4 *)puVar6[2];
    }
    puVar2 = puVar6;
    puVar6 = puVar7;
    cVar1 = *(char *)((int)puVar7 + 0x2d);
  }
  if (bVar8) {
    if (puVar2 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar6 = (undefined4 *)FUN_005c7a10(&param_3,1,iVar3);
      *param_2 = *puVar6;
      *(undefined1 *)(param_2 + 1) = 1;
      return param_2;
    }
    FUN_00574e80();
  }
  if (*(uint *)(iVar3 + 0x20) < 8) {
    iVar5 = iVar3 + 0xc;
  }
  else {
    iVar5 = *(int *)(iVar3 + 0xc);
  }
  iVar5 = FUN_0044df20(0,iVar5,*(undefined4 *)(iVar3 + 0x1c));
  if (iVar5 < 0) {
    puVar6 = (undefined4 *)FUN_005c7a10(&param_3,bVar8,iVar3);
    *param_2 = *puVar6;
    *(undefined1 *)(param_2 + 1) = 1;
    return param_2;
  }
  if (7 < *(uint *)(iVar3 + 0x20)) {
    FUN_0089120c(*(undefined4 *)(iVar3 + 0xc));
  }
  *(undefined4 *)(iVar3 + 0x20) = 7;
  *(undefined4 *)(iVar3 + 0x1c) = 0;
  *(undefined2 *)(iVar3 + 0xc) = 0;
  FUN_0089120c(iVar3);
  *param_2 = puVar2;
  *(undefined1 *)(param_2 + 1) = 0;
  return param_2;
}

