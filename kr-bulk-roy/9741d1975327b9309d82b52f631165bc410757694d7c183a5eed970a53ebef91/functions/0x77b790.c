
void FUN_0077b790(int param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 local_4c [5];
  uint local_38;
  undefined4 local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920880;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 != 0) {
    uVar1 = FUN_00765120(*(undefined1 *)(in_ECX + 8),local_14);
    *(undefined1 *)(in_ECX + 8) = uVar1;
    uVar1 = FUN_00765120(*(undefined1 *)(in_ECX + 9));
    *(undefined1 *)(in_ECX + 9) = uVar1;
    uVar1 = FUN_00765120(*(undefined1 *)(in_ECX + 10));
    *(undefined1 *)(in_ECX + 10) = uVar1;
    uVar1 = FUN_00765120(*(undefined1 *)(in_ECX + 0xb));
    *(undefined1 *)(in_ECX + 0xb) = uVar1;
    uVar2 = FUN_00764d80(local_30,&DAT_00bed1fc);
    local_8 = 0;
    FUN_00402800(uVar2);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    uVar2 = FUN_00764d80(local_30,&DAT_00bed1fc);
    local_8 = 1;
    FUN_00402800(uVar2);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    uVar2 = FUN_00764d80(local_30,&DAT_00bed1fc);
    local_8 = 2;
    FUN_00402800(uVar2);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    uVar2 = FUN_00764d80(local_30,&DAT_00bed1fc);
    local_8 = 3;
    FUN_00402800(uVar2);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    uVar2 = FUN_00764d80(local_30,&DAT_00bed1fc);
    local_8 = 4;
    FUN_00402800(uVar2);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    uVar2 = FUN_00764d80(local_30,&DAT_00bed1fc);
    local_8 = 5;
    FUN_00402800(uVar2);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    uVar2 = FUN_00764d80(local_30,&DAT_00bed1fc);
    local_8 = 6;
    FUN_00402800(uVar2);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    uVar2 = FUN_00764d80(local_4c,&DAT_00bed1fc);
    local_8 = 7;
    FUN_00402800(uVar2);
    if (7 < local_38) {
      FUN_0089120c(local_4c[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

