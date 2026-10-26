
void FUN_00443da0(void)

{
  undefined4 uVar1;
  undefined4 *in_EAX;
  int in_ECX;
  
  *in_EAX = *(undefined4 *)(in_ECX + 0x2c);
  in_EAX[1] = *(undefined4 *)(in_ECX + 0x30);
  uVar1 = *(undefined4 *)(in_ECX + 0x38);
  in_EAX[2] = *(undefined4 *)(in_ECX + 0x34);
  in_EAX[3] = uVar1;
  return;
}

