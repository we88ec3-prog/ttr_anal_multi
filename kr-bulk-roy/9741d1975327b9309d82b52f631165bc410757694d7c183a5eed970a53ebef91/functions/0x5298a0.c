
void FUN_005298a0(int param_1,undefined4 *param_2)

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
  cVar1 = *(char *)((int)puVar5 + 0x4d);
  puVar2 = *(undefined4 **)(param_1 + 4);
  while (cVar1 == '\0') {
    bVar6 = *(uint *)((int)param_2 + 0xc) < (uint)puVar5[3];
    if (bVar6) {
      puVar4 = (undefined4 *)*puVar5;
    }
    else {
      puVar4 = (undefined4 *)puVar5[2];
    }
    puVar2 = puVar5;
    puVar5 = puVar4;
    cVar1 = *(char *)((int)puVar4 + 0x4d);
  }
  param_2 = puVar2;
  if (bVar6) {
    if (puVar2 == (undefined4 *)**(int **)(param_1 + 4)) {
      bVar6 = true;
      goto LAB_005298f0;
    }
    FUN_00466cb0();
  }
  if (*(uint *)(iVar3 + 0xc) <= (uint)param_2[3]) {
    FUN_005291f0();
    FUN_0089120c(iVar3);
    *unaff_EDI = param_2;
    *(undefined1 *)(unaff_EDI + 1) = 0;
    return;
  }
LAB_005298f0:
  puVar5 = (undefined4 *)FUN_00529950(&param_1,bVar6,iVar3);
  *unaff_EDI = *puVar5;
  *(undefined1 *)(unaff_EDI + 1) = 1;
  return;
}

