
int FUN_004c0690(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar4 = 0;
  iVar3 = in_ECX + 0x5ee8;
  do {
    iVar1 = (**(code **)(*DAT_00fba7a4 + 0x1c))(iVar4);
    if (iVar1 != 0) {
      *(uint *)(iVar3 + -8) = (uint)*(ushort *)(iVar1 + 0x88);
      if ((*(int *)(iVar1 + 0x15c) != 0) && (*(int *)(iVar1 + 0x370) != 0)) {
        FUN_007a76b0(*(int *)(iVar1 + 0x15c));
      }
      *(undefined4 *)(iVar3 + -0x18) = 1;
      iVar2 = iVar2 + 1;
    }
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar4 < 3);
  return iVar2;
}

