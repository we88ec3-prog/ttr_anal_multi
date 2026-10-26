
void FUN_008eac50(undefined4 param_1,short param_2)

{
  int in_EAX;
  short *in_ECX;
  short *in_EDX;
  
  if (*(char *)(in_EAX + 0x124) != '\0') {
    (**(code **)(*(int *)(in_EAX + 0x214) + 0x70))();
    return;
  }
  if (*(short *)(in_EAX + 0x16c) != -1) {
    *in_EDX = *(short *)(in_EAX + 0x1b2) - param_2;
    *in_ECX = *(short *)(in_EAX + 0x1b2) - *(short *)(in_EAX + 0x1b4);
    return;
  }
  *in_EDX = *(short *)(in_EAX + 0xdc) - param_2;
  *in_ECX = *(short *)(in_EAX + 0xdc) - *(short *)(in_EAX + 0xde);
  return;
}

