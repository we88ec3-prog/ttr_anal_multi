
void FUN_0044ca40(void)

{
  BOOL BVar1;
  LPSTR unaff_ESI;
  ushort local_c [2];
  ushort local_8 [2];
  
  BVar1 = FileTimeToLocalFileTime((FILETIME *)&stack0x00000004,(FILETIME *)&stack0x00000004);
  if (BVar1 != 0) {
    BVar1 = FileTimeToDosDateTime((FILETIME *)&stack0x00000004,local_c,local_8);
    if (BVar1 != 0) {
      wsprintfA(unaff_ESI,"%d/%d/%d %02d:%02d:%02d",local_c[0] >> 5 & 0xf,local_c[0] & 0x1f,
                (local_c[0] >> 9) + 0x7bc,(uint)(local_8[0] >> 0xb),local_8[0] >> 5 & 0x3f,
                (local_8[0] & 0x1f) * 2);
      return;
    }
  }
  *unaff_ESI = '\0';
  return;
}

