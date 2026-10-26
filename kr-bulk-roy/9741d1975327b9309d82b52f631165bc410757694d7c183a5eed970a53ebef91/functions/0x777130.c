
undefined4 FUN_00777130(void)

{
  ushort *in_EAX;
  
  if ((0xe00 < *in_EAX) && (*in_EAX < 0xe2f)) {
    return 1;
  }
  return 0;
}

