
void FUN_00576910(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_006dfc40();
  iVar1 = *(int *)(iVar1 + 0x18);
  iVar2 = FUN_006dfc40();
  iVar2 = *(int *)(iVar2 + 0x1c);
  *(float *)(in_ECX + 0xfc) = (float)((iVar1 - *(int *)(in_ECX + 0xd0)) / 2);
  *(float *)(in_ECX + 0x100) = (float)((iVar2 - *(int *)(in_ECX + 0xd4)) / 2);
  FUN_00575be0();
  if (*(int *)(in_ECX + 0x90) != 0) {
    FUN_00577080();
  }
  return;
}

