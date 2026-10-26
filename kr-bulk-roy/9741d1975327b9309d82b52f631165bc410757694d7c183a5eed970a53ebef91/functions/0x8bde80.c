
void FUN_008bde80(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_1 != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0xc);
    iVar2 = *(int *)(param_1 + 4);
    if (0 < iVar2) {
      do {
        FUN_008b9f80();
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_008b9f80();
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}

