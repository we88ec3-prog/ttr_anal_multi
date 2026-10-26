
void FUN_008c5cc0(int param_1,int param_2)

{
  *(int *)(param_1 + 0x10) = param_2;
  *(uint *)(param_1 + 0x18) =
       CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 6),*(undefined1 *)(param_2 + 7)),
                         *(undefined1 *)(param_2 + 8)),*(undefined1 *)(param_2 + 9));
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}

