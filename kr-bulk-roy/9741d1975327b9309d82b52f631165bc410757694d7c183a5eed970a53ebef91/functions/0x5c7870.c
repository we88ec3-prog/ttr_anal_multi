
void FUN_005c7870(int param_1)

{
  int in_EAX;
  int in_ECX;
  int iVar1;
  
  if (in_ECX != param_1) {
    iVar1 = in_ECX - in_EAX;
    do {
      FUN_004026e0(in_ECX,0,0xffffffff);
      FUN_005c7cd0(iVar1 + 0x1c + in_EAX);
      in_ECX = in_ECX + 0x2c;
      in_EAX = in_EAX + 0x2c;
    } while (in_ECX != param_1);
  }
  return;
}

