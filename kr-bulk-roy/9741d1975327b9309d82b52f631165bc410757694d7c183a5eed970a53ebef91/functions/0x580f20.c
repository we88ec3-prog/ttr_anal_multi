
uint FUN_00580f20(byte param_1)

{
  uint in_ECX;
  
  return ((((in_ECX >> 0x10 & 0xff) + 0x1fe) / 3 | (uint)param_1 << 8) << 8 |
         ((in_ECX >> 8 & 0xff) + 0x1fe) / 3) << 8 | ((in_ECX & 0xff) + 0x1fe) / 3;
}

