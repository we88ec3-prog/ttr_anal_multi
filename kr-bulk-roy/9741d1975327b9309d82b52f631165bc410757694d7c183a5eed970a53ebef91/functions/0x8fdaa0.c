
void FUN_008fdaa0(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 in_ECX;
  
  *(undefined4 *)(in_EAX + 0x48) = in_ECX;
  *(undefined4 *)(in_EAX + 0x44) = param_1;
  *(undefined4 *)(in_EAX + 0x4c) = param_2;
  FUN_005723f0();
  return;
}

