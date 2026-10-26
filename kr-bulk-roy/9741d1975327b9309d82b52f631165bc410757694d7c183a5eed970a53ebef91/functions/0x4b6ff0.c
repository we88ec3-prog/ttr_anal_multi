
void FUN_004b6ff0(int param_1)

{
  short sVar1;
  int *piVar2;
  undefined4 uVar3;
  short ****ppppsVar4;
  short ****ppppsVar5;
  short ***local_5c [2];
  undefined4 ***local_54 [3];
  uint uStack_48;
  undefined4 local_40;
  undefined4 uStack_30;
  uint uStack_2c;
  uint uStack_24;
  void *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009309a5;
  local_14 = ExceptionList;
  local_1c = (void *)(DAT_00d61f20 ^ (uint)local_5c);
  ExceptionList = &local_14;
  if ((DAT_00fd9288 & 1) == 0) {
    DAT_00fd9288 = DAT_00fd9288 | 1;
    local_c = 0;
    FUN_0043f500(DAT_00d61f20 ^ (uint)&stack0xffffff98);
    _atexit((_func_4879 *)&LAB_00bce590);
  }
  local_c = 0xffffffff;
  FUN_0043ec80(*(undefined2 *)(param_1 + 2),*(undefined1 *)(param_1 + 4));
  local_c = 1;
  local_5c[0] = (short ***)FUN_00891268(0xc0);
  local_c._0_1_ = 2;
  if ((short ****)local_5c[0] == (short ****)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    if (local_40 < 8) {
      local_54[0] = local_54;
    }
    piVar2 = (int *)FUN_0043ed10(local_54[0]);
  }
  if ((DAT_00fb7354 & 1) == 0) {
    DAT_00fb7354 = DAT_00fb7354 | 1;
    local_c._0_1_ = 3;
    FUN_005533d0();
    _atexit((_func_4879 *)&LAB_00bcd100);
  }
  local_c = CONCAT31(local_c._1_3_,1);
  (**(code **)(*piVar2 + 4))();
  (**(code **)(*piVar2 + 0x20))(DAT_00fb73ac,DAT_00fb73b0);
  piVar2[0x10] = 0;
  uVar3 = FUN_0057ef20();
  FUN_0082f200(&DAT_00fb7378,uVar3);
  DAT_00fb7398 = DAT_00fb7398 + 1;
  ppppsVar5 = (short ****)local_5c[0];
  if (uStack_48 < 8) {
    ppppsVar5 = local_5c;
  }
  uStack_2c = 7;
  uStack_30 = 0;
  local_40 = (uint)local_40._2_2_ << 0x10;
  ppppsVar4 = ppppsVar5;
  do {
    sVar1 = *(short *)ppppsVar4;
    ppppsVar4 = (short ****)((int)ppppsVar4 + 2);
  } while (sVar1 != 0);
  FUN_00402160(ppppsVar5,(int)ppppsVar4 - (int)((int)ppppsVar5 + 2) >> 1);
  if ((DAT_00fb11e0 & 1) == 0) {
    DAT_00fb11e0 = DAT_00fb11e0 | 1;
    local_14._0_1_ = 5;
    FUN_004d4d10();
    _atexit((_func_4879 *)&LAB_00bccef0);
  }
  local_14 = (void *)CONCAT31(local_14._1_3_,4);
  FUN_004d6b30(&local_40);
  if (7 < uStack_2c) {
    FUN_0089120c(local_40);
  }
  if (7 < uStack_48) {
    FUN_0089120c(local_5c[0]);
  }
  ExceptionList = local_1c;
  __security_check_cookie(uStack_24 ^ (uint)&stack0xffffff9c);
  return;
}

