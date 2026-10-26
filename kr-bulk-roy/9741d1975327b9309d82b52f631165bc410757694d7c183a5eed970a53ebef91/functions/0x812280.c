
undefined4 FUN_00812280(void)

{
  int in_ECX;
  undefined4 local_8;
  
  local_8 = 1;
  alGetBufferi(*(undefined4 *)(in_ECX + 8),0x2003,&local_8);
  alGetError();
  return local_8;
}

