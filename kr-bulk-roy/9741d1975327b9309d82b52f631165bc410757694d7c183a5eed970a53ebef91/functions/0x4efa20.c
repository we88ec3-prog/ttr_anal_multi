
undefined4 FUN_004efa20(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092fa30;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch((&DAT_004efbd8)[param_2]) {
  case 0:
    FUN_004054c0();
    FUN_0058ab80();
    ExceptionList = local_10;
    return 0;
  case 1:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 0;
    break;
  case 2:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 1;
    break;
  case 3:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 2;
    break;
  case 4:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 3;
    break;
  case 5:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 4;
    break;
  case 6:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 5;
    break;
  case 7:
    goto switchD_004efa4d_caseD_7;
  }
  FUN_005854b0();
  uVar1 = FUN_00585330();
  FUN_00402250(uVar1);
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
switchD_004efa4d_caseD_7:
  ExceptionList = local_10;
  return 0;
}

