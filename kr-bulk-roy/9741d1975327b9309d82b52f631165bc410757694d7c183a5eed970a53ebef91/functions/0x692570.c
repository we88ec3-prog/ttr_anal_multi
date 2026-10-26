
void FUN_00692570(int param_1)

{
  int in_EAX;
  int in_ECX;
  int iVar1;
  
  if (in_ECX != param_1) {
    iVar1 = in_ECX - in_EAX;
    do {
      FUN_004026e0(in_ECX,0,0xffffffff);
      *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(iVar1 + 0x1c + in_EAX);
      *(undefined4 *)(in_EAX + 0x20) = *(undefined4 *)(in_ECX + 0x20);
      in_ECX = in_ECX + 0x24;
      in_EAX = in_EAX + 0x24;
    } while (in_ECX != param_1);
  }
  return;
}

