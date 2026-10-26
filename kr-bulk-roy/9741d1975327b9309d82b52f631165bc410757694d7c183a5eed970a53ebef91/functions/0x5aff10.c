
undefined4 FUN_005aff10(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x2905) {
    if (((param_1 == 0x2904) || (param_1 == 0x12)) || (param_1 == 0x13)) {
switchD_005aff3e_caseD_2905:
      return 1;
    }
    if (param_1 == 0x14) {
      return 1;
    }
  }
  else {
    switch(param_1) {
    case 0x2905:
    case 0x2906:
    case 0x2907:
    case 0x2908:
    case 0x2909:
    case 0x290d:
    case 0x290f:
    case 0x2910:
    case 0x2911:
    case 0x2912:
    case 0x2913:
    case 0x2915:
    case 0x2919:
    case 0x291a:
      goto switchD_005aff3e_caseD_2905;
    }
  }
  uVar1 = FUN_0059cc50(param_1);
  return uVar1;
}

