
uint FUN_008699d0(void)

{
  uint uVar1;
  uint local_c;
  undefined1 local_8 [4];
  
  uVar1 = FUN_00869930(0x80000000,&local_c,local_8,local_8,local_8);
  if (((char)uVar1 != '\0') && (0x80000000 < local_c)) {
    uVar1 = FUN_00869930(0x80000001,local_8,local_8,local_8,&local_c);
    if ((char)uVar1 != '\0') {
      return local_c >> 0x1f;
    }
  }
  return uVar1 & 0xffffff00;
}

