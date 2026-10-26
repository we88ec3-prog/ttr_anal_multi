
void FUN_006a4e50(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  FUN_007459c0();
  iVar1 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_006a4e8c;
    iVar1 = FUN_00745c20();
  }
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x60) != 0)) && ((*(uint *)(iVar1 + 0x28) >> 0xc & 1) == 0)
     ) {
    FUN_0074a010(iVar1);
  }
LAB_006a4e8c:
  if ((*(int *)(*(int *)(in_ECX + 0xf8) + 0xcc) != 0) &&
     (*(int *)(*(int *)(in_ECX + 0xf8) + 0xd8) != 0)) {
    uVar2 = FUN_005f55a0();
    switch(uVar2) {
    case 0:
      FUN_006a4820();
      return;
    case 1:
      FUN_006a4a60();
      return;
    case 2:
      FUN_006a48e0();
      return;
    case 3:
      FUN_006a49a0();
      return;
    }
  }
  return;
}

