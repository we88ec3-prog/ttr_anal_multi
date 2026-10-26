
undefined4 FUN_005b45b0(uint param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x310) == '\0') {
switchD_005b45d0_default:
    uVar1 = FUN_005b97a0(param_1);
    return uVar1;
  }
  if (0x2904 < param_1) {
    switch(param_1) {
    case 0x2905:
    case 0x2906:
    case 0x2907:
    case 0x2908:
    case 0x2909:
    case 0x290a:
    case 0x290d:
    case 0x290f:
    case 0x2910:
    case 0x2911:
    case 0x2912:
    case 0x2913:
    case 0x2915:
    case 0x2919:
    case 0x291a:
      goto switchD_005b45d0_caseD_11;
    default:
      goto switchD_005b45d0_default;
    }
  }
  if (param_1 != 0x2904) {
    switch(param_1) {
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
      break;
    default:
      goto switchD_005b45d0_default;
    }
  }
switchD_005b45d0_caseD_11:
  return 1;
}

