
void FUN_00765c70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  void *pvVar2;
  int *piVar3;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919048;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  in_ECX[0x4a] = 0x14;
  FUN_00745a50(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  (**(code **)(*in_ECX + 0x180))(uVar1);
  pvVar2 = _malloc(0xe0);
  local_8 = 0;
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0075da10();
  }
  local_8 = 0xffffffff;
  in_ECX[0x43] = (int)piVar3;
  (**(code **)(*piVar3 + 0x38))
            (0,0x41c3,(in_ECX[4] - in_ECX[2]) - in_ECX[0x4a],0,in_ECX[4] - in_ECX[2],
             in_ECX[5] - in_ECX[3]);
  FUN_00767ec0();
  ExceptionList = local_10;
  return;
}

