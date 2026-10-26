
void FUN_00570dd0(void)

{
  int *piVar1;
  int *unaff_ESI;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_18 = unaff_ESI[5] - unaff_ESI[1] / 2;
  local_14 = unaff_ESI[6] - unaff_ESI[2] / 2;
  local_10 = unaff_ESI[1] + local_18;
  local_c = unaff_ESI[2] + local_14;
  piVar1 = *(int **)(*unaff_ESI + 0x60);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))
              (unaff_ESI[3],unaff_ESI[4],&local_18,0,2,*(undefined4 *)(*unaff_ESI + 0x68),0xffffffff
              );
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

