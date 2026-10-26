
void FUN_00677080(char *param_1,char *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  char *pcVar5;
  int *piVar6;
  char *pcVar7;
  undefined **local_28 [3];
  int *local_1c;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pcVar5 = param_1;
  puStack_c = &LAB_00928c13;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe6998 & 1) == 0) {
    DAT_00fe6998 = DAT_00fe6998 | 1;
    local_8 = 0;
    FUN_0051a650(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00519e80();
    _atexit(FUN_00bcfee0);
  }
  local_8 = 0xffffffff;
  param_1 = param_2;
  FUN_006a4510(&param_1);
  if (param_2 == DAT_00fe3704) {
    pcVar7 = (char *)0x0;
  }
  else {
    pcVar7 = param_2 + 0x10;
  }
  *(char **)(pcVar5 + 0x1b4) = pcVar7;
  uVar1 = *(undefined4 *)(pcVar7 + 4);
  uVar2 = *(undefined4 *)pcVar7;
  local_18 = 0;
  local_1c = (int *)FUN_00891268(0xc);
  if (local_1c != (int *)0x0) {
    *local_1c = (int)local_1c;
    local_1c[1] = (int)local_1c;
    local_8 = 2;
    FUN_00678310(&local_1c,uVar2,uVar1,param_1);
    local_8 = 3;
    FUN_00677ed0();
    piVar6 = local_1c;
    piVar3 = (int *)*local_1c;
    *local_1c = (int)local_1c;
    local_1c[1] = (int)local_1c;
    while (piVar3 != piVar6) {
      piVar4 = (int *)*piVar3;
      FUN_0089120c(piVar3);
      piVar3 = piVar4;
    }
    FUN_0089120c(piVar6);
    ExceptionList = local_10;
    return;
  }
  param_1 = (char *)0x0;
  std::exception::exception((exception *)local_28,&param_1);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}

