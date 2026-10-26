
void FUN_007948a0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int in_EAX;
  uint unaff_EDI;
  
  if ((uint)((*(int *)(in_EAX + 0x1c) - *(int *)(in_EAX + 0x18)) / 0x30) <= unaff_EDI) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  puVar1 = (undefined4 *)(*(int *)(in_EAX + 0x18) + 0x24 + unaff_EDI * 0x30);
  *puVar1 = param_1;
  puVar1[1] = param_2;
  puVar1[2] = param_3;
  return;
}

