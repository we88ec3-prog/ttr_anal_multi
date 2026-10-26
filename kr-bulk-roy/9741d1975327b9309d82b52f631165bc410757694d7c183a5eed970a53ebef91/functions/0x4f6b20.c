
undefined4 FUN_004f6b20(void)

{
  undefined4 *in_EAX;
  int in_ECX;
  int unaff_EDI;
  
  FUN_008438c0(&stack0x00000004);
  if (in_ECX != *(int *)(unaff_EDI + 0x104)) {
    FUN_004026e0(*(undefined4 *)(in_ECX + 0x10),0,0xffffffff);
    return 1;
  }
  in_EAX[4] = 0;
  if (7 < (uint)in_EAX[5]) {
    in_EAX = (undefined4 *)*in_EAX;
  }
  *(undefined2 *)in_EAX = 0;
  return 0;
}

