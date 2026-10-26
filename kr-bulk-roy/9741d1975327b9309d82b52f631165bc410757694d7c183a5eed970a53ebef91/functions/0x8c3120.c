
void FUN_008c3120(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x60) + 8);
  iVar3 = *(int *)(param_1 + 0x15c);
  if (*(int *)(param_1 + 0x164) != 0) {
    if (iVar3 != 0) {
      puVar2 = (undefined4 *)(*(int *)(param_1 + 0x164) + 0x10);
      do {
        FUN_008b9f80(uVar1,*puVar2);
        *puVar2 = 0;
        *(undefined2 *)(puVar2 + -2) = 0;
        puVar2 = puVar2 + 5;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    FUN_008b9f80(uVar1,*(undefined4 *)(param_1 + 0x164));
    *(undefined4 *)(param_1 + 0x164) = 0;
  }
  *(undefined4 *)(param_1 + 0x15c) = 0;
  *(undefined2 *)(param_1 + 0x158) = 0;
  *(undefined4 *)(param_1 + 0x160) = 0;
  return;
}

