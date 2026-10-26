
int FUN_0080c950(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int local_8;
  
  if (param_1[0x11] != 0) {
    return -0x7fffbffb;
  }
  local_8 = 0;
  iVar2 = 0;
  do {
    piVar1 = (int *)FUN_00891268(0x40);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1[9] = 0x3f800000;
      *piVar1 = (int)MoonSound::CStreamDriver::vftable;
      piVar1[1] = 0;
      piVar1[2] = 0;
      piVar1[3] = 0;
      piVar1[4] = 0;
      piVar1[5] = 0;
      piVar1[6] = 0;
      piVar1[7] = 0;
      piVar1[8] = 0;
      InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(piVar1 + 10),4000);
    }
    param_1[local_8] = piVar1;
    if (iVar2 < 0) {
LAB_0080c9d8:
      iVar2 = -0x7fffbffb;
    }
    else {
      iVar2 = (**(code **)(*piVar1 + 4))(param_2);
      if (iVar2 < 0) goto LAB_0080c9d8;
      iVar2 = 0;
    }
    local_8 = local_8 + 1;
    if (0xf < local_8) {
      param_1[0x11] = *param_1;
      return iVar2;
    }
  } while( true );
}

