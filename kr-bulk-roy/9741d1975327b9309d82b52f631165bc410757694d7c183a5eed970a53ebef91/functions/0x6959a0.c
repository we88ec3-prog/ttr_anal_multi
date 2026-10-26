
void FUN_006959a0(void)

{
  int *in_ECX;
  
  FUN_006ad0e0();
  if (*(int *)(in_ECX[0x20] + 0xcc) != 0) {
    *(undefined1 *)(*(int *)(in_ECX[0x20] + 0xcc) + 0xe0) = 0;
  }
  (**(code **)(*in_ECX + 0xb4))(0xda);
  return;
}

