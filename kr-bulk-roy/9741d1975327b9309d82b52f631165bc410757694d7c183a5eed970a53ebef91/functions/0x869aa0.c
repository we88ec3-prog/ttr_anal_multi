
uint FUN_00869aa0(void)

{
  uint uVar1;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  undefined1 local_8 [4];
  
  local_c = 0;
  local_10 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  uVar1 = FUN_00869930(0,local_8,&local_1c,&local_14,&local_18);
  if ((char)uVar1 != '\0') {
    uVar1 = FUN_00869930(1,&local_c,local_8,local_8,&local_10);
    if ((((char)uVar1 != '\0') &&
        (((uVar1 = local_c, (local_c & 0xf00) == 0xf00 || ((local_c & 0xf00000) != 0)) &&
         (local_1c == 0x756e6547)))) && ((local_18 == 0x49656e69 && (local_14 == 0x6c65746e)))) {
      return local_10 >> 0x1c & 1;
    }
  }
  return uVar1 & 0xffffff00;
}

