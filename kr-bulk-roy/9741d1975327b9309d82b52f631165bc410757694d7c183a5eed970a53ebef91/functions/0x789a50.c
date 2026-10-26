
void FUN_00789a50(void)

{
  int in_EAX;
  int in_ECX;
  
  for (; in_EAX != 0; in_EAX = in_EAX + -1) {
    if (in_ECX != 0) {
      FUN_00786620();
    }
    in_ECX = in_ECX + 0x44;
  }
  return;
}

