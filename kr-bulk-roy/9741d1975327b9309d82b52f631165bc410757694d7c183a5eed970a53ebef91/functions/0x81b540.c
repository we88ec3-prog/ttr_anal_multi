
undefined1 FUN_0081b540(void)

{
  int in_ECX;
  byte in_DL;
  
  if (((*(byte *)(in_ECX + 0xd) == 0) || (*(byte *)(in_ECX + 0xd) <= in_DL)) &&
     ((*(byte *)(in_ECX + 0xe) == 0 || (in_DL <= *(byte *)(in_ECX + 0xe))))) {
    return 1;
  }
  return 0;
}

