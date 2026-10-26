
void FUN_00494c40(undefined1 *param_1)

{
  BOOL BVar1;
  ushort local_c [2];
  ushort local_8 [2];
  
  BVar1 = FileTimeToLocalFileTime((FILETIME *)&stack0x00000008,(FILETIME *)&stack0x00000008);
  if (BVar1 != 0) {
    BVar1 = FileTimeToDosDateTime((FILETIME *)&stack0x00000008,local_c,local_8);
    if (BVar1 != 0) {
      FUN_0049ae90("%d/%d/%d %02d:%02d:%02d",local_c[0] >> 5 & 0xf,local_c[0] & 0x1f,
                   (local_c[0] >> 9) + 0x7bc,local_8[0] >> 0xb,local_8[0] >> 5 & 0x3f,
                   (local_8[0] & 0x1f) * 2);
      return;
    }
  }
  *param_1 = 0;
  return;
}

