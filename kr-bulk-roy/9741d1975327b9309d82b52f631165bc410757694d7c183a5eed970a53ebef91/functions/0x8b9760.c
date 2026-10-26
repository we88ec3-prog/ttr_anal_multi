
undefined4 FUN_008b9760(void)

{
  uint in_EAX;
  
  if (8 < in_EAX) {
    return 0xfffffffe;
  }
  return *(undefined4 *)(&DAT_00bd6ddc + in_EAX * 8);
}

