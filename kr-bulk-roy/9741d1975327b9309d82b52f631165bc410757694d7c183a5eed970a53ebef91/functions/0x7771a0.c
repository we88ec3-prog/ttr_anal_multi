
undefined4 FUN_007771a0(void)

{
  ushort uVar1;
  ushort *in_EAX;
  
  uVar1 = *in_EAX;
  if (((uVar1 < 0xe32) || (0xe33 < uVar1)) && ((uVar1 < 0xe45 || (0xe46 < uVar1)))) {
    return 0;
  }
  return 1;
}

