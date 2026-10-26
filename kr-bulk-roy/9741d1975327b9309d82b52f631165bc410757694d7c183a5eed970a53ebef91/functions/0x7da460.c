
void FUN_007da460(float param_1)

{
  uint in_EAX;
  float *pfVar1;
  int in_ECX;
  int unaff_EDI;
  
  if ((*(int *)(in_ECX + 0x114) != *(int *)(in_ECX + 0x118)) &&
     (in_EAX <= (uint)(*(int *)(in_ECX + 0x118) - *(int *)(in_ECX + 0x114) >> 2))) {
    *(uint *)(in_ECX + 0x110) = in_EAX;
    if (in_EAX != 0) {
      pfVar1 = (float *)(*(int *)(in_ECX + 0xc0) + 0xc);
      do {
        in_EAX = in_EAX - 1;
        param_1 = param_1 - (pfVar1[1] + *pfVar1);
        pfVar1 = pfVar1 + 5;
      } while (in_EAX != 0);
    }
    if (unaff_EDI != 0) {
      FUN_007dbb40(*(undefined4 *)(unaff_EDI + 0x10),param_1);
    }
  }
  return;
}

