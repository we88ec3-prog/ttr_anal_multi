
void FUN_006f6c40(undefined1 *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int *unaff_ESI;
  
  while (param_2 != 0) {
    param_2 = param_2 + -1;
    if ((unaff_ESI + 0x83 <= (int *)*unaff_ESI) &&
       (iVar3 = *unaff_ESI + (-0xc - (int)unaff_ESI), iVar3 != 0)) {
      iVar1 = unaff_ESI[2];
      if (*(uint *)(*(int *)(iVar1 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar1 + 0x10) + 0x44)) {
        FUN_006fb3a0();
      }
      puVar2 = *(undefined4 **)(iVar1 + 8);
      uVar4 = FUN_006fec70(iVar1,unaff_ESI + 3,iVar3);
      *puVar2 = uVar4;
      puVar2[2] = 4;
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 0x10;
      unaff_ESI[1] = unaff_ESI[1] + 1;
      *unaff_ESI = (int)(unaff_ESI + 3);
      FUN_006f6b60();
    }
    *(undefined1 *)*unaff_ESI = *param_1;
    *unaff_ESI = *unaff_ESI + 1;
    param_1 = param_1 + 1;
  }
  return;
}

