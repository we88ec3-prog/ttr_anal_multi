
void FUN_0050f720(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *unaff_EDI;
  undefined4 local_8;
  
  iVar3 = (int)param_2;
  puVar5 = *(undefined4 **)(param_1 + 4);
  bVar2 = true;
  local_8 = 1;
  if (*(char *)((int)puVar5[1] + 0x69) == '\0') {
    puVar4 = (undefined4 *)puVar5[1];
    do {
      puVar5 = puVar4;
      if ((*(int *)((int)param_2 + 0xc) < (int)puVar5[3]) ||
         ((*(int *)((int)param_2 + 0xc) <= (int)puVar5[3] &&
          (*(int *)((int)param_2 + 0x10) < (int)puVar5[4])))) {
        puVar4 = (undefined4 *)*puVar5;
        bVar2 = true;
        local_8 = 1;
      }
      else {
        puVar4 = (undefined4 *)puVar5[2];
        bVar2 = false;
        local_8 = 0;
      }
    } while (*(char *)((int)puVar4 + 0x69) == '\0');
  }
  param_2 = puVar5;
  if (bVar2) {
    if (puVar5 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar5 = (undefined4 *)FUN_0050f810(&param_1,1,iVar3);
      uVar1 = *puVar5;
      *(undefined1 *)(unaff_EDI + 1) = 1;
      *unaff_EDI = uVar1;
      return;
    }
    FUN_0050fc50();
  }
  if ((*(int *)(iVar3 + 0xc) <= (int)param_2[3]) &&
     ((*(int *)(iVar3 + 0xc) < (int)param_2[3] || (*(int *)(iVar3 + 0x10) <= (int)param_2[4])))) {
    FUN_0050dde0();
    FUN_0089120c(iVar3);
    *(undefined1 *)(unaff_EDI + 1) = 0;
    *unaff_EDI = param_2;
    return;
  }
  puVar5 = (undefined4 *)FUN_0050f810(&param_1,local_8,iVar3);
  *unaff_EDI = *puVar5;
  *(undefined1 *)(unaff_EDI + 1) = 1;
  return;
}

