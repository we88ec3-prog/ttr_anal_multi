
undefined4 FUN_004d0fe0(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  uVar1 = FUN_004c7df0(unaff_ESI,1);
  (**(code **)(*(int *)(unaff_ESI + 0xf0) + 8))(0x14);
  if (*(int *)(unaff_ESI + 0x368) != 0) {
    *(undefined4 *)(*(int *)(unaff_ESI + 0x368) + 0x24) = 0;
  }
  if (*(int *)(unaff_ESI + 0x15c) != 0) {
    FUN_007a7240(*(int *)(unaff_ESI + 0x15c),*(int *)(*(int *)(unaff_ESI + 0x15c) + 0x18) + 31000,0,
                 0);
    *(undefined4 *)(*(int *)(unaff_ESI + 0x15c) + 0x13c) = 0;
  }
  return uVar1;
}

