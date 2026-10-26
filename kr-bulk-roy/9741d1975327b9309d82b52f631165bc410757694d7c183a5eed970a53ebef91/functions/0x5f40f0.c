
void FUN_005f40f0(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  FUN_007545b0();
  FUN_00749d00();
  FUN_00749a00(0,0x1e);
  FUN_00749d00();
  iVar1 = *(int *)(*(int *)(in_ECX + 0x198) + 0x14);
  iVar2 = iVar1 + 10;
  FUN_00749a00(*(undefined4 *)(*(int *)(in_ECX + 0x1c8) + 8),iVar2);
  FUN_00749a00(*(undefined4 *)(*(int *)(in_ECX + 0x1d0) + 8),iVar2);
  FUN_00749a00(*(undefined4 *)(*(int *)(in_ECX + 0x1d4) + 8),iVar1 + 0x1e);
  return;
}

