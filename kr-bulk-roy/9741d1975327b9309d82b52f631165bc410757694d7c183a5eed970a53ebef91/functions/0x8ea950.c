
void FUN_008ea950(void)

{
  int in_EAX;
  int iVar1;
  undefined4 in_ECX;
  
  iVar1 = (**(code **)(in_EAX + 0x1fc))();
  if (iVar1 != 0) {
    *(undefined4 *)(in_EAX + 0x278) = 0;
    *(undefined4 *)(in_EAX + 0x274) = 0;
    return;
  }
  *(undefined4 *)(in_EAX + 0x274) = in_ECX;
  FUN_008bc7a0();
  return;
}

