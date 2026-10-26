
void FUN_004f3cf0(undefined4 *param_1,undefined4 *param_2,code *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  int iVar5;
  
  puVar3 = param_1;
  while (puVar3 = puVar3 + 1, puVar3 != param_2) {
    uVar1 = *puVar3;
    cVar4 = (*param_3)(uVar1,*param_1);
    if (cVar4 == '\0') {
      cVar4 = (*param_3)(uVar1,puVar3[-1]);
      puVar2 = puVar3;
      while (cVar4 != '\0') {
        *puVar2 = puVar2[-1];
        cVar4 = (*param_3)(uVar1,puVar2[-2]);
        puVar2 = puVar2 + -1;
      }
      *puVar2 = uVar1;
    }
    else {
      iVar5 = (int)puVar3 - (int)param_1 >> 2;
      FID_conflict__memcpy(puVar3 + (1 - iVar5),param_1,iVar5 * 4);
      *param_1 = uVar1;
    }
  }
  return;
}

