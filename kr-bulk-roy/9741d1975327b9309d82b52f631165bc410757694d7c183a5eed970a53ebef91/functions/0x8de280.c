
void FUN_008de280(void)

{
  undefined4 uVar1;
  int in_EAX;
  undefined4 *in_ECX;
  
  uVar1 = *(undefined4 *)(in_EAX + 0x1c);
  FUN_008de260();
  FUN_008b9f80(uVar1,in_ECX[2]);
  in_ECX[2] = 0;
  *in_ECX = 0;
  in_ECX[1] = 0;
  return;
}

