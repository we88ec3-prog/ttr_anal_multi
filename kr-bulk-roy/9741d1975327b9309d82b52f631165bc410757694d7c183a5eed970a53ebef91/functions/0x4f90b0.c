
void FUN_004f90b0(int param_1,undefined4 *param_2)

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
  cVar1 = *(char *)((int)puVar5 + 0x2d);
  puVar2 = *(undefined4 **)(param_1 + 4);
  while (cVar1 == '\0') {
    bVar6 = *(char *)((int)param_2 + 0xc) < *(char *)(puVar5 + 3);
    if (bVar6) {
      puVar4 = (undefined4 *)*puVar5;
    }
    else {
      puVar4 = (undefined4 *)puVar5[2];
    }
    puVar2 = puVar5;
    puVar5 = puVar4;
    cVar1 = *(char *)((int)puVar4 + 0x2d);
  }
  param_2 = puVar2;
  if (bVar6) {
    if (puVar2 == (undefined4 *)**(int **)(param_1 + 4)) {
      bVar6 = true;
      goto LAB_004f9100;
    }
    FUN_00574e80();
  }
  if (*(char *)(iVar3 + 0xc) <= *(char *)(param_2 + 3)) {
    if (0xf < *(uint *)(iVar3 + 0x24)) {
      FUN_0089120c(*(undefined4 *)(iVar3 + 0x10));
    }
    *(undefined4 *)(iVar3 + 0x24) = 0xf;
    *(undefined4 *)(iVar3 + 0x20) = 0;
    *(undefined1 *)(iVar3 + 0x10) = 0;
    FUN_0089120c(iVar3);
    *unaff_ESI = param_2;
    *(undefined1 *)(unaff_ESI + 1) = 0;
    return;
  }
LAB_004f9100:
  puVar5 = (undefined4 *)FUN_004f94e0(&param_1,bVar6,iVar3);
  *unaff_ESI = *puVar5;
  *(undefined1 *)(unaff_ESI + 1) = 1;
  return;
}

