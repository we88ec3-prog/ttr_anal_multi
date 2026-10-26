
void FUN_004d4540(int param_1,undefined1 param_2)

{
  int iVar1;
  uint in_EAX;
  byte in_DL;
  
  if (((((in_EAX & 0xff) < 10) &&
       (param_1 = param_1 + (in_EAX & 0xff) * 0x210, *(int *)(param_1 + 0x5c) != 0)) &&
      (param_1 != 0)) && ((in_DL < 7 && (iVar1 = param_1 + 0x110 + (uint)in_DL * 0x1c, iVar1 != 0)))
     ) {
    *(undefined1 *)(iVar1 + 0x18) = param_2;
  }
  return;
}

