
undefined4 FUN_008e0d00(void)

{
  undefined4 uVar1;
  undefined4 *in_EAX;
  int in_ECX;
  uint uVar2;
  int unaff_ESI;
  
  *in_EAX = 0;
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  uVar2 = in_ECX + *(int *)(unaff_ESI + 900);
  if (*(uint *)(unaff_ESI + 0x37c) <= uVar2) {
    return 1;
  }
  uVar1 = *(undefined4 *)(*(int *)(unaff_ESI + 0x38c) + uVar2 * 4);
  in_EAX[3] = uVar1;
  in_EAX[1] = uVar1;
  in_EAX[2] = *(undefined4 *)(*(int *)(unaff_ESI + 0x38c) + 4 + uVar2 * 4);
  return 0;
}

