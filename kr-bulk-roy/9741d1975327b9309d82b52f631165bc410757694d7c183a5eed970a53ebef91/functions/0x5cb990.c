
uint FUN_005cb990(void)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = (**(code **)(*in_ECX + 0x30))();
  return uVar1 & 0xffffff00;
}

