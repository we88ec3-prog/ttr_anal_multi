
void FUN_00829140(int param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *unaff_EDI;
  bool bVar6;
  
  iVar3 = (int)param_2;
  puVar5 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  bVar6 = true;
  cVar1 = *(char *)((int)puVar5 + 0x95);
  puVar2 = *(undefined4 **)(param_1 + 4);
  while (cVar1 == '\0') {
    bVar6 = *(short *)((int)param_2 + 0xc) < *(short *)(puVar5 + 3);
    if (bVar6) {
      puVar4 = (undefined4 *)*puVar5;
    }
    else {
      puVar4 = (undefined4 *)puVar5[2];
    }
    puVar2 = puVar5;
    puVar5 = puVar4;
    cVar1 = *(char *)((int)puVar4 + 0x95);
  }
  param_2 = puVar2;
  if (bVar6) {
    if (puVar2 == (undefined4 *)**(int **)(param_1 + 4)) {
      bVar6 = true;
      goto LAB_00829195;
    }
    FUN_00829390();
  }
  if (*(short *)(iVar3 + 0xc) <= *(short *)(param_2 + 3)) {
    FUN_00827e30();
    FUN_0089120c(iVar3);
    *unaff_EDI = param_2;
    *(undefined1 *)(unaff_EDI + 1) = 0;
    return;
  }
LAB_00829195:
  puVar5 = (undefined4 *)FUN_00829200(&param_1,bVar6,iVar3);
  *unaff_EDI = *puVar5;
  *(undefined1 *)(unaff_EDI + 1) = 1;
  return;
}

