
int FUN_00454070(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar4 = 0;
  puVar3 = (undefined4 *)(in_ECX + 0x5ed0);
  do {
    iVar1 = (**(code **)(*DAT_00fba7a4 + 0x1c))(iVar4);
    if (iVar1 != 0) {
      puVar3[4] = (uint)*(ushort *)(iVar1 + 0x88);
      *puVar3 = 1;
      if ((*(int *)(iVar1 + 0x15c) != 0) && (*(int *)(iVar1 + 0x370) != 0)) {
        FUN_007a76b0(*(int *)(iVar1 + 0x15c));
      }
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 0xe;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  return iVar2;
}

