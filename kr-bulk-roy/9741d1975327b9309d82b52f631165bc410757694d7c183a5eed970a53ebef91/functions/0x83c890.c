
undefined4
FUN_0083c890(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined8 param_5
            )

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 auStack_100 [8];
  undefined1 local_f8 [72];
  int iStack_b0;
  int *local_a8;
  int *local_a4;
  void *local_4c;
  undefined1 *puStack_48;
  undefined4 local_44;
  
  local_44 = 0xffffffff;
  puStack_48 = &LAB_00906e4b;
  local_4c = ExceptionList;
  ExceptionList = &local_4c;
  FUN_008392d0(DAT_00d61f20 ^ (uint)&stack0xfffffec0);
  local_44 = 0;
  local_a4 = *(int **)(param_4 + 0x18);
  if (local_a4 != (int *)0x0) {
    (**(code **)(*local_a4 + 4))();
  }
  local_a8 = *(int **)(param_4 + 0x14);
  if (local_a8 != (int *)0x0) {
    (**(code **)(*local_a8 + 4))();
  }
  FUN_0083de80(local_f8,param_1,param_2,param_3,param_4,param_5);
  if (iStack_b0 == 1) {
    FUN_00841880();
    FUN_00841060();
  }
  else if (iStack_b0 == 2) {
    FUN_00841880();
    FUN_008410e0();
  }
  else if (iStack_b0 == 3) {
    uVar1 = FUN_00841880();
    FUN_00840fc0(in_ECX + 0x3c0,auStack_100,uVar1);
  }
  else {
    FUN_0083ec20();
  }
  local_44 = 0xffffffff;
  FUN_00839400();
  ExceptionList = local_4c;
  return 1;
}

