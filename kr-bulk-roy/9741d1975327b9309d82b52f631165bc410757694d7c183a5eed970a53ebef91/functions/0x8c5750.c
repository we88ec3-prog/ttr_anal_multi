
undefined4 FUN_008c5750(int param_1,int param_2)

{
  *(int *)(param_1 + 0x10) = param_2;
  *(uint *)(param_1 + 0x28) =
       CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_2 + 0xc),*(undefined1 *)(param_2 + 0xd)),
                         *(undefined1 *)(param_2 + 0xe)),*(undefined1 *)(param_2 + 0xf));
  *(undefined1 *)(param_1 + 0x18) = 0;
  return 0;
}

