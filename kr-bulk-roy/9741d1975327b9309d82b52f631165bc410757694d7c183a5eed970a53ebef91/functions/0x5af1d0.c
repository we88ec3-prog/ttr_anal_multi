
void FUN_005af1d0(void)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0x234);
  iVar2 = *(int *)(iVar1 + 0xac);
  if ((*(uint *)(iVar2 + 0x28) >> 8 & 1) != 0) {
    FUN_006b7990(iVar2);
  }
  if ((*(uint *)(*(int *)(iVar1 + 0xb0) + 0x28) >> 8 & 1) != 0) {
    FUN_006b9df0();
  }
  FUN_006b0c40();
  return;
}

