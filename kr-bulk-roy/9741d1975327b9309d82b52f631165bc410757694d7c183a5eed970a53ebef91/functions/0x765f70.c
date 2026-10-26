
void FUN_00765f70(undefined4 param_1,short *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090ccab;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00765af0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  iVar2 = FUN_00891268(0x38);
  local_8 = 0;
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00757200(iVar2);
  }
  local_8 = 0xffffffff;
  do {
    sVar1 = *param_2;
    param_2 = param_2 + 1;
  } while (sVar1 != 0);
  FUN_00757da0(uVar3);
  FUN_007bb350();
  FUN_00766390(0,0,0);
  FUN_00767fa0();
  ExceptionList = local_10;
  return;
}

