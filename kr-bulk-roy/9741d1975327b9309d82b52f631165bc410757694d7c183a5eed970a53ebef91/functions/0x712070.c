
void FUN_00712070(void)

{
  int *in_EAX;
  int in_ECX;
  
  if (((*in_EAX == 0xc) && ((in_EAX[2] & 0x100U) == 0)) &&
     ((int)(uint)*(byte *)(in_ECX + 0x32) <= in_EAX[2])) {
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + -1;
  }
  return;
}

