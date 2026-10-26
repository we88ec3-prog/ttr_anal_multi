
void FUN_004fb320(int param_1,undefined4 *param_2)

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
  cVar1 = *(char *)((int)puVar5 + 0xcd);
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
    cVar1 = *(char *)((int)puVar4 + 0xcd);
  }
  param_2 = puVar2;
  if (bVar6) {
    if (puVar2 == (undefined4 *)**(int **)(param_1 + 4)) {
      bVar6 = true;
      goto LAB_004fb373;
    }
    FUN_004fb580();
  }
  if (*(uint *)(iVar3 + 0xc) <= (uint)param_2[3]) {
    _eh_vector_destructor_iterator_((void *)(iVar3 + 0x18),0x24,5,FUN_004fa440);
    FUN_0089120c(iVar3);
    *unaff_ESI = param_2;
    *(undefined1 *)(unaff_ESI + 1) = 0;
    return;
  }
LAB_004fb373:
  puVar5 = (undefined4 *)FUN_004fb3e0(&param_1,bVar6,iVar3);
  *unaff_ESI = *puVar5;
  *(undefined1 *)(unaff_ESI + 1) = 1;
  return;
}

