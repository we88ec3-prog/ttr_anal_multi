
void FUN_004c5520(void)

{
  int unaff_ESI;
  
  _memset((void *)(unaff_ESI + 0x5eac),0,0x5ea8);
  *(undefined1 **)(unaff_ESI + 0x5f4c) = &LAB_004c5930;
  *(undefined1 **)(unaff_ESI + 0x5f50) = &DAT_00bf2375;
  *(code **)(unaff_ESI + 0x6074) = FUN_004c5610;
  *(undefined1 **)(unaff_ESI + 0x6078) = &DAT_00bf2375;
  *(code **)(unaff_ESI + 0x607c) = FUN_004c58a0;
  *(undefined1 **)(unaff_ESI + 0x6080) = &DAT_00bf2375;
  *(code **)(unaff_ESI + 0x6034) = FUN_004bca90;
  *(undefined1 **)(unaff_ESI + 0x6038) = &DAT_00bf2375;
  *(code **)(unaff_ESI + 0x6084) = FUN_004c5590;
  *(undefined1 **)(unaff_ESI + 0x6088) = &DAT_00bf2375;
  return;
}

