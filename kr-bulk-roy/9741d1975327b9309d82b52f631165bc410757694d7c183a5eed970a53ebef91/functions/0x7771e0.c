
bool FUN_007771e0(void)

{
  short in_AX;
  
  if ((((in_AX != 0xe3a) && (2 < (ushort)(in_AX - 0xe4dU))) && (1 < (ushort)(in_AX - 0xe5aU))) &&
     (((in_AX != 0xe2f && (in_AX != 0xe3f)) && (3 < (ushort)(in_AX - 0xe48U))))) {
    return (ushort)(in_AX - 0xe50U) < 10;
  }
  return true;
}

