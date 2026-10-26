
void FUN_006e3830(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined1 *in_ECX;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  float10 fVar7;
  undefined4 local_cc [19];
  undefined4 *local_80;
  int local_7c;
  int *local_78;
  float local_74;
  int *local_70;
  int local_6c;
  int local_68;
  int local_64;
  float local_60;
  undefined4 local_5c;
  undefined1 *local_58;
  undefined1 local_54 [60];
  undefined1 local_18 [12];
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_80 = param_1;
  local_5c = param_2;
  if (param_1 == (undefined4 *)0x0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_58 = in_ECX;
  iVar2 = FUN_006e3660(0);
  local_7c = iVar2;
  local_78 = (int *)FUN_006dfb80();
  if (in_ECX == (undefined1 *)0x0) {
    _memset(local_54,0,0x3c);
    local_58 = local_54;
  }
  FUN_006e39f0(param_2,local_58);
  local_60 = -1.0;
  local_6c = 0;
  local_68 = 0;
  if (0 < *(int *)(iVar2 + 0x58)) {
    do {
      iVar5 = local_68;
      puVar4 = *(undefined4 **)(*(int *)(iVar2 + 0x54) + local_68 * 4);
      (**(code **)(*local_78 + 0x20))(local_78,*puVar4,local_18);
      if (0 < (int)puVar4[0x198]) {
        local_70 = (int *)puVar4[0x197];
        local_64 = puVar4[0x198];
        do {
          iVar5 = *(int *)(*local_70 + 0x13c);
          if (0 < iVar5) {
            piVar3 = *(int **)(*local_70 + 0x138);
            do {
              iVar2 = *piVar3;
              if (((*(int *)(iVar2 + 0x10) == 0) || (*(int *)(iVar2 + 8) == local_c)) &&
                 (cVar1 = FUN_006e3c10(iVar2,local_5c,local_58), cVar1 != '\0')) {
                fVar7 = (float10)FUN_006e3f70(iVar2,local_cc,local_18);
                local_74 = (float)fVar7;
                if (local_60 < local_74) {
                  local_6c = iVar2;
                  local_60 = local_74;
                }
              }
              piVar3 = piVar3 + 1;
              iVar5 = iVar5 + -1;
              iVar2 = local_7c;
            } while (iVar5 != 0);
          }
          local_70 = local_70 + 1;
          local_64 = local_64 + -1;
        } while (local_64 != 0);
        local_64 = 0;
        iVar5 = local_68;
      }
      local_68 = iVar5 + 1;
    } while (local_68 < *(int *)(iVar2 + 0x58));
    if (local_6c != 0) {
      FUN_006e4450(local_cc,local_6c);
      puVar4 = local_cc;
      puVar6 = local_80;
      for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

