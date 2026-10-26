
void FUN_00844b70(void)

{
  int *in_ECX;
  int in_EDX;
  
  if (*(int *)(in_EDX + 0x168) == 0) {
    if (*(int *)(in_EDX + 0x16c) == 0) {
      if (*(int *)(in_EDX + 0x164) == 0) {
        return;
      }
      (**(code **)(*in_ECX + 0xe0))(*(undefined4 *)(in_EDX + 0x164));
      return;
    }
    (**(code **)(*in_ECX + 0xe4))(*(undefined4 *)(in_EDX + 0x16c));
  }
  return;
}

