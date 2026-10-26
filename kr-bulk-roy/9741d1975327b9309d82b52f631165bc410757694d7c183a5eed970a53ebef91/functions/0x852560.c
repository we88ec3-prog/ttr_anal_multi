
void FUN_00852560(int param_1)

{
  int in_EAX;
  int in_ECX;
  int iVar1;
  
  if (in_ECX != param_1) {
    iVar1 = in_ECX - in_EAX;
    do {
      FUN_006dd790(in_ECX);
      *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(iVar1 + 0x10 + in_EAX);
      in_ECX = in_ECX + 0x14;
      in_EAX = in_EAX + 0x14;
    } while (in_ECX != param_1);
  }
  return;
}

