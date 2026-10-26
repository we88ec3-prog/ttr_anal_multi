
void FUN_008ea9b0(void)

{
  int in_EAX;
  int iVar1;
  undefined4 in_ECX;
  
  iVar1 = (**(code **)(in_EAX + 0x1fc))();
  if (iVar1 != 0) {
    *(undefined4 *)(in_EAX + 0x280) = 0;
    *(undefined4 *)(in_EAX + 0x27c) = 0;
    return;
  }
  *(undefined4 *)(in_EAX + 0x27c) = in_ECX;
  FUN_008bc7a0();
  return;
}

