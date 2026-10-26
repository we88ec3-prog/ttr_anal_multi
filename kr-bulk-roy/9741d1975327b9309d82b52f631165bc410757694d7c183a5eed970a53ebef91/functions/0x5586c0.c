
void FUN_005586c0(char *param_1,byte *param_2)

{
  *param_1 = (param_2[1] & 0xfc) * '\x02';
  param_1[1] = *param_2 >> 2 & 0x38 | param_2[1] << 6;
  param_1[2] = *param_2 * '\b';
  param_1[3] = param_2[1] & 0x80;
  return;
}

