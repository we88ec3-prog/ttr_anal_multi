
void FUN_00528090(int param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  bool bVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *unaff_ESI;
  
  iVar5 = (int)param_2;
  puVar7 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  bVar3 = true;
  cVar1 = *(char *)((int)puVar7 + 0x71);
  puVar4 = *(undefined4 **)(param_1 + 4);
  while (cVar1 == '\0') {
    bVar3 = *(int *)((int)param_2 + 0xc) < (int)puVar7[3];
    if (bVar3) {
      puVar6 = (undefined4 *)*puVar7;
    }
    else {
      puVar6 = (undefined4 *)puVar7[2];
    }
    puVar4 = puVar7;
    puVar7 = puVar6;
    cVar1 = *(char *)((int)puVar6 + 0x71);
  }
  param_2 = puVar4;
  if (bVar3) {
    if (puVar4 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar7 = (undefined4 *)FUN_00528160(&param_1,1,puVar4,iVar5);
      uVar2 = *puVar7;
      *(undefined1 *)(unaff_ESI + 1) = 1;
      *unaff_ESI = uVar2;
      return;
    }
    FUN_00528330();
  }
  if ((int)param_2[3] < *(int *)(iVar5 + 0xc)) {
    puVar7 = (undefined4 *)FUN_00528160(&param_1,bVar3,puVar4,iVar5);
    *unaff_ESI = *puVar7;
    *(undefined1 *)(unaff_ESI + 1) = 1;
    return;
  }
  FUN_00527f60();
  FUN_0089120c(iVar5);
  *(undefined1 *)(unaff_ESI + 1) = 0;
  *unaff_ESI = param_2;
  return;
}

