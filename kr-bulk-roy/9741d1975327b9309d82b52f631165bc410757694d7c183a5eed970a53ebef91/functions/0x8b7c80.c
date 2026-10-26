
uint FUN_008b7c80(int param_1)

{
  if (-1 < param_1) {
    return param_1 + 0x8000U & 0xffff0000;
  }
  return -(0x8000U - param_1 & 0xffff0000);
}

