
void FUN_006c5860(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xac) == 1) {
    FUN_006c5400(in_ECX);
  }
  else if (*(int *)(in_ECX + 0xac) == 2) {
    FUN_006c54a0();
    return;
  }
  return;
}

