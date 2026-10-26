
void FUN_00505f70(int param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *unaff_ESI;
  bool bVar6;
  
  iVar3 = (int)param_2;
  puVar5 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  bVar6 = true;
  cVar1 = *(char *)((int)puVar5 + 0xb5);
  puVar2 = *(undefined4 **)(param_1 + 4);
  while (cVar1 == '\0') {
    bVar6 = *(int *)((int)param_2 + 0xc) < (int)puVar5[3];
    if (bVar6) {
      puVar4 = (undefined4 *)*puVar5;
    }
    else {
      puVar4 = (undefined4 *)puVar5[2];
    }
    puVar2 = puVar5;
    puVar5 = puVar4;
    cVar1 = *(char *)((int)puVar4 + 0xb5);
  }
  param_2 = puVar2;
  if (bVar6) {
    if (puVar2 == (undefined4 *)**(int **)(param_1 + 4)) {
      bVar6 = true;
      goto LAB_00505fc3;
    }
    FUN_00506290();
  }
  if (*(int *)(iVar3 + 0xc) <= (int)param_2[3]) {
    FUN_005045c0(iVar3 + 0x10);
    FUN_0089120c(iVar3);
    *unaff_ESI = param_2;
    *(undefined1 *)(unaff_ESI + 1) = 0;
    return;
  }
LAB_00505fc3:
  puVar5 = (undefined4 *)FUN_00506100(&param_1,bVar6,iVar3);
  *unaff_ESI = *puVar5;
  *(undefined1 *)(unaff_ESI + 1) = 1;
  return;
}

