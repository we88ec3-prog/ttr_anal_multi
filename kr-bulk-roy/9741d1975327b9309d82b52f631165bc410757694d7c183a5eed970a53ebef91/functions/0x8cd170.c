
void FUN_008cd170(void)

{
  int in_EAX;
  int in_EDX;
  
  if ((0 < in_EAX) && (in_EAX < 3)) {
    *(int *)(in_EDX + 0xc) = in_EAX;
    *(undefined4 *)(in_EDX + 4) = 0;
    FUN_008ccf00();
    FUN_008ccf00();
    return;
  }
  *(undefined4 *)(in_EDX + 4) = 6;
  *(int *)(in_EDX + 0xc) = in_EAX;
  return;
}

