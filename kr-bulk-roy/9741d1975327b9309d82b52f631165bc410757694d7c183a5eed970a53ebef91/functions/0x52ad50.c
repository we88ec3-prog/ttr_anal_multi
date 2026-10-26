
void FUN_0052ad50(int param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *unaff_ESI;
  bool bVar7;
  
  iVar4 = (int)param_2;
  puVar6 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  bVar7 = true;
  cVar1 = *(char *)((int)puVar6 + 0x31);
  puVar3 = *(undefined4 **)(param_1 + 4);
  while (cVar1 == '\0') {
    bVar7 = *(byte *)((int)param_2 + 0xc) < *(byte *)(puVar6 + 3);
    if (bVar7) {
      puVar5 = (undefined4 *)*puVar6;
    }
    else {
      puVar5 = (undefined4 *)puVar6[2];
    }
    puVar3 = puVar6;
    puVar6 = puVar5;
    cVar1 = *(char *)((int)puVar5 + 0x31);
  }
  param_2 = puVar3;
  if (bVar7) {
    if (puVar3 == (undefined4 *)**(int **)(param_1 + 4)) {
      bVar7 = true;
      goto LAB_0052ada0;
    }
    FUN_00536ea0();
  }
  if (*(byte *)(iVar4 + 0xc) <= *(byte *)(param_2 + 3)) {
    if (7 < *(uint *)(iVar4 + 0x28)) {
      FUN_0089120c(*(undefined4 *)(iVar4 + 0x14));
    }
    *(undefined4 *)(iVar4 + 0x28) = 7;
    *(undefined4 *)(iVar4 + 0x24) = 0;
    *(undefined2 *)(iVar4 + 0x14) = 0;
    FUN_0089120c(iVar4);
    *(undefined1 *)(unaff_ESI + 1) = 0;
    *unaff_ESI = param_2;
    return;
  }
LAB_0052ada0:
  puVar6 = (undefined4 *)FUN_0052aee0(&param_1,bVar7,iVar4);
  uVar2 = *puVar6;
  *(undefined1 *)(unaff_ESI + 1) = 1;
  *unaff_ESI = uVar2;
  return;
}

