
void FUN_004c5970(void)

{
  int unaff_ESI;
  
  _memset((void *)(unaff_ESI + 0x5eac),0,0x5ea8);
  *(code **)(unaff_ESI + 0x5fa4) = FUN_004c5c50;
  *(undefined1 **)(unaff_ESI + 0x5fa8) = &DAT_00bf2375;
  *(code **)(unaff_ESI + 0x5fd4) = FUN_004c5c50;
  *(undefined1 **)(unaff_ESI + 0x5fd8) = &DAT_00bf2375;
  *(code **)(unaff_ESI + 0x61bc) = FUN_004c5cb0;
  *(undefined1 **)(unaff_ESI + 0x61c0) = &DAT_00bf2375;
  *(code **)(unaff_ESI + 0x63e4) = FUN_00424610;
  *(undefined1 **)(unaff_ESI + 0x63e8) = &DAT_00bf2375;
  return;
}

