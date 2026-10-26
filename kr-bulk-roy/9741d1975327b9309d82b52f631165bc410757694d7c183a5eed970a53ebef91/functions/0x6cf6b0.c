
void FUN_006cf6b0(undefined4 param_1,undefined4 *param_2)

{
  undefined1 *in_EAX;
  
  *(undefined4 *)(in_EAX + 0x10) = 0;
  *(undefined4 *)(in_EAX + 0x14) = 0xf;
  *in_EAX = 0;
  FUN_0040b0b0(param_1,0);
  *(undefined4 *)(in_EAX + 0x1c) = *param_2;
  return;
}

