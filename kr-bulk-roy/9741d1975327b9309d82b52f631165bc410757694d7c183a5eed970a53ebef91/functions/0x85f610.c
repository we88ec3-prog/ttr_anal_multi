
void FUN_0085f610(int param_1)

{
  int in_EAX;
  int in_ECX;
  int iVar1;
  
  if (in_ECX != param_1) {
    iVar1 = in_ECX - in_EAX;
    do {
      if (in_EAX != in_ECX) {
        if (*(int *)(in_EAX + 4) == 0) {
          *(undefined4 *)(in_EAX + 4) = *(undefined4 *)(iVar1 + 4 + in_EAX);
        }
        FUN_00867fd0(in_EAX,in_ECX);
      }
      in_ECX = in_ECX + 0x10;
      in_EAX = in_EAX + 0x10;
    } while (in_ECX != param_1);
  }
  return;
}

