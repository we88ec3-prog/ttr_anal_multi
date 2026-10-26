
void FUN_0059c610(void)

{
  int in_EAX;
  undefined4 unaff_EDI;
  
  if (*(int *)(in_EAX + 0x10) == 0xf424c) {
    FUN_0059c570(unaff_EDI);
  }
  else if (*(int *)(in_EAX + 0x10) == 0xf424f) {
    FUN_0059c5c0(unaff_EDI);
    FUN_0063ae70();
    return;
  }
  FUN_0063ae70();
  return;
}

