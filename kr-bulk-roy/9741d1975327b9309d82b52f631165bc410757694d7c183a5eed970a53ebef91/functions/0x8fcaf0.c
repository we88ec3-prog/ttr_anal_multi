
undefined4 FUN_008fcaf0(void)

{
  uint in_EAX;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int unaff_EDI;
  
  uVar1 = *(int *)(unaff_EDI + 0x10c0) - *(int *)(unaff_EDI + 0x10bc);
  if (in_EAX <= uVar1) {
    uVar1 = in_EAX;
  }
  *(int *)(unaff_EDI + 0x10b8) = *(int *)(unaff_EDI + 0x10b8) + uVar1;
  uVar3 = in_EAX - uVar1;
  *(uint *)(unaff_EDI + 0x10bc) = *(int *)(unaff_EDI + 0x10bc) + uVar1;
  if (uVar3 == 0) {
    return 0;
  }
  while( true ) {
    uVar1 = 0x1000;
    if (uVar3 < 0x1000) {
      uVar1 = uVar3;
    }
    uVar2 = FUN_008fc770(unaff_EDI + 0xc,0,uVar1);
    if (uVar2 < uVar1) break;
    *(int *)(unaff_EDI + 0x10b8) = *(int *)(unaff_EDI + 0x10b8) + uVar1;
    uVar3 = uVar3 - uVar1;
    if (uVar3 == 0) {
      return 0;
    }
  }
  return 0x55;
}

