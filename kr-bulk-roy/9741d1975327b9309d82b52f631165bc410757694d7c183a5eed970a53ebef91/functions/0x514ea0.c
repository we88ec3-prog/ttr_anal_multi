
int FUN_00514ea0(void)

{
  uint in_EAX;
  uint in_ECX;
  int unaff_ESI;
  int local_c;
  uint local_8;
  
  local_8 = (in_EAX & 0xff) << 0x10 | in_ECX & 0xff;
  FUN_00515790(&local_8);
  if (local_c != *(int *)(unaff_ESI + 4)) {
    return local_c + 0x10;
  }
  return 0;
}

