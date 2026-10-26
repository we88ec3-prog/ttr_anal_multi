
void FUN_00442680(void)

{
  int unaff_ESI;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if ((*(int *)(unaff_ESI + 0xf4) != 0) &&
     ((*(uint *)(*(int *)(unaff_ESI + 0xf4) + 0x28) >> 8 & 1) != 0)) {
    FUN_00443da0();
    FUN_00749970((*(int *)(*(int *)(unaff_ESI + 0xf4) + 0x2c) -
                 *(int *)(*(int *)(unaff_ESI + 0xf4) + 0x34)) + local_18,local_14);
    FUN_004418a0();
  }
  if ((*(int *)(unaff_ESI + 0xf8) != 0) &&
     ((*(uint *)(*(int *)(unaff_ESI + 0xf8) + 0x28) >> 8 & 1) != 0)) {
    FUN_00443da0();
    FUN_00749970(local_10,local_14);
    FUN_00749920(*(undefined4 *)(unaff_ESI + 0xf8));
  }
  return;
}

