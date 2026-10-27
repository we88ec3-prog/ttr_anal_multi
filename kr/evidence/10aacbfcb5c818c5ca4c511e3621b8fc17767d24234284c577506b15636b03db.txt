
undefined2 FUN_0081a8e0(int param_1)

{
  byte in_AL;
  byte in_CL;
  
  if ((in_AL < 4) && (in_CL < 0xb)) {
    return *(undefined2 *)(param_1 + 4 + ((uint)in_AL * 0xb + (uint)in_CL) * 2);
  }
  return 0;
}

