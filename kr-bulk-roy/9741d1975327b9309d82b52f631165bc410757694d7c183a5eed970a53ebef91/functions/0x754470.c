
void FUN_00754470(void)

{
  int *unaff_ESI;
  int local_18 [2];
  int local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  (**(code **)(*unaff_ESI + 0x17c))(local_18);
  if (unaff_ESI[0x2b] - unaff_ESI[0x29] < local_10 - local_18[0]) {
    (**(code **)(*unaff_ESI + 0xbc))
              (unaff_ESI[2],unaff_ESI[3],
               unaff_ESI[4] + ((unaff_ESI[0x29] - unaff_ESI[0x2b]) - local_18[0]) + local_10,
               unaff_ESI[5]);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

