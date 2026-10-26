
undefined4 FUN_008c3bb0(int param_1,int param_2)

{
  *(int *)(param_1 + 0x10) = param_2;
  *(uint *)(param_1 + 0x20) =
       (uint)(ushort)(CONCAT11(*(undefined1 *)(param_2 + 6),*(undefined1 *)(param_2 + 7)) >> 1);
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return 0;
}

