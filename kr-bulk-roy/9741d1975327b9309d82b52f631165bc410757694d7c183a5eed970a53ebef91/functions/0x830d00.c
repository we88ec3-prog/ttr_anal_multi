
short * FUN_00830d00(short *param_1,short *param_2,short *param_3)

{
  int *piVar1;
  char *pcVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00909409;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00830e10(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  *param_1 = *param_2 + *param_3;
  param_1[1] = param_2[1] + param_3[1];
  param_1[2] = param_2[2] + param_3[2];
  param_1[3] = param_2[3] + param_3[3];
  param_1[4] = param_2[4] + param_3[4];
  param_1[5] = param_2[5] + param_3[5];
  if (param_1 + 6 != param_2 + 6) {
    FUN_004ca160(**(undefined4 **)(param_1 + 8),*(undefined4 **)(param_1 + 8));
    FUN_005cfc80(param_2 + 6);
  }
  piVar1 = (int *)**(int **)(param_3 + 8);
  if (piVar1 == *(int **)(param_3 + 8)) {
    *(int *)(param_1 + 0xe) = *(int *)(param_2 + 0xe) + *(int *)(param_3 + 0xe);
    *(int *)(param_1 + 0x10) = *(int *)(param_2 + 0x10) + *(int *)(param_3 + 0x10);
    ExceptionList = local_10;
    return param_1;
  }
  do {
    pcVar2 = (char *)FUN_0081a580();
    *pcVar2 = *pcVar2 + *(char *)((int)piVar1 + 0xe);
  } while( true );
}

