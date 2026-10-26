
undefined4 FUN_004dc700(void)

{
  int unaff_ESI;
  int local_8;
  
  FUN_004dd400(unaff_ESI,&local_8,&stack0x00000004);
  if (local_8 != *(int *)(unaff_ESI + 4)) {
    return *(undefined4 *)(local_8 + 0x18);
  }
  return 0;
}

