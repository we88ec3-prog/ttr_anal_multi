
void FUN_005e2440(undefined4 param_1)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  int in_ECX;
  short *psVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar6 = param_1;
  iVar4 = *(int *)(in_ECX + 0x180);
  if ((iVar4 != 0) && (*(int *)(in_ECX + 0x184) != 0)) {
    if (*(int *)(iVar4 + 0x38) == 2) {
      uVar6 = 0x18e;
      FUN_00585620(0x18e);
      psVar3 = (short *)FUN_00585330(uVar6);
      psVar5 = psVar3;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_00404300(psVar3,(int)psVar5 - (int)(psVar3 + 1) >> 1);
      return;
    }
    iVar2 = *(int *)(*(int *)(in_ECX + 0x184) + 8);
    if ((iVar2 == 0x10) || (iVar2 == 0x1c)) {
      uVar7 = *(undefined4 *)(iVar4 + 0x50);
      iVar4 = FUN_00404c10();
      param_1 = uVar7;
      FUN_008438c0(&param_1);
      if ((in_ECX != *(int *)(iVar4 + 4)) &&
         (((iVar4 = *(int *)(in_ECX + 0x10), iVar4 != 0 && (*(int *)(iVar4 + 0x1c) != 0)) &&
          (*(int *)(iVar4 + 0x38) == 2)))) {
        uVar7 = 399;
        FUN_00585620(399);
        FUN_00585330(uVar7);
        FUN_00404420(uVar6);
      }
    }
  }
  return;
}

