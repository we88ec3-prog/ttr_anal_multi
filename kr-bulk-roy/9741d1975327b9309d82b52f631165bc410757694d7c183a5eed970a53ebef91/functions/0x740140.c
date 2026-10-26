
int FUN_00740140(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  int unaff_ESI;
  int unaff_EDI;
  
  if (unaff_EDI == 0) {
    *param_1 = 0;
    param_1[1] = 0;
    return 0;
  }
  FUN_0082ef00(&stack0x00000004);
  if ((in_ECX != *(int *)(unaff_ESI + 0x20)) && (iVar2 = *(int *)(in_ECX + 0x10), iVar2 != 0)) {
    uVar1 = *(undefined4 *)(iVar2 + 0x24);
    param_1[1] = *(undefined4 *)(iVar2 + 0x28);
    *param_1 = uVar1;
    return 0;
  }
  iVar2 = FUN_008bb2e0(*(undefined4 *)(*(int *)(unaff_ESI + 8) + 0x58));
  if (iVar2 == 0) {
    iVar2 = *(int *)(*(int *)(*(int *)(unaff_ESI + 8) + 0x58) + 0x54);
    uVar1 = *(undefined4 *)(iVar2 + 0x40);
    param_1[1] = *(undefined4 *)(iVar2 + 0x44);
    *param_1 = uVar1;
    iVar2 = 0;
  }
  return iVar2;
}

