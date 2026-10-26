
void FUN_005e2770(undefined4 param_1)

{
  short sVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  short *psVar5;
  int in_ECX;
  short *psVar6;
  int unaff_EDI;
  undefined4 uVar7;
  
  uVar3 = param_1;
  iVar4 = *(int *)(unaff_EDI + 0x180);
  if ((iVar4 != 0) && ((*(int *)(iVar4 + 0x44) != 0 || (*(int *)(iVar4 + 0x48) != 0)))) {
    iVar4 = FUN_0051c080();
    if (iVar4 == 0) {
      param_1 = 0x198;
      iVar4 = FUN_00585620();
      FUN_005740f0(&param_1);
      if (in_ECX == *(int *)(iVar4 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      psVar6 = (short *)(in_ECX + 0x10);
      if (7 < *(uint *)(in_ECX + 0x24)) {
        psVar6 = *(short **)psVar6;
      }
      psVar5 = psVar6;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_00404300(psVar6,(int)psVar5 - (int)(psVar6 + 1) >> 1);
    }
    else {
      uVar7 = 0x197;
      FUN_00585620(0x197);
      FUN_00585330(uVar7);
      FUN_00404420(uVar3);
      iVar4 = *(int *)(*(int *)(unaff_EDI + 0x180) + 0x48);
      if (iVar4 == 0) {
        iVar4 = *(int *)(*(int *)(unaff_EDI + 0x180) + 0x44);
        if (iVar4 != 0) {
          FUN_005e3b30(iVar4);
          FUN_00404420(uVar3);
        }
      }
      else {
        FUN_005e3b30(iVar4 + -1);
      }
      if ((*(int *)(*(int *)(unaff_EDI + 0x180) + 0x44) != 0) ||
         (*(int *)(*(int *)(unaff_EDI + 0x180) + 0x48) != 0)) {
        FUN_00404420(uVar3);
        return;
      }
    }
  }
  return;
}

