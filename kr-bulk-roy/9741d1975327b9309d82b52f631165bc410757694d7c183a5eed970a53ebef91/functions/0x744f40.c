
void FUN_00744f40(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_ESI;
  
  if (((*(char *)(unaff_ESI + 0x158) != '\0') && (*(int *)(unaff_ESI + 0x24) != 0)) &&
     ((*(uint *)(unaff_ESI + 0x28) >> 7 & 1) != 0)) {
    iVar1 = FUN_00891268(0x34);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_00744b20();
    }
    iVar2 = unaff_ESI;
    if (((*(byte *)(unaff_ESI + 0x28) & 0x10) == 0) && (iVar2 = 0, *(int *)(unaff_ESI + 0x60) != 0))
    {
      iVar2 = FUN_00745c20();
    }
    *(undefined4 *)(iVar1 + 0x10) = param_1;
    if (iVar2 == 0) {
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = *(undefined4 *)(iVar2 + 0x20);
    }
    *(undefined4 *)(iVar1 + 4) = uVar3;
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(unaff_ESI + 0x20);
    *(int *)(iVar1 + 0xc) = unaff_ESI;
    if (*(char *)(param_2 + 0x164 + unaff_ESI) != '\0') {
      FUN_0077b6c0(unaff_ESI + 0x15c);
      FUN_00750920(iVar1);
      return;
    }
    FUN_007535c0(param_1);
    FUN_00750920(iVar1);
  }
  return;
}

