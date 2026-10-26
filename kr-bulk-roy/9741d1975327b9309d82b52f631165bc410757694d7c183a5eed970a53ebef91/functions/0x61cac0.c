
void FUN_0061cac0(int param_1,byte param_2,int param_3,char param_4)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int in_ECX;
  byte bVar4;
  int in_EDX;
  undefined4 *puVar5;
  undefined1 auStack_44 [3];
  byte local_41;
  int local_40;
  int local_3c;
  uint local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093dde4;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_44;
  ExceptionList = &local_14;
  local_41 = param_2;
  if ((DAT_00fb11a8 & 1) == 0) {
    DAT_00fb11a8 = DAT_00fb11a8 | 1;
    local_c = 0;
    FUN_00813890(DAT_00d61f20 ^ (uint)&stack0xffffffb0);
    _atexit((_func_4879 *)&LAB_00bccec0);
  }
  local_c = 0xffffffff;
  local_40 = param_1;
  FUN_0082ef00(&local_40);
  if (local_3c == DAT_00fb11b0) {
    local_40 = 0;
  }
  else {
    local_40 = *(int *)(local_3c + 0x10);
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if (local_40 != 0) {
    cVar2 = FUN_0061d1e0(in_ECX,param_1,local_41 + 1);
    if (*(int *)(local_40 + 0x14) == *(int *)(local_40 + 0x18)) {
      bVar4 = 0;
    }
    else {
      bVar4 = (char)(*(int *)(local_40 + 0x18) - *(int *)(local_40 + 0x14) >> 2) - 1;
    }
    if (local_41 <= bVar4) {
      if (cVar2 == '\0') {
        param_3 = (in_EDX + 0xd) * 7 + param_3;
        puVar5 = (undefined4 *)(in_ECX + param_3 * 4);
        *(undefined4 *)(*(int *)(in_ECX + param_3 * 4) + 0x154) = 0xffff503c;
      }
      else {
        param_3 = (in_EDX + 0xd) * 7 + param_3;
        iVar1 = *(int *)(in_ECX + param_3 * 4);
        puVar5 = (undefined4 *)(in_ECX + param_3 * 4);
        if (param_4 == '\0') {
          *(undefined4 *)(iVar1 + 0x154) = 0xffffffff;
        }
        else {
          *(undefined4 *)(iVar1 + 0x154) = 0xff5aff78;
        }
      }
      uVar3 = FUN_00473ba0();
      local_c = 2;
      FUN_00757800(uVar3);
      local_c = 0xffffffff;
      if (7 < local_24) {
        FUN_0089120c(local_38);
      }
      local_38 = local_38 & 0xffff0000;
      local_24 = 7;
      local_28 = 0;
      (**(code **)(*(int *)*puVar5 + 200))();
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_44);
  return;
}

