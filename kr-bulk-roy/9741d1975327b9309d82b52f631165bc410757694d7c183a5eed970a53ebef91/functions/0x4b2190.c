
undefined4 FUN_004b2190(int param_1,uint param_2)

{
  char *pcVar1;
  uint uVar2;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00947c5c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_1c = param_1 + 4;
  uVar2 = 4;
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_c = 0;
    FUN_004ffe60(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    _atexit((_func_4879 *)&LAB_00bccf00);
  }
  local_c = 0xffffffff;
  FUN_00500110();
  while (uVar2 < param_2) {
    pcVar1 = (char *)(local_1c + 1);
    switch(*(undefined1 *)(local_1c + 1)) {
    case 1:
    case 3:
      local_1c = local_1c + 0xf;
      uVar2 = uVar2 + 0xf;
      break;
    case 2:
    case 5:
    case 0xb:
      local_1c = local_1c + 0xb;
      uVar2 = uVar2 + 0xb;
      break;
    case 4:
    case 6:
      local_1c = local_1c + 0xd;
      uVar2 = uVar2 + 0xd;
      break;
    case 7:
    case 8:
      local_1c = local_1c + 10;
      uVar2 = uVar2 + 10;
      break;
    case 9:
      local_1c = local_1c + 9;
      uVar2 = uVar2 + 9;
      break;
    default:
      goto switchD_004b2231_caseD_a;
    }
    if (param_2 < uVar2) {
      FUN_006edb60(&DAT_00bf6cbc);
    }
    if (*pcVar1 != '\t') {
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        local_c = 1;
        FUN_004dec90();
        _atexit((_func_4879 *)&LAB_00bcce30);
        local_c = 0xffffffff;
      }
      FUN_0053d840(DAT_00fab134,(int)*(short *)(param_1 + 2));
    }
  }
switchD_004b2231_caseD_a:
  ExceptionList = local_14;
  return 0;
}

