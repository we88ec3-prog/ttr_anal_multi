
undefined4 FUN_008e01f0(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int extraout_ECX;
  int unaff_ESI;
  
  iVar1 = *(int *)(*(int *)(unaff_ESI + 4) + 0x290);
  iVar4 = iVar1 + 0x52c;
  if (*(int *)(iVar1 + 0x768) != 0) {
    uVar2 = FUN_008de130(param_2);
    uVar2 = uVar2 & 0xff;
    if (*(uint *)(iVar1 + 0x768) <= uVar2) {
      return 3;
    }
    iVar4 = *(int *)(iVar1 + 0x76c + uVar2 * 4);
    if ((*(int *)(unaff_ESI + 0x44) != 0) && (param_1 != 0)) {
      *(undefined4 *)(unaff_ESI + 0x48) = *(undefined4 *)(*(int *)(param_1 + 0x28) + 4 + uVar2 * 4);
    }
  }
  *(undefined4 *)(unaff_ESI + 0x378) = *(undefined4 *)(iVar4 + 0x220);
  *(undefined4 *)(unaff_ESI + 0x388) = *(undefined4 *)(iVar4 + 0x238);
  uVar3 = FUN_008e0150(*(undefined4 *)(*(int *)(unaff_ESI + 0x4c) + 0x558));
  *(undefined4 *)(unaff_ESI + 0x380) = uVar3;
  *(undefined4 *)(unaff_ESI + 0x2e8) = *(undefined4 *)(extraout_ECX + 0x210);
  *(undefined4 *)(unaff_ESI + 0x2ec) = *(undefined4 *)(extraout_ECX + 0x214);
  *(int *)(unaff_ESI + 0x3a0) = extraout_ECX;
  return 0;
}

