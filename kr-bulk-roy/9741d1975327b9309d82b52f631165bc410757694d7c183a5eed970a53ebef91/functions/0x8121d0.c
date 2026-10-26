
float10 FUN_008121d0(void)

{
  int in_ECX;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = 0xac44;
  local_8 = 0x10;
  local_10 = 1;
  local_c = 0;
  alGetBufferi(*(undefined4 *)(in_ECX + 8),0x2001,&local_14);
  alGetError();
  alGetBufferi(*(undefined4 *)(in_ECX + 8),0x2002,&local_8);
  alGetError();
  alGetBufferi(*(undefined4 *)(in_ECX + 8),0x2003,&local_10);
  alGetError();
  alGetBufferi(*(undefined4 *)(in_ECX + 8),0x2004,&local_c);
  alGetError();
  return (float10)((float)local_c /
                  (float)(local_10 * ((int)(local_8 + (local_8 >> 0x1f & 7U)) >> 3) * local_14));
}

