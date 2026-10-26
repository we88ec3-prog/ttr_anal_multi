
void FUN_0064e970(char param_1)

{
  int iVar1;
  int *in_EAX;
  
  (**(code **)(*in_EAX + 0x16c))(param_1 == '\0');
  if (param_1 == '\0') {
    if ((in_EAX[10] & 4U) != 0) {
      in_EAX[10] = in_EAX[10] ^ 4;
    }
  }
  else {
    in_EAX[10] = in_EAX[10] | 4;
  }
  iVar1 = in_EAX[0x20];
  if (param_1 != '\0') {
    *(uint *)(iVar1 + 0x28) = *(uint *)(iVar1 + 0x28) | 4;
    return;
  }
  if ((*(uint *)(iVar1 + 0x28) & 4) != 0) {
    *(uint *)(iVar1 + 0x28) = *(uint *)(iVar1 + 0x28) ^ 4;
  }
  return;
}

