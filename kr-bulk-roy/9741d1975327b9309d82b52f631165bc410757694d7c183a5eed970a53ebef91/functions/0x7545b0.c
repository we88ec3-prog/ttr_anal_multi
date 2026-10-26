
void FUN_007545b0(void)

{
  int *unaff_ESI;
  undefined1 local_18 [4];
  int local_14;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  (**(code **)(*unaff_ESI + 0x178))(local_18);
  (**(code **)(*unaff_ESI + 0xbc))
            (unaff_ESI[2],unaff_ESI[3],unaff_ESI[4],
             ((unaff_ESI[0x30] + unaff_ESI[0x31] * 2 + unaff_ESI[0x2e]) - local_14) + unaff_ESI[3] +
             local_c);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

