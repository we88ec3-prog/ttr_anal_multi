
void FUN_00413570(void)

{
  int in_ECX;
  
  if ((*(uint *)(in_ECX + 0x28) >> 8 & 1) != 0) {
    FUN_004138c0();
    FUN_00413960();
    return;
  }
  return;
}

