
undefined1 FUN_0081b3d0(void)

{
  int in_ECX;
  byte in_DL;
  
  if (((*(byte *)(in_ECX + 10) == 0) || (*(byte *)(in_ECX + 10) <= in_DL)) &&
     ((*(byte *)(in_ECX + 0xb) == 0 || (in_DL <= *(byte *)(in_ECX + 0xb))))) {
    return 1;
  }
  return 0;
}

