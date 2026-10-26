
/* WARNING: Removing unreachable block (ram,0x0056e5c6) */
/* WARNING: Removing unreachable block (ram,0x0056e4f1) */
/* WARNING: Removing unreachable block (ram,0x0056e501) */
/* WARNING: Removing unreachable block (ram,0x0056e519) */
/* WARNING: Removing unreachable block (ram,0x0056e446) */
/* WARNING: Removing unreachable block (ram,0x0056e527) */
/* WARNING: Removing unreachable block (ram,0x0056e547) */
/* WARNING: Removing unreachable block (ram,0x0056e53e) */
/* WARNING: Removing unreachable block (ram,0x0056e549) */
/* WARNING: Removing unreachable block (ram,0x0056e5a9) */
/* WARNING: Removing unreachable block (ram,0x0056e5af) */
/* WARNING: Removing unreachable block (ram,0x0056e5cc) */
/* WARNING: Removing unreachable block (ram,0x0056e5de) */
/* WARNING: Removing unreachable block (ram,0x0056e5ee) */
/* WARNING: Removing unreachable block (ram,0x0056e5f4) */
/* WARNING: Removing unreachable block (ram,0x0056e61d) */
/* WARNING: Removing unreachable block (ram,0x0056e62b) */
/* WARNING: Removing unreachable block (ram,0x0056e631) */
/* WARNING: Removing unreachable block (ram,0x0056e66d) */
/* WARNING: Removing unreachable block (ram,0x0056e67a) */
/* WARNING: Removing unreachable block (ram,0x0056e69c) */
/* WARNING: Removing unreachable block (ram,0x0056e6a8) */
/* WARNING: Removing unreachable block (ram,0x0056e6bc) */

undefined4 FUN_0056e330(undefined4 *param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  char *in_ECX;
  int *piStack_24;
  void *local_14;
  undefined1 *puStack_10;
  int iStack_c;
  
  iStack_c = 0xffffffff;
  puStack_10 = &LAB_00936304;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((undefined4 *)param_1[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[7])(1,DAT_00d61f20 ^ (uint)&stack0xffffffa8);
    param_1[7] = 0;
  }
  param_1[4] = 0;
  puVar2 = param_1;
  if (0xf < (uint)param_1[5]) {
    puVar2 = (undefined4 *)*param_1;
  }
  *(undefined1 *)puVar2 = 0;
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
  iStack_c._0_1_ = 0;
  iStack_c._1_3_ = 0;
  if (param_2 != 0) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      iStack_c._0_1_ = 1;
      iStack_c._1_3_ = 0;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    iStack_c._0_1_ = 0;
    if (DAT_00fab1d0 != 0) {
      FUN_0056ddf0();
      iStack_c._0_1_ = 2;
      FUN_004e0f60();
      iStack_c._0_1_ = 0;
      if (piStack_24 != (int *)0x0) {
        LOCK();
        iVar5 = piStack_24[1] + -1;
        piStack_24[1] = iVar5;
        UNLOCK();
        if (iVar5 == 0) {
          (**(code **)*piStack_24)();
          LOCK();
          iVar5 = piStack_24[2] + -1;
          piStack_24[2] = iVar5;
          UNLOCK();
          if (iVar5 == 0) {
            (**(code **)(*piStack_24 + 4))();
          }
        }
      }
    }
  }
  pcVar3 = in_ECX + 1;
  do {
    cVar1 = *in_ECX;
    in_ECX = in_ECX + 1;
  } while (cVar1 != '\0');
  if (in_ECX != pcVar3) {
    uVar4 = FUN_00734330();
    param_1[7] = uVar4;
  }
  if (param_1[7] == 0) {
    iVar5 = FUN_00891268(0x48);
    iStack_c._0_1_ = 4;
    if (iVar5 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_00734010();
    }
    iStack_c = (uint)iStack_c._1_3_ << 8;
    param_1[7] = uVar4;
    FUN_007343d0(0x100);
    FUN_00734470(param_1[7],0xff000000);
  }
  ExceptionList = local_14;
  return 1;
}

