
undefined4 FUN_00731230(void)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  int *unaff_ESI;
  
  iVar3 = *(int *)(*(int *)(*unaff_ESI + 4) + 0xc + (int)unaff_ESI);
  while( true ) {
    if (iVar3 != 0) {
      return 0;
    }
    uVar2 = FUN_00733b00();
    if (((0xff < (int)uVar2) ||
        (((iVar3 = _isspace(uVar2 & 0xff), iVar3 == 0 && ((char)uVar2 != '\n')) &&
         ((char)uVar2 != '\r')))) || ((int)uVar2 < 1)) break;
    uVar1 = FUN_00733980();
    FUN_00429630(1,uVar1);
    iVar3 = *(int *)(*(int *)(*unaff_ESI + 4) + 0xc + (int)unaff_ESI);
  }
  return 1;
}

