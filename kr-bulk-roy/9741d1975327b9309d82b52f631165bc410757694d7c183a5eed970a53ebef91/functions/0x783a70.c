
int FUN_00783a70(void)

{
  undefined4 uVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  
  if (*(int *)(in_EAX + 0x54) != 0) {
    cVar2 = FUN_00783ac0();
    iVar4 = in_EAX;
    if (cVar2 == '\0') {
      iVar4 = 0;
    }
    iVar3 = _fclose(*(FILE **)(in_EAX + 0x54));
    if (iVar3 == 0) goto LAB_00783a9b;
  }
  iVar4 = 0;
LAB_00783a9b:
  *(undefined1 *)(in_EAX + 0x50) = 0;
  *(undefined1 *)(in_EAX + 0x49) = 0;
  FUN_00730d00();
  uVar1 = DAT_00fe31e4;
  *(undefined4 *)(in_EAX + 0x54) = 0;
  *(undefined4 *)(in_EAX + 0x44) = 0;
  *(undefined4 *)(in_EAX + 0x4c) = uVar1;
  return iVar4;
}

