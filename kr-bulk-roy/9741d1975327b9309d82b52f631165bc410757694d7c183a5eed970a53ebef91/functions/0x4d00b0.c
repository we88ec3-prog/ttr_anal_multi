
undefined4 FUN_004d00b0(void)

{
  int *in_ECX;
  
  *(char *)(in_ECX + 0x41) = (char)in_ECX[0x2c];
  in_ECX[0x3e] = in_ECX[0x28];
  in_ECX[0x3f] = in_ECX[0x29];
  in_ECX[0x40] = in_ECX[0x2a];
  (**(code **)(*in_ECX + 0x10))();
  return 1;
}

