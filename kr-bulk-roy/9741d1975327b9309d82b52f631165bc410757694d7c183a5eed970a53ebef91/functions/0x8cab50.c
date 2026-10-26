
undefined4 FUN_008cab50(void)

{
  char cVar1;
  ushort uVar2;
  int in_EAX;
  int iVar3;
  
  uVar2 = *(ushort *)(in_EAX + 0x54);
  iVar3 = *(int *)(in_EAX + 0x5c);
  if ((uVar2 < 2) || (iVar3 == 0)) {
    *(undefined4 *)(in_EAX + 0x5c) = 0;
  }
  else if (uVar2 != 0) {
    while( true ) {
      if (uVar2 < 2) {
        *(undefined4 *)(iVar3 + 4) = 0;
      }
      else {
        *(int *)(iVar3 + 4) = *(int *)(iVar3 + 8) + *(int *)(iVar3 + 0x10) * 4;
      }
      if ((*(byte *)(iVar3 + 0xc) & 8) == 0) {
        *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + *(int *)(iVar3 + 0x10) * 4 + -4;
        *(int *)(iVar3 + 0x14) = (*(int *)(iVar3 + 0x14) - *(int *)(iVar3 + 0x10)) + 1;
      }
      cVar1 = FUN_008caae0();
      if ((cVar1 != '\0') || (cVar1 = FUN_008caae0(), cVar1 != '\0')) break;
      iVar3 = *(int *)(iVar3 + 4);
      uVar2 = uVar2 - 1;
      if (uVar2 == 0) {
        return 0;
      }
    }
    return 1;
  }
  return 0;
}

