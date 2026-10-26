
void FUN_0058fa00(int *param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  undefined1 local_c [8];
  
  if (*(int *)(unaff_EDI + 8) == 0) {
LAB_0058fa17:
    FUN_00539350(unaff_ESI,1,param_2);
    return;
  }
  if (param_1 == (int *)**(int **)(unaff_EDI + 4)) {
    piVar2 = param_1 + 3;
    if (7 < (uint)param_1[8]) {
      piVar2 = (int *)*piVar2;
    }
    iVar3 = FUN_0044df20(0,piVar2,param_1[7]);
    if (iVar3 < 0) {
      FUN_00539350(unaff_ESI,1,param_2);
      return;
    }
  }
  else if (param_1 == *(int **)(unaff_EDI + 4)) {
    cVar1 = FUN_0044fa20();
    if (cVar1 != '\0') {
      FUN_00539350(unaff_ESI,0,param_2);
      return;
    }
  }
  else {
    cVar1 = FUN_0044fa20();
    if (cVar1 != '\0') {
      FUN_004f9850();
      cVar1 = FUN_0044fa20();
      if (cVar1 != '\0') {
        if (*(char *)(param_1[2] + 0x45) == '\0') {
          FUN_00539350(unaff_ESI,1,param_2);
          return;
        }
        FUN_00539350(unaff_ESI,0,param_2);
        return;
      }
    }
    cVar1 = FUN_0044fa20();
    if ((cVar1 != '\0') &&
       ((FUN_00426d80(), param_1 == *(int **)(unaff_EDI + 4) ||
        (cVar1 = FUN_0044fa20(), cVar1 != '\0')))) {
      if (*(char *)(param_1[2] + 0x45) != '\0') {
        FUN_00539350(unaff_ESI,0,param_2);
        return;
      }
      goto LAB_0058fa17;
    }
  }
  puVar4 = (undefined4 *)FUN_00539230(unaff_EDI,local_c,param_2);
  *unaff_ESI = *puVar4;
  return;
}

