
uint FUN_007312a0(void)

{
  int iVar1;
  uint uVar2;
  uint *unaff_ESI;
  
  uVar2 = *unaff_ESI;
  iVar1 = *(int *)(*(int *)(uVar2 + 4) + 0xc + (int)unaff_ESI);
  while (iVar1 == 0) {
    uVar2 = FUN_00733b00();
    if (uVar2 == 0x3c) {
      return 1;
    }
    if ((int)uVar2 < 1) break;
    FUN_00733980();
    FUN_00429630(1,uVar2);
    uVar2 = *(uint *)(*unaff_ESI + 4);
    iVar1 = *(int *)(uVar2 + 0xc + (int)unaff_ESI);
  }
  return uVar2 & 0xffffff00;
}

