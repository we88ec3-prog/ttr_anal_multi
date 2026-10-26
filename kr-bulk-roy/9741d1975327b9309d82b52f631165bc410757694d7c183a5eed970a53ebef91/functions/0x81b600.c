
undefined4 FUN_0081b600(void)

{
  int in_EAX;
  int in_ECX;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x14) != 0) {
    in_ECX = (in_EAX / in_ECX) * 100;
  }
  if (((*(int *)(unaff_ESI + 0xc) == 0) || (*(int *)(unaff_ESI + 0xc) <= in_ECX)) &&
     ((*(int *)(unaff_ESI + 0x10) == 0 || (in_ECX <= *(int *)(unaff_ESI + 0x10))))) {
    return 1;
  }
  return 0;
}

