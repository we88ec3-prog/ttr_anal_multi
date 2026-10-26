
void FUN_006fb0c0(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0x10);
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  *(undefined4 *)(iVar1 + 0x2c) = 0;
  if ((*(byte *)(*(int *)(iVar1 + 0x70) + 5) & 3) != 0) {
    FUN_006f9f70(iVar1,*(int *)(iVar1 + 0x70));
  }
  if ((3 < *(int *)(*(int *)(iVar1 + 0x70) + 0x50)) &&
     (iVar2 = *(int *)(*(int *)(iVar1 + 0x70) + 0x48), (*(byte *)(iVar2 + 5) & 3) != 0)) {
    FUN_006f9f70(iVar1,iVar2);
  }
  if ((3 < *(int *)(*(int *)(unaff_ESI + 0x10) + 0x68)) &&
     (iVar2 = *(int *)(*(int *)(unaff_ESI + 0x10) + 0x60), (*(byte *)(iVar2 + 5) & 3) != 0)) {
    FUN_006f9f70(iVar1,iVar2);
  }
  FUN_006fafd0();
  *(undefined1 *)(iVar1 + 0x15) = 1;
  return;
}

