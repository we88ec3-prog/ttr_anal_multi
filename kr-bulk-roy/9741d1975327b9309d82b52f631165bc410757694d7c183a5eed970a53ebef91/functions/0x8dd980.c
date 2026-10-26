
undefined2 FUN_008dd980(void)

{
  uint in_EAX;
  
  if (in_EAX < 0x100) {
    return *(undefined2 *)((int)&DAT_00be9d00 + in_EAX * 2);
  }
  return 0;
}

