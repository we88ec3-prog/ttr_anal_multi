
undefined4 FUN_0059cc50(uint param_1)

{
  undefined4 uVar1;
  undefined4 in_ECX;
  
  if (DAT_00fbab38 == 0) {
    if (param_1 < 0x2afa) {
      if (param_1 == 0x2af9) {
        FUN_0059a230();
        return 1;
      }
      switch(param_1) {
      case 0x2904:
        FUN_0059a3a0();
        return 1;
      case 0x2905:
        FUN_00599ba0();
        return 1;
      case 0x2906:
        FUN_00599b70();
        return 1;
      case 0x2907:
        FUN_0059c430();
        return 1;
      case 0x2908:
        FUN_0059c460();
        return 1;
      case 0x2909:
        FUN_0059c2c0();
        return 1;
      case 0x290a:
        FUN_00599d00(in_ECX);
        return 1;
      case 0x290c:
        FUN_0059d990(in_ECX);
        return 1;
      case 0x290f:
        FUN_00599970(in_ECX);
        return 1;
      case 0x2910:
        FUN_0059c400();
        return 1;
      case 0x2911:
        FUN_0059a3d0();
        return 1;
      case 0x2912:
        FUN_0059c210();
        return 1;
      case 0x2916:
        goto switchD_0059cc87_caseD_2916;
      case 0x2917:
        FUN_00599fe0();
        return 1;
      case 0x2918:
        FUN_0059a060();
        return 1;
      case 0x2919:
        FUN_0059e030();
        return 1;
      case 0x291a:
        FUN_0059ded0(in_ECX);
        return 1;
      }
    }
  }
  else if (param_1 == 0x2916) {
switchD_0059cc87_caseD_2916:
    FUN_00599e90();
    return 1;
  }
  uVar1 = FUN_005a4b90(param_1);
  return uVar1;
}

