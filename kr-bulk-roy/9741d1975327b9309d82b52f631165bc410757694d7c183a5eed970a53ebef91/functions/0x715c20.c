
undefined1 * FUN_00715c20(undefined1 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  FUN_00403040(in_ECX + 0x13c,0,0xffffffff);
  return param_1;
}

