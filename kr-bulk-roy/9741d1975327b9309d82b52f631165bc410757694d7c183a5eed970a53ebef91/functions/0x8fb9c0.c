
void FUN_008fb9c0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 0x1c);
  iVar2 = *(int *)(param_1 + 0xc);
  if (iVar2 != 0) {
    FUN_008fb750();
    FUN_008b9f80(uVar1,iVar2);
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}

