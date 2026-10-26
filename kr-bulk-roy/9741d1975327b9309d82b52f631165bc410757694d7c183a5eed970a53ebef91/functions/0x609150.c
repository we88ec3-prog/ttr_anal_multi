
void FUN_00609150(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int *in_ECX;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 *local_2c;
  int local_28 [4];
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009416f8;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x40] + 0x20)) {
      FUN_00609550(in_ECX);
      ExceptionList = local_14;
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3e] + 0x20)) {
      FUN_006098b0(in_ECX);
    }
  }
  else if (iVar1 == 0xf43a9) {
    local_30 = 0;
    local_34 = 0;
    FUN_00404ba0(DAT_00d61f20 ^ (uint)&stack0xffffffc0);
    cVar3 = FUN_00509a00(in_ECX[0x59],&local_30,&local_34);
    if (cVar3 == '\0') {
      uVar5 = 0x196;
      FUN_005854b0(0x196,0,0);
      uVar5 = FUN_00585330(uVar5);
      uVar4 = 0x12;
      FUN_005854b0(0x12,uVar5);
      uVar5 = FUN_00585330(uVar4);
      FUN_00404b10(0xca,uVar5);
      FUN_0068a350();
      ExceptionList = local_14;
      return;
    }
    local_28[0] = 0;
    local_28[1] = 0;
    local_28[2] = 0;
    local_c = 0;
    local_2c = (undefined1 *)FUN_00891268(3);
    if (local_2c == (undefined1 *)0x0) {
      local_2c = (undefined1 *)0x0;
    }
    else {
      iVar1 = in_ECX[0x43];
      iVar2 = in_ECX[0x42];
      *local_2c = 1;
      local_2c[1] = (char)iVar2;
      local_2c[2] = (char)iVar1;
    }
    FUN_00443d10();
    FUN_00414680();
    FUN_004a39f0(local_30,local_34,in_ECX[0x59],local_28);
    if (local_28[0] != 0) {
      FUN_0089120c(local_28[0]);
      ExceptionList = local_14;
      return;
    }
  }
  else if (iVar1 == 0xf43aa) {
    FUN_00609ab0(in_ECX);
    (**(code **)(*in_ECX + 0x16c))(1);
    ExceptionList = pvStack_18;
    return;
  }
  ExceptionList = local_14;
  return;
}

