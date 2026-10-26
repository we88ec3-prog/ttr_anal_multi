
void FUN_00403130(undefined4 param_1)

{
  undefined1 *in_ECX;
  
  *(undefined4 *)(in_ECX + 0x14) = 0xf;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *in_ECX = 0;
  FUN_00403040(param_1,0,0xffffffff);
  return;
}

