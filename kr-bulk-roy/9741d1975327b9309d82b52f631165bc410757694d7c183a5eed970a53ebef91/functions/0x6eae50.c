
undefined4 FUN_006eae50(int param_1,int param_2)

{
  if (((*(uint *)(param_2 + 0x1c) & 0x10000) != 0) && (0xfffe0100 < *(uint *)(param_2 + 0xc4))) {
    *(undefined4 *)(param_1 + 0x44) = 0x80000000;
    return 1;
  }
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffffaf | 0x20;
  *(undefined4 *)(param_1 + 0x44) = 0x80000000;
  return 1;
}

