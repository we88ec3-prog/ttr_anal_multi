
undefined4 FUN_004b9770(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009493e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  switch(*(undefined1 *)(param_1 + 2)) {
  case 0:
    piVar2 = (int *)FUN_00891268(0x6104);
    local_8 = 0;
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      FUN_004b9e30();
      *piVar2 = (int)Scene::CScenarioDecision::vftable;
      DAT_00d6a674 = 0x53434544;
    }
    local_8 = 0xffffffff;
    FUN_004b7d50();
    (**(code **)(*piVar2 + 0x38))(param_1,param_2,param_3);
    ExceptionList = local_10;
    return 0;
  case 1:
    iVar1 = FUN_00891268(0xbfac);
    local_8 = 2;
    if (iVar1 != 0) {
      piVar2 = (int *)FUN_004bd590();
      goto LAB_004b9933;
    }
    break;
  case 2:
    iVar1 = FUN_00891268(0xbfc4);
    local_8 = 1;
    if (iVar1 != 0) {
      piVar2 = (int *)FUN_004bc170();
      goto LAB_004b9933;
    }
    break;
  case 3:
    iVar1 = FUN_00891268(0xbfa8);
    local_8 = 4;
    if (iVar1 != 0) {
      piVar2 = (int *)FUN_004c4fb0();
      goto LAB_004b9933;
    }
    break;
  case 4:
    iVar1 = FUN_00891268(0xbfa8);
    local_8 = 3;
    if (iVar1 != 0) {
      piVar2 = (int *)FUN_004c0610();
      goto LAB_004b9933;
    }
    break;
  case 5:
    iVar1 = FUN_00891268(0xbfa8);
    local_8 = 5;
    if (iVar1 != 0) {
      piVar2 = (int *)FUN_00453e60();
      goto LAB_004b9933;
    }
    break;
  case 6:
    iVar1 = FUN_00891268(0xbfa8);
    local_8 = 6;
    if (iVar1 != 0) {
      piVar2 = (int *)FUN_00434320();
      goto LAB_004b9933;
    }
    break;
  case 7:
    iVar1 = FUN_00891268(0xbfa8);
    local_8 = 7;
    if (iVar1 != 0) {
      piVar2 = (int *)FUN_00422440();
      goto LAB_004b9933;
    }
    break;
  default:
    FUN_006edb60(&DAT_00c06e90,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    ExceptionList = local_10;
    return 0x80004005;
  }
  piVar2 = (int *)0x0;
LAB_004b9933:
  local_8 = 0xffffffff;
  FUN_004b7d50();
  (**(code **)(*piVar2 + 0x38))(param_1,param_2,param_3);
  ExceptionList = local_10;
  return 0;
}

