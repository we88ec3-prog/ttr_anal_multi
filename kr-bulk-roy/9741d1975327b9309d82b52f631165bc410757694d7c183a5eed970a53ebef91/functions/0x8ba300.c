
void FUN_008ba300(int param_1)

{
  uint *puVar1;
  
  if ((*(int *)(param_1 + 0x9c) != 0) && ((*(byte *)(*(int *)(param_1 + 0x9c) + 4) & 1) != 0)) {
    FUN_008b9f80(*(undefined4 *)(*(int *)(param_1 + 4) + 100),*(undefined4 *)(param_1 + 0x58));
    *(undefined4 *)(param_1 + 0x58) = 0;
    puVar1 = (uint *)(*(int *)(param_1 + 0x9c) + 4);
    *puVar1 = *puVar1 & 0xfffffffe;
    return;
  }
  *(undefined4 *)(param_1 + 0x58) = 0;
  return;
}

