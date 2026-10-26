
void FUN_008f5120(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x18) = param_2[5];
  *(undefined4 *)(param_1 + 4) = *param_2;
  *(undefined4 *)(param_1 + 0x1c) = param_2[6];
  FUN_008f4e50(param_2,0);
  FUN_008f4e50(param_2,1);
  return;
}

