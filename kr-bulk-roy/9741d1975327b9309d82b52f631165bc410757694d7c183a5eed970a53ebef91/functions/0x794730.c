
void FUN_00794730(undefined4 param_1)

{
  int in_EAX;
  uint unaff_EDI;
  
  if ((uint)((*(int *)(in_EAX + 0x1c) - *(int *)(in_EAX + 0x18)) / 0x18) <= unaff_EDI) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  *(undefined4 *)(*(int *)(in_EAX + 0x18) + 0x10 + unaff_EDI * 0x18) = param_1;
  return;
}

